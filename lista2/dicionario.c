#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 1000
#define TAM_PALAVRA 64 /* bytes, incluindo o '\0' */
#define MAX_CP 64      /* máximo de letras por palavra */

typedef struct {
    char texto[TAM_PALAVRA];
} Palavra;

/* Unidade = vogal ou consoante (dígrafos ch, lh, nh, qu, gu contam como UMA
 * unidade) */
typedef struct {
    int ini;   /* posição da 1ª letra no vetor de letras */
    int tam;   /* 1 ou 2 letras */
    int vogal; /* 1 = vogal, 0 = consoante */
    int c;     /* 1ª letra, em minúscula */
} Unidade;

/* ======================= UTF-8 e letras ======================= */

/* UTF-8 -> vetor de pontos de código. Retorna a quantidade ou -1 se inválido */
int decodifica(const char *s, int *cp) {
    int n = 0;
    const unsigned char *p = (const unsigned char *)s;
    while (*p) {
        if (n >= MAX_CP) return -1;
        if (*p < 0x80) {
            cp[n++] = *p++;
        }
        else if ((*p & 0xE0) == 0xC0 && (p[1] & 0xC0) == 0x80) {
            cp[n++] = ((*p & 0x1F) << 6) | (p[1] & 0x3F);
            p += 2;
        }
        else {
            return -1;
        }
    }
    return n;
}

/* Escreve um ponto de código (< 0x800) em UTF-8 e devolve o novo fim do buffer
 */
char *poe_cp(char *d, int c) {
    if (c < 0x80) {
        *d++ = (char)c;
    }
    else {
        *d++ = (char)(0xC0 | (c >> 6));
        *d++ = (char)(0x80 | (c & 0x3F));
    }
    return d;
}

int minusculo(int c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    if (c >= 0xC0 && c <= 0xDE && c != 0xD7) return c + 32; /* Á, Ã, Ç, Ü... */
    return c;
}

/* Letra sem acento (recebe minúscula): á ã â à -> a, é ê -> e, ... ç -> c */
int base(int c) {
    switch (c) {
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3: return 'a';
        case 0xE9:
        case 0xEA: return 'e';
        case 0xED: return 'i';
        case 0xF3:
        case 0xF4:
        case 0xF5: return 'o';
        case 0xFA:
        case 0xFC: return 'u';
        case 0xE7: return 'c';
    }
    return c;
}

int eh_letra(int c) { /* recebe minúscula */
    if (c >= 'a' && c <= 'z') return 1;
    switch (c) {
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3:
        case 0xE7:
        case 0xE9:
        case 0xEA:
        case 0xED:
        case 0xF3:
        case 0xF4:
        case 0xF5:
        case 0xFA:
        case 0xFC: return 1;
    }
    return 0;
}

int eh_vogal(int c) {
    int b = base(c);
    return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u';
}

int eh_forte(int c) { /* a, e, o (com ou sem acento) */
    int b = base(c);
    return b == 'a' || b == 'e' || b == 'o';
}

int eh_fraca_acentuada(int c) { /* í, ú: formam hiato com a vogal vizinha */
    return c == 0xED || c == 0xFA;
}

/* Quantidade de caracteres (não de bytes) -- usado para alinhar a saída */
int largura(const char *s) {
    int n = 0;
    for (; *s; s++)
        if (((unsigned char)*s & 0xC0) != 0x80) n++;
    return n;
}

/* ======================= Divisão silábica ======================= */

/* Agrupa as letras em unidades (vogais, consoantes e dígrafos) */
int tokeniza(const int *lc, int n, Unidade *u) {
    int k = 0, i = 0;
    while (i < n) {
        u[k].ini = i;
        u[k].c = lc[i];
        u[k].tam = 1;
        u[k].vogal = eh_vogal(lc[i]);
        if (!u[k].vogal && i + 1 < n) {
            int d = lc[i + 1];
            if ((lc[i] == 'c' || lc[i] == 'l' || lc[i] == 'n') && d == 'h') {
                u[k].tam = 2; /* ch, lh, nh */
            }
            else if ((lc[i] == 'q' || lc[i] == 'g') && d == 'u' && i + 2 < n &&
                     (base(lc[i + 2]) == 'e' || base(lc[i + 2]) == 'i')) {
                u[k].tam = 2; /* que, qui, gue, gui: u mudo */
            }
        }
        i += u[k].tam;
        k++;
    }
    return k;
}

