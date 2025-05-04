#include <stdio.h>
#include <stdlib.h>

int somatorio(int n) {
    if (n > 0) return n + somatorio(n-1);
    return 0; 
}

int main() {
    int n;

    printf("> Digite um numero inteiro positivo:\n");
    scanf("%d", &n);

    printf("-> Somatorio de 1 ate %d: %d\n", n, somatorio(n));

    return 0;
}

/*
    Solicito um numero N ao usuário, e depois chamo a função somatorio tendo como parâmetro N.
    
    Passo Recursivo - Enquanto N for maior que 0 ele chama um novo somatório com n-1 somando ao n atual.

    Caso Base - Após N for maior que 0 ele retorna 0.
*/