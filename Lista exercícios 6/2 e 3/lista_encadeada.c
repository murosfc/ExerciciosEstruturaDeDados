#include <stdlib.h>

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

void ExcluirElemento (tipo_lista* lista, int num)
{
	tipo_no *atual, *anterior;
	atual=lista->inicio;
	if (atual->dado == num)	//excluir o primeiro
	{
		lista->inicio=atual->proximo;
		free (atual);
		lista->quantidadeElementos--;		
	}
	else
	{
		while (atual != NULL && atual->dado != num)
		{
			anterior=atual;
			atual=atual->proximo;
		}
		if (atual->proximo==NULL && atual->dado == num)	//excluir o último
		{
			anterior->proximo=NULL;
			free(atual);
			lista->quantidadeElementos--;
		}
		else if(atual->proximo!=NULL && atual->dado == num)//excluir entre elementos
		{
			anterior->proximo=atual->proximo;
			free (atual);
			lista->quantidadeElementos--;
			lista->ordenado=0;			
		}
	}	
}

int quantidadeElementosLista(tipo_lista* lista)
{
	return lista->quantidadeElementos;
}

int listaVazia (tipo_lista* lista) //retorna 1 (verdadeiro) se lista estiver vazia
{
	if (lista->quantidadeElementos == 0)
		return 1;
	else return 0;
}

void apagarLista(tipo_lista* lista)
{
	tipo_no *atual, *proximo;
	atual=lista->inicio;
	while (proximo != NULL)
	{
		proximo=atual->proximo;
		free (atual);
		atual=proximo;
	}
	free (lista);
	lista=CriarListaVazia();	
}

int* obterElementosLista(tipo_lista* lista)
{
    tipo_no *atual = lista->inicio;
    int *elementosImpressos, posicao;

    elementosImpressos = (int*) malloc(lista->quantidadeElementos * sizeof(int));

    posicao = 0;
    while (atual != NULL)
    {
        elementosImpressos[posicao] = atual->dado;
        atual = atual->proximo;
        posicao++;
    }
    return elementosImpressos;
}

tipo_lista* concatenarListas (tipo_lista* lista_1, tipo_lista* lista_2)
{
	tipo_no *atual;
	if (lista_1->inicio == NULL)
	{
		lista_1 = lista_2;	
	}
		
	else
	{
		atual=lista_1->inicio;
		while (atual->proximo != NULL)
			atual=atual->proximo;
		atual->proximo=lista_2->inicio;
		lista_1->quantidadeElementos=lista_1->quantidadeElementos+lista_2->quantidadeElementos;
	}
	return lista_1;
}

void excluirIguais (tipo_lista* lista, int num)
{
	tipo_no *atual, *anterior;
	atual=lista->inicio;		
	while (atual != NULL)
	{
		if ( (atual->dado == num) && (atual==lista->inicio) )	//excluir o primeiro
		{
			lista->inicio=atual->proximo;
			free (atual);
			lista->quantidadeElementos--;
			atual=lista->inicio;		
		}
		else if( (atual->proximo != NULL) && (atual->dado == num) )//excluir entre elementos
		{
			anterior->proximo=atual->proximo;
			free (atual);
			atual=anterior;
			lista->quantidadeElementos--;				
		}
		else if ( (atual->proximo==NULL) && (atual->dado == num) )	//excluir o último
		{
			anterior->proximo=NULL;
			free(atual);
			lista->quantidadeElementos--;
			atual=anterior;	
		}
		anterior=atual;			
		atual=atual->proximo;
	}
}
float calcularMedia (tipo_lista* lista)
{
	float media=0;
	tipo_no *atual=lista->inicio;	
	if (atual !=NULL)
	{
		while (atual!=NULL)
		{
			media=media+atual->dado;
			atual=atual->proximo;						
		}
		media=media/lista->quantidadeElementos;
	}
	return media;
}

int verificarProfundidade (tipo_lista* lista, int valorProcurado)
{
	int posicao=0;
	tipo_no *atual=lista->inicio;
	if (atual !=NULL)
	{		
		while (atual !=NULL)
		{
			posicao++;
			if (atual->dado == valorProcurado)
				return posicao;
			atual=atual->proximo;
		}
	}
	return 0;
}

int compararListas (tipo_lista* lista1,tipo_lista* lista2)
{
	tipo_no *atual1,*atual2;
	int contaiguais=0;
	atual1=lista1->inicio;
	atual2=lista2->inicio;
	if (lista1->quantidadeElementos == lista2->quantidadeElementos)
	{
		while (atual1!=NULL)
		{
			if(atual1->dado == atual2->dado)
				contaiguais++;
			atual1=atual1->proximo;
			atual2=atual2->proximo;
		}
		if (contaiguais == lista1->quantidadeElementos)
			return 1;
		else return 0;			
	}
	else return 0;	
}

void ordernarElementos (tipo_lista *lista)
{
	tipo_no *i,*j;	
	int swap;
	i=lista->inicio;	
	while (i->proximo!=NULL)
	{
		j=i->proximo;
		while(j!=NULL)
		{
			if (j->dado < i->dado)
			{
				swap=i->dado;
				i->dado=j->dado;
				j->dado=swap;
			}
			j=j->proximo;							
		}
		i=i->proximo;
	}
	lista->ordenado=1;
}

void inserirElementoOrdenado(tipo_lista* lista, int dado)
{
    tipo_no *novo, *atual = lista->inicio, *anterior = NULL;
    
	if (lista->ordenado == 0)
		ordernarElementos(lista);
	
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;

    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
    }
    else
    {
        while ((atual != NULL) && (atual->dado < dado))
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == NULL)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }
    lista->quantidadeElementos++;
}
void CopiarLista (tipo_lista* lista_1, tipo_lista* lista_2) //copia da lista 2 para a lista 1
{
	tipo_no *atual;
	apagarLista(lista_1);
	atual=lista_2->inicio;
	while (atual !=NULL)
	{
		InserirElemento(lista_1,atual->dado);
		atual=atual->proximo;
	}
}