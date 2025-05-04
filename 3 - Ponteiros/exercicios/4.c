#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variavel que salvará o tamanho do vetor
    int tamanho;

    // Variavel que receberá o elemento do usuário
    int valor;

    // Solicita ao usuário o tamanho do vetor
    printf("> Digite o tamanho do vetor:\n");
    scanf("%d", &tamanho);

    // Declara e aloca memória de acordo com o tamanho pedido
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Solicita os elementos ao usuário
    for (int i = 0; i < tamanho; i++) {
        printf("> Digite o elemento[%d]:\n", i);
        scanf("%d", &valor);
        // Passa o valor para o vetor
        vetor[i] = valor;
    }

    // Printa os elementos na tela
    printf("\nElementos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("-> %d\n", vetor[i]);
    }
    
    // Libera memória
    free(vetor);
    return 0;
}

/*
    Solicito o tamanho do vetor, faço a alocação de memória para o vetor, aí crio um for a qual
    peço todos os elementos, a qual primeiramente passo o valor para "valor", e logo em seguida 
    para o vetor. Depois de solicitados os elementos, imprimo eles na tela, e finalmente libero
    a memoria alocada para o vetor.
*/
    
