#include <stdio.h>

int ehPermutacao(int matriz[500][500], int n, int *soma) {
    int i, j;
    int achou = 0;
    int achou2 = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                achou++;
            }
            else if (matriz[i][j] == 0) {
                achou2++;
            }
        }
    }
    if (achou == 1 && achou2 == n - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n;
    int m[500][500];
    int i, j;
    int a;
    int soma = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    a = ehPermutacao(m, n, &soma);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            soma += m[i][j];
        }
    }

    printf("%d\n", n);
    if (a == 1) {
        printf("PERMUTACAO\n");
    }
    else {
        printf("NAO EH PERMUTACAO\n");
    }
    printf("%d\n", soma);

    return 0;
}