/* Crie um Tipo Abstrato de Dados (TAD) que represente o tipo conjunto de inteiros. Utilize uma representa¸c˜ao de vetor de inteiros com 100 posi¸c˜oes, onde o menor valor ´e o 0 e o maior valor ´e 99. Implemente
as seguintes opera¸c˜oes:
(a) Cria um conjunto vazio
(b) Insere um elemento no conjunto
(c) Remove um elemento do conjunto
(d) Uni˜ao - Faz a uni˜ao de dois conjunto e retorna um terceiro conjunto
(e) Intersec¸c˜ao - Faz a intersec¸c˜ao entre dois conjunto e retorna um terceiro conjunto
(f) Diferen¸ca - Faz a diferen¸ca entre dois conjuntos e retorna um terceiro
(g) Testa se um n´umero pertence ao conjunto
(h) Menor valor
(i) Maior valor
(j) Testa se dois conjuntos s˜ao iguais
(k) Tamanho - Retorna o tamanho de um vetor. Obs. Criar um campo no struct para isso conjunto para
isso e manter atualizado.
(l) Testa se o conjunto ´e vazio
(m) Imprime um conjunto - Retorna para o programa principal um vetor, previamente alocado de forma
dinˆamica, contendo todos os elementos pertencentes ao conjunto. O programa principal receber´a o
vetor e far´a a impress˜ao usando a funcionalidade de tamanho do vetor implementada no TAD.
*/

#include <stdio.h>
#include "conjuntos.h"
#include <time.h>
#include <stdlib.h>

#define TAM 100 //tamanho maximo do conjunto

struct vet 
{
	int num;
	struct vet *prox;
};

typedef struct vet tipo_vet_print;

int main()
{
	tipo_conjunto *conjunto1, *conjunto2, *conjunto3;
	tipo_vet_print *conjunto_print;
	int numero=1,i;
	srand (time(NULL));
	conjunto1= cria_conjunto();
	conjunto2 = cria_conjunto();
	conjunto3 = cria_conjunto();
	for (i=0;i<TAM;i++) //preenche o conjunto 1 aleatóriamente
	{
		if(rand()%2 == 1)
			insere_conjunto(conjunto1,i);		
	}
	srand (time(NULL)*time(NULL));
	for (i=0;i<TAM;i++) //preenche o conjunto 2 aleatóriamente
	{
		if(rand()%2 == 1)
			insere_conjunto(conjunto2,i);		
	}
	while (numero>=0) //removendo itens do conjunto 1 testando se pertence
	{
		printf ("\ndigite um numero para remover do conjunto 1 ou negativo para sair: ");
		scanf ("%d",&numero);
		if(numero>=0)
		{
			if (pertence(conjunto1,numero)==0) //verifica se pertence ao conjunto antes de remover
					printf ("\nNumero %d nao consta no conjunto 1\n",numero);
				else {
					remove_conjunto(conjunto1,numero);
					printf ("\nNumero %d removido do conjunto\n",numero);
				}	
		}			
	}
	conjunto_print=conjunto_para_impressao(conjunto1); //imprimir conjunto 1
	printf ("\nElementos no conjunto 1:\n{");
	numero=tamanho_conjuntop(conjunto_print);
	for (i=0;i<numero;i++)	
	{
		printf ("%d, ",conjunto_print->num);
		conjunto_print=conjunto_print->prox;
	}		
	printf ("\b\b}\n\n");	
	
	conjunto3=uniao(conjunto1,conjunto2); //uniao
	conjunto_print=conjunto_para_impressao(conjunto3);
	numero=tamanho_conjuntop(conjunto_print);
	printf ("\nUniao entre os conjuntos 1 e 2:\n{");
	for (i=0;i<numero;i++)	
	{
		printf ("%d, ",conjunto_print->num);
		conjunto_print=conjunto_print->prox;
	}		
	printf ("\b\b}\n\n");
	
	conjunto3=interseccao(conjunto1,conjunto2); //interseccao
	conjunto_print=conjunto_para_impressao(conjunto3);
	numero=tamanho_conjuntop(conjunto_print);
	printf ("\nInterseccao entre os conjuntos 1 e 2:\n{");
	for (i=0;i<numero;i++)	
	{
		printf ("%d, ",conjunto_print->num);
		conjunto_print=conjunto_print->prox;
	}		
	printf ("\b\b}\n\n");
	
	conjunto3=diferenca(conjunto1,conjunto2); //diferenca don conjunto 1 para o 2
	conjunto_print=conjunto_para_impressao(conjunto3);
	numero=tamanho_conjuntop(conjunto_print);
	printf ("\nDiferenca entre os conjuntos 1 e 2:\n{");
	for (i=0;i<numero;i++)	
	{
		printf ("%d, ",conjunto_print->num);
		conjunto_print=conjunto_print->prox;
	}		
	printf ("\b\b}\n\n");
	
	conjunto3=diferenca(conjunto2,conjunto1); //diferenca don conjunto 2 para o 1
	conjunto_print=conjunto_para_impressao(conjunto3);
	numero=tamanho_conjuntop(conjunto_print);
	printf ("\nDiferenca entre os conjuntos 2 e 1:\n{");
	for (i=0;i<numero;i++)	
	{
		printf ("%d, ",conjunto_print->num);
		conjunto_print=conjunto_print->prox;
	}		
	printf ("\b\b}\n\n");
		
	printf ("\nMenor valor do conjunto 1: %d\n",menor_valor(conjunto1));
	printf ("\nMenor valor do conjunto 2: %d\n",menor_valor(conjunto2));
	printf ("\nMaior valor do conjunto 1: %d\n",maior_valor(conjunto1));
	printf ("\nMaior valor do conjunto 2: %d\n",maior_valor(conjunto2));
	
	if (compara_conjunto(conjunto1,conjunto2)==1) //verifica se conjuntos sao iguais
		printf ("\nConjuntos 1 e 2 sao iguais\n");
	else printf ("\nConjuntos 1 e 2 nao sao iguais\n");
	
	printf ("\nO conjunto 1 possui %d elementos\n",tamanho_conjunto(conjunto1)); //retorna os tamanhos dos conjuntos
	printf ("\nO conjunto 2 possui %d elementos\n",tamanho_conjunto(conjunto2));
	
	if (is_conjunto_vazio(conjunto1)== NULL) //Verifica e informa se o conjunto 1 é vazio
		printf ("\nO conjunto 1 eh vazio\n");
	else printf ("\nO conjunto 1 nao eh vazio\n");
	
	if (is_conjunto_vazio(conjunto2)== NULL) //Verifica e informa se o conjunto 1 é vazio
		printf ("\nO conjunto 2 eh vazio\n");
	else printf ("\nO conjunto 2 nao eh vazio\n");
	
	conjunto3= cria_conjunto(); //inicia novamente o conjunto 3 com vazio
	if (is_conjunto_vazio(conjunto3)== NULL) //Verifica e informa se o conjunto 3 é vazio
		printf ("\nO conjunto 3 eh vazio\n");
	else printf ("\nO conjunto 3 nao eh vazio\n");	
	
	return 0;	
}