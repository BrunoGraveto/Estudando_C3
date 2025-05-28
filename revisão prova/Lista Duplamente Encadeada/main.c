#include <stdio.h>
#include "lista_dupla.c"

int main() {
    Lista* ld = criaLista();

    insereInicioLista(ld, 10);
    insereInicioLista(ld, 20);
    insereFimLista(ld, 30);
    insereFimLista(ld, 40);

    printf("Lista Direta:\n");
    imprimeListaDireta(ld);

    printf("\nLista Reversa:\n");
    imprimeListaReversa(ld);

    int valor;
    if (consultaLista(ld, 2, &valor))
        printf("\nValor na posição 2: %d\n", valor);

    removeLista(ld, 30);
    printf("\nLista após remover 30:\n");
    imprimeListaDireta(ld);

    printf("\nTamanho: %d\n", tamanhoLista(ld));
    printf("Lista está %s\n", listaVazia(ld) ? "vazia" : "preenchida");

    liberaLista(ld);
    return 0;
}
