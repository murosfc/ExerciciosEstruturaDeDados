/* 1. Implementar um programa para armazenar numeros inteiros em uma lista
encadeada. O programa devera apresentar um menu com as seguintes
opc~oes:
(a) Inclus~ao de elemento no incio da lista
(b) Exclus~ao de elemento do incio da lista
(c) Impress~ao dos elementos da lista
(d) Finalizac~ao do Programa
Caso seja escolhida a opc~ao 1, o usuario devera digitar o numero a ser
includo. Caso seja escolhida a opc~ao de Finalizac~ao do Programa, todos
os elementos restantes na estrutura de dados dever~ao ser desalocados para
so depois o programa ser encerrado. */

#include <stdio.h>
#include <stdlib.h>

typedef struct num {
	int num;
	struct num *prox;
} dados;

dados *incluir (dados *inicio);
dados *excluir (dados *inicio);
void imprimir (dados *inicio);
void finalizar (dados *inicio);

int main()
{
	int opt;
	dados *inicio = NULL;
	do{
		printf ("*************************MENU*************************\n");
		printf ("**                                                  **\n");
		printf ("**          DIGITE UMA DAS OPCOES ABAIXO            **\n");
		printf ("**                                                  **\n");
		printf ("** 1 - incluir elemento no inicio da lista          **\n");
		printf ("** 2 - excluir elemento do inicio da lista          **\n");
		printf ("** 3 - imprimir elementos da lista                  **\n");
		printf ("** 4 - encerrar programa                            **\n");		
		printf ("**                                                  **\n");
		printf ("******************************************************\n");
		scanf ("%d",&opt);
		system ("clear"); //"clear" para linux "cls" para windows
		switch (opt)
		{
		case 1:				
			inicio = incluir (inicio);		
			//			
			break;
		case 2:
			inicio = excluir (inicio);			
			break;
		case 3:
			imprimir (inicio);			
			break;
		case 4:
			finalizar (inicio);				
			break;		
		default:
			printf ("\nOpcao invalida, tente novamente\n\n\a");
		}
	}
	while (opt != 4);
	printf ("\n\nPrograma encerrado com sucesso!\n");
	return 0;
}
dados *incluir (dados *inicio)
{
	int numero;
	dados *novo;
	novo = (dados *) malloc (sizeof (dados ));
	printf ("\n\nDigite o valor a incluir na lista:\n");
	scanf ("%d",&numero);
	novo -> num = numero;
	novo -> prox = inicio;	
	return novo;		
}	
dados *excluir (dados *inicio)
{
	dados *temp;
	if (inicio == NULL)
		printf ("\nNao ha dados na lista, impossível excluir!\n\n\a");
	else {
		printf ("\nExcluindo o valor %d \n",inicio->num);
		temp = inicio;
		inicio = inicio -> prox;
		free (temp);
		return inicio;
	}
	return NULL;
}
void imprimir (dados *inicio)
{
	dados *temp;
	temp = inicio;
	if (inicio==NULL)
	    printf ("\nNao ha dados na lista\n\n\a");
	else
	{
	printf ("\nLista de dados: ");
	while (temp != NULL)
	{
		printf ("%d ",temp->num);
		temp = temp->prox;
	}
	printf ("\n\n");
    }
}
void finalizar (dados *inicio)
{
	dados *temp;
	temp = inicio;
	if (inicio!=NULL)
	{
	while (temp->prox != NULL)
	{
		inicio = inicio -> prox;
		free (temp);
		temp = inicio;
	}
	}
}