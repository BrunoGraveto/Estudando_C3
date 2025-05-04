#ifndef PROTOTIPOS_PILHA_H
#define PROTOTIPOS_PILHA_H

/*
    Struct da celula:
*/
typedef struct Celula {
    int valor;
    struct Celula *prox;
} Celula;

/*
    Struct da pilha:
*/
typedef struct {
    Celula *topo;
} Pilha;

Pilha* criarPilha();
int pop(Pilha *pilha, int *valor);
int push(Pilha *pilha, int valor);
int size(Pilha *pilha);
int destroy(Pilha *pilha);
int print(Pilha *pilha);
int vazia(Pilha *pilha);

// Exercicio 1
int pop2(Pilha *pilha, int *valores);
int push2(Pilha *pilha, int valores[2]);

// Exercicio 2
int popN(Pilha *pilha, int n, int *valores);

// Exercicio 3
Pilha* copy(Pilha *pilha);

// Exercicio 4
int maiorMenorMedia(Pilha *pilha);

// Exercicio 5
int equals(Pilha *pilha, Pilha *pilha2);

// Exercicio 6
int printc(Pilha *pilha);

// Exercicio 7
int countPar(Pilha *pilha);
int countImpar(Pilha *pilha);

// Exercicio 8
Pilha* inverterAB(Pilha *pilha);
int xCy(Pilha *pilhaX, Pilha *pilhaY);

#endif