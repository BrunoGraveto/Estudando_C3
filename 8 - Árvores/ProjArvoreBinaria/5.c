#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    ArvBin* arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);  
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);

    preOrdem_ArvBin(arvore);
    printf("\n");

    Remove_ArvoreAtual(*arvore);

    preOrdem_ArvBin(arvore);

    return 0; 
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

//Se o nó não tiver filho esquerdo, ele é substituído diretamente pelo filho direito e sua memória é liberada. 

//Caso contrário, busca-se o maior valor na subárvore esquerda, ou seja, o nó mais à direita dessa subárvore. 

//Esse nó substitui o removido, e os ponteiros são ajustados para manter a conectividade da árvore. Por fim, o nó original é liberado da memória.