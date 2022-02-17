#include<stdio.h>
#include<stdlib.h>

struct reg_no_arvore
{
    struct reg_no_arvore *ptrEsquerda;
    int chave;
    struct reg_no_arvore *ptrDireita;
};
typedef struct reg_no_arvore **tipo_no_arvore;


tipo_no_arvore inicializar_arvore(tipo_no_arvore sub_raiz)
{
    sub_raiz = (struct reg_no_arvore**)malloc(sizeof(struct reg_no_arvore*));
    *sub_raiz = NULL;
}

void incluir_no_arvore(tipo_no_arvore sub_raiz, int chave)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = malloc(sizeof(struct reg_no_arvore));
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

void percurso_em_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_ordem(&((*sub_raiz)->ptrEsquerda));
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pre_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_pre_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pre_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pos_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_pos_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pos_ordem(&((*sub_raiz)->ptrDireita));
        printf("%d ", (*sub_raiz)->chave);
    }
}

int encontrar_elemento(tipo_no_arvore sub_raiz, int chave)
{
    if ((*sub_raiz) == NULL)
    {
        return 0;
    }
    else
    {
        if (chave == (*sub_raiz)->chave)
        {
            return 1;
        }
        else
        {
            if (chave < (*sub_raiz)->chave)
            {
                return encontrar_elemento(&((*sub_raiz)->ptrEsquerda), chave);
            }
            else
            {
                if (chave > (*sub_raiz)->chave)
                {
                    return encontrar_elemento(&((*sub_raiz)->ptrDireita), chave);
                }
            }
        }
    }
}

int excluir_menor(tipo_no_arvore sub_raiz)
{
    struct reg_no_arvore *auxiliar;
    int chave;

    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptrEsquerda != NULL)
        {
            return excluir_menor(&((*sub_raiz)->ptrEsquerda));
        }
        else
        {
            auxiliar = *sub_raiz;
            chave = auxiliar->chave;
            *sub_raiz = (*sub_raiz)->ptrDireita;
            free(auxiliar);
            return chave;
        }
    }
    else
    {
        return -1;
    }
}

int excluir_elemento(tipo_no_arvore sub_raiz, int chave)
{
    struct reg_no_arvore *auxiliar;

    if (*sub_raiz != NULL)
    {
        if (chave < (*sub_raiz)->chave)
        {
            return excluir_elemento(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                return excluir_elemento(&((*sub_raiz)->ptrDireita), chave);
            }
            else
            {
                if ((*sub_raiz)->ptrEsquerda == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->ptrDireita;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->ptrDireita == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->ptrEsquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->chave = excluir_menor(&((*sub_raiz)->ptrDireita));
                    }
                }
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}