/* Grupos consonantais inseparáveis: bl cl fl gl pl / br cr dr fr gr pr tr vr */
int inseparavel(const Unidade *x, const Unidade *y) {
    if (x->tam != 1 || y->tam != 1) return 0;
    if (y->c == 'r') return strchr("bcdfgptv", x->c) != NULL;
    if (y->c == 'l') return strchr("bcfgp", x->c) != NULL;
    return 0;
}

/* A vogal fraca u[j] está "presa" numa sílaba própria?
 * (ra-i-nha, ju-iz, ca-ir, ru-im, ba-ul) */
int hiato_por_consoante(const Unidade *u, int nu, int j) {
    int k = j + 1;
    if (k >= nu) return 0;
    if (u[k].tam == 2 && u[k].c == 'n') return 1; /* nh */
    if (u[k].tam == 1 && !u[k].vogal &&
        strchr("rlzmn", u[k].c)) { /* r l z m n */
        k++;
        if (k == nu) return 1;                      /* fim da palavra */
        if (k == nu - 1 && u[k].c == 's') return 1; /* ... + s final */
    }
    return 0;
}

/* Entre duas vogais seguidas u[i-1] e u[i]: separa (hiato) ou mantém (ditongo)?
 */
int separa_vogais(const Unidade *u, int nu, int i) {
    int a = u[i - 1].c, b = u[i].c;

    /* ditongos nasais: ão, ãe, õe */
    if ((a == 0xE3 || a == 0xF5) && (base(b) == 'e' || base(b) == 'o'))
        return 0;

    if (eh_forte(a)) {
        if (eh_forte(b)) return 1;           /* po-e-ta, co-e-lho */
        if (eh_fraca_acentuada(b)) return 1; /* sa-í-da, ba-ú */
        if (base(b) == 'i' && i + 1 < nu && u[i + 1].vogal && u[i + 1].c == 'u')
            return 1;                         /* sa-iu, ca-iu */
        return hiato_por_consoante(u, nu, i); /* pai, rei, ou  x  ra-i-nha */
    }

    /* a é vogal fraca (i, u) */
    if (eh_fraca_acentuada(a)) return 1;
    if (eh_forte(b)) {
        /* ditongo crescente só depois de g/q: á-gua, qua-tro, lín-gua */
        if (base(a) == 'u' && i >= 2 && !u[i - 2].vogal && u[i - 2].tam == 1 &&
            (u[i - 2].c == 'g' || u[i - 2].c == 'q'))
            return 0;
        return 1; /* ru-a, pi-a-no, his-tó-ri-a */
    }
    /* fraca + fraca: mui-to, fui, viu  x  ru-í-na, ju-iz */
    if (eh_fraca_acentuada(b)) return 1;
    return hiato_por_consoante(u, nu, i);
}

/* Faz a divisão silábica de 'texto' (UTF-8), grava em 'saida' e devolve nº de
 * sílabas */
int divide(const char *texto, char *saida) {
    int orig[MAX_CP], lc[MAX_CP], brk[MAX_CP] = {0};
    Unidade u[MAX_CP];
    int n = decodifica(texto, orig);
    int nsil = 1;

    for (int i = 0; i < n; i++)
        lc[i] = minusculo(orig[i]);
    int nu = tokeniza(lc, n, u);

    /* 1) vogal + vogal: hiato ou ditongo? */
    for (int i = 1; i < nu; i++)
        if (u[i - 1].vogal && u[i].vogal && separa_vogais(u, nu, i)) brk[i] = 1;

    /* 2) consoantes entre duas vogais */
    for (int i = 1; i < nu;) {
        if (!u[i].vogal && u[i - 1].vogal) {
            int e = i;
            while (e < nu && !u[e].vogal)
                e++;
            if (e < nu) { /* só se houver vogal depois */
                int L = e - i, pos;
                if (L == 1) pos = i; /* ca-sa */
                else if (inseparavel(&u[e - 2], &u[e - 1]))
                    pos = e - 2;  /* pa-la-vra */
                else pos = e - 1; /* pás-sa-ro, obs-tá-cu-lo */
                brk[pos] = 1;
            }
            i = e;
        }
        else {
            i++;
        }
    }

    /* 3) monta a saída com hífens */
    char *d = saida;
    for (int i = 0; i < nu; i++) {
        if (brk[i]) {
            *d++ = '-';
            nsil++;
        }
        for (int k = 0; k < u[i].tam; k++)
            d = poe_cp(d, orig[u[i].ini + k]);
    }
    *d = '\0';
    return nsil;
}

