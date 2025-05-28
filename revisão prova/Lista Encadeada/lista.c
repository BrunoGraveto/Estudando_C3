#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento {
    int valor;
    struct elemento* prox;
};
typedef struct elemento Elem;

Lista* criaLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL)
        (*lista) = NULL;
    return lista;
}

int insereInicioLista(Lista* lista, int valor) {
    if (lista == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->valor = valor;
    no->prox = (*lista);
    (*lista) = no;
    return 1;
}

int insereFimLista(Lista* lista, int valor) {
    if (lista == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->valor = valor;
    no->prox = NULL;
    if ((*lista) == NULL) {
        (*lista) = no;
    } else {
        Elem *aux = (*lista);
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }   
    return 1;
}

int removeLista(Lista* lista, int valorRetirar) {
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elem *no = (*lista), *ant;
    while (no != NULL && no->valor != valorRetirar) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL)
        return 0;
    if (ant == NULL) { // Caso seja o primeiro da lista o elemento a ser removido
        (*lista) = no->prox; // dai ele aponta já o inicio para o proximo do inicio
    } else {
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consultaLista(Lista* lista, int pos, int* valor) {
    if (lista == NULL || *lista == NULL || pos < 0)
        return 0;

    Elem* no = *lista;
    int counter = 0;
    while (no != NULL && counter < pos) {
        no = no->prox;
        counter++;
    }
    if (no == NULL)
        return 0;
    *valor = no->valor;
    return 1;
}

void imprimeLista(Lista* lista) {
    if (lista == NULL || (*lista) == NULL)
        return;
    Elem *no = (*lista);
    while (no != NULL) {
        printf("-> %d\n", no->valor);
        no = no->prox;
    }
}

int tamanhoLista(Lista* lista) {
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elem *no = (*lista);
    int counter = 0;
    while (no != NULL) {
        counter++;
        no = no->prox;
    }
    return counter;
}

int listaVazia(Lista* lista) {
    if (lista == NULL || (*lista) == NULL) 
        return 1;
    return 0;
}   

int liberaLista(Lista* lista) {
    if (lista == NULL) 
        return 0;
    Elem *no;
    while ((*lista) != NULL) {
        no = (*lista);
        (*lista) = (*lista)->prox;
        free(no);
    }
    return 1;
}