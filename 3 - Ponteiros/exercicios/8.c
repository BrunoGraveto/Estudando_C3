#include <stdio.h>
#include <stdlib.h>

void printarVetor(int *vetor, int tamanho) {
    // Enquanto o tamanho for menor ou igual a 0 ele continua a chamar a si mesmo
    if (tamanho >= 0) {
        printarVetor(vetor, tamanho-1); // Chama novamente a função
        printf("-> %d\n", vetor[tamanho]); // Printa após as chamadas
    }
}

int main() {

    // Variavel que salvará o tamanho do vetor a ser solicitado, e outro para salvar o valor do elemento solicitado
    int tamanho, valor;

    // Solicita o tamanho do vetor
    printf("> Digite o tamanho vetor dinamico:\n");
    scanf("%d", &tamanho);

    // Cria e aloca o vetor dinamicamente
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Solicita os elementos
    for (int i = 0; i < tamanho; i++) {
        printf("> Digite o elemento[%d]:\n", i);
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    // Chama a função para printar os elementos do vetor
    printarVetor(vetor, tamanho-1);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}

/*
    Tenho como função apenas uma recursiva para printar o vetor;
    No main solicito o tamanho do vetor, aloco memória para ele, e solicito os elementos,
    assim chamando a função para mostrar e logo em seguida liberando a memória.
*/