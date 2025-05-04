#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    int numeros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    Pilha *pilha = criarPilha();
    for (int i = 0; i < 8; i++) {
        push(pilha, numeros[i]);
    }

    Pilha *pilhaCopia = copy(pilha);
    print(pilhaCopia);

    destroy(pilha);
    destroy(pilhaCopia);

    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio e adiciono alguns elementos a pilha, logo em seguida chamando a pilhaCopia, função para copiar a pilha
    e uso uma função criada print para mostrar que os elementos foram copiados corretamente e depois libero
    a pilha e sua cópia.
*/