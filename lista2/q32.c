#include <stdio.h>

int m[50000][6]; // alocaçao dinamica???

int main() {
    int N;
    int achou = 0, sena = 0, quina = 0, quadra = 0; // calloc
    int i, j;
    int k, w;
    int s[6];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d%d%d%d%d%d",
              &m[i][0],
              &m[i][1],
              &m[i][2],
              &m[i][3],
              &m[i][4],
              &m[i][5]);
    }
    for (j = 0; j < 6; j++) {
        scanf("%d", &s[j]);
    }
    for (i = 0; i < N; i++) {
        achou = 0;
        for (k = 0; k < 6; k++) {
            for (w = 0; w < 6; w++) {
                if (m[i][k] == s[w]) achou++;
            }
        }
        if (achou == 4) quadra++;
        else if (achou == 5) quina++;
        else if (achou == 6) sena++;
    } /*i	as apostas (linhas da matriz)	N - 1
 k	os 6 números da aposta i	5
 w	os 6 números do sorteio	5
 j	só aparece na leitura do sorteio	5*/

    if (sena > 0) printf("Houve %d acertador(es) da sena\n", sena);
    else {
        printf("Nao houve acertador para sena\n");
    }
    if (quina > 0) printf("Houve %d acertador(es) da quina\n", quina);
    else {
        printf("Nao houve acertador para quina\n");
    }
    if (quadra > 0) printf("Houve %d acertador(es) da quadra\n", quadra);
    else {
        printf("Nao houve acertador para quadra\n");
    } // essa bosta tava dando erro pq eu botei em outra ordem... morra!
    return 0;
}