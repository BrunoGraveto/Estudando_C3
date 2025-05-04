#include <stdio.h>
#include <stdlib.h>

void printDec(int n) {
    if (n > 0) {
        printf("-> %d\n", n);
        printDec(n-1);
    } 
}

int main() {

    int n;

    printf("-> Digite um numero inteiro positivo:\n");
    scanf("%d", &n);

    printf("\n-> Numero(s) natural(is) de forma decrescente ate %d:\n", n);
    printDec(n);

    return 0;
}