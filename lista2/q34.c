#include <stdio.h>

int m[1000][1000];

int main() {
    int n;
    int i, j, k;
    int aux;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (j = 0; j < n; j++) {
        for (i = 0; i < n - 1; i++) { // Quando chego na última posição (n - 1),
                                      // só sobrou um elemento,
            // e ele já está no lugar certo, porque todos os outros menores já
            // foram para o começo
            int pos = i;
            for (k = i + 1; k < n;
                 k++) { // o que falta olhar é de i + 1 até o fim
                if (m[k][j] < m[pos][j]) {
                    pos = k;
                } // o pos guarda a posição do menor valor encontrado até agora,
                // e essa posição muda conforme a busca avança.
            }
            int aux = m[i][j];
            m[i][j] = m[pos][j];
            m[pos][j] = aux;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}