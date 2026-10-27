#include <stdio.h>
#include <stdlib.h>

/**
 * Aloca dinamicamente uma matriz n x n de inteiros (zerada).
 * @param n Dimensão da matriz
 * @return int** Ponteiro para a matriz
 */
int ** cria_matrix( int n ) {
    int i;
    int **m = (int **)malloc(n * sizeof(int *));  /* n linhas + 1 sentinela */

    for (i = 0; i < n; i++) {
        m[i] = (int *)malloc(n * sizeof(int));
    }
    return m;
}

/**
 * Libera a memória ocupada pela matriz.
 * @param m Ponteiro para a matriz
 */
void destroi_matrix( int ** m ) {
     int i;
    for (i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

/**
 * Verifica se a matriz é de permutação e calcula a soma dos elementos.
 * @return 1 se for de permutação, 0 caso contrário
 */
int ePermutacao( int ** m, int n, int * soma ) {
    int i, j, uns, zeros;
    int resultado = 1;

    *soma = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            *soma += m[i][j];
        }
    }

    for (i = 0; i < n; i++) {           
        uns = 0; zeros = 0;
        for (j = 0; j < n; j++) {
            if (m[i][j] == 1) uns++;
            else if (m[i][j] == 0) zeros++;
        }
        if (uns != 1 || zeros != n - 1) resultado = 0;
    }

    for (j = 0; j < n; j++) {           
        uns = 0; zeros = 0;
        for (i = 0; i < n; i++) {
            if (m[i][j] == 1) uns++;
            else if (m[i][j] == 0) zeros++;
        }
        if (uns != 1 || zeros != n - 1) resultado = 0;
    }

    return resultado;
}

int main() {
    int n, i, j, soma, eh;
    int **m;

    scanf("%d", &n);
    m = cria_matrix(n);
    if (m == NULL) return 1;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    eh = ePermutacao(m, n, &soma);

    printf("%d\n", n);
    if (eh) printf("PERMUTACAO\n");
    else    printf("NAO E PERMUTACAO\n");
    printf("%d\n", soma);

    destroi_matrix(m);
    return 0;
}