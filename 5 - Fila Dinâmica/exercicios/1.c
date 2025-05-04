// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main() {
    struct aluno alunos[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };
    Fila *fila1 = cria_Fila();
    Fila *fila2 = cria_Fila();
    for (int i = 0; i < 4; i++) {
        insere_Fila(fila1, alunos[i]);
    }

    separarFila(fila1, fila2, alunos[1].matricula);

    printf("-> Fila 1:\n");
    imprime_Fila(fila1);

    printf("\n-> Fila 2:\n");
    imprime_Fila(fila2);

    libera_Fila(fila1);
    libera_Fila(fila2);
    return 0;
}

/*
    Criamos duas filas, apenas inserindo valores na primeira, e passando as passando junto a uma matricula como parâmetro para a função.
    Na função, encontramos a posição da matricula solicitada na fila primeira, determinamos seu final e inicio da segunda nesse ponto,
    depois definimos o final da segunda como o final da antiga primeira.
    Assim a antiga fila primeira foi separada em duas com ponto de separo a matricula, resultando nessa nova primeira e essa segunda.
    Após isso printamos as filas para demonstração.
*/