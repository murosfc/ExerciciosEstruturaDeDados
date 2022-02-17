/*Fa¸ca uma fun¸c˜ao recursiva que calcule e retorne o N-´esimo termo da sequˆencia Fibonacci. Alguns n´umeros
desta sequˆencia s˜ao: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...*/

#include <stdio.h>

int fibonacci (int n)
{
	int valor;
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else 
	{
		valor = fibonacci (n-1) + fibonacci(n-2);
		return valor;
	}
		
}

int main ()
{
	int n=0;
	while (n>=0)
	{
		printf("\nDigite o termo da sequencia Fibonacci desejas obter:\n");
		scanf ("%d",&n);
		printf ("\nO valor da sequencia Fibonacci para o termo %d = %d\n\n",n,fibonacci(n));	   	
	}
	
	return 0;
}