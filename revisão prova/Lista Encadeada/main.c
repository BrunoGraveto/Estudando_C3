#include <stdio.h>
#include "lista.c"

int main() {
    Lista* minhaLista = criaLista();

    // Inserindo elementos no início
    insereInicioLista(minhaLista, 10);
    insereInicioLista(minhaLista, 20);
    insereInicioLista(minhaLista, 30);

    printf("Lista após inserções no início:\n");
    imprimeLista(minhaLista);

    // Inserindo no final
    insereFimLista(minhaLista, 40);
    insereFimLista(minhaLista, 50);

    printf("\nLista após inserções no fim:\n");
    imprimeLista(minhaLista);

    // Consultando elemento por posição
    int valor;
    if (consultaLista(minhaLista, 2, &valor)) {
        printf("\nValor na posição 2: %d\n", valor);
    } else {
        printf("\nErro ao consultar posição 2.\n");
    }

    // Removendo um elemento
    if (removeLista(minhaLista, 20)) {
        printf("\nElemento 20 removido com sucesso.\n");
    } else {
        printf("\nErro ao remover elemento 20.\n");
    }

    printf("\nLista após remoção:\n");
    imprimeLista(minhaLista);

    // Tamanho e verificação de lista
    printf("\nTamanho atual da lista: %d\n", tamanhoLista(minhaLista));
    printf("A lista está %s.\n", listaVazia(minhaLista) ? "vazia" : "preenchida");

    // Liberando a lista
    if (liberaLista(minhaLista)) {
        printf("\nLista liberada com sucesso.\n");
    } else {
        printf("\nErro ao liberar a lista.\n");
    }

    return 0;
}
