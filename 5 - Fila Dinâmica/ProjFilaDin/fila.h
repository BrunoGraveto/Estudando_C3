#ifndef FILADIN_H
#define FILADIN_H

#include <stdio.h>
#include <stdlib.h>

#include "prototipos_fila.h" 
#include "pilha.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

struct elementoFila {
    struct fila *dados;
    struct elementoFila *prox;
};
typedef struct elementoFila ElemFila;
struct filaDeFila {
    struct elementoFila *inicio;
    struct elementoFila *final;
    int qtd;
};

struct elementoPilha {
    Pilha *dados;
    struct elementoPilha *prox;
};
typedef struct elementoPilha ElemPilha;
struct filaDePilha {
    struct elementoPilha *inicio;
    struct elementoPilha *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    fi = fi;
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

////////////////////////////////////////////////////////
// EXERCICIO 1 /////////////////////////////////////////
////////////////////////////////////////////////////////

int separarFila(Fila* f1, Fila* f2, int matricula) {
    if (f1 == NULL || f2 == NULL || Fila_vazia(f1) || (!Fila_vazia(f2)) || f1->final->dados.matricula == matricula) return 0;
    Elem *elem = f1->inicio;
    while (elem != NULL && elem->dados.matricula != matricula) elem = elem->prox;
    if (elem != NULL) {
        f2->inicio = elem->prox;
        f2->final = f1->final;
        f2->qtd = tamanho_Fila(f2);
        f1->final = elem;
        f1->final->prox = NULL;
        f1->qtd = tamanho_Fila(f1);
    } else {
        return 0;
    }
    return 1;
}

////////////////////////////////////////////////////////
// EXERCICIO 2  ////////////////////////////////////////
////////////////////////////////////////////////////////

/////////////
///// A /////
/////////////

FilaDeFila* criarFilaDeFila() {
    FilaDeFila* fila = (FilaDeFila*) malloc(sizeof(FilaDeFila));
    if(fila != NULL){
        fila->final = NULL;
        fila->inicio = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int inserirFilaNaFila(FilaDeFila* filaDeFila, Fila* fila) {
    if (filaDeFila == NULL || fila == NULL) return 0;
    ElemFila *elemFila = (ElemFila*) malloc(sizeof(ElemFila));
    if (elemFila == NULL) return 0;
    elemFila->dados = fila;
    elemFila->prox = NULL;
    if (filaDeFila->final == NULL) {
        filaDeFila->inicio = elemFila;
    } else {
        filaDeFila->final->prox = elemFila;
    }
    filaDeFila->final = elemFila;
    filaDeFila->qtd++;
    return 1;
}

void imprimirFilaDeFila(FilaDeFila* filaDeFila) {
    if (filaDeFila == NULL) return;
    ElemFila *elemFila = filaDeFila->inicio;
    while (elemFila != NULL) {
        printf("\nFila:\n");
        imprime_Fila(elemFila->dados);
        elemFila = elemFila->prox;
    }
}

void liberarFilaDeFila(FilaDeFila* filaDeFila) {
    if (filaDeFila == NULL) return;
    ElemFila *elemFila = filaDeFila->inicio;
    while (elemFila != NULL) {
        elemFila = filaDeFila->inicio;
        libera_Fila(elemFila->dados);
        filaDeFila->inicio = filaDeFila->inicio->prox;
        free(elemFila);
    }
    free(filaDeFila);
}

/////////////
///// B /////
/////////////

FilaDePilha* criarFilaDePilha() {
    FilaDePilha* fila = (FilaDePilha*) malloc(sizeof(FilaDePilha));
    if (fila != NULL){
        fila->final = NULL;
        fila->inicio = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int inserirPilhaNaFila(FilaDePilha* filaDePilha, Pilha* pilha) {
    if (filaDePilha == NULL || pilha == NULL) return 0;
    ElemPilha *elemPilha = (ElemPilha*) malloc(sizeof(ElemPilha));
    if (elemPilha == NULL) return 0;
    elemPilha->dados = pilha;
    elemPilha->prox = NULL;
    if (filaDePilha->final == NULL) {
        filaDePilha->inicio = elemPilha;
    } else {
        filaDePilha->final->prox = elemPilha;
    }
    filaDePilha->final = elemPilha;
    filaDePilha->qtd++;
    return 1;
}

void imprimirFilaDePilha(FilaDePilha* filaDePilha) {
    if (filaDePilha == NULL) return;
    ElemPilha *elemPilha = filaDePilha->inicio;
    while (elemPilha != NULL) {
        printf("\nPilha:\n");
        imprimirPilha(elemPilha->dados);
        elemPilha = elemPilha->prox;
    }
}

void liberarFilaDePilha(FilaDePilha* filaDePilha) {
    if (filaDePilha == NULL) return;
    ElemPilha *elemPilha = filaDePilha->inicio;
    while (elemPilha != NULL) {
        elemPilha = filaDePilha->inicio;
        liberarPilha(elemPilha->dados);
        filaDePilha->inicio = filaDePilha->inicio->prox;
        free(elemPilha);
    }
    free(filaDePilha);
}

#endif
