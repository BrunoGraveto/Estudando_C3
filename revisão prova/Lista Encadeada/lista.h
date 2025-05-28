#ifndef LISTA_H
#define LISTA_H

typedef struct elemento* Lista;

Lista* criaLista();
int insereInicioLista(Lista* lista, int valor);
int insereFimLista(Lista* lista, int valor);
int removeLista(Lista* lista, int valorRetirar);
int consultaLista(Lista* lista, int pos, int* valor);
void imprimeLista(Lista* lista);
int tamanhoLista(Lista* lista);
int listaVazia(Lista* lista);
int liberaLista(Lista* lista);

#endif