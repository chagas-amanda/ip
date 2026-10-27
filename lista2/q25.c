#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FRACTIONS 100

typedef struct {
    int x;
    int y;
    char original[32];
} Fraction;

int main(void) {
    char buffer[MAX_LINE];
    int n = 0;
    int t;

    /* Lê o número de casos de teste */
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 0;
    }
    n = atoi(buffer);

    for (t = 1; t <= n; t++) {
        Fraction fracs[MAX_FRACTIONS];
        int count = 0;
        char *token;
        int i, j;
        int found = 0;

        /* Lê a linha com as frações do caso de teste atual */
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            break;
        }

        /* Remove a quebra de linha do final, se houver */
        buffer[strcspn(buffer, "\r\n")] = '\0';

        /* Se a linha estiver vazia, pula para a próxima */
        if (strlen(buffer) == 0) {
            t--; /* compensa o incremento para continuar no mesmo caso se
                    necessário */
            continue;
        }

        /* Faz o parsing das frações separadas por espaço */
        token = strtok(buffer, " ");
        while (token != NULL && count < MAX_FRACTIONS) {
            int x, y;
            if (sscanf(token, "%d/%d", &x, &y) == 2) {
                fracs[count].x = x;
                fracs[count].y = y;
                strcpy(fracs[count].original, token);
                count++;
            }
            token = strtok(NULL, " ");
        }

        /* Imprime o cabeçalho do caso de teste */
        printf("Caso de teste %d\n", t);

        /* Compara as frações usando multiplicação cruzada */
        for (i = 0; i < count; i++) {
            for (j = i + 1; j < count; j++) {
                /* x1 * y2 == x2 * y1 */
                if ((long long)fracs[i].x * fracs[j].y ==
                    (long long)fracs[j].x * fracs[i].y) {
                    printf("%s equivalente a %s\n",
                           fracs[i].original,
                           fracs[j].original);
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
    }

    return 0;
}