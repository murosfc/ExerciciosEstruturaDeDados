/* 1. Implementar um programa para armazenar n´umeros inteiros em uma lista encadeada. O programa dever´a
apresentar um menu com as seguintes op¸c˜oes:
(a) Inclus˜ao de elemento no in´icio da lista
(b) Inclus˜ao de elemento no fim da lista
(c) Exclus˜ao de elemento do in´icio da lista
(d) Exclus˜ao de elemento do fim da lista
(e) Impress˜ao dos elementos da lista
(f) Limpar a lista - excluir_ini todos os elementos
(g) Finaliza¸c˜ao do Programa
Caso seja escolhida uma op¸c˜ao de inclus˜ao, o usu´ario dever´a digitar o n´umero a ser inclu´ido. Caso seja
escolhida a op¸c˜ao de Finaliza¸c˜ao do Programa, todos os elementos restantes na estrutura de dados dever˜ao
ser desalocados para s´o depois o programa ser encerrado.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct num {
	int num;
	struct num *prox;
} dados;

dados *incluir_ini (dados *inicio);
void incluir_fim (dados *inicio);
dados *excluir_ini (dados *inicio);
void excluir_fim (dados *inicio);
void imprimir (dados *inicio);
void limpar_lista (dados *inicio);

int main()
{
	int opt;
	dados *inicio = NULL;
	do{
		printf ("******************************************************\n");
		printf ("**                       MENU                       **\n");
		printf ("**                                                  **\n");
		printf ("**          DIGITE UMA DAS OPCOES ABAIXO:           **\n");
		printf ("**                                                  **\n");
		printf ("** 1 - Incluir elemento no inicio da lista          **\n");
		printf ("** 2 - Incluir elemento no final da lista           **\n");
		printf ("** 3 - Excluir elemento do inicio da lista          **\n");
		printf ("** 4 - Excluir elemento no final da lista           **\n");
		printf ("** 5 - Imprimir elementos da lista                  **\n");
		printf ("** 6 - Limpar a lista                               **\n");
		printf ("** 7 - Encerrar programa                            **\n");		
		printf ("**                                                  **\n");
		printf ("******************************************************\n");
		scanf ("%d",&opt);
		system ("cls"); //"clear" para linux "cls" para windows
		switch (opt)
		{
		case 1:				
			inicio = incluir_ini (inicio);		
			break;
		case 2:
			if (inicio==NULL) //Se não houver elementos, inclui com função atualizando o *inicio
				inicio = incluir_ini (inicio);
			else incluir_fim (inicio);	//se houver elementos, inclui no final com procedimento		
			break;
		case 3:
			inicio = excluir_ini (inicio);			
			break;
		case 4:
			if (inicio == NULL || inicio->prox == NULL) //Se houver apenas 1 elemento na lista, exclui com função atualizando o *inicio
			{
				inicio = excluir_ini (inicio);
			}
			else excluir_fim (inicio);	//se mais de um elemento, inclui no final com procedimento			
			break;
		case 5:
			imprimir (inicio);			
			break;
		case 6:
			limpar_lista (inicio);	
			inicio=NULL;			
			break;	
		case 7:
			limpar_lista (inicio);							
			break;	
		default:
			printf ("\nOpcao invalida, tente novamente\n\n\a");
		}
	}
	while (opt != 7);
	printf ("\n\nPrograma encerrado com sucesso!\n");
	return 0;
}
dados *incluir_ini (dados *inicio)
{
	int numero;
	dados *novo;
	novo = (dados *) malloc (sizeof (dados ));
	printf ("\n\nDigite o valor a incluir no inicio da lista:\n");
	scanf ("%d",&numero);
	novo -> num = numero;
	novo -> prox = inicio;	
	return novo;		
}
void incluir_fim (dados *inicio)
{
	int numero;
	dados *novo;
	novo = (dados *) malloc (sizeof (dados ));
	while (inicio->prox != NULL)
		inicio=inicio->prox;
	printf ("\n\nDigite o valor a incluir no final da lista:\n");
	scanf ("%d",&numero);
	novo -> num = numero;
	novo -> prox = NULL;	
	inicio->prox = novo;
}	
void excluir_fim (dados *inicio)
{
	dados *anterior;
	while (inicio->prox != NULL)
	{
		anterior = inicio;
		inicio=inicio->prox;
	}
	printf ("\nExcluindo o valor %d \n",inicio->num);
	free (inicio);
	anterior->prox = NULL;				
}	
dados *excluir_ini (dados *inicio)
{
	dados *temp;
	if (inicio == NULL)
		printf ("\nNao ha dados na lista, impossivel excluir!\n\n\a");
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
void limpar_lista (dados *inicio)
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