#ifndef AVN_H
#define AVN_H

typedef int TIPOCHAVE;

typedef struct no {
    TIPOCHAVE chave;
    struct no* primFilho;
    struct no* proxIrmao;
} NO;

NO* criarNo(TIPOCHAVE chave);
void adicionarFilho(NO* pai, NO* filho);
void removerFilho(NO** raiz, TIPOCHAVE chave);
NO* buscarNo(NO* raiz, TIPOCHAVE chave);
void imprimirArvore(NO* raiz, int nivel);
void liberarArvore(NO* raiz);

#endif
