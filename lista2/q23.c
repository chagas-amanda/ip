#include <stdio.h>

int main() {
    int img[200][200];
    int tam, fundo;
    int i, j;
    int x, y, cor, r, estilo;

    scanf("%d %d", &tam, &fundo);

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            img[i][j] = fundo;
        }
    }

    scanf("%d %d", &x, &y);
    while (x != -1 || y != -1) {
        scanf("%d %d %d", &cor, &r, &estilo);

        if (x - r >= 0 && x + r < tam && y - r >= 0 && y + r < tam) {
            for (i = y - r; i <= y + r; i++) {
                for (j = x - r; j <= x + r; j++) {
                    if (estilo == 2) {
                        img[i][j] = cor;
                    }
                    else if (i == y - r || i == y + r || j == x - r ||
                             j == x + r) {
                        img[i][j] = cor;
                    }
                }
            }
        }

        scanf("%d %d", &x, &y);
    }

    printf("P2\n%d %d\n255\n", tam, tam);
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}