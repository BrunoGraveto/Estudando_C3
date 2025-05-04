#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int numeros[2] = {0, 1};
    Pilha *pilha = criarPilha();
    push2(pilha, numeros);

    printf("\nTamanho da pilha antes: %d\n\n", size(pilha));
    printf("Elementos da pilha:\n");
    print(pilha);

    int *numerosPop = (int *)malloc(2 * sizeof(int));
    pop2(pilha, numerosPop);

    printf("\nElementos retirados da pilha:\n");
    for (int i = 0; i < 2; i++) {
        printf("-> %d\n", numerosPop[i]);
    }

    printf("\nTamanho da pilha depois: %d\n", size(pilha));

    destroy(pilha);

    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio a pilha, e através de uma função push2 que tem como parâmetro a pilha e o vetor dos inteiros, adiciono a pilha
    os certos elementos.
    Aí para a função pop2, aloco memoria para um vetor de 2 posições, e passo como parametro, para que seja armazenado
    ao retirar da pilha.
*/