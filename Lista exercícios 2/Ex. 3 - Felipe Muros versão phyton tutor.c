/* Implemente uma fun¸c˜ao que receba um vetor de inteiros de tamanho
n. Essa fun¸c˜ao deve alocar dinamicamente um outro vetor tamb´em de
tamanho n que contenha os endere¸cos dos valores do vetor de inteiros de
forma ordenada crescente, ficando a primeira posi¸c˜ao do vetor de ponteiros
o endere¸co do menor valor at´e a ´ultima posi¸c˜ao, que conter´a o endere¸co
do maior valor. Essa fun¸c˜ao deve obedecer ao prot´otipo:
int** ordenar(int n, int* vetorInteiro);
Simplificar o c´odigo gerado para que o mesmo apresente no site
http://pythontutor.com/c.htmlmode=edit os dois vetores, um com dados
originais (Inicializar o vetor com dados exemplos) e um outro contendo os
endere¸cos dos dados originais dispostos em ordem decrescente em fun¸c˜ao
dos valores. */

#include <stdio.h>
#include <stdlib.h>

int **ordenar(int n, int *vetorInteiro)
{
    int **vetpoint;
    int i,j;
    vetpoint = (int**) malloc (11 * sizeof (int*));
    for (i=0;i<n;i++)
        vetpoint[i]=&vetorInteiro[i];            
    for (i=0;i<n-1;i++)
    {        
        for (j=i+1;j<n;j++)
            if (*vetpoint[i]>*vetpoint[j])
            {
                vetpoint[n+1]=vetpoint[j];
                vetpoint[j]=vetpoint[i];
                vetpoint[i]=vetpoint[n+1];    
            }
    }
    free (vetpoint[n+1]);        
    return vetpoint;
    free (vetpoint);  
}

int main()
{
    int i;
    int **vetorPont,vet[10]={5,4,9,7,3,5,1,0,7,2};    
    vetorPont = (int**) malloc (10* sizeof (int*));
    vetorPont = ordenar (10,vet);  
    free (vetorPont);
    return 0;
}


