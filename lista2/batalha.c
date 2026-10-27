#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define AGUA ' '
#define NAVIO '@'          // navio pequeno (1 posicao)
#define BARCO 'B'          // metade de um barco grande ainda inteira
#define BARCO_ATINGIDO 'T' // metade de um barco grande atingida
#define EXPLOSAO '*'       // navio pequeno atingido
#define FALHA 'x'          // tiro na agua

// Resultados possiveis de um tiro
#define ERROU 0
#define ACERTOU 1
#define METADE_BARCO 2
#define AFUNDOU_BARCO 3

// Direcoes: direita, esquerda, acima, abaixo
static const int DL[4] = {0, 0, -1, 1};
static const int DC[4] = {1, -1, 0, 0};

/* Le uma linha inteira do teclado (evita sobras de Enter no buffer) */
void le_linha(char *buf, int tam) {
    if (fgets(buf, tam, stdin) == NULL) exit(0); // fim da entrada
}

/* Espera o jogador digitar 'c' (aceita 'c' ou 'C', com qualquer coisa depois)
 */
void espera_c() {
    char linha[100];
    char ch;
    do {
        printf("Digite \'c\' para continuar...");
        le_linha(linha, sizeof(linha));
    }
    while (sscanf(linha, " %c", &ch) != 1 || tolower(ch) != 'c');
}

/* Instrucoes: aparecem uma unica vez, no comeco do jogo */
void mostra_instrucoes() {
    printf("\n");
    printf("Bora jogar Batalha Naval???\n\n");
    printf("* = barco comum\n");
    printf("■ = barco grande (ocupa duas posicoes adjacentes)\n");
    printf("x = agua\n\n");
    printf("pra ganhar vc tem que afundar TODOS os barcos antes do SEU "
           "computador. Partiu uma disputa meio distópica?\?!!\n\n");
}

/* Pergunta inicial: 'c' aceita jogar (retorna 1), 'n' recusa (retorna 0) */
int aceita_jogar() {
    char linha[100];
    char ch;
    while (1) {
        printf("Digite \'c\' para continuar ou \'n\' para recusar...");
        le_linha(linha, sizeof(linha));
        if (sscanf(linha, " %c", &ch) == 1) {
            ch = tolower(ch);
            if (ch == 'c') return 1;
            if (ch == 'n') return 0;
        }
    }
}

/* Retorna o desenho de uma casa. Se mostrar_navios for 0, esconde os navios
 * inteiros */
const char *simbolo(char t, int mostrar_navios) {
    switch (t) {
        case NAVIO: return mostrar_navios ? "@" : " ";
        case BARCO: return mostrar_navios ? "#" : " ";
        case BARCO_ATINGIDO: return "■";
        case EXPLOSAO: return "*";
        case FALHA: return "x";
        default: return " ";
    }
}

void mostra_tabuleiro(char **Tab, int nl, int nc, int mostrar_navios) {
    int l, c;
    /**
     *   0 1 2
     * A| | | |
     * B| | | |
     * C| | | |
     * =========
     * A| | | |
     * B| | | |
     * C| | | |
     *   0 1 2
     */
    if (!mostrar_navios) {
        printf("  ");
        for (c = 0; c < nc; c++)
            printf("%d ", c);
        printf("\n");
    }

    for (l = 0; l < nl; l++) {
        printf("%c|", 'A' + l);
        for (c = 0; c < nc; c++)
            printf("%s|", simbolo(Tab[l][c], mostrar_navios));
        printf("\n");
    }

    if (mostrar_navios) {
        printf("  ");
        for (c = 0; c < nc; c++)
            printf("%d ", c);
        printf("\n");
    }
}

void screen(char **PC, char **J, int nl, int nc) {
    int c;
    mostra_tabuleiro(PC, nl, nc, 0);
    printf("==");
    for (c = 0; c < nc; c++)
        printf("==");
    printf("\n");
    mostra_tabuleiro(J, nl, nc, 1);
}

int sorteia(int min, int max) {
    int n = rand();
    return n % (max - min + 1) + min;
}

/* Sorteia o barco grande: 2 posicoes vizinhas (direita, esquerda, acima ou
 * abaixo) */
void sorteia_barco(char **Tab, int nl, int nc) {
    int colocado = 0;
    int l, c, d, l2, c2;
    while (!colocado) {
        l = sorteia(0, nl - 1);
        c = sorteia(0, nc - 1);
        d = sorteia(0, 3);
        l2 = l + DL[d];
        c2 = c + DC[d];
        if (l2 >= 0 && l2 < nl && c2 >= 0 && c2 < nc && Tab[l][c] == AGUA &&
            Tab[l2][c2] == AGUA) {
            Tab[l][c] = BARCO;
            Tab[l2][c2] = BARCO;
            colocado = 1;
        }
    }
}

void sorteia_tabuleiro(char **Tab, int nl, int nc, int nv) {
    int n = 0;
    int l, c;
    sorteia_barco(Tab, nl, nc); // primeiro o barco grande
    while (n < nv) {
        l = sorteia(0, nl - 1);
        c = sorteia(0, nc - 1);
        if (Tab[l][c] == AGUA) {
            Tab[l][c] = NAVIO;
            n++;
        }
    }
}

void init_tabuleiro(char **Tab, int nl, int nc) {
    int l, c;
    for (l = 0; l < nl; l++)
        for (c = 0; c < nc; c++)
            Tab[l][c] = AGUA;
}

char **cria_tabuleiro(int nl, int nc) {
    int i;
    char **Tab = NULL;
    Tab = (char **)malloc(nl * sizeof(char *));
    for (i = 0; i < nl; i++) {
        Tab[i] = (char *)malloc(nc * sizeof(char));
    }
    return Tab;
}

