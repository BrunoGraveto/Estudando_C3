#ifndef PROTOTIPOS_LISTA_H
#define PROTOTIPOS_LISTA_H

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia();
void imprime_lista(Lista* li);

// -> Exercicio 1:
// A
struct aluno* consultarAlunoMat(Lista* lista, int matricula);
// B
struct aluno* consultarAlunoPos(Lista* lista, int pos);

#endif