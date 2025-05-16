#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main() {

    struct aluno alunos1[4] = {
        {1, "Jefferson", 9.7, 6.7, 8.4},
        {2, "Bruno", 9.5, 7.8, 8.5},
        {3, "Marciano", 5.7, 6.1, 7.4},
        {4, "Igor", 7.5, 8.7, 6.8}
    };

    struct aluno alunos2[4] = {
        {1, "Jefferson", 9.7, 6.7, 8.4},
        {3, "Marciano", 5.7, 6.1, 7.4},
        {4, "Igor", 7.5, 8.7, 6.8}
    };

    Lista *lista1 = cria_lista();
    Lista *lista2 = cria_lista();


    for (int i = 0; i < 4; i++) {
        insere_lista_ordenada(lista1, alunos1[i]);
        insere_lista_ordenada(lista2, alunos2[i]);
    }

    for (int i = 0; i < 2; i++) {
        if (equals(lista1, lista2)) {
            printf("-> Listas Diferentes!\n\n");
        } else {
            printf("-> Listas Iguais!\n\n");
        }
        removerNo(lista1, 2);
    }

    libera_lista(lista1);
    libera_lista(lista2);   
}