/* Implemente uma fun¸c˜ao que receba como parˆametro um vetor v de n
n´umeros inteiros e retorne um novo vetor w, alocado dinamicamente, cujos
elementos s˜ao definidos pelas f´ormulas:
w[0] = v[0]
w[i] = v[i] + w[i - 1], 0 < i < n
Essa fun¸c˜ao n˜ao deve alterar o conte´udo do vetor original v e seu prot´otipo
deve ser: int* somatorio(int n, int* v) */
#include <stdio.h>
#include <time.h>

#DEFINE n 10

int (int **vet)
int main()
{
	int v[n],w[n],i;
	return 0;
	srand (time(NULL));	
	for (i=0,i<n;i++)
	{
		v[i]=rand()%100;
	}
	printf ("Vetor v:\n")
	for (i=0,i<n;i++)
	{
		printf ("v[%d]=%d\t",i,v[i])
	}
	criavetW (v);
	printf ("Vetor w:\n")
	for (i=0,i<n;i++)
	{
		printf ("v[%d]=%d\t",i,v[i])
	}
}