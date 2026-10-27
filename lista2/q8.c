#include <stdio.h>

int main() {
    int m[100][100];
    int k, x, l, h; // largura da borda e o por último o valor da borda
    int i, j, r;
    int topo = 0, esq = 0, base = l - 1, dir = c - 1;

    scanf("%d %d %d %d", &l, &h, &k, &x);

    printf("P2\n%d %d\n255\n", l, h);
    // achar as coord.
    for (i = 0; i < h; i++) {
        for (j = 0; j < l; j++) {
            if (i < k || i >= h - k || j < k || j >= l - k) {
                m[i][j] = x;

                printf("%d ", m[i][j]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}