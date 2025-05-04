#include <stdio.h>
#include <stdlib.h>

int somar(int *vetor, int tamanho, int index) {
    if (index < tamanho) return (vetor[index] + somar(vetor, tamanho, index+1));
    return 0;
}

int main() {
    int tamanhoVetor;

    printf("> Digite o tamanho do vetor:\n");
    scanf("%d", &tamanhoVetor);

    int vetor[tamanhoVetor];

    for (int c = 0; c < tamanhoVetor; c++) {
        printf("> Digite o elemento[%d]:\n", c);
        scanf("%d", &vetor[c]);
    }

    printf("-> Soma do vetor: %d\n", somar(vetor, tamanhoVetor, 0));

    return 0;
}

/*
    Solicito o tamanho do vetor e seus elementos ao usuário, após isso chamo a função passando como parâmetro o próprio vetor, o seu tamanho e um index.
    
    Passo Recursivo - Enquanto o index for menor que o tamanho ele continua a chamar a funcão somada ao inteiro do determinado
    index do vetor.
    
    Caso Base - Quando o index for >= ao tamanho ele retorna 0.
*/