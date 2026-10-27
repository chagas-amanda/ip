#include <stdio.h>

/*int main() {
    int m[10][10];
    int nl, nc;
    int i, j, k, w;
    int cont = 0;
    int unicos = 0;

    scanf("%d%d", &nl, &nc);
    if (nl < 1 || nl > 10 || nc < 1 || nc > 10) {
        printf("dimensao invalida\n");
        return 0;
    }

    for (i = 0; i < nl; i++) {
        for (j = 0; j < nc; j++) {
            cont = 0; // zera para este elemento
            for (k = 0; k < nl; k++)
                for (w = 0; w < nc; w++)
                    if (m[i][j] == m[k][w]) cont++;

            if (cont == 1) {
                if (unicos > 0) printf(",");
                printf("%d", m[i][j]);
                unicos++;
            }
        }
    }
    if (unicos == 0) printf("sem elementos unicos");
    else printf("\n");

    return 0;
}*/

/* turismo

int main() {
    int d[6][6] = {
        {0, 63, 210, 190, -1, 190}, // Cárceres
        {63, 0, 160, 150, 95, 10},  // Bugres
        {210, 160, 0, 10, 1, 10},   // Cuiabá
        {190, 150, 10, 0, 10, 20},  // Várzea
        {10, 95, 7, 21, 0, 80},     // Tangará
        {190, 2, -1, 41, 80, 0}     // Lacerda
    };
    int n, i, trecho, total = 0;
    int rota[100];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &rota[i]);

    for (i = 0; i < n - 1; i++) {
        trecho = d[rota[i]][rota[i + 1]];
        if (trecho == -1) {
            printf("rota invalida!\n");
            return 0;
        }
        total = total + trecho;
    }

    printf("%d\n", total);
    return 0;
    //sudoku

    #include <stdio.h>

    int main(void) {
        int matriz[9][9];
    int i, j,k, r, c;
    int conjunto[10];

    /* Lê os 81 números da matriz 9x9
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (scanf("%d", &matriz[i][j]) != 1) {
                return 0;
            }
        }
    }

    /* 1. Verifica as linhas
    for (i = 0; i < 9; i++) {
        for (k = 1; k <= 9; k++) conjunto[k] = 0;
        for (j = 0; j < 9; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || conjunto[num] == 1) {
                printf("invalido\n");
                return 0;
            }
            conjunto[num] = 1;
        }
    }

    /* 2. Verifica as colunas
    for (j = 0; j < 9; j++) {
        for (k = 1; k <= 9; k++) conjunto[k] = 0;
        for (i = 0; i < 9; i++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || conjunto[num] == 1) {
                printf("invalido\n");
                return 0;
            }
            conjunto[num] = 1;
        }
    }

    /* 3. Verifica os 9 blocos 3x3
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            for (k = 1; k <= 9; k++) conjunto[k] = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    int num = matriz[r * 3 + i][c * 3 + j];
                    if (num < 1 || num > 9 || conjunto[num] == 1) {
                        printf("invalido\n");
                        return 0;
                    }
                    conjunto[num] = 1;
                }
            }
        }
    }

    printf("valido\n");
    return 0;
}
// satélite
int main() {
    int m[6][6];
    int i, j;
    int soma = 0;
    int maior = -45;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            soma =
            m[i][j] + m[i - 1][j] + m[i + 1][j] + m[i][j - 1] + m[i][j + 1];
            if (soma > maior) maior = soma;
        }
    }
    printf("%d\n", maior);

    return 0;
}

//União e intersecção de conjuntos
#include <stdlib.h>

int main(void) {
    int TA, TB;
    int *A, *B;
    int i, j, val, repetido, primeiro, em_B, em_A;

    TA = 0;
    TB = 0;


    while (1) {
        if (scanf("%d", &TA) == 1 && TA >= 1 && TA <= 100) {
            break;
        }
    }


    while (1) {
        if (scanf("%d", &TB) == 1 && TB >= 1 && TB <= 100) {
            break;
        }
    }


    A = (int *)malloc(TA * sizeof(int));
    B = (int *)malloc(TB * sizeof(int));

    if (A == NULL || B == NULL) {
        return 1;
    }


    i = 0;
    while (i < TA) {
        scanf("%d", &val);


        repetido = 0;
        for (j = 0; j < i; j++) {
            if (A[j] == val) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            A[i] = val;
            i++;
        }
    }

    i = 0;
    while (i < TB) {
        scanf("%d", &val);


        repetido = 0;
        for (j = 0; j < i; j++) {
            if (B[j] == val) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            B[i] = val;
            i++;
        }
    }


    printf("[");
    primeiro = 1;
    for (i = 0; i < TA; i++) {
        em_B = 0;
        for (j = 0; j < TB; j++) {
            if (A[i] == B[j]) {
                em_B = 1;
                break;
            }
        }
        if (!em_B) {
            if (!primeiro) {
                printf(",");
            }
            printf("%d", A[i]);
            primeiro = 0;
        }
    }
    printf("]\n");

    printf("[");
    primeiro = 1;

    for (i = 0; i < TA; i++) {
        em_B = 0;
        for (j = 0; j < TB; j++) {
            if (A[i] == B[j]) {
                em_B = 1;
                break;
            }
        }
        if (!em_B) {
            if (!primeiro) {
                printf(",");
            }
            printf("%d", A[i]);
            primeiro = 0;
        }
    }


    for (j = 0; j < TB; j++) {
        em_A = 0;
        for (i = 0; i < TA; i++) {
            if (B[j] == A[i]) {
                em_A = 1;
                break;
            }
        }
        if (!em_A) {
            if (!primeiro) {
                printf(",");
            }
            printf("%d", B[j]);
            primeiro = 0;
        }
    }
    printf("]\n");

    free(A);
    free(B);

    return 0;
}
//diag secundaria

#include <stdlib.h>

void imprimirDiagonalSecundaria(int **M, int n) {
    int i,coluna=0;

    for(i=0;i<n;i++){
        coluna = n - i - 1;
        printf("%d\n", M[i][coluna]);
    }
}

int main() {
    int n;
    int i, j;
    int **m;

    scanf("%d", &n);


    m = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        m[i] = malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    imprimirDiagonalSecundaria(m,n);

    for (i = 0; i < n; i++) {
        free(m[i]); // m free(m[i]) para cada gaveta, dentro de um laço,
        // e depois o free(m) do caderno, uma vez só e depois das gavetas
    }


    free(m);

    return 0;
}
*/

