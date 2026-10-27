#include <stdio.h>
#include <stdlib.h>
/*int main() {
    int tabela[3][2];
    int soma = 0;
    int n;
    int i = 0, j = 0;

    scanf("%d", &tabela[0][0]);
    scanf("%d", &tabela[0][1]);
    scanf("%d", &tabela[1][0]);
    scanf("%d", &tabela[1][1]);
    scanf("%d", &tabela[2][0]);
    scanf("%d", &tabela[2][1]);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            soma += tabela[i][j];
        }
    }
    printf("Sua tabela: %d %d %d %d %d %d\n",
           tabela[0][0] tabela[0][1] tabela[1][0] tabela[1][1] tabela
               [2][0] tabela[2][1]);
    printf("A soma total é: %d\n", soma);

    return 0;
}*/

int main() {
    int n, a, b;
    int i, j;
    char r, t;
    int d;

    scanf("%d %c %c", &n, &r, &t);

    if (n > 99 || n % 2 == 0 || n <= 0) {
        printf("Dimensao invalida!\n");
        return 0; // nem ve o resto
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int centro = n / 2;
            a = abs(i - centro); // passos de linha
            b = abs(j - centro); // passos de coluna

            d = a + b;

            if (d == centro) {
                printf("%c ", r);
            }
            else if (d < centro) {
                printf("%c ", t);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}