/*Fa¸ca uma fun¸c˜ao recursiva que permita somar os elementos de um vetor de inteiros*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

int somavet (int vet[TAM], int i)
{
	int soma;
	if (i==0)
		return vet[i];
	else
	{
		soma=vet[i]+somavet(vet,i-1);
		return soma;
	}
}

int main ()
{
	srand (time(NULL));
	int i,vet[TAM];
	for (i=0;i<TAM;i++)
		vet[i]=rand ()%100;
	printf ("\nSoma dos elementos do vetor = %d\n\n",somavet(vet,TAM));
	return 0;
}