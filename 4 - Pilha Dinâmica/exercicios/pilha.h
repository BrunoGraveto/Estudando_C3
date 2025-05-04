#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "prototipos_pilha.h"

#define ZERO 48
#define UM 49

#define A 65
#define B 66

/*
    Cria a pilha:
*/
Pilha* criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL; 
    pilha->topo = NULL;
    return pilha;
}

/*
    Retira o elemento da pilha:
*/
int pop(Pilha *pilha, int *valor) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    if (celula == NULL) return 0;
    *valor = pilha->topo->valor;
    pilha->topo = celula->prox;
    free(celula);
    return 1;
}

/*
    Coloca o elemento da pilha:
*/
int push(Pilha *pilha, int valor) {
    if (pilha == NULL) return 0;
    Celula *celula = (Celula *)malloc(sizeof(Celula));
    if (celula == NULL) return 0;
    celula->valor = valor;
    celula->prox = pilha->topo;
    pilha->topo = celula;
    return 1;
}

/*
    Obtem o tamanho da pilha:
*/
int size(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    int size = 0;
    while (celula != NULL) {
        size++;
        celula = celula->prox;
    }
    return size;
}

/*
    Libera a memória de toda a pilha:
*/
int destroy(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    while(celula != NULL) {
        Celula *aux = celula;
        celula = celula->prox;
        free(aux);
    }
    pilha->topo = NULL;
    return 1;
}

/*
    Imprime os valores da pilha:
*/
int print(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        printf("-> %d\n", celula->valor);
        celula = celula->prox;
    }
    return 1;
}

/*
    Verifica se a pilha esta vazia:
*/
int vazia(Pilha *pilha) {
    if (pilha == NULL) return 1;
    if (pilha->topo == NULL) return 1;
    return 0;
}

// Exercicio 1 //////////////////////////////

/*
    Retira 2 elementos da pilha:
*/
int pop2(Pilha *pilha, int *valores) {
    if (pilha == NULL) return 0; 
    if (size(pilha) < 2) return 0;
    if (valores == NULL) return 0;
    Celula *celula;
    for (int i = 0; i < 2; i++) {
        celula = pilha->topo;
        valores[i] = pilha->topo->valor;
        pilha->topo = celula->prox;
        free(celula);   
    }
    return 1;
}

/*
    Coloca 2 elementos na pilha:
*/
int push2(Pilha *pilha, int valores[2]) {
    if (pilha == NULL) return 0;
    for (int i = 0; i < 2; i++) {
        Celula *celula = (Celula *)malloc(sizeof(Celula));
        if (celula == NULL) return 0;
        celula->valor = valores[i];
        celula->prox = pilha->topo;
        pilha->topo = celula;
    }
    return 1;
}

/////////////////////////////////////////////
// Exercicio 2 //////////////////////////////
/////////////////////////////////////////////

/*  
*/
int popN(Pilha *pilha, int n, int *valores) {
    if (pilha == NULL) return 0;
    if (size(pilha) < n) return 0;
    Celula *celula;
    for (int i = 0; i < n; i++) {
        celula = pilha->topo;
        valores[i] = pilha->topo->valor;
        pilha->topo = celula->prox;
        free(celula);   
    }
    return 1;
}   

/////////////////////////////////////////////
// Exercicio 3 //////////////////////////////
/////////////////////////////////////////////

Pilha* copy(Pilha *pilha) {
    if (vazia(pilha)) return NULL;
    Pilha *pilhaAux = criarPilha();
    Pilha *pilhaCopia = criarPilha();
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        push(pilhaAux, celula->valor);
        celula = celula->prox;
    }
    celula = pilhaAux->topo;
    while (celula != NULL) {
        push(pilhaCopia, celula->valor);
        celula = celula->prox;
    }
    return pilhaCopia;
}

/////////////////////////////////////////////
// Exercicio 4 //////////////////////////////
/////////////////////////////////////////////

int maiorMenorMedia(Pilha *pilha) {
    if (vazia(pilha)) return 0;
    Celula *celula = pilha->topo;
    int menor = pilha->topo->valor;
    int maior = pilha->topo->valor;
    int media = 0;
    while (celula != NULL) {
        if (celula->valor < menor) menor = celula->valor;
        if (celula->valor > maior) menor = celula->valor;
        media += celula->valor;
        celula = celula->prox;
    }
    media /= size(pilha);
    printf("-> Menor valor: %d\n", menor);
    printf("-> Maior valor: %d\n", maior);
    printf("-> Media aritmetica: %d\n", media);
    return 1;
}

