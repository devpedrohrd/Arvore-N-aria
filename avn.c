#include <stdio.h>
#include <stdlib.h>
#include "avn.h"

NO* criarNo(TIPOCHAVE chave) {
    NO* novoNo = (NO*)malloc(sizeof(NO));
    novoNo->chave = chave;
    novoNo->primFilho = NULL;
    novoNo->proxIrmao = NULL;
    return novoNo;
}

void adicionarFilho(NO* pai, NO* filho) {
    if (pai->primFilho == NULL) {
        pai->primFilho = filho;
    } else {
        NO* temp = pai->primFilho;
        while (temp->proxIrmao != NULL) {
            temp = temp->proxIrmao;
        }
        temp->proxIrmao = filho;
    }
}

void removerFilho(NO** raiz, TIPOCHAVE chave) {
    if (*raiz == NULL) return;

    if ((*raiz)->chave == chave) {
        NO* temp = *raiz;
        *raiz = (*raiz)->primFilho;

        if (*raiz != NULL) {
            NO* irmao = (*raiz)->proxIrmao;
            (*raiz)->proxIrmao = temp->proxIrmao;

            while (irmao != NULL) {
                adicionarFilho(*raiz, irmao);
                irmao = irmao->proxIrmao;
            }
        }

        free(temp);
        return;
    }

    NO* pai = *raiz;
    NO* atual = pai->primFilho;
    NO* anterior = NULL;

    while (atual != NULL && atual->chave != chave) {
        anterior = atual;
        atual = atual->proxIrmao;
    }

    if (atual == NULL) return;

    if (anterior == NULL) {
        pai->primFilho = atual->proxIrmao;
    } else {
        anterior->proxIrmao = atual->proxIrmao;
    }

    if (atual->primFilho != NULL) {
        NO* temp = atual->primFilho;
        while (temp->proxIrmao != NULL) {
            temp = temp->proxIrmao;
        }
        temp->proxIrmao = pai->primFilho;
        pai->primFilho = atual->primFilho;
    }

    free(atual);
}


NO* buscarNo(NO* raiz, TIPOCHAVE chave) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == chave) return raiz;

    NO* encontrado = buscarNo(raiz->primFilho, chave);
    if (encontrado) return encontrado;

    return buscarNo(raiz->proxIrmao, chave);
}

void imprimirArvore(NO* raiz, int nivel) {
    if (raiz == NULL) return;

    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("%d\n", raiz->chave);

    imprimirArvore(raiz->primFilho, nivel + 1);
    imprimirArvore(raiz->proxIrmao, nivel);
}

void liberarArvore(NO* raiz) {
    if (raiz == NULL) return;

    liberarArvore(raiz->primFilho);
    liberarArvore(raiz->proxIrmao);
    free(raiz);
}
