#include <stdio.h>
#include <stdlib.h>

void printPares(int n, int par) {
    if (par <= n) {
        printf("-> %d\n", par);
        printPares(n, par + 2);
    }
}

int main() {

    int n;

    printf("-> Digite um numero par:\n");
    scanf("%d", &n);

    printf("\nNumero(s) pare(s) ate %d:\n", n);
    printPares(n, 0);

    return 0;
}