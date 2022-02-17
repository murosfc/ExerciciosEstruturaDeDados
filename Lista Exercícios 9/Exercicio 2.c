/*2.Crie um programa para gerar uma sequ^encia de 10 numeros aleatorios, entre 1 e 200, a partir da semente
contendo os tr^es ultimos numeros da sua matrcula. Faca o desenho de uma arvore binaria de busca
cuja sequencia de entrada sejam os 10 numeros gerados. Indique os enderecos dos campos como no slide
apresentado em sala. Gere um arquivo em formato JPG e envie pelo Moodle.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tadArvoreBB3.h"

int main()
{
    int i, aux;
    tipo_no_arvore arvore;
    
    arvore = inicializar_arvore (arvore);
    
    srand (227);
    
    printf ("\nElementos na ordem em que foram inseridos:");
    for (i=0;i<10;i++)
    {
        aux = rand()%201 +1;
        incluir_no_arvore (arvore, aux);
        printf ("\nElemento %d = %d", i, aux);
    }
    
    printf ("\n\nArvore em ordem:\n");
    percurso_em_ordem (arvore);
    printf ("\n\n");

    return 0;
}