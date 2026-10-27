#include <stdio.h>

int main() {
    int n;
    int m[10][10];
    int i, j;
    int bissim = 1; // 1 = verdadeiro (assumimos que é, até provar o contrário)

    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("dimensao invalida\n");
        return 0;
    }

    // leitura da matriz
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    // verificação
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // simetria na diagonal principal
            if (m[i][j] != m[j][i]) {
                bissim = 0;
            }
            // simetria na diagonal secundária
            if (m[i][j] != m[n - 1 - j][n - 1 - i]) {
                bissim = 0;
            }
        }
    }

    if (bissim == 1) {
        printf("bissimetrica\n");
    }
    else {
        printf("nao bissimetrica\n");
    }

    return 0;
}