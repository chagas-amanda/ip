#include <stdio.h>

int main() {
    int matriz[1001][1001];
    int n, m;
    int i, j;
    int maior = -1, menor = 1001;
    int contMA = 0, contME = 0;
    double total = 0;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                contMA = 1;
            }
            else if (matriz[i][j] == maior) {
                contMA++;
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                contME = 1;
            }
            else if (matriz[i][j] == menor) {
                contME++;
            }
        }
    }
    total = n * m;

    printf("%d %.2f%%\n", menor, contME * 100 / total);
    printf("%d %.2f%%\n", maior, contMA * 100 / total);

    return 0;
}