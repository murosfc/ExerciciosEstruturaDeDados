/*Considere uma pilha P vazia e uma fila F n˜ao vazia. Utilizando apenas os testes de fila e pilha vazias,
as opera¸c˜oes Enfileira, Desenfileira, Empilha, Desempilha, e uma vari´avel aux do TipoItem, escreva uma
fun¸c˜ao que inverta a ordem dos elementos da fila.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha_fila.h"

#define TAM 20

void interteFila (tipo_fila *filainicial, tipo_pilha *pilhainicial)
{
	int aux;
	aux=removeFila(filainicial);
	while (aux != NULL)
	{
		push(pilhainicial,aux);
		aux=removeFila(filainicial);
	}
	aux=pull(pilhainicial);
	while (aux != NULL)
	{
		addFila(filainicial,aux);
		aux=pull(pilhainicial);
	}
}

int main ()
{
	int aux;
	
	tipo_fila *F;
	tipo_pilha *P;
	
	P=criarPilha();
	F=criarFila();
	
	srand (time (NULL));
	for (aux=0;aux<TAM;aux++)
		addFila(F,rand()%100+1);
	
	printf ("\nFila inicial\n");
	for (aux=0;aux<tamanhoFila(F);aux++)
		printf ("%d ",consultaFilaPorProfundidade(F,aux));
	
	interteFila (F,P);
	
	printf ("\n\nFila invertida\n");		
	for (aux=0;aux<tamanhoFila(F);aux++)
		printf ("%d ",consultaFilaPorProfundidade(F,aux));
}