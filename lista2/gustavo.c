#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pi = NULL;
    int n, i, M, qM;
    scanf("%d", &n);
    if (n < 1) return 0;
    pi = (int *)malloc(n * sizeof(int));
    if (pi == NULL) {
        printf("mem insuficiente");
        for (i = 0; i < n; i++) {
            return 0;
        }
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &pi[i]);

        M = pi[0];
        qM = pi[1];
        if (qM > M) {
            t = qM;
            qM = M;
            M = t;
        }
        if (pi[i] > M) {
            qM = M;
            M = pi[i];
        }
        else if (pi[i] > qM) {
            qM = p[i];
        }
    }
    printf("M:%d\n qM:%d\n", M, qM);
    free(pi)
        :

          return 0;
}