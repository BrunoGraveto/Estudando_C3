#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

// Tipo da lista (ponteiro para o primeiro nó)
typedef struct elemento* Lista;

// Operações
Lista* criaLista();
int insereInicioLista(Lista* lista, int valor);
int insereFimLista(Lista* lista, int valor);
int removeLista(Lista* lista, int valor);
int consultaLista(Lista* lista, int pos, int* valor);
void imprimeListaDireta(Lista* lista);
void imprimeListaReversa(Lista* lista);
int tamanhoLista(Lista* lista);
int listaVazia(Lista* lista);
int liberaLista(Lista* lista);

#endif