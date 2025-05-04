#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"
#include "aluno.h"

int main() {

    struct aluno alunos1[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    struct aluno alunos2[4] = {
        {1,"Bruno",9.5,7.8,8.5},
        {2,"Jefferson",7.5,8.7,6.8},
        {3,"Igor",9.7,6.7,8.4},
        {4,"Marciano",5.7,6.1,7.4}
    };

    Fila *fila1 = cria_Fila();
    Fila *fila2 = cria_Fila();

    for (int i = 0; i < 4; i++) {
        insere_Fila(fila1, alunos1[i]);
        insere_Fila(fila2, alunos2[i]);
    }

    PilhaDeFila *pilhaDeFila = criarPilhaDeFila();
    inserirFilaNaPilha(pilhaDeFila, fila1);
    inserirFilaNaPilha(pilhaDeFila, fila2);

    imprimirPilhaDeFila(pilhaDeFila);

    liberarPilhaDeFila(pilhaDeFila);
    libera_Fila(fila1);
    libera_Fila(fila2);

    return 0;
}