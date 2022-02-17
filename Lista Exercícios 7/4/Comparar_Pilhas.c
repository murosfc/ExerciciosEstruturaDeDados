#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pilha_fila.h"

#define TAM 10

int main ()
{
	int num,i;
	srand (time(NULL));
	tipo_pilha *pilha1, *pilha2, *pilha3, *pilha4;
	pilha1=criarPilha();
	pilha2=criarPilha();
	pilha3=criarPilha();
	pilha4=criarPilha();
	for (i=0;i<TAM;i++)
	{
		num=rand()%100+1;
		push(pilha1,num);
		push(pilha2,num);
		push (pilha3,rand()%50+1);
	}
	if (comparaPilhas(pilha1,pilha2) == 1)
		printf ("\nPilhas 1 e 2 sao iguais\n");
	else printf ("\nPilhas 1 e 2 sao diferentes\n");
	if (comparaPilhas(pilha1,pilha3) == 1)
		printf ("\nPilhas 1 e 3 sao iguais\n");
	else printf ("\nPilhas 1 e 3 sao diferentes\n");
	if (comparaPilhas(pilha1,pilha4) == 1)
		printf ("\nPilhas 1 e 4 sao iguais\n");
	else printf ("\nPilhas 1 e 4 sao diferentes\n");
	if (comparaPilhas(pilha3,pilha4) == 1)
		printf ("\nPilhas 3 e 4 sao iguais\n");
	else printf ("\nPilhas 3 e 4 sao diferentes\n");
	return 0;
}