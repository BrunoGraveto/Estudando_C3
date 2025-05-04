#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    int numeros[5] = {23, 112, 94, 37, 49};

    Pilha *pilha = criarPilha();
    for (int i = 0; i < 5; i++) {
        push(pilha, numeros[i]);
    }

    printf("Elementos:\n");
    print(pilha);
    printf("\n\n");
    maiorMenorMedia(pilha);
    destroy(pilha);

    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio e adiciono alguns elementos na pilha, mostro os elementos, e chamo a função maiorMenorMedia,
    que dentro dela mesmo informa o maior, menor numero e sua media, logo em seguida liberando a pilha.
*/
