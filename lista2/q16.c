#include <stdio.h>
#include <string.h>

#define MAX_TEXT 2500
#define MAX_WORDS 500
#define MAX_WORD_LEN 100

/* Estrutura para armazenar cada palavra única e sua frequência */
typedef struct {
    char palavra[MAX_WORD_LEN];
    int freq;
} Registro;

int main() {
    /* TODAS as variáveis declaradas rigidamente no início do escopo (C89) */
    char texto[MAX_TEXT];
    char copia1[MAX_TEXT];
    char copia2[MAX_TEXT];
    Registro palavras[MAX_WORDS];
    int total_palavras;
    char delimitadores[30];
    char *token;
    int i;
    int encontrada;
    int freq_atual;

    /* Inicializações e atribuições */
    total_palavras = 0;
    strcpy(delimitadores, " \t\n\r.,!?()[]{}");

    /* Lê a linha de texto de entrada */
    if (!fgets(texto, sizeof(texto), stdin)) return 0;

    /* Remove caracteres de nova linha do final */
    texto[strcspn(texto, "\r\n")] = '\0';

    /* Criamos cópias do texto para não destruir o original durante o uso de
     * strtok */
    strcpy(copia1, texto);
    strcpy(copia2, texto);

    /* 1ª Etapa: Conta a frequência de cada palavra única no texto */
    token = strtok(copia1, delimitadores);
    while (token != NULL) {
        encontrada = 0;
        for (i = 0; i < total_palavras; i++) {
            if (strcmp(palavras[i].palavra, token) == 0) {
                palavras[i].freq++;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada && total_palavras < MAX_WORDS) {
            strcpy(palavras[total_palavras].palavra, token);
            palavras[total_palavras].freq = 1;
            total_palavras++;
        }
        token = strtok(NULL, delimitadores);
    }

    /* 2ª Etapa: Percorre o texto novamente na ordem original e imprime os
     * resultados */
    token = strtok(copia2, delimitadores);
    while (token != NULL) {
        freq_atual = 0;
        for (i = 0; i < total_palavras; i++) {
            if (strcmp(palavras[i].palavra, token) == 0) {
                freq_atual = palavras[i].freq;
                break;
            }
        }
        printf("(%s)%d\n", token, freq_atual);
        token = strtok(NULL, delimitadores);
    }

    return 0;
}