#include <stdlib.h>

typedef struct no
{
	int dado;
	struct no *ponteiro;
} tipo_no;

typedef struct fila
{
	tipo_no *inicio, *fim;	
	int quantidadeElementos;
} tipo_fila;

typedef struct pilha
{
	tipo_no *topo;
	int quantidadeElementos;
}tipo_pilha;

tipo_pilha* criarPilha ()
{
	tipo_pilha *pilhacriar;
	pilhacriar = (tipo_pilha *) malloc (sizeof (tipo_pilha));
	pilhacriar->topo=NULL;
	pilhacriar->quantidadeElementos=0;
	return pilhacriar;
}

void push (tipo_pilha *pilhaAdd, int num)
{
	tipo_no *novo;
	novo = (tipo_no *) malloc (sizeof (tipo_no));	
		novo->dado=num;
		novo->ponteiro=pilhaAdd->topo;
		pilhaAdd->topo=novo;
		pilhaAdd->quantidadeElementos ++;	
}

int pull (tipo_pilha *pilhaRemove)
{
	if (pilhaRemove->topo !=NULL)
	{
		int valor_topo;
		tipo_no *temp =pilhaRemove->topo;
		valor_topo=temp->dado;
		pilhaRemove->topo=temp->ponteiro;
		free (temp);
		pilhaRemove->quantidadeElementos --;	
		return valor_topo;
	}
	else return NULL;
}

int isPilhaVazia (tipo_pilha *pilhaConsulta)
{
	if (pilhaConsulta->quantidadeElementos == 0)
		return 1;
	else return 0;
}

int tamanhoPilha (tipo_pilha *pilhaConsulta)
{
	return pilhaConsulta->quantidadeElementos;
}

void apagarPilha (tipo_pilha *free_pilha)
{
	tipo_no *temp;
	if (free_pilha->topo != NULL)
	{
		while (free_pilha->quantidadeElementos != 0)
		{
			temp=free_pilha->topo;
			free_pilha->topo=temp->ponteiro;
			free (temp);
			free_pilha->quantidadeElementos--;
		}
	}
}

tipo_fila * criarFila ()
{
	tipo_fila *filacriar;
	filacriar= (tipo_fila*) malloc (sizeof (tipo_fila));
	filacriar->inicio=NULL;
	filacriar->fim=NULL;
	return filacriar;
}

void addaux (tipo_fila * filaAdd, tipo_no *novo, int num) //auxiliar para adicionar na fila
{
		novo->dado = num;
		novo->ponteiro=NULL;
		filaAdd->fim=novo;
		filaAdd->quantidadeElementos ++;
}

int addFila (tipo_fila * filaAdd, int num)
{
	tipo_no *novo;
	novo= (tipo_no *) malloc (sizeof (tipo_no));
	if (filaAdd->inicio == NULL)
	{
		addaux (filaAdd, novo, num);
		filaAdd->fim=novo;		
	}
	else 
	{
		addaux (filaAdd, novo, num);
	}
	if (novo->dado == num)
		return 1;
	else return 0;
}


int removeFila (tipo_fila* fila_remove)
{
	tipo_no *novo;
	int valor_removido;
	if (fila_remove->inicio !=NULL)
	{
		novo=fila_remove->inicio;
		valor_removido=novo->dado;		
		if (fila_remove->inicio == fila_remove->fim)
		{
			fila_remove->inicio=NULL;
			fila_remove->fim=NULL;						
			free (novo);
		}
		else 
		{
			fila_remove->inicio=novo->ponteiro;
			free (novo);
		}
		fila_remove->quantidadeElementos --;
	}
	else valor_removido = NULL;
	return valor_removido;
}

int isFilaVazia (tipo_fila * testa_fila)
{
	if (testa_fila->quantidadeElementos == 0)
		return 1;
	else return 0;
}

int tamanhoFila (tipo_fila * testa_fila)
{
	return testa_fila->quantidadeElementos;
}

void apagarFila (tipo_fila * apaga_fila)
{
	tipo_no *temp;
	while (apaga_fila->inicio != NULL)
	{
		temp=apaga_fila->inicio;
		if (apaga_fila->inicio != apaga_fila->fim)
		{
			apaga_fila->inicio=temp->ponteiro;
			free (temp);
		}
		else
		{
			apaga_fila->inicio=NULL;
			apaga_fila->fim=NULL;
			free (temp);	
		}
	}	
}