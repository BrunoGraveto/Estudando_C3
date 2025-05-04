#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    int elementos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Pilha *pilha = criarPilha();
    for (int i = 0; i < 11; i++) {
        push(pilha, elementos[i]);
    }

    printf("Valores da pilha:\n");
    print(pilha);

    printf("\nQuantidade de pares: %d\n", countPar(pilha));
    printf("\nQuantidade de impares: %d\n", countImpar(pilha));

    destroy(pilha);

    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio e adiciono alguns elementos a pilha, printo os valores da pilha, e chamo
    as duas funções ambas de par e impar para verificar suas quantidades, e ao final
    libero a pilha.
*/