#include <stdio.h>

int main() {
    int ml[10][10];
    int mi[320][320];
    int x, y;
    int i, j, a, b;
    int achou;

    scanf("%d", &x);
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            scanf("%d", &ml[i][j]);
        }
    }
    scanf("%d", &y);
    for (i = 0; i < y; i++) {
        for (j = 0; j < y; j++) {
            scanf("%d", &mi[i][j]);
        }
    }

    for (i = 0; i <= y - x; i++) {
        for (j = 0; j <= y - x; j++) {
            achou = 1; /* supoe que o logotipo bate neste canto */
            for (a = 0; a < x; a++) {
                for (b = 0; b < x; b++) {
                    if (ml[a][b] != mi[i + a][j + b]) {
                        achou = 0; /* achou um pixel diferente */
                    }
                }
            }
            if (achou == 1) {
                printf("sim\n");
                return 0;
            }
        }
    }

    printf("nao\n");
    return 0;
}