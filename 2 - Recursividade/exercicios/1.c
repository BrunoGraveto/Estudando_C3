#include <stdio.h>
#include <stdlib.h>

void printarInvertido(char *str) {
    if (str[0] != '\0') {
        printarInvertido(&str[1]);
        printf("%c", str[0]);
    }
}

int main() {

    int num;
    char strNum[10];

    printf("> Digite um numero inteiro:\n");
    scanf("%d", &num);

    sprintf(strNum, "%d", num);
    printarInvertido(strNum);

    return 0;
}

/*
    Na parte da função para inverter acabei utilizando a mesma lógica do slide do professor
    a qual apenas inverto a ordem da chamada do metódo e o printf. 
    Já para mandar o "numero" na função, obtive uma var int com um scanf e passei ela para
    uma string atraves do sprintf assim podendo mandar para o método.
*/