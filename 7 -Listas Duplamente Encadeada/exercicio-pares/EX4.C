#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.h"
#include "ListaDinEncadDupla.c"

int main () {

    struct aluno al[] = {
        {1, "Andre", 9.5, 1.0, 5.3},
        {2, "Joao", 9.0, 8.4, 7.7},
        {3, "Maria", 8.5, 7.8, 6.9},
        {4, "Ana", 7.0, 6.1, 5.4}
    };

    Lista *li = cria_lista();

    for (int con = 0; con < 4; con++){
        insere_lista_final_circular(li, al[con]);
    }

    struct aluno alunoNovo = {6, "Jefferson", 9.0, 4.6, 5.9};

    insere_lista_inicio_circular(li, alunoNovo);

    printf("-------------------------------------\n");

    imprime_lista_circular(li);

    return 0;
}

//Feito em Dupla Jefferson korte junior RA 2651114 & Bruno eduardo RA: 26677156

//Nesse exercicio peguei como base as funçoes: imprimi_lista, remove_lista_inicio, remove_lista_final, inserir_lista_inicio e inserir_lista_final e apenas adicionei para o ponteiro ant do primeiro elemento apontar para o ultimo e o ponteiro prox do ultimo elemento apontar para o primeiro. Assim ficando uma lista circular.