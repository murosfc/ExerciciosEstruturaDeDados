#include <stdlib.h>

#define TAM 20

typedef struct fila
{
	int dado[TAM],quantidade_elementos, inicio, fim;
} tipo_fila;

void apagarFila (tipo_fila *Fila)
{	
	int i;
	for (i=0;i<TAM;i++)
		Fila->dado[i]=0;
	Fila->quantidade_elementos=0;
	Fila->inicio=0;
	Fila->fim=0;
}

tipo_fila *criarFila ()
{
	tipo_fila *Fila;
	Fila= (tipo_fila*) malloc (sizeof (tipo_fila));
	apagarFila (Fila);
	return Fila;
}

int addFila (tipo_fila* FilaAdd,int num)
{
	if (FilaAdd->fim < TAM-1 && FilaAdd->fim+1 !=  FilaAdd->inicio)
	{
		if (FilaAdd->quantidade_elementos > 0) //para adicionar o primeiro elemento sem avançar o fim
			FilaAdd->fim ++;
		FilaAdd->quantidade_elementos ++;
		FilaAdd->dado[FilaAdd->fim] = num;
		return 1;
	}
	else if (FilaAdd->fim == TAM-1 && FilaAdd->inicio > 0) //quando o fim for o último elemento, ele vai para o primeiro, desde que este esteja livre
	{
		FilaAdd->fim=0;
		FilaAdd->quantidade_elementos ++;
		FilaAdd->dado[FilaAdd->fim] = num;
		return 1;
	}
	else return 0;
}
	
int removeFila (tipo_fila *FilaRemove)	
{
	int removido;
	removido = FilaRemove->dado[FilaRemove->inicio];
	FilaRemove->dado[FilaRemove->inicio]=0;
	if (FilaRemove->quantidade_elementos > 1)
	{		
		if (FilaRemove->inicio == TAM-1)
		{
			FilaRemove->inicio=0;
			FilaRemove->quantidade_elementos --;
		}else
		{
			FilaRemove->inicio ++;
			FilaRemove->quantidade_elementos --;
		}		
	}
	else 
	{		
		apagarFila (FilaRemove);
	}
	return removido;
}

int isFilaVazia (tipo_fila *FilaConsulta)
{
	if (FilaConsulta->quantidade_elementos == 0)
		return 1;
	else return 0;
}

int tamanhoFila (tipo_fila *FilaConsulta)
{
	return FilaConsulta->quantidade_elementos;
}

	