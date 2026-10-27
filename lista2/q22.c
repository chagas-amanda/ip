#include <stdio.h>

int main() {
    int N;
    int i, j;

    scanf("%d", &N);
    int matriz[101][101];
    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < N + 1; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matriz[i][j] + matriz[i][j + 1] + matriz[i + 1][j] +
                    matriz[i + 1][j + 1] >=
                2) {
                printf("S");
            }
            else {
                printf("U");
            }
        }
        printf("\n");
    }

    return 0;
}