#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* criaFila();
int insereFila(Fila* fila, int valor);
int removeFila(Fila* fila);
int consultaFila(Fila* fila, int *valor);
int filaVazia(Fila* fila);
int tamanhoFila(Fila* fila);
void imprimeFila(Fila* fila);
int liberaFila(Fila* fila);

#endif