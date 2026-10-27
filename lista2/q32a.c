#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *m;
    int *sorteado;
    int sena = 0, quina = 0,
        quadra = 0; // ainda zerei esses na mao pq achei triviais
    int i, j, num, a;

    scanf("%d", &n);

    m = calloc(n * 6, sizeof(int)); // n apostas, 6 por aposta e 4 bytes por
                                    // int
    sorteado =
        calloc(60, sizeof(int)); // 61 posiçoes zeradas pq ngm foi sorteado neh
    // ent tds começam zerados e qnd forem sendo sorteados aí muda prs um

    if (m == NULL || sorteado == NULL) { // vai ver se falhou
        printf("Erro de alocacao\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &m[i * 6 + j]); // ve da posiçao 0 a 5, dps 6 a 11, vai
                                        // vendo as linhas e tals neh
        }
    }

    for (j = 0; j < 6; j++) {
        scanf("%d", &num);
        sorteado[num] = 1;
    }

    for (i = 0; i < n; i++) {
        a = 0;
        for (j = 0; j < 6; j++) {
            a += sorteado[m[i * 6 + j]];
        }
        if (a == 6) sena++;
        else if (a == 5) quina++;
        else if (a == 4) quadra++;
    }
    if (sena == 0) printf("Nao houve acertador para sena\n");
    else printf("Houve %d acertador(es) da sena\n", sena);

    if (quina == 0) printf("Nao houve acertador para quina\n");
    else printf("Houve %d acertador(es) da quina\n", quina);

    if (quadra == 0) printf("Nao houve acertador para quadra\n");
    else printf("Houve %d acertador(es) da quadra\n", quadra);

    free(m);
    free(sorteado);
    return 0;
}
