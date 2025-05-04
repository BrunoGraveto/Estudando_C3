#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    // Valores que serão colocados na pilha
    int numeros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Criando a pilha
    Pilha *pilha = criarPilha();

    // Colocando os valores na pilha
    for (int i = 0; i < 10; i++) {
        push(pilha, numeros[i]);
    }

    // Mostra o tamanho da pilha inicialmente
    printf("\nTamanho da pilha: %d\n", size(pilha));

    // Printa os elementos da pilha
    printf("Elementos da pilha:\n");
    print(pilha);

    // Retia alguns valores da pilha
    int *valor = (int *)malloc(sizeof(int));
    if (valor == NULL) return 1;
    for (int i = 0; i < 5; i++) {
        pop(pilha, valor);
        printf("-> Valor retirado: %d\n", *valor);
    }
    free(valor);

    // Mostra o tamanho da pilha novamente
    printf("\n\nTamanho da pilha: %d\n\n", size(pilha));

    // Libera memoria da pilha
    destroy(pilha);
    printf("Liberando memoria da pilha...\n");

    // Verifica se a pilha esta ou não vazia
    if (vazia(pilha)) {
        printf("-> Agora a pilha esta vazia!\n");
    } else {
        printf("-> A pilha nao esta vazia!\n");
    }

    return 0;
}