/*5. Fa¸ca uma fun¸c˜ao para inverter a ordem dos elementos existentes em uma string. Utilize, obrigatoriamente,
uma pilha como mem´oria tempor´aria para armazenar a string. Fa¸ca um programa principal para testar a
sua funcionalidade, entre com uma frase de at´e 20 caracteres e a imprima ap´os a invers˜ao. Utilize o tipo
abstrato de dados pilha desenvolvido na quest˜ao anterior.*/

#include <stdlib.h>
#include <stdio.h>
#include "pilha_string.h"

int main ()
{
	char frase[20];
	tipo_pilha *pilhaFrase;
	pilhaFrase= criaPilha ();
	int i=0;
	printf ("\nDigite a frase:\n");
	scanf ("%[^\n]",frase);
	while (frase[i] != '\0')
	{
		push (pilhaFrase, frase[i]);
		i++;
	}			
	printf ("\nFrase invertida:\n");
	while ( i >= 0 )
	{
		printf ("%c",pop (pilhaFrase));
		i--;
	}
	printf ("\n\n");
	return 0;
}