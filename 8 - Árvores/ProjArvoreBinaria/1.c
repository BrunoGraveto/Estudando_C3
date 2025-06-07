#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    ArvBin *raiz  = cria_ArvBin();

    for (int i = 1; i < 3; i++)
        insere_ArvBin(raiz, i);

    for (int i = 1; i < 3; i++)
        remove_ArvBin(raiz, i);

    libera_ArvBin(raiz);

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      insere_ArvBin
    Antes de realmente inserir ele verifica se a arvore esta vazia, caso esteja
    ele define a raiz como esse nó, caso contrário, inicia um andamento através
    de um loop procurando um "espaço vazio", se o nó atual que estiver verificando
    ja existir, ele libera esse nó solicitado e deixa o antigo, se não existir,
    ele verifica se o valor do nó é maior que o do nó que está verificando, se for
    ele percorre pela direita, caso contrário, pela esquerda.
    Após encontrar o "espaço vazio" ele verifica, se o ultimo nó verificado (antes
    de encontrar NULL) for menor que o nó solicitado, ele é adicionado a direita,
    caso contrário a esquerda.
*/

/*      remove_ArvBin
    Ele inicia uma andamento pela arvore procurando pelo nó soliticado, caso encontre ele
    verifica o nó pertence a raiz da arvore, caso seja ele define que a partir desse 
    ponto a raiz seja o nó retornado depois de utilizar a função remove_atual, no
    caso seus nós filhos, se não, ele verifica se é o nó da esquerda ou direita e faz
    o mesmo.
*/