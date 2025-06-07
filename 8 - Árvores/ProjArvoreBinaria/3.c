#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    ArvBin *raiz  = cria_ArvBin();

    for (int i = 1; i < 50; i++)
        insere_ArvBin(raiz, i);

    printf("-> Quantidade de nos: %d\n", totalNO_ArvBin(raiz));

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

//A função utiliza recursão para percorrer toda a árvore binária.
//Primeiro, verifica se a árvore está vazia (ponteiro nulo ou apontando para nulo); nesse caso, retorna 0, pois não há nós para contar.
//Se a árvore não está vazia, a função retorna 1 (contando o nó atual) somado ao total de nós das subárvores à esquerda e à direita, obtidos por chamadas recursivas da própria função.
//Dessa forma, todos os nós da árvore são contabilizados.