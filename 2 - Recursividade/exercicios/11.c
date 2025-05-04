#include <stdio.h>
#include <stdlib.h>

void printParesDec(int n) {
    if (n > 0) {
        printf("-> %d\n", n);
        printParesDec(n - 2);
    }
}

int main() {

    int n;

    printf("-> Digite um numero par:\n");
    scanf("%d", &n);

    printf("\nNumero(s) pare(s) de %d ate 0 de forma decrescente:\n", n);
    printParesDec(n);

    return 0;
}