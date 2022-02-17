#include<stdio.h>
#include"tadArvoreBB2.h"
int main()
{
    tipo_no_arvore *arvore = NULL;
    int chave;

    incluir_no_arvore(&arvore, 100);
    incluir_no_arvore(&arvore, 50);
    incluir_no_arvore(&arvore, 150);
    incluir_no_arvore(&arvore, 25);
    incluir_no_arvore(&arvore, 75);
    incluir_no_arvore(&arvore, 45);
    incluir_no_arvore(&arvore, 35);
    incluir_no_arvore(&arvore, 48);
    incluir_no_arvore(&arvore, 150);
    incluir_no_arvore(&arvore, 175);
    incluir_no_arvore(&arvore, 165);
    incluir_no_arvore(&arvore, 160);
    printf("\nListagem em ordem:\n");
    percurso_em_ordem(&arvore);
    printf("\nListagem em pré-ordem:\n");
    percurso_em_pre_ordem(&arvore);
    printf("\nListagem em pós-ordem:\n");
    percurso_em_pos_ordem(&arvore);
    printf("\nEncontrar 45: %d", encontrar_elemento(&arvore, 45));
    printf("\nEncontrar 44: %d", encontrar_elemento(&arvore, 44));
    chave = excluir_menor(&arvore);
    printf("\nMenor elemento excluido: %d", chave);
    printf("\nExcluir 45: %d", excluir_elemento(&arvore, 45));
    printf("\nExcluir 44: %d\n", excluir_elemento(&arvore, 44));
    percurso_em_ordem(&arvore);
    printf("\n");
    return 0;
}
