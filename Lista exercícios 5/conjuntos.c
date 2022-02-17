#include <stdlib.h>

#define TAM 100 //tamanho maximo do conjunto

struct conjuntos
{
	int vetor[TAM];
	int tamanho;
};

typedef struct conjuntos tipo_conjunto;

struct vet 
{
	int num;
	struct vet *prox;
};

typedef struct vet tipo_vet_print;

tipo_conjunto *cria_conjunto ()
{
	tipo_conjunto *conj;
	int i;
	conj= (tipo_conjunto *) malloc (sizeof (tipo_conjunto));
	for (i=0;i<TAM;i++)
		conj->vetor[i]=0;
	conj->tamanho = 0;
	return conj;	   	
}

void insere_conjunto (tipo_conjunto *conj,int num)
{
	if (conj->vetor[num] ==0 && num>=0 && num<100)
	{
		conj->vetor[num] = 1;
		conj->tamanho=conj->tamanho+1;
	}
}
void remove_conjunto (tipo_conjunto *conj,int num)
{
	if (conj->vetor[num] == 1 && num>=0 && num<100)
	{
		conj->vetor[num] =0;
		conj->tamanho=conj->tamanho-1;
	}
}
tipo_conjunto *uniao (tipo_conjunto *conj1,tipo_conjunto *conj2) //novo conjunto contem dados de ambos os conjuntos, soma
{
	tipo_conjunto *uniao;
	int i=0;
	uniao = (tipo_conjunto *) malloc (sizeof (tipo_conjunto));
	uniao->tamanho=0;
	for (i=0;i<TAM;i++)
	{
		if (conj1->vetor[i]==1 || conj2->vetor[i]==1)
		{
			uniao->vetor[i]=1;	
			uniao->tamanho=uniao->tamanho+1;
		}			
	}
	return uniao;
}
tipo_conjunto *interseccao (tipo_conjunto *conj1,tipo_conjunto *conj2) //novo conjunto contém apenas os itens que aparecem em ambos conjuntos
{
	tipo_conjunto *inter;
	int i=0;
	inter = (tipo_conjunto *) malloc (sizeof (tipo_conjunto));
	inter->tamanho=0;
	for (i=0;i<TAM;i++)
	{
		if (conj1->vetor[i]==1 && conj2->vetor[i]==1)
		{
			inter->vetor[i]=1;
			inter->tamanho=inter->tamanho+1;
		}			
	}
	return inter;
}
tipo_conjunto *diferenca (tipo_conjunto *conj1,tipo_conjunto *conj2) //novo conjunto contém apenas os itens do conj1 que não aparecem no conj2
{
	tipo_conjunto *diff;
	int i=0;
	diff = (tipo_conjunto *) malloc (sizeof (tipo_conjunto));
	diff->tamanho=0;
	for (i=0;i<TAM;i++)
	{
		if (conj1->vetor[i]==1 && conj2->vetor[i]==0)
		{
			diff->vetor[i]=1;
			diff->tamanho=diff->tamanho+1;
		}			
	}
	return diff;
}
int pertence (tipo_conjunto *conj, int num) //verifica se num pertence ao conjunto. 1 para pertence 0 para nao
{
	if (conj->vetor[num]==1)
		return 1;
	else return 0;
}
int menor_valor (tipo_conjunto *conj) //retorna o menor valor do conjunto ou NULL se ele conjunto for vazio
{
	int i;
	for (i=0;i<TAM;i++)
		if (conj->vetor[i]==1)
			return i;
	return NULL;	
}
int maior_valor (tipo_conjunto *conj) //retorna o maior valor do conjunto ou NULL se ele conjunto for vazio
{
	int i;
	for (i=TAM;i>=0;i--)
		if (conj->vetor[i]==1)
			return i;
	return NULL;
}
int compara_conjunto (tipo_conjunto *conj1,tipo_conjunto *conj2) //retorna 1 se conjuntos forem iguais retorna 0 caso contrário
{
	int i;
	for (i=0;i<TAM;i++)
		if (conj1->vetor[i] != conj2->vetor[i])
			return 0;
	return 1;		
}
int tamanho_conjunto (tipo_conjunto *conj) // retorna o tamanho do cojunto
{
	return conj->tamanho;
}
int tamanho_conjuntop (tipo_vet_print *conj)
{
	int i=0;
	while (conj != NULL)
	{
		i++;
		conj=conj->prox;
	}
		
	return i;
}
int is_conjunto_vazio (tipo_conjunto *conj) //retornar NULL se conjunto for vazio e 1 caso contrário
{
	int i;
	for (i=0;i<TAM;i++)
		if (conj->vetor[i]==1)
			return 1;
	return NULL;
}
tipo_vet_print *conjunto_para_impressao (tipo_conjunto *conj) //retorna um conjunto para impressao
{
	int i=0;
	tipo_vet_print *inicio, *novo, *atual;
	inicio = (tipo_vet_print *) malloc (sizeof (tipo_vet_print));		
	inicio=NULL;	
	for (i=0;i<TAM;i++)
	{
		if (conj->vetor[i]==1)
		{
			if (inicio == NULL)
			{
				novo = (tipo_vet_print *) malloc (sizeof (tipo_vet_print));
				novo->num=i;
				novo->prox=NULL;
				inicio=novo;
				atual=inicio;
			}
			else {
				novo = (tipo_vet_print *) malloc (sizeof (tipo_vet_print));
				novo->num=i;
				novo->prox=NULL;
				atual->prox=novo;				
				atual=novo;
			}
		}			
	}	
	return inicio;	
}
/* Incluindo no inicio
tipo_vet_print *conjunto_para_impressao (tipo_conjunto *conj) //retorna um conjunto para impressao
{
	int i=0;
	tipo_vet_print *inicio, *novo;
	inicio = (tipo_vet_print *) malloc (sizeof (tipo_vet_print));		
	inicio=NULL;
	for (i=0;i<TAM;i++)
	{
		if (conj->vetor[i]==1)
		{
			if (inicio==NULL)
			{
				novo = (tipo_vet_print *) malloc (sizeof (tipo_vet_print));
				novo->num=i;
				novo->prox=NULL;
				inicio=novo;
			}
			else
			{
				novo = (tipo_vet_print *) malloc (sizeof (tipo_vet_print));
				novo->num=i;			
				novo->prox=inicio;
				inicio=novo;			
			}
		}
			
	}	
	return inicio;	
}*/