void libera_tabuleiro(char **Tab, int nl) {
    int l;
    for (l = 0; l < nl; l++)
        free(Tab[l]);
    free(Tab);
}

/* Conta quantas partes de navio ainda nao foram atingidas */
int conta_navios(char **Tab, int nl, int nc) {
    int l, c, n = 0;
    for (l = 0; l < nl; l++)
        for (c = 0; c < nc; c++)
            if (Tab[l][c] == NAVIO || Tab[l][c] == BARCO) n++;
    return n;
}

/* Retorna 1 se ja houve tiro nessa posicao */
int ja_atirou(char **Tab, int l, int c) {
    return Tab[l][c] == EXPLOSAO || Tab[l][c] == FALHA ||
           Tab[l][c] == BARCO_ATINGIDO;
}

/* Realiza o tiro e retorna ERROU, ACERTOU, METADE_BARCO ou AFUNDOU_BARCO */
int atira(char **Tab, int nl, int nc, int l, int c) {
    int i, l2, c2;

    if (Tab[l][c] == NAVIO) {
        Tab[l][c] = EXPLOSAO;
        return ACERTOU;
    }

    if (Tab[l][c] == BARCO) {
        Tab[l][c] = BARCO_ATINGIDO;
        // Como so existe um barco grande por tabuleiro, se uma casa vizinha
        // ja foi atingida, ela e a outra metade: o barco afundou por completo
        for (i = 0; i < 4; i++) {
            l2 = l + DL[i];
            c2 = c + DC[i];
            if (l2 >= 0 && l2 < nl && c2 >= 0 && c2 < nc &&
                Tab[l2][c2] == BARCO_ATINGIDO)
                return AFUNDOU_BARCO;
        }
        return METADE_BARCO;
    }

    Tab[l][c] = FALHA;
    return ERROU;
}

const char *texto_jogador(int r) {
    switch (r) {
        case ACERTOU: return "divou mona!";
        case METADE_BARCO: return "voce afundou metade de um barco ";
        case AFUNDOU_BARCO:
            return "parabens, voce afundou o titanic :D (ele tinha familia "
                   "ta?)";
        default: return "errou feio,errou feio,errou rude!";
    }
}

const char *texto_pc(int r) {
    switch (r) {
        case ACERTOU: return "ele divou viu?!";
        case METADE_BARCO:
            return "afundou metade do seu barco (se lascou hihi :D)";
        case AFUNDOU_BARCO:
            return "afundou o seu titanic :D com o Jack junto (#Roseviuva)";
        default: return "errou! (essa eh a tal da burrice artificial?)";
    }
}

int main() {
    char **TabPC = NULL;
    char **TabJ = NULL;
    int nl = 5, nc = 8;
    int nv = 7;
    int jogada = 0;
    int fim = 0;
    int l, c;
    int r;
    char ch;
    char linha[100];
    char msg[400] = "";

    // Instrucoes (so aparecem uma vez)
    mostra_instrucoes();
    if (!aceita_jogar()) {
        printf("\nNossa...sem graca\n");
        return 0;
    }

    srand(time(0));

    TabPC = cria_tabuleiro(nl, nc);
    TabJ = cria_tabuleiro(nl, nc);

    init_tabuleiro(TabPC, nl, nc);
    init_tabuleiro(TabJ, nl, nc);

    sorteia_tabuleiro(TabPC, nl, nc, nv);
    sorteia_tabuleiro(TabJ, nl, nc, nv);

    do {
        if (jogada % 2 == 0) {
            // Jogador
            printf("\n\n\n\n\n\n\n\n\n");
            screen(TabPC, TabJ, nl, nc);
            if (msg[0] != '\0') printf("\n%s\n\n", msg);

            // Na primeira jogada o jogador acabou de apertar 'c' nas instrucoes
            if (jogada > 0) espera_c();

            printf("Jogada: ");
            le_linha(linha, sizeof(linha));
            if (sscanf(linha, " %c%d", &ch, &c) != 2) {
                strcpy(msg,
                       "Jogada invalida! Use letra e numero, por exemplo B3.");
                continue;
            }
            l = toupper(ch) - 'A';

            if (l < 0 || l >= nl || c < 0 || c >= nc ||
                ja_atirou(TabPC, l, c)) {
                strcpy(msg, "Jogada invalida! Tente de novo.");
                continue; // nao conta a jogada, o jogador joga de novo
            }

            r = atira(TabPC, nl, nc, l, c);
            sprintf(
                msg, "Voce atirou em %c%d: %s", 'A' + l, c, texto_jogador(r));

            if (conta_navios(TabPC, nl, nc) == 0) {
                strcat(msg, "\n\nvoce ganhou a batalha, mas ganhou a guerra?");
                fim = 1;
            }
        }
        else {
            // PC
            do {
                l = sorteia(0, nl - 1);
                c = sorteia(0, nc - 1);
            }
            while (ja_atirou(TabJ, l, c));

            r = atira(TabJ, nl, nc, l, c);
            sprintf(msg + strlen(msg),
                    "\nO computador atirou em %c%d: %s",
                    'A' + l,
                    c,
                    texto_pc(r));

            if (conta_navios(TabJ, nl, nc) == 0) {
                strcat(msg,
                       "\n\nque pena (pra voce), perdeu pro computador, "
                       "bem-vindo ao futuro :D");
                fim = 1;
            }
        }
        jogada++;
    }
    while (!fim);

    // Tela final, mostrando como terminou
    printf("\n\n\n");
    screen(TabPC, TabJ, nl, nc);
    printf("\n%s\n", msg);

    libera_tabuleiro(TabPC, nl);
    libera_tabuleiro(TabJ, nl);

    return 0;
}