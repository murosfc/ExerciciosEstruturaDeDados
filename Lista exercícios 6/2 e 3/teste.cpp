#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
	struct no *proximo;
	int dado;
} tipo_no;

typedef struct lista
{
	tipo_no *inicio;
	int quantidadeElementos;
	int ordenado;
} tipo_lista;

tipo_lista *CriarListaVazia ()
{	
	tipo_lista *inicio;
	inicio=(tipo_lista*) malloc (sizeof (tipo_lista));
	inicio->inicio=NULL;
	inicio->quantidadeElementos=0;
	inicio->ordenado=0;
	return inicio;
}

void InserirElemento (tipo_lista* lista, int num)
{
	tipo_no *novo, *atual;
	novo= (tipo_no*) malloc (sizeof (tipo_no));
	if (lista->inicio == NULL) //insere o primeiro elemento da lista
	{
		novo->proximo=NULL;
		novo->dado=num;
		lista->inicio=novo;
		lista->quantidadeElementos++;
		lista->ordenado=0;
	}
	else 
	{
		atual=lista->inicio;
		while (atual->proximo != NULL)
			atual=atual->proximo;
		novo->proximo=NULL;
		novo->dado=num;
		atual->proximo=novo;
		lista->quantidadeElementos++;
		lista->ordenado=0;
	}	
		
}

void concatenarListas (tipo_lista* lista_1, tipo_lista* lista_2)
{
	tipo_no *atualLista_1, *atualLista_2, *novo;
	novo= (tipo_no*) malloc (sizeof(tipo_no));
	atualLista_2=lista_2->inicio;	
	if (lista_1->inicio == NULL)
	{
		novo=atualLista_2;
		lista_1->inicio=novo;
		atualLista_2=atualLista_2->proximo;
		atualLista_1=lista_1->inicio;
		while (atualLista_2 != NULL)
		{
			novo= (tipo_no*) malloc (sizeof(tipo_no));
			novo=atualLista_2;
			atualLista_2=atualLista_2->proximo;
			atualLista_1->proximo=novo;			
		}
	}
	else
	{
		atualLista_1=lista_1->inicio;
		while (atualLista_1->proximo !=NULL)
			atualLista_1=atualLista_1->proximo;		
		while (atualLista_2 != NULL)
		{
			novo= (tipo_no*) malloc (sizeof(tipo_no));
			novo=atualLista_2;
			atualLista_2=atualLista_2->proximo;
			atualLista_1->proximo=novo;			
		}
	}
}

int main()
{
	tipo_lista *lista_1,*lista_2;
	int num;
	lista_1 = CriarListaVazia(); 	
	lista_2 = CriarListaVazia();
	srand (time(NULL)); //preencher lista 2 com randomicos
	for (num=0;num<10;num++)
		InserirElemento(lista_2,rand()%100);
	concatenarListas(lista_1,lista_2);	
	return 0;
}
