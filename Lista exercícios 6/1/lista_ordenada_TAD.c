#include<stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct reg_lista
{
    tipo_no *inicio;
    int quantidadeElementos;
} tipo_lista;

tipo_lista* criarListaVazia()
{
    tipo_lista* lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    lista->quantidadeElementos = 0;
    return lista;
}

int listaVazia(tipo_lista* lista)
{
    if (lista->quantidadeElementos == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int quantidadeElementosLista(tipo_lista* lista)
{
    return lista->quantidadeElementos;
}

tipo_lista* apagarLista(tipo_lista* lista)
{
    tipo_no *auxiliar;

    while (!listaVazia(lista))
    {
        auxiliar = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(auxiliar);
    }
    free(lista);
    return NULL;
}

void inserirElementoOrdenado(tipo_lista* lista, int dado)
{
    tipo_no *novo, *atual = lista->inicio, *anterior = NULL;

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

int excluirElementoOrdenado(tipo_lista* lista, int dado)
{
    tipo_no *auxiliar, *anterior = NULL, *atual = lista->inicio;

    while ((atual != NULL) && (atual->dado != dado))
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual->dado == dado)
    {
        if (anterior == NULL)
        {
            lista->inicio = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }
        auxiliar = atual;
        free(auxiliar);
        lista->quantidadeElementos--;
        return 1;
    }
    else
    {
        return 0;
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
	return posicao;
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