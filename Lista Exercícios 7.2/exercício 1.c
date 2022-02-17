#include <stdio.h>

double fatorial (int numero);

int main ()
{
	int numero;
	printf ("\nDigite o numero para o qual deseja calcular o fatorial:\n");
	scanf ("%d",&numero);
	printf ("\nFatorial de %d = %.0f\n\n",numero, fatorial (numero));
	return 0;
}

double fatorial (int numero)
{
	double resultado;
	if (numero <= 0)
		return 1;
	else 
	{
   	    resultado = numero* fatorial(numero -1);
		return resultado;	
	}
}