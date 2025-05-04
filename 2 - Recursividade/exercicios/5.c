#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void inverter(float *vetor, int index, int index2) {
    if (index >= index2) return;
    float aux = vetor[index];
    vetor[index] = vetor[index2];
    vetor[index2] = aux;
    return inverter(vetor, index+1, index2-1);
}

int main() {
    float vetor[SIZE];

    for (int c = 0; c < SIZE; c++) {
        printf("> Digite o elemento[%d]:\n", c);
        scanf("%f", &vetor[c]);
    }

    inverter(vetor, 0, SIZE-1);

    system("cls");
    printf("\nVetor invertido:\n");
    for (int c = 0; c < SIZE; c++) {
        printf("-> %.2f\n", vetor[c]);
    }

    return 0;
}

/*
    Solicitei ao usuário N(100 no caso) números de ponto flutuante e depois chamei a função, que tem como parâmetro
    o vetor, o "index" e o "index2".

    Passo Recursivo - Na função, enquanto o "index" for menor que o "index2", ele irá inverter os valores de ambos "index" e "index2", por que um começa em 0 e outro em N-1(99 no caso), os indices vão aumentando e diminuindo até se encontrar, assim
    invertendo todo o vetor.

    Caso Base - Quando o "index" for maior ou igual ao "index2" ele "encerra".
*/