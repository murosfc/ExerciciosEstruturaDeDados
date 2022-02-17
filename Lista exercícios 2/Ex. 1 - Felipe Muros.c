/* Implemente um programa que ap´os a entrada de valores inteiros para duas
vari´aveis fa¸ca a troca dos valores destas vari´aveis na mem´oria. Utilizar
uma fun¸c˜ao para realizar a troca. */

#include <stdio.h>

void troca (int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main ()
{
	int a = 3,b = 5;
	printf ("Valores iniciais:\n a=%d \n b=%d \n\n",a,b);
	troca (&a,&b);
	printf ("Valores trocados:\n a=%d \n b=%d \n",a,b);
	return 0;
}