#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y) {
    if (y == 0) return x;
    return mdc(y, (x % y));
}

int main() {

    int x, y;

    printf("> Digite um numero:\n");
    scanf("%d", &x);

    printf("> Digite outro numero:\n");
    scanf("%d", &y);

    printf("\n-> Maximo divisor comum dos inteiros X e Y:\n%d\n", mdc(x, y));

    return 0;
}

/*
    Solicitei ao usuário dois números, e chamei a função, que se é passado os dois próprios 
    números como parâmetro.

    Passo Recursivo - Enquanto X for diferente de 0, ele chama a função novamente, passando
    agora primeiramente como parametro Y, e como segundo o resto da divisão de X por Y.

    Caso Base - Retorna X quando Y for igual a 0.
*/