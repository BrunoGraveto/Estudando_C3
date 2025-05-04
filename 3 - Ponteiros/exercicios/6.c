#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    // Codigo inicial
    char str[30], *cptr = str;

    // Solicito a string
    printf("> Digite uma string:\n");
    scanf(" %[^\n]", str);
    
    // Obtem o tamanho da string
    int tamanhoStr = strlen(str);

    // Printa a ordem inversa
    printf("Ordem inversa:\n");
    for (int i = tamanhoStr; i >= 0; i--) { // Inicializa no ultimo index, assim decrementando e printando
        printf("%c ", *(cptr+i));
    }

    return 0;
}

/*
    Crio uma string de 30 caracteres e um ponteiro char, já apontando para a string;
    Obtenho o tamanho da string para poder manusear o ponteiro;
    Chamo um for iniciado com seu contador no tamanho da string, e printo invertidamente.
*/