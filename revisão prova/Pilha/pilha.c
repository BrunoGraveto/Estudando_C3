#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elemento {
    int valor;
    struct elemento *prox;
};
typedef struct elemento Elem;


Pilha* criaPilha() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL)
        (*pilha) = NULL;
    return pilha;
}

int inserePilha(Pilha* pilha, int valor) {
    if (pilha == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->valor = valor;
    no->prox = (*pilha);
    (*pilha) = no;
    return 1;
}

int removePilha(Pilha* pilha) {
    if (pilha == NULL || (*pilha) == NULL)
        return 0;
    Elem *no = (*pilha);
    (*pilha) = (*pilha)->prox;
    free(no);
    return 1;
}

int consultaTopoPilha(Pilha* pilha, int *valor) {
    if (pilha == NULL || (*pilha) == NULL)
        return 0;
    *valor = (*pilha)->valor;
    return 1;
}

int tamanhoPilha(Pilha* pilha) {
    if (pilha == NULL || (*pilha) == NULL)
        return 0;
    int total = 0;
    Elem *no = (*pilha);
    while (no != NULL) {
        total++;
        no = no->prox;
    }
    return total;
}

int liberaPilha(Pilha* pilha) {
    if (pilha == NULL)
        return 0;
    Elem *no;
    while ((*pilha) != NULL) {
        no = (*pilha);
        (*pilha) = (*pilha)->prox;
        free(no);
    }
    return 1;
}