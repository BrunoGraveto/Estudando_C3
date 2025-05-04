#include <stdio.h>
#include <stdlib.h>

#define NOVA_MEM 3

/*
    Struct de produto
*/
typedef struct {
    int cod;
    char nome[100];
    float preco;
} Produto;

/*
    Mostra um produto
*/
void mostrarProduto(Produto produto) {
    printf("-> Produto #%02d\n", produto.cod+1);
    printf("Nome: %s\n", produto.nome);
    printf("Preco: R$%.2f\n", produto.preco);
}

/*
    Solicita ao usuário um novo produto
*/
int novoProduto(Produto *produtos, int *counterProdutos, int tamanhoProdutos) {
    // Caso precise aloca mais memoria ao vetor de produtos
    if (*counterProdutos >= tamanhoProdutos) {
        tamanhoProdutos+=NOVA_MEM;
        produtos = (Produto *)realloc(produtos, tamanhoProdutos);
    }

    // Vars do Produto
    int cod = *counterProdutos;
    char nome[100];
    float preco;

    // Codigo
    printf("-> Produto #%02d\n\n", cod+1);
    produtos[cod].cod = cod;

    // Nome
    printf("> Digite o nome do produto:\n");
    if (scanf(" %[^\n]", nome) != 1) return 1;
    sprintf(produtos[cod].nome, "%s", nome);
    
    // Preço
    printf("\n> Digite o preco do produto:\n");
    if (scanf("%f", &preco) != 1 || preco <= 0) return 1;
    produtos[cod].preco = preco;

    // Incrementa o counter de produtos
    (*counterProdutos)++;
    return 0;
}

/*
    Consulta um produto existente
*/
int consultarProduto (Produto* produtos, int counterProdutos) {
    // Variavel codigo
    int cod;

    // Solicita o codigo que deseja consultar
    printf("> Digite o codigo do produto:\n");
    scanf("%d", &cod);

    // Verifica se o codigo é valido
    if (cod <= 0 || cod > counterProdutos) return 1;

    // Motra o produto de determinado codigo
    system("cls");
    mostrarProduto(produtos[cod-1]);
    printf("\n");
    return 0;
}

/*
    Mostra todos os produtos
*/
void vizualizarProdutos(Produto *produtos, int counterProdutos) {
    printf("Produtos:\n\n");
    for (int i = 0; i < counterProdutos; i++) {
        mostrarProduto(produtos[i]);
        printf("\n");
    }
}

int main() {
    // Variaveis
    int menu, counterProdutos = 0, limiteProdutos = NOVA_MEM, sair = 0;
    // Aloca memoria primeiramente de NOVA_MEM produtos
    Produto *produtos = (Produto *)malloc(limiteProdutos * sizeof(Produto));

    // Menu
    while (sair == 0) {
        printf("---------------------------------------\n");
        printf("                  LOJA                 \n");
        printf("---------------------------------------\n");
        printf("[1] Cadastrar novo produto\n");
        printf("[2] Consultar produto\n");
        printf("[3] Vizualizar\n");
        printf("[4] Sair\n");
        scanf("%d", &menu);

        system("cls");
        switch (menu) {
        case 1:
            if (novoProduto(produtos, &counterProdutos, limiteProdutos) == 0) {
                printf("\n-> Produto adicionado com sucesso!\n\n");
            } else {
                printf("\n-> Houve algum problema ao tentar cadastrar o produto!\n\n");
            }
            break;
        case 2:
            if (counterProdutos <= 0) {
                printf("-> Nao existe(m) produto(s) para consultar(dos)!\n\n");
            } else if (consultarProduto(produtos, counterProdutos) == 1) {
                printf("-> Nao foi possivel consultar o produto!\n\n");
            }
            break;
        case 3:
            if (counterProdutos <= 0) {
                printf("-> Nao existe(m) produto(s) para ser(em) vizualizar(dos)!\n\n");
            } else {
                vizualizarProdutos(produtos, counterProdutos);
            }
            break;
        case 4:
            printf("-> Saindo...\n\n");
            sair = 1;
            break;
        default:
            printf("-> Opcao invalida!\n\n");
            break;
        }
        if (sair != 1) system("pause && cls");
    }

    // Libera a memoria de produtos
    free(produtos);
    return 0;
}

/*
    Criei um Struct para Produto;
    Criei funçÕes para:
    - Mostrar o vetor: void
    - Criar um novo produto: int (0 caso ocorreu tudo certo, 1 se algo deu errado)
    - Consultar um produto existente: int (0 caso ocorreu tudo certo, 1 se algo deu errado)
    - Visualizar todos os produtos: void
    No main criei um menu, que além de tem uma opção de saída, chama as funções citadas anteriormente, apenas adicionando algumas verificações(se já existe algum produto, se foi possivel criar o produto e etc).
*/