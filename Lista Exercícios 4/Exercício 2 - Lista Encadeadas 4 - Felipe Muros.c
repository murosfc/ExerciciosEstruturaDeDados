/* Implementar um programa para armazenar nomes em uma lista encadeada ordenada. O programa dever´a
apresentar um menu com as seguintes op¸c˜oes:
(a) Inclus˜ao de Nome
(b) Exclus˜ao de Nome
(c) Busca por um Nome
(d) Limpar a lista - Excluir todos os elementos
(e) Finaliza¸c˜ao do Programa
Caso seja escolhida uma op¸c˜ao de inclus˜ao, o usu´ario dever´a digitar o nome a ser inclu´ıdo.
Caso seja escolhida a op¸c˜ao de busca, um nome dever´a ser digitado pelo usu´ario e verificada a existˆencia
do mesmo na lista. O programa dever´a imprimir em que posi¸c˜ao da lista o nome foi encontrado.
Quando escolhida a op¸c˜ao de Finaliza¸c˜ao do Programa, todos os elementos restantes na estrutura de dados
dever˜ao ser desalocados para s´o depois o programa ser encerrado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

#define T 20

typedef struct no {
	char name[T];
	struct no *prox;
} nomes;

nomes *incluir_nome (nomes *ini);
nomes *excluir_nome (nomes *ini);
nomes *preencher_nulo (nomes *ini, char nome[T]);
void imprimir (nomes *ini);
void limparlista (nomes *ini);
void buscanome (nomes *ini);

int main()
{
	nomes *inicio=NULL;
	int opt;
	do	{
		printf ("******************************************************\n");
		printf ("**                       MENU                       **\n");
		printf ("**                                                  **\n");
		printf ("**          DIGITE UMA DAS OPCOES ABAIXO            **\n");
		printf ("**                                                  **\n");
		printf ("** 1 - Inclusao de Nome                             **\n");
		printf ("** 2 - Exclusao de Nome                             **\n");
		printf ("** 3 - Busca por um Nome                            **\n");
		printf ("** 4 - Limpar a lista - Excluir todos os elementos  **\n");
		printf ("** 5 - Imprimir lista de nomes                      **\n");
		printf ("** 6 - Finalizar programa                           **\n");		
		printf ("**                                                  **\n");
		printf ("******************************************************\n\n");
		scanf ("%d",&opt);
		switch (opt)
		{
			case 1:				
				inicio= incluir_nome (inicio);
			break;
			case 2:
			    inicio= excluir_nome (inicio);
			break;
			case 3:
			    buscanome (inicio);
			break;
			case 4:
			    limparlista (inicio);
			    inicio=NULL;
			break;
			case 5:
				imprimir (inicio);
			break;
			case 6:
			    limparlista (inicio);
			    inicio=NULL;
			    system ("cls");
	   	   	   	printf ("\nPrograma finalizado com sucesso!\n\n");
				return 0;
			break;
			default:
			    printf ("\nOpcao invalida, tente novamente");
		} 
	} while (opt != 6);
	return 0;
}
nomes *incluir_nome (nomes *ini)
{
	char nome[T];
	nomes *atual, *anterior, *novo;
	int controle=0;
	novo = (nomes *) malloc (sizeof (nomes));
	printf ("\nDigite o nome para inserir na lista: ");
	scanf ("%s",nome);
	strcpy(novo->name,nome);		
	if (ini == NULL) //insere no inicio
	{
		novo->prox=NULL;
		ini=novo;		
	}
	else 
	{		
		atual=ini;					
		while ((atual != NULL) && (strcmp (nome,atual->name) > 0))
		{
			anterior=atual;
			atual=atual->prox;
			controle++;
		}
		if (atual == NULL) //insere no final
		{
			novo->prox=NULL;
			anterior->prox=novo;			
		}
		else if (controle == 0) //controle resolve o bug de inserir na primeira posi褯
		{ //empurra os demais e insere no inicio
			novo->prox=atual;
			ini=novo;
		} else
		{ //insere entre o atual e pr󸩭o
			novo->prox=atual;
			anterior->prox=novo;			
		}
	}
	return ini;
}
nomes *excluir_nome (nomes *ini)
{
	char nome[T];
	int controle=0;
	nomes *anterior=NULL, *atual=ini;		
	if (ini == NULL)
		printf ("\nNao ha nomes na lista, impossivel excluir\n");
	else
	{ 
	printf ("\nDigite o nome que deseja excluir da lista: ");
	scanf ("%s",nome);
	while ((atual!=NULL) && (strcmp(atual->name,nome)!=0))
	{
		anterior=atual;
		atual=atual->prox;		
	}
	if (anterior==NULL)
	{	
		ini=atual->prox;		
		controle=1;
		free (atual);		
	}
	else
	{
		anterior->prox=atual->prox;
		controle=1;
		free (atual);
	}
	if (controle == 0)
		printf ("\nNao foi possivel excluir, nome nao encontrado na lista\n");
	else printf ("\nNome: %s excluido da lista com sucesso!\n",nome);
	}	
	return ini;
}
void buscanome (nomes *ini)
{
	char nome[T];
	int i=-1, controle=0;
	if (ini == NULL)
		printf ("\nLista vazia, nao eh possivel buscar um nome\n\n");
	else{
		printf ("\nDigite o nome que deseja buscar: ");
		scanf ("%s",nome);
		while (ini != NULL)
		{
			i++;
			if (strcmp(nome,ini->name) == 0)
			{
				printf ("\nNome %s encontrado na posicao %d\n\n",nome,i);
				controle = 1;
			}
			ini=ini->prox;
		}
	}
	if (controle == 0)
		printf ("\nNome %s nao encontrato na lista\n\n",nome);		
}
void imprimir (nomes *ini)
{
	system ("cls");
	if (ini==NULL)
		printf("\nLista vazia\n\a");
	else{
		printf ("\nNomes em ordem:\n");
		while (ini != NULL)
		{
			printf ("%s\n",ini->name);
			ini=ini->prox;
		}
	}
	printf ("\n\n");
}
void limparlista (nomes *ini)
{
	nomes *temp;
	while (ini != NULL)
	{
		temp=ini;
		ini=ini->prox;
		free (temp);
	}
	printf ("\nLista limpa com sucesso!\n");
}
