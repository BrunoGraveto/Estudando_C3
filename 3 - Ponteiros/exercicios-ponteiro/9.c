#include <stdio.h>
#include <stdlib.h>

/*
    Função para alocar a memória para a matriz
*/
int** alocarMemoriaMatriz(int m, int n) {
    // Aloca as linhas
    int **matriz = (int **)malloc(m * sizeof(int*));
    // Verifica se as linhas foram alocadas
    if (matriz == NULL) {
        printf("-> Problema ao alocar memória para as linhas da matriz!\n");
        return NULL;
    }
    // Aloca as colunas das linhas
    for (int c = 0; c < m; c++) {
        matriz[c] = (int *)malloc(n * sizeof(int));
        // Verifica se as colunas foram alocadas
        if (matriz[c] == NULL) {
            printf("-> Problema ao alocar memória para as colunas da matriz!\n");
            // Libera a matriz até a linha c, que é a atual que estava tentando ser alocada
            liberarMemoriaMatriz(matriz, c);
            return NULL;
        } 
    }
    return matriz;
}

/*
    Função para liberar a memória da matriz
*/
int liberarMemoriaMatriz(int **matriz, int m) {
    for (int c = 0; c < m; c++) {
        free(matriz[c]);
    }
    free(matriz);
    return 0;
}

int main () {

    // Variaveis auxiliares
    int linhas, colunas, valor;

    // Solicita a quantidade de linhas da matriz
    printf("> Digite a quantidade de linhas da matriz:\n");
    scanf("%d", &linhas);

    // Solicita a quantidade de colunas da matriz
    printf("> Digite a quantidade de colunas da matriz:\n");
    scanf("%d", &colunas);

    // Chama a função alocarMemoriaMatriz para a matriz
    int **matriz = alocarMemoriaMatriz(linhas, colunas);

    // Solicita os elementos
    system("cls");
    for (int m = 0; m < linhas; m++) {
        for (int n = 0; n < colunas; n++) {
            printf("> Digite o elemento[%d][%d]:\n", m, n);
            scanf("%d", &valor);
            matriz[m][n] = valor;
        }
    }

    // Mostra os elementos
    system("cls");
    for (int m = 0; m < linhas; m++) 
        for (int n = 0; n < colunas; n++)
            printf("[%d][%d] %d\n", m, n, matriz[m][n]);

    // Libera a memória alocada para a matriz
    liberarMemoriaMatriz(matriz, linhas);

    return 0;
}

/*
    Fiz uma função para que, depois de passado o tamanho das "linhas" e "colunas", é
    feito sua alocação dinâmica;
    Outra foi feita também para liberar a memória alocada, a qual se é passado uma
    matriz e a quantidade de "linhas";
    No main solicito ao usuário as "linhas" e "colunas", chamo a função para alocação de 
    uma matriz, solicito também os elementos, printo eles, e em seguida chamo a função para 
    liberar sua memória.
*/