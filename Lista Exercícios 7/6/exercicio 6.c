/*5. Construa uma fun¸c˜ao, que use a estrutura pilha e verifique se o n´umero de abre parˆenteses ´e igual ao
n´umero de fecha parˆenteses em uma express˜ao matem´atica. Fa¸ca um programa principal para testar a
sua funcionalidade, entre com uma frase e imprima a string ap´os a invers˜ao. Utilize o tipo abstrato de
dados pilha desenvolvido na quest˜ao anterior.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha_string.h"

#define TAM 100

int main ()
{
	char frase[TAM], funcao_matematica[100];
	tipo_pilha *pilhaFrase, *funcao;
	pilhaFrase= criaPilha ();
	funcao= criaPilha();
	int i=0;
	
	printf ("\nFuncao 1: ");
	strcpy(funcao_matematica, "((3*2)+4/(5+2)*(24-56))");
		while (funcao_matematica[i] != '\0')
	{
		push (funcao, funcao_matematica[i]);
		i++;
	} 	
 	if (checaParenteses (funcao) == 1)
 		printf ("\nNumero de abre parenteses igual ao de fecha\n");
 	else printf ("\nNumero de abre parenteses diferente do de fecha\n");
 	
 	printf ("\nFuncao 2: ");
	i=0;
	strcpy(funcao_matematica,"((3*2)+4/(5+2)*(24-56)))");
		while (funcao_matematica[i] != '\0')
	{
		push (funcao, funcao_matematica[i]);
		i++;
	} 	
 	if (checaParenteses (funcao) == 1)
 		printf ("\nNumero de abre parenteses igual ao de fecha\n");
 	else printf ("\nNumero de abre parenteses diferente do de fecha\n");

	i=0;
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