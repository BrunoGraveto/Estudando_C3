#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

struct elemento {
    int valor;
    struct elemento* prox;
    struct elemento* ant;
};
typedef struct elemento Elem;

Lista* criaLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

int insereInicioLista(Lista* lista, int valor) {
    if (lista == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->valor = valor;
    no->ant = NULL;
    no->prox = *lista;

    if (*lista != NULL)
        (*lista)->ant = no;

    *lista = no;
    return 1;
}

int insereFimLista(Lista* lista, int valor) {
    if (lista == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->valor = valor;
    no->prox = NULL;

    if (*lista == NULL) {
        no->ant = NULL;
        *lista = no;
    } else {
        Elem* aux = *lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
        no->ant = aux;
    }

    return 1;
}

int removeLista(Lista* lista, int valor) {
    if (lista == NULL || *lista == NULL) return 0;

    Elem* no = *lista;
    while (no != NULL && no->valor != valor)
        no = no->prox;

    if (no == NULL) return 0;

    if (no->ant == NULL) // primeiro nó
        *lista = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)
        no->prox->ant = no->ant;

    free(no);
    return 1;
}

int consultaLista(Lista* lista, int pos, int* valor) {
    if (lista == NULL || *lista == NULL || pos < 0) return 0;

    Elem* no = *lista;
    int count = 0;
    while (no != NULL && count < pos) {
        no = no->prox;
        count++;
    }

    if (no == NULL) return 0;

    *valor = no->valor;
    return 1;
}

void imprimeListaDireta(Lista* lista) {
    if (lista == NULL || *lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *lista;
    while (no != NULL) {
        printf("-> %d\n", no->valor);
        no = no->prox;
    }
}

void imprimeListaReversa(Lista* lista) {
    if (lista == NULL || *lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *lista;
    while (no->prox != NULL) // vai até o último
        no = no->prox;

    while (no != NULL) {
        printf("<- %d\n", no->valor);
        no = no->ant;
    }
}

int tamanhoLista(Lista* lista) {
    if (lista == NULL || *lista == NULL) return 0;

    int count = 0;
    Elem* no = *lista;
    while (no != NULL) {
        count++;
        no = no->prox;
    }
    return count;
}

int listaVazia(Lista* lista) {
    return (lista == NULL || *lista == NULL);
}

int liberaLista(Lista* lista) {
    if (lista == NULL) return 0;

    Elem* no;
    while (*lista != NULL) {
        no = *lista;
        *lista = (*lista)->prox;
        free(no);
    }
    free(lista);
    return 1;
}
