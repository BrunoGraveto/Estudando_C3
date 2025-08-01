#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);


void imprimeDetalhada(struct NO* no, int valorPai, char* tipo); //Exercício 2
void imprimeFolhasDecrescente(struct NO* no); //Exercício 4
void removePares_ArvBin(ArvBin *raiz); //Exercício 6
void imprimeDetalhadaChar(struct NO* no, int valorPai, char* tipo); //Exercício 8


#endif // ARVOREBINARIA_H


