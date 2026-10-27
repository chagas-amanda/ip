// imprimir na ordem lida
/*#include <stdio.h>
#define N 5

int main() {
    int v[N], i;
    for (i = 0; i < N; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }
    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
imprimir de forma inversa

    c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);
    for (i = N - 1; i >= 0; i--)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

3 - Soma dos elementos

        c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, soma = 0;
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        soma += v[i];
    }
    printf("Soma = %d\n", soma);
    return 0;
}

4 - Maior e menor elemento

        c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, maior, menor;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);

    maior = menor = v[0];
    for (i = 1; i < N; i++) {
        if (v[i] > maior) maior = v[i];
        if (v[i] < menor) menor = v[i];
    }
    printf("Maior = %d\nMenor = %d\n", maior, menor);
    return 0;
}

5 - Índices da primeira ocorrência do maior e do menor

        c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, iMaior = 0, iMenor = 0;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);

    for (i = 1; i < N; i++) {
        if (v[i] > v[iMaior]) iMaior = i; // ">" estrito mantém a primeira
        ocorrência if (v[i] < v[iMenor]) iMenor =
            i; // "<" estrito mantém a primeira
        ocorrência
    }
    printf("Maior: %d (indice %d)\n", v[iMaior], iMaior);
    printf("Menor: %d (indice %d)\n", v[iMenor], iMenor);
    return 0;
}

6 - Contar positivos, negativos e nulos

                          c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, pos = 0, neg = 0, nulos = 0;
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        if (v[i] > 0) pos++;
        else if (v[i] < 0) neg++;
        else nulos++;
    }
    printf("Positivos: %d\nNegativos: %d\nNulos: %d\n", pos, neg, nulos);
    return 0;
}

7 - Trocar os elementos de dois índices válidos

        c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, a, b, aux;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);

    do {
        printf("Indices (0 a %d): ", N - 1);
        scanf("%d %d", &a, &b);
    }
    while (a < 0 || a >= N || b < 0 || b >= N);

    aux = v[a];
    v[a] = v[b];
    v[b] = aux;

    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

8 - Contar quantas vezes um número aparece

        c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, x, cont = 0;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);

    printf("Numero procurado: ");
    scanf("%d", &x);

    for (i = 0; i < N; i++)
        if (v[i] == x) cont++;

    printf("%d apareceu %d vez(es)\n", x, cont);
    return 0;
}

9 - Inverter o vetor sem vetor auxiliar

        c
#include <stdio.h>
#define N 5

    int main() {
    int v[N], i, aux;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);

    for (i = 0; i < N / 2; i++) { // troca o 1o com o ultimo, o 2o com o
        penultimo... aux = v[i];
        v[i] = v[N - 1 - i];
        v[N - 1 - i] = aux;
    }

    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

Só uma variável temporária(aux)
é usada, não um segundo vetor.O laço vai só até N / 2, porque, se fosse até N,
    ele desfaria a inversão.

        10 -
        Função de deslocamento circular de uma posição para a esquerda

            c
#include <stdio.h>
#define N 5

        void deslocaEsquerda(int v[], int n) {
    int i, primeiro = v[0];
    for (i = 0; i < n - 1; i++)
        v[i] = v[i + 1];
    v[n - 1] = primeiro;
}

int main() {
    int v[N], i;
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);

    deslocaEsquerda(v, N);

    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

Ler uma palavra com % s e imprimir

                          c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX];
    scanf("%s", s); // sem & porque o nome do vetor ja e o endereco
    printf("%s\n", s);
    return 0;
}

O % s para no primeiro espaço, então só lê uma palavra.

                                   2 -
                                   Ler uma frase com espaços e imprimir completa

                                       c
#include <stdio.h>
#define MAX 100

                                   int main() {
    char s[MAX];
    scanf("%[^\n]%*c", s);
    printf("%s\n", s);
    return 0;
}

3 - Comprimento sem strlen

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX];
    int i = 0;
    scanf("%[^\n]%*c", s);
    while (s[i] != '\0')
        i++;
    printf("Comprimento = %d\n", i);
    return 0;
}

4 - Contar letras do alfabeto(maiúsculas e minúsculas)

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX];
    int i, cont = 0;
    scanf("%[^\n]%*c", s);
    for (i = 0; s[i] != '\0'; i++)
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            cont++;
    printf("Letras = %d\n", cont);
    return 0;
}

5 - Contar dígitos numéricos

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX];
    int i, cont = 0;
    scanf("%[^\n]%*c", s);
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= '0' && s[i] <= '9') cont++;
    printf("Digitos = %d\n", cont);
    return 0;
}

6 - Maiúsculas viram minúsculas e vice -
    versa

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX];
    int i;
    scanf("%[^\n]%*c", s);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + ('a' - 'A');      // +32
        else if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - ('a' - 'A'); // -32
    }
    printf("%s\n", s);
    return 0;
}

7 - Substituir todas as ocorrências de um caractere por outro

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX], antigo, novo;
    int i;
    scanf("%[^\n]%*c", s);
    printf("Trocar qual caractere: ");
    scanf(" %c", &antigo);
    printf("Por qual: ");
    scanf(" %c", &novo);

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == antigo) s[i] = novo;

    printf("%s\n", s);
    return 0;
}

8 - Contar um caractere, diferenciando maiúsculas e minúsculas

                             c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX], c;
    int i, cont = 0;
    scanf("%[^\n]%*c", s);
    printf("Caractere: ");
    scanf(" %c", &c);

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c) // 'A' e diferente de 'a'
            cont++;

    printf("'%c' apareceu %d vez(es)\n", c, cont);
    return 0;
}

9 - Inverter a string no próprio vetor e imprimir com % s

                                                            c
#include <stdio.h>
#define MAX 100

        int main() {
    char s[MAX], aux;
    int i, tam = 0;
    scanf("%[^\n]%*c", s);
    while (s[tam] != '\0')
        tam++;

    for (i = 0; i < tam / 2; i++) {
        aux = s[i];
        s[i] = s[tam - 1 - i];
        s[tam - 1 - i] = aux;
    }

    printf("%s\n", s);
    return 0;
}

10 - Comparar duas strings

         c
#include <stdio.h>
#define MAX 100

    int main() {
    char a[MAX], b[MAX];
    int i = 0;
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);

    while (a[i] != '\0' && a[i] == b[i])
        i++;

    if (a[i] == b[i]) // os dois chegaram juntos no '\0'
        printf("Iguais\n");
    else printf("Diferentes\n");
    return 0;
}

11 - Ler 3 strings, uma por linha,
    e imprimir

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char a[MAX], b[MAX], c[MAX];
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);
    scanf("%[^\n]%*c", c);
    printf("%s\n%s\n%s\n", a, b, c);
    return 0;
}

12 - Ler uma string com espaços e, na linha seguinte,
    um único caractere(que pode ser espaço)

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX], c;
    scanf("%[^\n]%*c", s);
    scanf("%c", &c); // sem espaco antes do %c, senao ele pularia um
    espaco digitado printf("String: %s\n", s);
    printf("Caractere: '%c'\n", c);
    return 0;
}

O detalhe é o % c sem espaço antes.Com " %c", o espaço digitado seria ignorado.

                                                  13 -
                                                  Remover todos os espaços

                                                      c
#include <stdio.h>
#define MAX 100

                                                  int main() {
    char s[MAX];
    int i, j = 0;
    scanf("%[^\n]%*c", s);

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] != ' ') s[j++] = s[i];
    s[j] = '\0';

    printf("%s\n", s);
    return 0;
}

14 - Função que conta ocorrências de um caractere

         c
#include <stdio.h>
#define MAX 100

    int contaChar(char s[], char c) {
    int i, cont = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c) cont++;
    return cont;
}

int main() {
    char s[MAX], c;
    scanf("%[^\n]%*c", s);
    printf("Caractere: ");
    scanf(" %c", &c);
    printf("'%c' aparece %d vez(es)\n", c, contaChar(s, c));
    return 0;
}

15 - Função que copia a primeira string para a segunda

         c
#include <stdio.h>
#define MAX 100

    void copia(char origem[], char destino[]) {
    int i;
    for (i = 0; origem[i] != '\0'; i++)
        destino[i] = origem[i];
    destino[i] = '\0'; // nao esquecer o terminador
}

int main() {
    char a[MAX], b[MAX];
    scanf("%[^\n]%*c", a);
    copia(a, b);
    printf("Copia: %s\n", b);
    return 0;
}

16 - Concatenar duas strings em uma terceira

         c
#include <stdio.h>
#define MAX 100

    int main() {
    char a[MAX], b[MAX], c[2 * MAX];
    int i, k = 0;
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);

    for (i = 0; a[i] != '\0'; i++)
        c[k++] = a[i];
    for (i = 0; b[i] != '\0'; i++)
        c[k++] = b[i];
    c[k] = '\0';

    printf("%s\n", c);
    return 0;
}

A terceira string tem 2 * MAX para caber as duas.

                          17 -
    Caractere que mais aparece(empate : o primeiro no texto)

        c
#include <stdio.h>
#define MAX 100

    int main() {
    char s[MAX], maisFreq;
    int i, j, cont, maior = 0;
    scanf("%[^\n]%*c", s);

    for (i = 0; s[i] != '\0'; i++) {
        cont = 0;
        for (j = 0; s[j] != '\0'; j++)
            if (s[j] == s[i]) cont++;
        if (cont > maior) { // ">" estrito: em empate, mantem o que veio
            primeiro maior = cont;
            maisFreq = s[i];
        }
    }

    printf("'%c' aparece %d vez(es)\n", maisFreq, maior);
    return 0;
}

Aqui o espaço também conta como caractere.Se o enunciado pedir para ignorá - lo,
    adicione if (s[i] == ' ') continue;
  no início do primeiro for.
  Parte 3 - Ponteiros

35 - Ponteiro para modificar a variável

c
#include <stdio.h>

int main() {
      int x = 10;
      int *p = &x;
      *p = 50;
      printf("x = %d\n", x);
      return 0;
  }

  36 - Função que multiplica por 3 o valor apontado

           c
#include <stdio.h>

      void triplica(int *p) {
      *p = *p * 3;
  }

  int main() {
      int x;
      scanf("%d", &x);
      triplica(&x);
      printf("x = %d\n", x);
      return 0;
  }

  37 - Função de troca

           c
#include <stdio.h>

      void troca(int *a, int *b) {
      int aux = *a;
      *a = *b;
      *b = aux;
  }

  int main() {
      int x, y;
      scanf("%d %d", &x, &y);
      troca(&x, &y);
      printf("x = %d, y = %d\n", x, y);
      return 0;
  }

  38 - Maior e menor via ponteiros

           c
#include <stdio.h>
#define N 5

      void maiorMenor(int v[], int n, int *maior, int *menor) {
      int i;
      *maior = *menor = v[0];
      for (i = 1; i < n; i++) {
          if (v[i] > *maior) *maior = v[i];
          if (v[i] < *menor) *menor = v[i];
      }
  }

  int main() {
      int v[N], i, maior, menor;
      for (i = 0; i < N; i++)
          scanf("%d", &v[i]);
      maiorMenor(v, N, &maior, &menor);
      printf("Maior = %d\nMenor = %d\n", maior, menor);
      return 0;
  }

  39 - Positivos, negativos e nulos via ponteiros

                      c
#include <stdio.h>
#define N 5

      void contaSinais(int v[], int n, int *pos, int *neg, int *nulos) {
      int i;
      *pos = *neg = *nulos = 0;
      for (i = 0; i < n; i++) {
          if (v[i] > 0) (*pos)++;
          else if (v[i] < 0) (*neg)++;
          else (*nulos)++;
      }
  }

  int main() {
      int v[N], i, pos, neg, nulos;
      for (i = 0; i < N; i++)
          scanf("%d", &v[i]);
      contaSinais(v, N, &pos, &neg, &nulos);
      printf("Positivos: %d\nNegativos: %d\nNulos: %d\n", pos, neg, nulos);
      return 0;
  }

  Os parênteses em(*pos)++ são obrigatórios.Sem eles,
      *pos++ incrementa o ponteiro,
      não o valor.

          40 -
          Por valor × por endereço

          Na passagem por valor,
      a função recebe uma cópia da variável.Qualquer alteração fica só na cópia,
      e a variável original da main não muda.Na passagem por endereço(&x),
      a função recebe o endereço da variável original e, usando *p,
      acessa e modifica a própria variável
              .Por isso funções como troca precisam receber ponteiros.

          41 -
          Por que uma função void modifica o vetor

          Quando um vetor é passado para uma função,
      o que vai é o endereço do primeiro elemento,
      e não uma cópia do vetor inteiro.Então
      v[i] = ... dentro da função altera a memória do vetor original
                 .O tipo de retorno
             void só diz que a função não devolve um valor
                 .Ele não impede a função de alterar dados pelos quais ela tem
             acesso.

             Parte 4 -
             Leitura e EOF

             42 -
             O que é EOF

             EOF(End Of File) é um sinal de que não há mais dados para ler
      : o fim do arquivo,
      ou, no terminal,
      o Ctrl + D(Linux).Funções como scanf e getchar retornam a constante
               EOF(geralmente - 1) quando isso acontece,
      e o programa pode usar esse retorno como condição para sair
          do laço de leitura
              .Assim a leitura termina sem precisar saber de antemão quantos
          dados virão.

          43 -
          Soma de inteiros até EOF

          c
#include <stdio.h>

          int main() {
      int n, soma = 0;
      while (scanf("%d", &n) != EOF)
          soma += n;
      printf("Soma = %d\n", soma);
      return 0;
  }

  44 - Pares e ímpares até EOF

           c
#include <stdio.h>

      int main() {
      int n, pares = 0, impares = 0;
      while (scanf("%d", &n) != EOF) {
          if (n % 2 == 0) pares++;
          else impares++;
      }
      printf("Pares: %d\nImpares: %d\n", pares, impares);
      return 0;
  }

  Para ímpares use n % 2 != 0 em vez de == 1,
      porque - 3 % 2 dá -
          1 em C.Aqui o else já resolve isso.

          45 -
          Maior e menor até EOF

              c
#include <stdio.h>

          int main() {
      int n, maior, menor;
      scanf("%d", &n); // pelo menos um numero sera informado
      maior = menor = n;
      while (scanf("%d", &n) != EOF) {
          if (n > maior) maior = n;
          if (n < menor) menor = n;
      }
      printf("Maior = %d\nMenor = %d\n", maior, menor);
      return 0;
  }

  46 - Ler caracteres até EOF em um vetor(máx.1024)

           c
#include <stdio.h>
#define MAX 1024

      int main() {
      char v[MAX];
      int c, n = 0, i; // c e int para conseguir guardar o EOF

      while (n < MAX && (c = getchar()) != EOF)
          v[n++] = c;

      for (i = 0; i < n; i++)
          putchar(v[i]);
      printf("\nTotal: %d caracteres\n", n);
      return 0;
  }
  7 - Versão com scanf(ajustado para linha vazia)

          c
#include <stdio.h>
#define MAX 1000

      int meu_strlen(char *s) {
      int i = 0;
      while (s[i] != '\0')
          i++;
      return i;
  }

  int main() {
      char s[MAX];

      s[0] = '\0';
      while (scanf("%999[^\n]", s) != EOF) {
          getchar(); // consome o '\n' que o scanf deixou
          printf("%d\n", meu_strlen(s));
          s[0] = '\0'; // linha vazia: scanf nao escreve nada em s
      }
      return 0;
  }

  Mudei duas coisas em relação ao % [^\n] %
      *c de antes :

      O
      getchar() separado consome o \n.Com
      % *c dentro do scanf,
      uma linha vazia fazia o scanf falhar e travar.O
      s[0] = '\0' garante que,
      numa linha vazia(em que o scanf retorna 0 e não grava nada),
      o comprimento impresso seja 0,
      e não o da linha anterior.O que significa scanf("%d", &n) != EOF

          O scanf retorna a quantidade de itens lidos com sucesso,
      ou EOF se a entrada acabou antes de ler qualquer coisa
          .Então o laço
      while (scanf("%d", &n) != EOF) continua enquanto houver dados
          .A vantagem é não precisar saber quantos números vão chegar
      : o programa processa tudo que existir e para sozinho no fim da entrada(
              útil em corretores automáticos e com redirecionamento de arquivos)
          .Um cuidado : se a entrada tiver algo
                        inválido(uma letra, por exemplo),
      o scanf retorna 0, não EOF,
      e o laço pode repetir para sempre.Por isso scanf(...) ==
          1 é mais seguro.

              49 -
              Redirecionar entrada e saída no Linux

                      ./
                  programa<entrada.txt> saida
                      .txt

                  O<faz o programa ler do arquivo em vez do teclado, e o> grava
                  na saída em vez de mostrar na tela.

                  Parte 5 -
              Funções com strings e ponteiros

              50 -
              contar_letras

              c
#include <stdio.h>
#define MAX 100

              int contar_letras(char *texto) {
      int i, cont = 0;
      for (i = 0; texto[i] != '\0'; i++)
          if ((texto[i] >= 'A' && texto[i] <= 'Z') ||
              (texto[i] >= 'a' && texto[i] <= 'z'))
              cont++;
      return cont;
  }

  int main() {
      char s[MAX];
      scanf("%[^\n]%*c", s);
      printf("Letras = %d\n", contar_letras(s));
      return 0;
  }

  51 - inverter sem string auxiliar

           c
#include <stdio.h>
#define MAX 100

      void inverter(char *texto) {
      int i, tam = 0;
      char aux;
      while (texto[tam] != '\0')
          tam++;
      for (i = 0; i < tam / 2; i++) {
          aux = texto[i];
          texto[i] = texto[tam - 1 - i];
          texto[tam - 1 - i] = aux;
      }
  }

  int main() {
      char s[MAX];
      scanf("%[^\n]%*c", s);
      inverter(s);
      printf("%s\n", s);
      return 0;
  }

  52 - analisar_texto

           c
#include <stdio.h>
#define MAX 100

      void
      analisar_texto(char *texto, int *letras, int *numeros, int *simbolos) {
      int i;
      *letras = *numeros = *simbolos = 0;
      for (i = 0; texto[i] != '\0'; i++) {
          if ((texto[i] >= 'A' && texto[i] <= 'Z') ||
              (texto[i] >= 'a' && texto[i] <= 'z'))
              (*letras)++;
          else if (texto[i] >= '0' && texto[i] <= '9') (*numeros)++;
          else (*simbolos)++; // inclui espacos
      }
  }

  int main() {
      char s[MAX];
      int l, n, o;
      scanf("%[^\n]%*c", s);
      analisar_texto(s, &l, &n, &o);
      printf("Letras: %d\nDigitos: %d\nOutros: %d\n", l, n, o);
      return 0;
  }

  53 - limpar_string

           c
#include <stdio.h>
#define MAX 100

      void limpar_string(char *texto) {
      int i, j = 0;
      for (i = 0; texto[i] != '\0'; i++)
          if ((texto[i] >= 'A' && texto[i] <= 'Z') ||
              (texto[i] >= 'a' && texto[i] <= 'z') ||
              (texto[i] >= '0' && texto[i] <= '9'))
              texto[j++] = texto[i];
      texto[j] = '\0';
  }

  int main() {
      char s[MAX];
      scanf("%[^\n]%*c", s);
      limpar_string(s);
      printf("%s\n", s);
      return 0;
  }

  54 - converte_maiusculo

           c
#include <stdio.h>
#define MAX 100

      void converte_maiusculo(char *texto) {
      int i;
      for (i = 0; texto[i] != '\0'; i++)
          if (texto[i] >= 'a' && texto[i] <= 'z')
              texto[i] = texto[i] - ('a' - 'A');
  }

  int main() {
      char s[MAX];
      scanf("%[^\n]%*c", s);
      converte_maiusculo(s);
      printf("%s\n", s);
      return 0;
  }

  55 - finalizar_texto

           c
#include <stdio.h>
#define MAX 100

      void finalizar_texto(char *texto, int posicao) {
      texto[posicao] = '\0';
  }

  int main() {
      char s[MAX];
      int pos;
      scanf("%[^\n]%*c", s);
      printf("Posicao: ");
      scanf("%d", &pos);
      finalizar_texto(s, pos);
      printf("%s\n", s);
      return 0;
  }

  A posição precisa estar dentro da string(0 até o comprimento)
          .Fora disso você escreve fora dos limites.

      Exercícios integrados

      56 -
      Remoção de valores

      c
#include <stdio.h>
#define MAX 100

      int main() {
      int v[MAX], n, x, i, j = 0;
      scanf("%d", &n);
      for (i = 0; i < n; i++)
          scanf("%d", &v[i]);
      scanf("%d", &x);

      for (i = 0; i < n; i++)
          if (v[i] != x)
              v[j++] = v[i]; // os demais "andam" para preencher as vagas

      printf("Removidos: %d\n", n - j);
      for (i = 0; i < j; i++)
          printf("%d ", v[i]);
      printf("\n");
      return 0;
  }

  57 - Primeira ocorrência via ponteiro

           c
#include <stdio.h>
#define MAX 100

      void primeira(char *s, char c, int *indice) {
      int i;
      *indice = -1;
      for (i = 0; s[i] != '\0'; i++)
          if (s[i] == c) {
              *indice = i;
              return;
          }
  }

  int main() {
      char s[MAX], c;
      int idx;
      scanf("%[^\n]%*c", s);
      scanf("%c", &c);
      primeira(s, c, &idx);
      printf("Indice = %d\n", idx);
      return 0;
  }

  58 - Verificação de substring

           c
#include <stdio.h>
#define MAX 100

      int contem(char *a, char *b) {
      int i, j;
      for (i = 0; a[i] != '\0'; i++) {
          j = 0;
          while (b[j] != '\0' && a[i + j] == b[j])
              j++;
          if (b[j] == '\0') // b inteira casou a partir de i
              return 1;
      }
      return 0;
  }

  int main() {
      char a[MAX], b[MAX];
      scanf("%[^\n]%*c", a);
      scanf("%[^\n]%*c", b);
      printf("%d\n", contem(a, b));
      return 0;
  }

A comparação == entre caracteres já diferencia maiúsculas de minúsculas, como o
enunciado pede.

Parte extra - Erros comuns

59 - Acessar fora dos limites do vetor

O C não verifica limites. O acesso lê ou escreve em memória que não pertence ao
vetor, o que é comportamento indefinido: pode devolver lixo, corromper outras
variáveis ou derrubar o programa. No terminal, o erro típico é Segmentation
fault (core dumped), mas nem sempre aparece, e às vezes o programa roda
“normalmente” com resultado errado, o que é pior.

60 - Por que a string termina com '\0', e '0' × '\0'

Em C, a string é só um vetor de char, sem tamanho guardado. O '\0' marca onde
ela acaba: printf("%s"), strlen e os seus laços while (s[i] != '\0') dependem
dele. Sem o terminador, eles continuam lendo memória além da string. Já '0' é o
caractere dígito zero, cujo código ASCII é 48. '\0' é o caractere nulo, de
código ASCII 0.

61 - Operadores * e &

O & pega o endereço de uma variável (&x é onde x está na memória). O * tem dois
papéis: na declaração (int *p) indica que p é um ponteiro, e no uso (*p) acessa
o valor que está no endereço guardado em p. Resumindo: & vai da variável ao
endereço, e * vai do endereço ao valor.

62 - Por que vetor[i + 1] dá problema na última posição

Se i é a última posição (N - 1), então i + 1 vale N, que está fora do vetor,
já que os índices válidos vão de 0 a N - 1. O acesso lê ou escreve em memória
que não é do vetor, com os problemas descritos no item 59. Em laços, a solução é
limitar o for a i < N - 1 quando for usar vetor[i + 1].

63 - Modificar uma variável recebida por valor

A função altera apenas a cópia local. Ao terminar, essa cópia é descartada e a
variável original continua com o valor antigo. O código compila e roda sem erro,
mas não faz o que se esperava (por exemplo, uma troca(int a, int b) não troca
nada na main). Para a alteração valer, é preciso passar o endereço e usar
ponteiros.

  Implemente char *primeira(char *s, char c), que devolve um ponteiro para a
primeira ocorrência de c em s, ou NULL se não existir. Na main, imprima o índice
usando subtração de ponteiros (p - s).

Q2. Implemente int contem(char *a, char *b), que retorna 1 se b aparece em a
como sequência consecutiva e 0 caso contrário. Não use nenhum índice ([]), só
aritmética de ponteiros.

Q3. Implemente void remove_vogais(char *s), que remove as vogais (maiúsculas e
minúsculas) da própria string, sem string auxiliar.

Q4. Implemente int str_para_int(char *s, int base), que converte a string para
inteiro na base indicada (2 a 16). Exemplos: ("101", 2) dá 5, ("ff", 16) dá 255
e ("1A", 16) dá 26. Pare ao encontrar um caractere inválido para a base.
  Opcional: trate o sinal -.

Q5. Implemente double str_para_double(char *s), que converte textos como
"123.45" e "-0.5" para double, sem usar atof nem strtod.

Q6. Implemente void remove_valor(int *v, int *n, int x), que remove de v todas
as ocorrências de x, atualiza *n com o novo tamanho e usa só ponteiros no
percurso.

T1. Qual a diferença entre *p++ e (*p)++?

T2. Por que a variável que recebe o retorno de getchar() deve ser int e não
char?

Gabarito

Q1

c
#include <stdio.h>

char *primeira(char *s, char c) {
    while (*s != '\0') {
        if (*s == c) return s;
        s++;
    }
    return NULL;
}

int main() {
    char s[100], c, *p;
    scanf("%[^\n]%*c", s);
    scanf("%c", &c);
    p = primeira(s, c);
    if (p != NULL) printf("Indice = %d\n", (int)(p - s));
    else printf("Nao existe\n");
    return 0;
}

Q2

    c int
    contem(char *a, char *b) {
    char *p, *q, *r;
    for (p = a; *p != '\0'; p++) {
        q = p;
        r = b;
        while (*r != '\0' && *q == *r) {
            q++;
            r++;
        }
        if (*r == '\0') // b inteira casou
            return 1;
    }
    return 0;
}

Q3

    c int
    eh_vogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void remove_vogais(char *s) {
    char *w = s; // w = onde escrever, s = onde ler
    for (; *s != '\0'; s++)
        if (!eh_vogal(*s)) *w++ = *s;
    *w = '\0';
}

É a mesma ideia do item 13(remover espaços), com dois “cursores”.

                                             Q4

                                             c int str_para_int(char *s,
                                                                int base) {
    int resultado = 0, digito, negativo = 0;

    if (*s == '-') {
        negativo = 1;
        s++;
    }
    for (; *s != '\0'; s++) {
        if (*s >= '0' && *s <= '9') digito = *s - '0';
        else if (*s >= 'A' && *s <= 'Z') digito = *s - 'A' + 10;
        else if (*s >= 'a' && *s <= 'z') digito = *s - 'a' + 10;
        else break;
        if (digito >= base) // digito invalido para essa base
            break;
        resultado = resultado * base + digito;
    }
    return negativo ? -resultado : resultado;
}

A ideia é a regra de Horner
    : para cada caractere,
      resultado = resultado *base + digito.Em "1A" na base 16 : 0 * 16 + 1 = 1,
      depois 1 * 16 + 10 = 26. O truque é converter o caractere em número
    : '7' -
      '0' dá 7 e 'C' - 'A' +
      10 dá 12.

      Q5

          c double
          str_para_double(char *s) {
    double r = 0.0, escala = 0.1;
    int negativo = 0;

    if (*s == '-') {
        negativo = 1;
        s++;
    }
    while (*s >= '0' && *s <= '9') { // parte inteira
        r = r * 10 + (*s - '0');
        s++;
    }
    if (*s == '.') { // parte fracionaria
        s++;
        while (*s >= '0' && *s <= '9') {
            r += (*s - '0') * escala;
            escala /= 10;
            s++;
        }
    }
    return negativo ? -r : r;
}

Em "123.45" : a parte inteira dá 123,
              depois 4 * 0.1 = 0.4 e 5 * 0.01 = 0.05,
                         totalizando 123.45.

              Q6

                  c void
                  remove_valor(int *v, int *n, int x) {
    int *ler, *escrever = v;
    for (ler = v; ler < v + *n; ler++)
        if (*ler != x) *escrever++ = *ler;
    *n = (int)(escrever - v);
}

T1. *p++ pega o valor apontado e depois avança o ponteiro para o próximo
elemento, porque ++ tem precedência sobre * e age em p. (*p)++ incrementa o
valor apontado e o ponteiro continua no mesmo lugar. É o mesmo cuidado do
item 39.

T2. O getchar() retorna um int que pode ser qualquer caractere (0 a 255) ou EOF
(normalmente -1). Em um char, o EOF pode ser confundido com um caractere válido
(ou, se char for sem sinal, nunca ser reconhecido), e o laço de leitura pode
terminar cedo ou nunca terminar. Com int os dois casos ficam distintos. A -
Inverter cada palavra, mantendo a ordem das palavras

Exemplo: ola mundo C vira alo odnum C.

c
#include <stdio.h>
#define MAX 100

void inverte(char *ini, char *fim) {
    char aux;
    while (ini < fim) {
        aux = *ini;
        *ini = *fim;
        *fim = aux;
        ini++;
        fim--;
    }
}

void inverte_cada_palavra(char *s) {
    char *ini;
    while (*s != '\0') {
        while (*s == ' ') // pula espacos
            s++;
        ini = s;
        while (*s != '\0' && *s != ' ') // acha o fim da palavra
            s++;
        if (s > ini) inverte(ini, s - 1);
    }
}

int main() {
    char s[MAX];
    scanf("%[^\n]%*c", s);
    inverte_cada_palavra(s);
    printf("%s\n", s);
    return 0;
}

B - Inverter a ordem das palavras

        Exemplo : ola mundo C vira C mundo ola.

                  c
#include <stdio.h>
#define MAX 100

                  void inverte(char *ini, char *fim) {
    char aux;
    while (ini < fim) {
        aux = *ini;
        *ini = *fim;
        *fim = aux;
        ini++;
        fim--;
    }
}

void inverte_cada_palavra(char *s) {
    char *ini;
    while (*s != '\0') {
        while (*s == ' ')
            s++;
        ini = s;
        while (*s != '\0' && *s != ' ')
            s++;
        if (s > ini) inverte(ini, s - 1);
    }
}

void inverte_ordem_palavras(char *s) {
    char *fim = s;
    if (*s == '\0') return;
    while (*fim != '\0')
        fim++;
    inverte(s, fim - 1);     // 1) inverte a string inteira: "C odnum alo"
    inverte_cada_palavra(s); // 2) desfaz a inversao dentro de cada palavra:
    "C mundo ola"
}

int main() {
    char s[MAX];
    scanf("%[^\n]%*c", s);
    inverte_ordem_palavras(s);
    printf("%s\n", s);
    return 0;
}

// conta vogal com ponteiro

/ int contarVogais(char *frase) {
    int i;
    int cont = 0;
    for (i = 0; *(frase + i) != '\0'; i++) {
        if (*(frase + i) == 'A' || *(frase + i) == 'E' || *(frase + i) == 'I' ||
            *(frase + i) == 'O' || *(frase + i) == 'U' || *(frase + i) == 'a' ||
            *(frase + i) == 'e' || *(frase + i) == 'i' || *(frase + i) == 'o' ||
            *(frase + i) == 'u') {
            cont++;
            *(frase + i) = '*';
        }
    }
    return cont;
}

int main() {
    char entrada[10000];
    int total;

    scanf("%[^\n]", entrada);

    total = contarVogais(entrada); // troca rola aqui
    printf("%s\n", entrada); // ai imprime a nova entrada com base na funcao
    printf("Vogais encontradas: %d\n", total);

    return 0;
}
int tamanho(char str[]) {
    int j;
    int tamanho = 0;
    for (j = 0; str[j] != '\0'; j++) {
        tamanho++;
    }
    return tamanho;
}

char *invertestr(char str[]) {
    char temp;
    int inicio = 0;
    int fim = tamanho(str) - 1;
    while (inicio < fim) {
        temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
    return str;
}

int main() {
    char vet[6];

    scanf("%s", vet);
    invertestr(vet);
    printf("%s\n", vet);
    return 0;
}
int main() {
    char str[51];
    int i;
    int cont = 0;

    scanf("%[^\n]", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u') {
            cont++;
        }
    }
    printf("%d\n", cont);

    return 0;
}

int meu_strlen(char *str) {
    int s = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        s++;
    }
    return s;
}

int main() {
    char str[100];
    int strlen;

    scanf("%s", str);
    strlen = meu_strlen(str);

    printf("%d\n", strlen);
    return 0;
}

int validar_senha(char *senha) {
    int i;
    int tamanho = 0;
    int valido = 0;
    for (i = 0; senha[i] != '\0'; i++) {
        tamanho++;

        if (senha[i] == '@' || senha[i] == '!' || senha[i] == '#') {
            valido = 1;
        }
    }
    if (valido == 1 && tamanho >= 8) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    char s[10001];

    int v;

    scanf("%s", s);

    v = validar_senha(s);

    printf("%d\n", v);
}

void criptografar(char *str) {
    int j;

    for (j = 0; str[j] != '\0'; j++) {
        if ((str[j] >= 'a' && str[j] <= 'z') ||
            (str[j] >= 'A' && str[j] <= 'Z')) {
            str[j] += 1;
        }
    }
}

int main() {
    char a[10001];

    scanf("%s", a);

    criptografar(a);

    printf("%s\n", a);
}

int eh_palindromo(char *str) {
    int tamanho = 0;
    int inicio = 0;
    int i;
    int cont = 1;

    for (i = 0; str[i] != '\0'; i++) {
        tamanho++;
    }
    int fim = tamanho - 1;
    while (inicio < fim) {
        if (str[inicio] != str[fim]) {
            cont = 0;
            break;
        }

        inicio++;
        fim--;
    }
    if (cont == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char m[10001];
    int resultado;

    scanf("%s", m);
    resultado = eh_palindromo(m);

    printf("%d\n", resultado);

    return 0;
}

#include <stdio.h> //Processador de Linhas com eof

Escreva um programa que lê várias linhas de texto, uma por vez,
    até o fim da entrada(EOF) — ou seja,
    você não sabe de antemão quantas linhas virão.Para cada linha lida,
    o programa deve :

    Contar quantos espaços em branco(' ') existem na linha
        .Contar quantas palavras
    existem(dica : uma "palavra" é um trecho de caracteres sem espaço;
            o número de palavras costuma ter uma relação direta com o número de
                espaços — pensa em qual é essa relação,
            com cuidado nos casos de borda)
        .Substituir todo espaço por um hífen
        -.Imprimir,
    para aquela linha : a linha já modificada,
                        a contagem de espaços e a contagem de palavras.* /

                            int contarEspacos(char *linha) {
    int i;
    int cont = 0;

    for (i = 0; *(linha + i) != '\0'; i++) {
        if (*(linha + i) == ' ') {
            cont++;
        }
    }
    return cont;
}
void substituirEspacos(char *linha) {
    int j;
    for (j = 0; *(linha + j) != '\0'; j++) {
        if (*(linha + j) == ' ') {
            *(linha + j) = '-';
        }
    }
}

int main() {
    char teste[100001];
    int espacoT;
    int numero;

    // le tudo menos o \n
    while (scanf("%[^\n]", teste) != EOF) {
        getchar(); // capturar e descartar esse \n que sobrou
        espacoT = contarEspacos(teste);
        numero = espacoT + 1;
        substituirEspacos(teste);
        printf("%s\n", teste);
        printf("Espacos: %d\n", espacoT);
        printf("Palavras: %d\n", numero);
    }

    return 0;
}*/
#include <stdio.h>

int main() {
    int a, b;
    int i, j;
    int cont = 1;

    scanf("%d %d", &a, &b);

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            if ((i + j) % 2 == 0) {
                printf("0 ");
            }
            else {
                printf("%d ", cont);
                cont++;
            }
        }
        printf("\n");
    }

    return 0;
}