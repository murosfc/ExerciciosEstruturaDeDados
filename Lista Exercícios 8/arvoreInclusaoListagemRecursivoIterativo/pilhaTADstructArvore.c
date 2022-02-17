#include<stdlib.h>

typedef struct reg_no_arvore
{
    struct reg_no_arvore *ptrEsquerda;
    int chave;
    struct reg_no_arvore *ptrDireita;
}tipo_no_arvore;

typedef struct no
{
    tipo_no_arvore *dado;
    struct no *proximo;
} tipo_no;

typedef struct reg_pilha
{
    tipo_no *inicio;
    int quantidadeElementos;
} tipo_pilha;

tipo_pilha* criarPilhaVazia()
{
    tipo_pilha* pilha = (tipo_pilha*) malloc(sizeof(tipo_pilha));
    pilha->inicio = NULL;
    pilha->quantidadeElementos = 0;
    return pilha;
}

int pilhaVazia(tipo_pilha* pilha)
{
    if (pilha->quantidadeElementos == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int quantidadeElementosPilha(tipo_pilha* pilha)
{
    return pilha->quantidadeElementos;
}

tipo_pilha* apagarPilha(tipo_pilha* pilha)
{
    tipo_no *auxiliar;

    while (!pilhaVazia(pilha))
    {
        auxiliar = pilha->inicio;
        pilha->inicio = pilha->inicio->proximo;
        free(auxiliar);
        pilha->quantidadeElementos--;
    }
    free(pilha);
    return NULL;
}

void empilhar(tipo_pilha* pilha, tipo_no_arvore* dado)
{
    tipo_no *novo;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = pilha->inicio;
    pilha->inicio = novo;
    pilha->quantidadeElementos++;
}

tipo_no_arvore* desempilhar(tipo_pilha* pilha)
{
    tipo_no *auxiliar;
    tipo_no_arvore *dado;

    if (pilha->inicio != NULL)
    {
        dado = pilha->inicio->dado;
        auxiliar = pilha->inicio;
        pilha->inicio = pilha->inicio->proximo;
        free(auxiliar);
        pilha->quantidadeElementos--;
        return dado;
    }
    return NULL;
}
