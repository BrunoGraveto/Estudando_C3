#include <stdio.h>
#include <stdlib.h>

// Função para inverter os vetores e retornar o maior valor
int inverteVetor(int *v1, int *v2, int n) {
    // Variavel para salvar o maior numero do vetor, e uma para funcionar como contador
    int maiorValor = v1[0], counter;
    // Passa pelos elemementos dos vetores fazendo a inversão, e também a verificação do maior numero
    for (int i = n-1; i >= 0; i--) {
        // Passa o elemento de v1 para v2
        v2[counter++] = v1[i];
        // Verifica o maior numero
        if (maiorValor < v2[counter]) maiorValor = v2[counter];
    }
    // retorna o maior numero
    return maiorValor;
}

int main() {
    // Variavel que salvará o tamanho do vetor
    int tamanho;

    // Solicita ao usuário o tamanho do vetor
    printf("> Digite o tamanho do vetor:\n");
    scanf("%d", &tamanho);

    // Cria os dois vetores com o tamanho solicitado
    int v1[tamanho];
    int v2[tamanho];

    // Solicita os elementos ao usuário e salva no vetor1
    for (int i = 0; i < tamanho; i++) {
        printf("> Digite o elemento[%d]:\n", i);
        scanf("%d", v1[i]);
    }

    // Passa de forma invertida os elementos de v1 e v2, retornando o maior valor de v1
    int maiorValor = inverteVetor(v1, v2, tamanho);

    // Printa os elementos invertidos
    printf("\nVetor 2:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("-> %d\n", v2[i]);
    }

    // Mostra o maior valor de v1
    printf("\nMaior valor do vetor:\n-> %d\n", maiorValor);

    return 0;
}

/*
    Solicito o tamanho do vetor, crio dois vetores com o mesmo, solicito os elementos para o vetor 1, chamo a função inverterVetor passando como parâmetro os dois vetores e n, que é o tamanho dos vetores. Já na função, tomo como maior valor do vetor o elemento[0](por enquanto), e crio também uma variavel counter que irá, enquanto o indice do vetor 2 está avançando, o do vetor 2 esta diminuindo que foi tomado como igual ao tamanho do vetor ao inicio do for. 
    Assim, passando pelas iterações, ele vai colocando invertidamente os elementos de v1 em v2, ao mesmo tempo que verificando qual o elemento mais grande do vetor, que ao final será retornado pela função.
    Depois de passado da função, ele printa os elementos de v2 e também o maior valor do vetor.
*/