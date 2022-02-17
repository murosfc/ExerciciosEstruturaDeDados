#include <stdio.h>
#include "racionais.h"

typedef struct racional tipo_racional;

int main()
{
	int dividendo,divisor;
	tipo_racional *racional1,*racional2;
	printf ("\nDigite o dividendo do primeiro racional: ");
	scanf ("%d",&dividendo);
	printf ("\nDigite o divisor do primeiro racional: ");
	scanf ("%d",&divisor);
	racional1=cria_racional(dividendo,divisor);
	printf ("\nRacional 1: %d/%d\n",dividendo,divisor);
	printf ("\nDigite o dividendo do segundo racional: ");
	scanf ("%d",&dividendo);
	printf ("\nDigite o divisor do segundo racional: ");
	scanf ("%d",&divisor);
	racional2=cria_racional(dividendo,divisor);
	printf ("\nRacional 2: %d/%d\n",dividendo,divisor);
	soma_racional(racional1,racional2,&dividendo,&divisor);
	printf ("\nSoma das fracoes: %d/%d\n",dividendo,divisor);
	multiplica_racional(racional1,racional2,&dividendo,&divisor);
	printf ("\nMultiplicacao das fracoes: %d/%d\n",dividendo,divisor);
	if (racionaiscmp(racional1,racional2)==1)
		printf ("\nAs fracoes sao iguais\n");
	else printf ("\nAs fracoes sao diferentes\n");
	return 0;
}