/////////////////////////////////////////////
// Exercicio 5 //////////////////////////////
/////////////////////////////////////////////

int equals(Pilha *pilha, Pilha *pilha2) {
    int sizePilha = size(pilha);
    int sizePilha2 = size(pilha2);
    if (sizePilha != sizePilha2) return 0;
    int *valores = (int *)malloc(sizePilha * sizeof(int));
    if (valores == NULL) return 0;
    int *valores2 = (int *)malloc(sizePilha * sizeof(int));
    if (valores2 == NULL) {
        free(valores);
        return 0;
    }
    Pilha *pilhaCopia = copy(pilha);
    Pilha *pilhaCopia2 = copy(pilha2);
    popN(pilhaCopia, sizePilha, valores);
    popN(pilhaCopia2, sizePilha, valores2);
    int retorno = 1;
    for (int i = 0; i < sizePilha; i++) {
        if (valores[i] != valores2[i]) {
            retorno = 0;
            break;
        } 
    } 
    free(valores);
    free(valores2);
    destroy(pilhaCopia);
    destroy(pilhaCopia2);
    return retorno;
}

/////////////////////////////////////////////
// Exercicio 6 //////////////////////////////
/////////////////////////////////////////////

int printc(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        printf("%c", celula->valor);
        celula = celula->prox;
    }
    printf("\n");
    return 1;
}

int palindromo(Pilha *pilha) {
    if (vazia(pilha)) return 0;
    int sizePilha = size(pilha);
    Celula *celula = pilha->topo;
    Pilha *pilhaVf = copy(pilha);
    int counter = sizePilha-1;
    int *caracteres = (int *)malloc(sizePilha * sizeof(int));
    if (caracteres == NULL) return 0;
    popN(pilhaVf, sizePilha, caracteres);
    while (celula != NULL && counter >= 0) {
        while (celula->valor == 32 || celula->valor == 46) celula = celula->prox;
        while (caracteres[counter] == 32 || caracteres[counter] == 46) counter--;
        if (celula->valor != caracteres[counter--]) {
            free(caracteres);
            return 0;
        }
        celula = celula->prox;
    }
    free(caracteres);
    pilhaVf = NULL;
    return 1;
}

/////////////////////////////////////////////
// Exercicio 7 //////////////////////////////
/////////////////////////////////////////////

int countPar(Pilha *pilha) {
    if (vazia(pilha)) return 0;
    int totalPares = 0;
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        if (celula->valor % 2 == 0) totalPares++;
        celula = celula->prox;
    }
    return totalPares;
}

int countImpar(Pilha *pilha) {
    if (vazia(pilha)) return 0;
    int totalImpares = 0;
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        if (celula->valor % 2 != 0) totalImpares++;
        celula = celula->prox;
    }
    return totalImpares;
}

/////////////////////////////////////////////
// Exercicio 8 //////////////////////////////
/////////////////////////////////////////////

Pilha* inverterAB(Pilha *pilha) {
    if (vazia(pilha)) return NULL;
    Pilha *pilhaInvertida = criarPilha();
    Pilha *pilhaAB = criarPilha();
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        if (celula->valor == A) {
            push(pilhaInvertida, B);
        } else {
            push(pilhaInvertida, A);
        }
        celula = celula->prox;
    }
    celula = pilhaInvertida->topo;
    while (celula != NULL) {
        push(pilhaAB, celula->valor);
        celula = celula->prox;
    }
    destroy(pilhaInvertida);
    return pilhaAB;
}

int xCy(Pilha *pilhaX, Pilha *pilhaY) {
    if(vazia(pilhaX)) return 0;
    if(vazia(pilhaY)) return 0;
    Pilha *pilhaVf = inverterAB(pilhaX);
    if (vazia(pilhaVf)) return 0;
    Celula *celulaVf = pilhaVf->topo;
    Celula *celulaY = pilhaY->topo;
    while (celulaVf != NULL && celulaY != NULL) {
        if (celulaVf->valor != celulaY->valor) return 0;
        celulaVf = celulaVf->prox;
        celulaY = celulaY->prox;
    }
    destroy(pilhaVf);
    if (celulaVf != NULL || celulaY != NULL) return 0;
    return 1;
}

#endif