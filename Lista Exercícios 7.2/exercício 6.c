/*Implemente um programa para criar um vetor com 1000 (Mil) n´umeros aleat´orios, com range compreendido
entre 0 e 10000 (Dez mil). Os n´umeros dever˜ao ser inseridos no vetor de forma ordenada e n˜ao poder˜ao
acontecer repeti¸c˜oes de n´umeros. Na maioria das vezes haver´a um deslocamento na estrutura para a
inclus˜ao de um novo n´umero. Uma vez o vetor completo, fa¸ca a impress˜ao para verificar se os requisitos
est˜ao sendo atendidos e teste a fun¸c˜ao de busca bin´aria para um vetor de tamanho REAL igual a 1000
posi¸c˜oes.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000

int buscaBinaria (int *vet, int valorProcurado)
 { 
   int esquerda = -1, direita = TAM, meio, valorPosicaoVetor;   
   while (esquerda < direita) 
   {  
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

int buscaBinariaInserir (int *vet, int valorProcurado)
 { 
   int esquerda = -1, direita = TAM+1, meio, valorPosicaoVetor;   
   while (esquerda < direita-1) 
   {        
	  meio = (esquerda + direita)/2;
	  valorPosicaoVetor= *(vet + meio);
      if (valorPosicaoVetor == valorProcurado)
      	return -2;
      else if (valorPosicaoVetor < valorProcurado)
	  	  esquerda = meio;
      else direita = meio; 
   }
   return direita;
}

void preencherVetor (int *vet)
{
	int indice, valorInserir, i, quantElementos=0;
	
	for (i=0;i<TAM;i++) //preenche o vetor com valor maior que o máximo, para evita comparações com lixo e memoria
		*(vet + i)=10000;
	
	while (quantElementos < TAM)
	{
		valorInserir= rand()%10000;
		if (quantElementos == 0)
			indice=0;
		else indice=buscaBinariaInserir(vet,valorInserir);
		if (indice != -2) 
		{
			quantElementos++;
			for (i=quantElementos;i>indice;i--)
			{
				*(vet + i)= *(vet +(i-1));
			}
			*(vet + indice)=valorInserir;
		}				
	}	
}

int main()
{
	int vetor[TAM],i,posicao, valorProcurado;
	srand (time (NULL));

	preencherVetor (vetor);
	
	printf ("\nVetor gerado\n");
	for (i=0;i<TAM;i++)
	{
		printf ("%d, ",vetor[i]);
	}
	printf ("\b\b  \n\n\n");
	
	while (valorProcurado >= 0)
	{
		printf("\nDigite o valor a buscar no vetor:\n");
		scanf ("%d",&valorProcurado);
		posicao=buscaBinaria(vetor, valorProcurado);
		if (posicao == -1)
			printf ("\nValor nao encontrado no vetor\n");
		else printf("\nValor encontrado na posicao %d\n\n",posicao);		
	}
	return 0;
}
	
	
	
	