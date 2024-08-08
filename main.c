#include <stdio.h>
#include <stdlib.h>
#include "avn.h"

int main() {
    NO* raiz = NULL;
    int opcao;
    TIPOCHAVE chavePai, chaveFilho;

    printf("Digite a chave para a raiz da arvore: ");
    scanf("%d", &chavePai);
    raiz = criarNo(chavePai);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar filho\n");
        printf("2. Remover filho\n");
        printf("3. Imprimir arvore\n");
        printf("4. Buscar filho\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("Digite a chave do pai: ");
                scanf("%d", &chavePai);
                printf("Digite a chave do novo filho: ");
                scanf("%d", &chaveFilho);
                NO* pai = buscarNo(raiz, chavePai);
                if (pai != NULL) {
                    adicionarFilho(pai, criarNo(chaveFilho));
                    printf("Filho adicionado com sucesso!\n");
                } else {
                    printf("Pai nao encontrado!\n");
                }
                break;
            }
            case 2: {
                printf("Digite a chave do filho a ser removido: ");
                scanf("%d", &chaveFilho);
                removerFilho(&raiz, chaveFilho);
                printf("Filho removido com sucesso!\n");
                break;
            }
            case 3:
                printf("Arvore:\n");
                imprimirArvore(raiz, 0);
                break;
            
            case 4: {
                printf("Digite a chave do filho a ser buscado: ");
                scanf("%d", &chaveFilho);
                NO* filho = buscarNo(raiz, chaveFilho);
                if (filho != NULL) {
                    printf("Filho encontrado: %d\n", filho->chave);
                } else {
                    printf("Filho nao encontrado!\n");
                }
                break;
            }
            case 5:
                liberarArvore(raiz);
                return 0;
            default:
                printf("Opçao invalida!\n");
                break;
        }
    }

    return 0;
}
