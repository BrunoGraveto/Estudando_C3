#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    Pilha *input = criarPilha();
    char c;

    printf("> Digite algo:\n");
    while ((c = getchar()) != '\n' && c != EOF) {
        push(input, c);
    }

    printf("\nInverso:\n");
    if(!printc(input)) return 0;

    if (palindromo(input)) {
        printf("\n-> Frase palindroma!\n");
    } else {
        printf("\n-> Frase nao palindroma!\n");
    }
    
    destroy(input);
    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Crio uma pilha, solicito que o usuario digite alguma coisa, assim capturando caractere por caractere
    salvando com seu codigo ascii dentro da pilha(inicialmente feita para inteiros), aí depois utitizo a função
    printc para printar em sequencia os caracteres invertidos, depois chamo a função palindromo para verificar
    se é uma frase palindroma ou não, e ao final libero a pilha.
*/