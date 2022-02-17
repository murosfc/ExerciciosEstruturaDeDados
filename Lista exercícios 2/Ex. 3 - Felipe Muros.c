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
#include <time.h>

#define N 10//alterar valor de 'n' conforme necessidade do estudo

int **ordenar(int n, int *vetorInteiro);

int main()
{
	int i; 
	int vet[N],**vetpoint;
	srand (time (NULL));
	vetpoint = (int**) malloc (N* sizeof (int*));
	for (i=0; i<N; i++)
	{
		vet[i]= rand()%100; //alterar conforme o valor maior e menor dentro do vetor
	}
	printf ("Vetor 'v' inicial:\n");
	for (i=0;i<N;i++)
	{
		printf ("v[%d]=%d end: %x\n",i,vet[i],&vet[i]);
	}
	vetpoint = ordenar (N,vet);
	printf ("\nVetor 'v' ordenado:\n");
	for (i=0;i<N;i++)
	{
		printf ("v[%d]=%d end: %x\n",i,*vetpoint[i],vetpoint[i]);
	}
	free (vetpoint);
	return 0;
}

int **ordenar(int n, int *vetorInteiro)
{
	int **vetorPonteiros,**aux;
	int i,j;
	vetorPonteiros = (int**) malloc (n* sizeof (int*));
	aux= (int**) malloc (sizeof (int*));
	for (i=0;i<n;i++)
	{
		vetorPonteiros[i]=&vetorInteiro[i];
	}				
	for (i=0;i<n-1;i++)
	{		
		for (j=i+1;j<n;j++)
		{		
			if (*vetorPonteiros[i]>*vetorPonteiros[j])
			{
				aux=vetorPonteiros[j];
				vetorPonteiros[j]=vetorPonteiros[i];
				vetorPonteiros[i]=aux;	
			}	
		}
	}			
	return vetorPonteiros;	
}
