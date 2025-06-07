#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    ArvBin *raiz  = cria_ArvBin();

    for (int i = 1; i < 50; i++)
        insere_ArvBin(raiz, i);

    if (consulta_ArvBin(raiz, 49)) printf("-> Tem 49!\n");
    if (consulta_ArvBin(raiz, 50)) printf("-> Tem 50!\n");

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      consulta_ArvBin
    Percorre pela arvore verificando se o valor é maior ou menor para 
    maior eficiencia, assim, quando encontrado o valor retornado 1, sinal
    de sucesso, caso não encontre, ao fim da função retorna 0, sinal de
    não sucesso.
*/