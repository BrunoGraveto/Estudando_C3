#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    int numeros[5] = {24, 112, 94, 37, 49};
    Pilha *pilha = criarPilha();
    for (int i = 0; i < 5; i++) {
        push(pilha, numeros[i]);
    }

    int numeros2[5] = {24, 112, 94, 37, 49};
    Pilha *pilha2 = criarPilha();
    for (int i = 0; i < 5; i++) {
        push(pilha2, numeros2[i]);
    }

    if (equals(pilha, pilha2)) {
        printf("-> igual\n");
    } else {
        printf("-> Diferente!\n");
    }

    destroy(pilha);
    destroy(pilha2);

    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio e adiciono elementos a 2 vetores, e chamo a função equals passando como parametro as 
    duas pilhas para sua verificação assim informando se são iguais ou diferentes, e depois destruo
    as duas pilhas.
*/