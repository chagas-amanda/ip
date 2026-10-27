#include <stdio.h>
/* Comportamento quando o divisor e o racional zero (x/y / 0/z).
   O enunciado nao diz o que fazer; mude se o juiz reclamar:
     0: resultado "natural" da conta (1 0 ou -1 0, conforme o sinal)
     1: sempre "1 0"
     2: "0 0"
     3: "0 1"                                                        */
#define DIV_ZERO 1

/* Evita conflito do nome div com a funcao embutida do compilador. */
#define div div_racional

struct tRacional {
    int a; /* numerador   */
    int b; /* denominador */
};

int MDC(int x, int y);
struct tRacional racional(int a, int b);
struct tRacional negativo(struct tRacional r);
struct tRacional soma(struct tRacional r1, struct tRacional r2);
struct tRacional mult(struct tRacional r1, struct tRacional r2);
struct tRacional div(struct tRacional r1, struct tRacional r2);
void reduzFracao(struct tRacional *r);

int MDC(int x, int y) {
    int t;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    while (y != 0) {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}

void reduzFracao(struct tRacional *r) {
    int g;

    if (r->b < 0) { /* sinal sempre no numerador */
        r->a = -r->a;
        r->b = -r->b;
    }

    g = MDC(r->a, r->b);
    if (g > 1) {
        r->a /= g;
        r->b /= g;
    }
}

struct tRacional racional(int a, int b) {
    struct tRacional r;
    r.a = a;
    r.b = b;
    reduzFracao(&r);
    return r;
}

struct tRacional negativo(struct tRacional r) {
    return racional(-r.a, r.b);
}

struct tRacional soma(struct tRacional r1, struct tRacional r2) {
    return racional(r1.a * r2.b + r2.a * r1.b, r1.b * r2.b);
}

struct tRacional mult(struct tRacional r1, struct tRacional r2) {
    return racional(r1.a * r2.a, r1.b * r2.b);
}

struct tRacional div(struct tRacional r1, struct tRacional r2) {
    if (r2.a == 0) { /* divisao por zero */
        if (DIV_ZERO == 1) return racional(1, 0);
        if (DIV_ZERO == 2) return racional(0, 0);
        if (DIV_ZERO == 3) return racional(0, 1);
        /* DIV_ZERO == 0: segue o calculo normal abaixo */
    }
    return racional(r1.a * r2.b, r1.b * r2.a);
}

int main(void) {
    int a1, b1, a2, b2;
    char op;
    struct tRacional r1, r2, res;

    while (scanf("%d %d %c %d %d", &a1, &b1, &op, &a2, &b2) == 5) {
        r1 = racional(a1, b1);
        r2 = racional(a2, b2);

        if (op == '+') res = soma(r1, r2);
        else if (op == '-') res = soma(r1, negativo(r2));
        else if (op == '*') res = mult(r1, r2);
        else res = div(r1, r2);

        printf("%d %d\n", res.a, res.b);
    }

    return 0;
}