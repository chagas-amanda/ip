#include <stdio.h>
#include <stdlib.h>

#define MAXCH 2048

int main() {
    char str[MAXCH + 1];

    scanf("%[^\n]%*c", &str);

    return 0;
}