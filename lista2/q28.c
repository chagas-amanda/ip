#include <stdio.h>

int main() {
    int l, c;
    int i, j;
    int m[10][10];

    scanf("%d%d", &l, &c);
    int topo = 0, esq = 0, base = l - 1, dir = c - 1;

    if (l < 1 || c < 1 || l > 10 || c > 10) {
        printf("Dimensao invalida\n");
        return 0;
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    while (topo <= base && esq <= dir) {
        for (j = esq; j <= dir; j++) {
            printf("%d ", m[topo][j]);
        }
        topo++;
        for (i = topo; i <= base; i++) {
            printf("%d ", m[i][dir]);
        }
        dir--;
        if (topo <= base) {
            for (j = dir; j >= esq; j--) {
                printf("%d ", m[base][j]);
            }
            base--;
        }
        if (esq <= dir) {
            for (i = base; i >= topo; i--) {
                printf("%d ", m[i][esq]);
            }
            esq++;
        }
    }

    return 0;
}
