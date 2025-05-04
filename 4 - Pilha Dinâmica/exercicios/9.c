#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int sair = 0;
    int menu = 0;
    int elemento;
    int *elementoRetirado;
    Pilha *pilha;
    Pilha *pilhaBinario;
    while (sair == 0) {
        printf("------------------------------------------\n");
        printf("                Pilha Menu\n");
        printf("------------------------------------------\n");
        printf("[1] - Criar pilha.\n");
        printf("[2] - Verifica se a pilha esta vazia.\n");
        printf("[3] - Verifica se a pilha esta cheia.\n");
        printf("[4] - Empilha o elemento na pilha.\n");
        printf("[5] - Desempilha elemento da pilha.\n");
        printf("[6] - Le topo de um pilha.\n");
        printf("[7] - Converte um numero decimal em binario.\n");
        printf("[8] - Sair.\n");
        scanf("%d", &menu);
        system("cls");
        switch(menu) {
            case 1:
                pilha = criarPilha();
                printf("\n-> Pilha criada com sucesso!\n\n");
                break;
            case 2:
                if (vazia(pilha)) {
                    printf("\n-> A pilha esta vazia!\n\n");
                } else {
                    printf("\n-> A pilha nao esta vazia!\n\n");
                }
                break;
            case 3:
                printf("\n-> A pilha nao possui limite, ao nao ser quando acabe a memoria!\n\n");
                break;
            case 4:
                system("cls");
                printf("\n> Digite o elemento(inteiro):\n");
                scanf("%d", &elemento);
                system("cls");
                if (push(pilha, elemento)) {
                    printf("\n-> %d adicionado a pilha!\n\n", elemento);
                } else {
                    printf("\n-> Nao foi possivel adicionar %d na pilha!\n\n", elemento);
                }
                break;
            case 5:
                elementoRetirado = (int *)malloc(sizeof(int));
                if(elementoRetirado == NULL) return 0;
                if (pop(pilha, elementoRetirado)) {
                    printf("\n-> %d removido da pilha!\n\n", *elementoRetirado);
                } else {
                    printf("\n-> Nao foi possivel remover %d da pilha!\n\n", *elementoRetirado);
                }
                free(elementoRetirado);
                break;
            case 6:
                if (size(pilha) < 0) printf("\n-> A pilha esta vazia!\n\n");
                printf("\n-> Topo da pilha: %d\n\n", pilha->topo->valor);
                break;
            case 7:
                printf("\n> Digite um numero:\n");
                scanf("%d", &elemento);
                pilhaBinario = criarPilha();
                while (elemento > 0) {
                    if (elemento % 2 == 0) {
                        push(pilhaBinario, ZERO);
                    } else {
                        push(pilhaBinario, UM);
                    }
                    elemento /= 2;
                }
                printf("\n-> Conversao:\n");
                if(!printc(pilhaBinario)) return 0;
                free(elementoRetirado);
                destroy(pilhaBinario);
                break;
            case 8:
                printf("\n-> Saindo...\n\n");
                sair = 1;
                break;
            default:
                printf("\n-> Opcao invalida!\n\n");
        }
        if (sair != 1) system("pause && cls");
    }

    free(elementoRetirado);
    destroy(pilha);
    destroy(pilhaBinario);
    return 0;
}

// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

/*
    Fiz um meno simples, a que o numero que o usuário digitar, chamar a cada determinada
    função, sendo dentre elas a mais diferente a de converter de decimal para primário,
    em que crio uma pilha, e enquanto o elemento solicitado for maior que 0 ele executa o
    processo de conversão, colocando zeros ou uns através do push na pilha, e depois uso
    a função printc criada anteriormente que printa em sequencia os caracteres.
*/