// radar termico
#include <stdlib.h>

int main() {
    int m, n;
    int t;
    int i, j;
    int **M;
    int c = 0;

    scanf("%d %d", &m, &n);
    scanf("%d", &t);

    M = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        M[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    // Varredura sem  bordas (i de 1 até m-2, j de 1 até n-2)
    for (i = 1; i < m - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            if (M[i][j] >= t && M[i - 1][j - 1] >= t && M[i - 1][j + 1] >= t &&
                M[i + 1][j - 1] >= t && M[i + 1][j + 1] >= t) {
                c++;
            }
        }
    }

    if (c == 0) {
        printf("Nenhuma anomalia detectada\n");
    }
    else {
        for (i = 1; i < m - 1; i++) {
            for (j = 1; j < n - 1; j++) {
                if (M[i][j] >= t && M[i - 1][j - 1] >= t &&
                    M[i - 1][j + 1] >= t && M[i + 1][j - 1] >= t &&
                    M[i + 1][j + 1] >= t) {
                    printf("Centro do nucleo encontrado na posicao: (%d,%d)\n",
                           i,
                           j);
                }
            }
        }
    }

    for (i = 0; i < m; i++) {
        free(M[i]);
    }
    free(M); // eu buguei no free, eh smp esse modelo? antes eu só fiz o free de
    // M

    return 0;
}