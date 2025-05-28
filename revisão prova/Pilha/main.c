#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main() {

    Pilha* pilha = criaPilha();
    int valor = 0;

    for (int i = 0; i < 10; i++)
        inserePilha(pilha, i);

    consultaTopoPilha(pilha, &valor);
    printf("Topo: %d\n\n", valor);

    for (int i = 0; i < 5; i++) 
        removePilha(pilha);

    consultaTopoPilha(pilha, &valor);
    printf("Topo: %d\n", valor);

    liberaPilha(pilha);

    return 0;
}