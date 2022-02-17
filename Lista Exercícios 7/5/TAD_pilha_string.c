#include <stdlib.h>

typedef struct no
{
	struct no *anterior;
	char letra;
} tipo_no;

typedef struct pilha
{
	tipo_no *topo;
	int tamanho;
} tipo_pilha;

tipo_pilha *criaPilha()
{
	tipo_pilha *Pilha;
	Pilha= (tipo_pilha *) malloc (sizeof (tipo_pilha));
	Pilha->topo =NULL;
	Pilha->tamanho=0;
	return Pilha;
}

void push (tipo_pilha* Pilha, char word)
{
	tipo_no *novo;
	novo = (tipo_no *) malloc (sizeof (tipo_no));
	if (Pilha->topo == NULL) //grava o primeiro char
	{
		novo->letra=word;
		novo->anterior=NULL;
		Pilha->topo=novo;
		Pilha->tamanho ++;
	} else
	{
		novo->letra=word;
		novo->anterior=Pilha->topo;
		Pilha->topo=novo;
		Pilha->tamanho ++;
	}	
}

char pop (tipo_pilha* Pilha)
{
	tipo_no *temp;
	char word;	
	if (Pilha->topo == NULL)
		return NULL;
	else
	{
		temp = Pilha->topo;
		word= temp->letra;
		Pilha->topo=temp->anterior;
		Pilha->tamanho --;
		free (temp);
	}
	return word;
}

int tamanhoPilha (tipo_pilha *Pilha)
{
	return Pilha->tamanho;
}
