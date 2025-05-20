#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.c"

int main() {

    struct aluno alunos[] = {
        {1, "Bruno Alcantara", 10.0, 10.0, 10.0},
        {2, "Jefferson Korte", 10.0, 10.0, 10.0},
        {3, "Igor Carvalho", 10.0, 10.0, 10.0}
    };

    Lista* lista = cria_lista();
    for (int i = 0; i < 3; i++)
        insere_lista_final(lista, alunos[i]);

    removerPorMatricula(lista, 3);

    imprime_lista(lista);

    libera_lista(lista);

    return 0;
}