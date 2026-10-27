#include <stdio.h>
#define MAX 10

int main() {
    int m[MAX][MAX];
    int l, c;
    int i, j;
    int k, w;
    int igual;
    int unicos = 0;

    scanf("%d", &l);
    scanf("%d", &c);

    if (l > MAX || c > MAX || l < 1 || c < 1) {
        printf("dimensao invalida\n");
        return 0;
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            igual = 0;
            for (k = 0; k < l; k++) {
                for (w = 0; w < c; w++) {
                    if (m[i][j] == m[k][w]) igual++;
                }
            }
            if (igual == 1) {
                if (unicos > 0) printf(",");
                printf("%d", m[i][j]);
                unicos++;
            }
        }
    }

    if (unicos == 0) printf("sem elementos unicos\n");
    else printf("\n");

    return 0;
}