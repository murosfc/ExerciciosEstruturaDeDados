#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"pilhaTADstructArvore.h"

struct reg_no_arvore
{
    struct reg_no_arvore *ptrEsquerda;
    int chave;
    struct reg_no_arvore *ptrDireita;
};
typedef struct reg_no_arvore tipo_no_arvore;

void incluir_no_arvore(tipo_no_arvore **sub_raiz, int chave)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = malloc(sizeof(tipo_no_arvore));
        (*sub_raiz)->chave = chave;
        (*sub_raiz)->ptrEsquerda = NULL;
        (*sub_raiz)->ptrDireita = NULL;
    }
    else
    {
        if (chave < (*sub_raiz)->chave)
        {
            incluir_no_arvore(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                incluir_no_arvore(&((*sub_raiz)->ptrDireita), chave);
            }
        }
    }
}

void incluir_no_arvore_iterativo(tipo_no_arvore **sub_raiz, int chave)
{
    while (*sub_raiz != NULL)
    {
        if (chave < (*sub_raiz)->chave)
        {
            sub_raiz = &((*sub_raiz)->ptrEsquerda);
        }
        else
        {
            sub_raiz = &((*sub_raiz)->ptrDireita);
        }
    }
    *sub_raiz = malloc(sizeof(tipo_no_arvore));
    (*sub_raiz)->chave = chave;
    (*sub_raiz)->ptrEsquerda = NULL;
    (*sub_raiz)->ptrDireita = NULL;
}

void percurso_em_ordem_recursivo(tipo_no_arvore *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        percurso_em_ordem_recursivo(sub_raiz->ptrEsquerda);
        printf("%d ", sub_raiz->chave);
        percurso_em_ordem_recursivo(sub_raiz->ptrDireita);
    }
}

void percurso_em_ordem_iterativo(tipo_no_arvore *sub_raiz, tipo_pilha* pilha)
{
    printf("\n\n");
    while ((sub_raiz != NULL) || (!pilhaVazia(pilha)))
    {
        if (sub_raiz != NULL)
        {
            empilhar(pilha, sub_raiz);
            sub_raiz = sub_raiz->ptrEsquerda;
        }
        else
        {
            sub_raiz = desempilhar(pilha);
            printf("%d ", sub_raiz->chave);
            sub_raiz = sub_raiz->ptrDireita;
        }
    }
}

int main()
{
    tipo_no_arvore *arvore = NULL;
    int chave;
    tipo_pilha* pilha;

    pilha = criarPilhaVazia();

    incluir_no_arvore_iterativo(&arvore, 100);
    incluir_no_arvore_iterativo(&arvore, 50);
    incluir_no_arvore_iterativo(&arvore, 150);
    incluir_no_arvore_iterativo(&arvore, 25);
    incluir_no_arvore_iterativo(&arvore, 75);
    incluir_no_arvore_iterativo(&arvore, 45);
    incluir_no_arvore_iterativo(&arvore, 35);
    incluir_no_arvore_iterativo(&arvore, 48);
    incluir_no_arvore_iterativo(&arvore, 150);
    incluir_no_arvore_iterativo(&arvore, 175);
    incluir_no_arvore_iterativo(&arvore, 165);
    incluir_no_arvore_iterativo(&arvore, 160);
    percurso_em_ordem_recursivo(arvore);
    percurso_em_ordem_iterativo(arvore,pilha);
    return 0;
}
