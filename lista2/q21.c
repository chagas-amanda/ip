#include <stdio.h>
#define A 1111

int main() {
    int n, m;
    int i, j;
    int achou = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    int matriz[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matriz[i][j] == A && matriz[(i - 1 + n) % n][j] == 4 &&
                matriz[i][(j - 1 + m) % m] == 0 &&
                matriz[i][(j + 1) % m] == 0 && matriz[(i + 1) % n][j] == 8) {
                printf("%d %d\n", i, j);
                achou = 1;
            }
        }
    }

    if (achou == 0) {
        printf("WALLY NAO ESTA NA MATRIZ\n");
    }
    return 0;
}