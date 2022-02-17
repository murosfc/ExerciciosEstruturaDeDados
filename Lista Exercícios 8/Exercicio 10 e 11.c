/*Implemente um programa principal que use uma ´arvore bin´aria de busca e inclua 1000 (Mil) n´umeros
aleat´orios, com range compreendido entre 0 e 10000 (Dez mil). N˜ao podem ser inclu´idos n´umeros repetidos.
Uma vez a ´arvore completa, fa¸ca a impress˜ao em ordem para verificar se est´a tudo ok. Utilize a fun¸c˜ao
de busca do exerc´icio anterior para testar algumas buscas. */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tadArvoreBB3.h"

#define TAM 1000

int main() 
{
	tipo_no_arvore arvore;
	int chave, i, teste;
	
	arvore= inicializar_arvore(arvore);
	
	srand (1);
	while ( conta_nos(arvore)<TAM)
	{
		chave = rand()%10001;
		if (encontrar_elemento(arvore,chave)==0)
			incluir_no_arvore(arvore,chave);
	}
	
	printf ("\nImpresssao da arvore em ordem:\n");
	percurso_em_ordem(arvore);
	
	printf ("\n\n");
	
	for (i=0;i<10;i++)
	{
		chave = rand()%10001;		
		if (encontrar_elemento(arvore,chave) == 1)
			printf ("\nElemento %d localizado na arvore", chave);
		else printf ("\nElemento %d nao localizado na arvore", chave);
	}
	
	printf ("\n\n");	

	// Exercicio 11	
	srand (1);
	for (i=0;i<10;i++)
	{
		chave = rand()%10001;		
		if (encontrar_elemento(arvore,chave) == 1)
			printf ("\nElemento %d localizado apos %d comparacao(oes)",chave, encontrar_elemento_plus(arvore,chave));
		else printf ("\nElemento %d nao localizado na arvore");
	}	
	
	return 0;
}