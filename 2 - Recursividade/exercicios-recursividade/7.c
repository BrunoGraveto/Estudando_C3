#include <stdio.h>
#include <stdlib.h>

int counter(char* str, int kAscii) {
    if (str[0] != '\0') {
        if (str[0] == kAscii) {
            return 1 + counter(&str[1], kAscii);
        }
        return counter(&str[1], kAscii);
    }
    return 0;
}

int main () {

    int k;
    int n;
    int kAscii;
    char str[50];

    printf("> Digite um numero natural de 0 a 9:");
    scanf("%d", &k);

    printf("> Digite qualquer numero natural:\n");
    scanf("%d", &n);

    kAscii = k + 48;
    printf("kAscii: %c\n", kAscii);

    sprintf(str, "%d", n);

    printf("-> Quantidade de %d's em %d: %d\n", k, n, counter(str, kAscii));

    return 0;
}

/*
    Solicitei ao usuário um número de 0 a 9, depois um numero qualquer e chamei a função
    passando como parâmetro o numero em formato de string, e o código ascii do numero que deseja
    encontrar.

    Passo Recursivo - Enquanto não for o final da string, ele verifica se o numero a se encontrar
    é o mesmo do numero que está buscando, caso seja, chama a função para o proximo caractere novamente
    + 1, indicando que encontrou, se não apenas retorna a função normalmente.

    Caso Base - Quando for o final da string retorna 0
*/