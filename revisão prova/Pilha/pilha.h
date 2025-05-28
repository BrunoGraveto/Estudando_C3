#ifndef PILHA_H
#define PILHA_H

typedef struct elemento* Pilha;

Pilha* criaPilha();
int inserePilha(Pilha* pilha, int valor);
int removePilha(Pilha *pilha);
int consultaTopoPilha(Pilha* pilha, int* valor);
int tamanhoPilha(Pilha *pilha);
int liberaPilha(Pilha *pilha);

#endif