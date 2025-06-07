#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    ArvBin *raiz  = cria_ArvBin();

    insere_ArvBin(raiz, 10);
    insere_ArvBin(raiz, 5);
    insere_ArvBin(raiz, 8);
    insere_ArvBin(raiz, 3);

    preOrdem_ArvBin(raiz);
    printf("-------------------------------------\n");
    emOrdem_ArvBin(raiz);
    printf("-------------------------------------\n");
    posOrdem_ArvBin(raiz);

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      emOrdem_ArvBin
    Função recursiva parecida com a preOrdem_ArvBin, a qual é mudado a sequencia
    das chamadas recursivas, sendo assim, chamando primeiramente a função passando
    como parametro o nó esquerdo, depois o print, e por ultimo a função passando
    o nó direito, assim, passando na "volta" e imprimindo os valores maiores da 
    direita.
*/

/*      posOrdem_ArvBin
    Função recursiva parecida com a preOrdem_ArvBin, sendo praticamente o reverso,
    a qual é chamado primeiramente a função passando como parametro o nó direito,
    depois o esquerdo, e por fim printando.
*/