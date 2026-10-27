#include <stdio.h>
#include <string.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int matricula;
    Data nasc;
    char nome[201];
} Aluno;

/* Retorna 1 se d1 é mais novo ou da mesma idade que d2; 0 caso contrário */
int ComparaDataNasc(Data d1, Data d2) {
    if (d1.ano != d2.ano) return d1.ano > d2.ano;
    if (d1.mes != d2.mes) return d1.mes > d2.mes;
    return d1.dia >= d2.dia;
}

int main(void) {
    int n, i, j;
    size_t len;
    Aluno alunos[30];

    if (scanf("%d", &n) != 1) return 0;

    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d",
              &alunos[i].matricula,
              &alunos[i].nasc.dia,
              &alunos[i].nasc.mes,
              &alunos[i].nasc.ano);

        getchar(); /* consome o espaço antes do nome */
        fgets(alunos[i].nome, 201, stdin);

        len = strlen(alunos[i].nome);
        while (len > 0 && (alunos[i].nome[len - 1] == '\n' ||
                           alunos[i].nome[len - 1] == '\r')) {
            alunos[i].nome[--len] = '\0';
        }
    }

    /* Bubble sort: mais novo primeiro */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (!ComparaDataNasc(alunos[j].nasc, alunos[j + 1].nasc)) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n",
               alunos[i].matricula,
               alunos[i].nome,
               alunos[i].nasc.dia,
               alunos[i].nasc.mes,
               alunos[i].nasc.ano);
    }

    return 0;
}