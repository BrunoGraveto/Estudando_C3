#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int numeros[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    Pilha *pilha = criarPilha();
    for (int i = 0; i < 8; i++) {
        push(pilha, numeros[i]);
    }

    printf("\nTamanho da pilha antes: %d\n\n", size(pilha));
    printf("Elementos da pilha:\n");
    print(pilha);

    int n = 4;

    int *numerosPop = (int *)malloc(n * sizeof(int));
    popN(pilha, n, numerosPop);

    printf("\nN elementos retirados da pilha:\n");
    for (int i = 0; i < n; i++) {
        printf("-> %d\n", numerosPop[i]);
    }

    printf("\n\nTamanho da pilha depois: %d\n", size(pilha));

    destroy(pilha);

    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio a pilha, adiciono alguns elementos atraves do push, ai para o uso da popN, aloco memoria
    com o numero de posições igual ao tamanho da pilha e passo como parametro na função para que os elementos
    sejam retirados e adicionados ao vetor. E depois libero a pilha.
*/