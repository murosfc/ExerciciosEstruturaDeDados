/*Crie uma fun¸c˜ao recursiva que receba um n´umero inteiro positivo N e calcule o somat´orio dos n´umeros de
1 a N.*/

#include <stdio.h>

int somaAteN (int N)
{
	int soma;
	if (N<=1)
		return 1;
	else
	{
		soma=N+somaAteN(N-1);
		return soma;
	}
}

int main ()
{
	int N;
	printf ("\nDigite o valor que deseja somar elementos anteriores ate 1:\n");
	scanf ("%d",&N);
	printf ("\nValor do somatorio = %d\n\n",somaAteN(N));
	return 0;
}