/*. Implemente uma fun¸c˜ao que receba trˆes filas, filaOriginal, filaImpares e filaPares (todas j´a inicializadas),
e separe todos os valores guardados em filaOriginal de tal forma que os valores pares s˜ao colocados na fila
filaPares e os valores ´impares na filaImpares. Ao final da execu¸c˜ao desta fun¸c˜ao, filaOriginal permanecer´a
com todos os seus elementos. O prot´otipo desta fun¸c˜ao ´e o seguinte: void separaFilas(tipo_fila* filaOriginal,
tipo_fila* filaPares,tipo_fila* filaImpares).*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilha_fila.h"

#define TAM 100


void separaFilas(tipo_fila* filaOriginal, tipo_fila* filaPares,tipo_fila* filaImpares)
{
	int i, aux, j=tamanhoFila(filaOriginal);
	for (i=0;i<j;i++)
	{
		aux=consultaFilaPorProfundidade (filaOriginal,i);
		if (aux %2 ==0)
			addFila(filaPares, aux);
		else addFila(filaImpares, aux);
	}
}

int main ()
{
	tipo_fila *filaOriginal, *filaImpares, *filaPares;
	int i, j;
	filaOriginal=criarFila();
	filaImpares=criarFila();
	filaPares=criarFila();
	srand (time (NULL));
	for (i=0;i<TAM;i++)
		addFila(filaOriginal, rand()%100+1);
	separaFilas(filaOriginal,filaPares,filaImpares);
	printf ("\nFila Original:\n");
	j=tamanhoFila(filaOriginal);
	for (i=0;i<j;i++)
		printf ("%d ",consultaFilaPorProfundidade (filaOriginal,i));
	printf ("\n\nFila Pares:\n");
	j=tamanhoFila(filaPares);
	for (i=0;i<j;i++)
		printf ("%d ",consultaFilaPorProfundidade (filaPares,i));
	printf ("\n\nFila Impares:\n");
	j= tamanhoFila(filaImpares);
	for (i=0;i<j;i++)
		printf ("%d ",consultaFilaPorProfundidade (filaImpares,i));
	return 0;
}
