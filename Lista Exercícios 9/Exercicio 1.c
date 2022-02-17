/*1. Construir um programa para manipular 2 arvores binarias de busca. Na primeira devem ser inseridos 50
numeros aleatorios. Crie uma func~ao que copie os dados da primeira arvore na segunda de forma que as
estruturas das arvores se mantenham id^enticas. Imprima as duas arvores no melhor formato que prove
que as duas s~ao id^enticas.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tadArvoreBB3.h"

int main()
{
    int i;
    tipo_no_arvore arvore1,arvore2;
    
    arvore1 = inicializar_arvore (arvore1);
    arvore2 = inicializar_arvore (arvore2);
    
    srand (5);
    
    for (i=0;i<50;i++)
    {
        incluir_no_arvore (arvore1, rand()%100);
    }
    
    copiar_arvore (arvore1, arvore2); //Copia arvore 1 em arvore 2
    
    printf ("\nArvore 1 em pre-ordem:\n");
    percurso_em_pre_ordem (arvore1);
    printf ("\nArvore 2 em pre-ordem:\n");
    percurso_em_pre_ordem (arvore1);
    
    printf ("\n\nArvore 1 em ordem:\n");
    percurso_em_ordem (arvore1);
    printf ("\nArvore 2 em ordem:\n");
    percurso_em_ordem (arvore1);
    
    printf ("\n\nArvore 1 em pos-ordem:\n");
    percurso_em_pos_ordem (arvore1);
    printf ("\nArvore 2 em pos-ordem:\n");
    percurso_em_pos_ordem (arvore1);

    return 0;
}