/* ======================= Ordenação ======================= */

/* Ordem alfabética ignorando acento e caixa; o acento só desempata */
int compara(const void *x, const void *y) {
    int a[MAX_CP], b[MAX_CP];
    int na = decodifica(((const Palavra *)x)->texto, a);
    int nb = decodifica(((const Palavra *)y)->texto, b);
    int m = na < nb ? na : nb;

    for (int i = 0; i < m; i++) {
        int ca = base(minusculo(a[i])), cb = base(minusculo(b[i]));
        if (ca != cb) return ca - cb;
    }
    if (na != nb) return na - nb;
    for (int i = 0; i < m; i++) {
        int ca = minusculo(a[i]), cb = minusculo(b[i]);
        if (ca != cb) return ca - cb;
    }
    return 0;
}

int ja_existe(const Palavra *lista, int total, const char *nova) {
    int a[MAX_CP], b[MAX_CP];
    int nb = decodifica(nova, b);
    for (int i = 0; i < total; i++) {
        int na = decodifica(lista[i].texto, a), igual = (na == nb);
        for (int k = 0; igual && k < na; k++)
            if (minusculo(a[k]) != minusculo(b[k])) igual = 0;
        if (igual) return 1;
    }
    return 0;
}

/* ======================= Programa principal ======================= */

int main(void) {
    static Palavra lista[MAX_PALAVRAS];
    int total = 0;
    char linha[512];

    printf("=== DICIONARIO ===\n");
    printf("Digite palavras (uma ou varias por linha). Linha vazia para "
           "terminar.\n");

    while (1) {
        printf("> ");
        if (!fgets(linha, sizeof linha, stdin)) break;
        linha[strcspn(linha, "\r\n")] = '\0';
        if (linha[0] == '\0') break;

        for (char *tok = strtok(linha, " \t,;"); tok;
             tok = strtok(NULL, " \t,;")) {
            int cp[MAX_CP];
            int n = (strlen(tok) < TAM_PALAVRA) ? decodifica(tok, cp) : -1;
            int ok = (n > 0);
            for (int i = 0; ok && i < n; i++)
                if (!eh_letra(minusculo(cp[i]))) ok = 0;

            if (!ok) printf("  ignorada (invalida): %s\n", tok);
            else if (ja_existe(lista, total, tok))
                printf("  ignorada (repetida): %s\n", tok);
            else if (total >= MAX_PALAVRAS) printf("  dicionario cheio!\n");
            else strcpy(lista[total++].texto, tok);
        }
    }

    if (total == 0) {
        printf("Nenhuma palavra digitada.\n");
        return 0;
    }

    qsort(lista, total, sizeof(Palavra), compara);

    int maior = 7; /* largura da coluna "Palavra" */
    for (int i = 0; i < total; i++)
        if (largura(lista[i].texto) > maior) maior = largura(lista[i].texto);

    printf("\n=== %d PALAVRA(S) EM ORDEM ALFABETICA ===\n", total);
    printf("%-*s%s\n", maior + 3, "Palavra", "Divisao silabica");
    for (int i = 0; i < total; i++) {
        char silabas[256];
        int nsil = divide(lista[i].texto, silabas);

        printf("%s", lista[i].texto);
        for (int k = largura(lista[i].texto); k < maior + 3; k++)
            putchar(' ');
        printf("%s  (%d silaba%s)\n", silabas, nsil, nsil == 1 ? "" : "s");
    }
    return 0;
}