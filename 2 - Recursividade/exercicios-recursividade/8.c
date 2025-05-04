#include <stdio.h>
#include <stdlib.h>

int multipRec(int n1, int n2) {
    if (n2 > 0) return n1 + multipRec(n1, n2-1);
    return 0; 
}

int main() {

    int n1, n2;

    printf("> Digite um numero para multiplicar:\n");
    scanf("%d", &n1);

    printf("> Digite outro numero para multiplicar por %d:\n", n1);
    scanf("%d", &n2);

    printf("\n-> Resultado: %d\n", multipRec(n1, n2));

    return 0;
}