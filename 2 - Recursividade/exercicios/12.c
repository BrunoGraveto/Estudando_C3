#include <stdio.h>
#include <stdlib.h>

int fatorialDuplo(int n) {
    if (n > 0) return n * fatorialDuplo(n-2);
    return 1; 
}

int main() {

    int n;

    printf("> Digite um numero natural impar:\n");
    scanf("%d", &n);

    printf("\n-> Fatorial Duplo: %d\n", fatorialDuplo(n));

    return 0;
}

/*
    Solicito um numero natural impar, chamo a função passando como parâmetro somente N, e o utilizo como
    anteriormente também como "counter".

    Passo Recursivo - Enquanto N for maior que 0 ele chama a função novamente a multiplicando por N, e diminuindo N em 2, assim indo até 0 pulando de 2 em 2 e fazendo as multiplicações.

    Caso Base - Quando N for menor ou igual a 0, retorna 1.
*/