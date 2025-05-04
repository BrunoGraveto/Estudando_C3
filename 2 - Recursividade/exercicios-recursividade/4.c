#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente) {
    if (expoente > 0) return base + potencia(base, expoente-1);
    return 0;
}

int main() {

    int base, expoente;

    printf("> Digite a base da potencia:\n");
    scanf("%d", &base);

    printf("> Digite o expoente da potencia:\n");
    scanf("%d", &expoente);

    printf("-> %d^%d = %d", base, expoente, potencia(base, expoente));

    return 0;
}

/*
    Solicito uma base e um expoente ao usuário e chamo a função potência a qual se é
    passado a base e o expoente como parâmetro.

    Passo Recursivo - Enquanto o expoente for maior que 0 ele continua chamando a própria
    função (com expoente - 1) somada a base.

    Caso Base - Após o expoente for menor que 0 ele retorna 0.
*/