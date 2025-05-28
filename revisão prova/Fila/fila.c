#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct elemento {
    int valor;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct fila {
    struct elemento* inicio;
    struct elemento* fim;
    int qtd;
};

Fila* criaFila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int insereFila(Fila* fila, int valor) {
    if (fila == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->valor = valor;
    no->prox = NULL;
    if (fila->inicio == NULL) { // Se a fila estiver vazia
        fila->inicio = no;
    } else { // Caso não, ela insere no elemento após o fim
        fila->fim->prox = no;
    }
    fila->fim = no; // Aqui ele atualiza o fim da fila, que agora é o nó recem adicionado
    fila->qtd++;
    return 1;
}

int removeFila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) 
        return 0;
    Elem *no = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) // Caso só tenha um elemento, ai como o fim era o inicio, ele deixa null
        fila->fim == NULL;
    free(no);
    fila->qtd--;
    return 1;
}

int consultaFila(Fila* fila, int *valor) {
    if (fila == NULL || fila->inicio == NULL)
        return 0;
    *valor = fila->inicio->valor;
    return 1;
}

int filaVazia(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) 
        return 1;
    return 0;
}

int tamanhoFila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) 
        return 0;
    return fila->qtd;
}

void imprimeFila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL)
        return 0;
    Elem *no = fila->inicio;
    while (no != NULL) {
        printf("-> %d\n", no->valor);
        no = no->prox;
    }
}

int liberaFila(Fila* fila) {
    if (fila == NULL)
        return 0;
    Elem *no;
    while (fila->inicio != NULL) {
        no = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(no);
    }
    return 1;
}

int retirarImpares(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL)
        return 0;
    Elem *no = fila->inicio, *ant;
    while (no != NULL) {
        if (no->valor % 2 == 1) {
            
        }

    }
}
