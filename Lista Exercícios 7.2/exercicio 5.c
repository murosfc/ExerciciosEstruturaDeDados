/*Crie uma fun¸c˜ao que execute uma busca bin´aria em um vetor de inteiros recebido por parˆametro. Obtenha
da fun¸c˜ao a posi¸c˜ao encontrada e o n´umero de compara¸c˜oes realizadas na busca. Caso n˜ao seja encontrado
um n´umero, coloque -1 na vari´avel de controle da busca. Crie um programa principal para incluir 20
n´umeros inteiros de forma ordenada no vetor e teste a fun¸c˜ao de busca bin´aria.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OrdenarVetor (int vet[20])
{
	int i,j,swap;
	for (i=0;i<20-1;i++)
		for (j=i;j<20;j++)
		{
			if (vet[j]<vet[i])
			{
				swap=vet[i];
				vet[i]=vet[j];
				vet[j]=swap;
			}
		}		
}

int buscaBinaria (int *vet, int valorProcurado, int *comparacoes)
 { 
   int esquerda = -1, direita = 21, meio, valorPosicaoVetor;   
   while (esquerda < direita-1) 
   {  
      *comparacoes += 1;
	  meio = (esquerda + direita)/2;
	  valorPosicaoVetor= *(vet + meio);
      if (valorPosicaoVetor == valorProcurado)
      	return meio;
      else if (valorPosicaoVetor < valorProcurado)
	  	  esquerda = meio;
      else direita = meio; 
   }
   return -1;
}
	

int main()
{
	int comparacoes=0, posicao, i,vetor [20];
	srand (time (NULL));
	
	for (i=0;i<20;i++)
		vetor[i]=rand()%100+1; //inicia o vetor preenchedo com aleatórios
	OrdenarVetor (vetor);
	printf ("Vetor:\n");
	for (i=0;i<20;i++)
		printf ("%d, ",vetor[i]);
	printf ("\b\b  ");
	while (i>0)
	{
		printf ("\nDigite o valor que deseja procurar no vetor:\n");
		scanf ("%d",&i);
		posicao=buscaBinaria(vetor,i,&comparacoes);
		if (posicao==-1)
			printf ("\nValor nao encontrado no vetor\n\n");
		else printf("\nValor encontrado na posicao numero %d apos %d comparacoes\n\n",posicao,comparacoes);		
	}	
	return 0;
}