#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vetorFila.h"

int main ()
{
	tipo_fila *Fila;
	int valor_fila, opcao_menu=0;
	Fila=criarFila();
	srand (time (NULL));
	while (opcao_menu != 7)
	{
		printf ("\nDigite um das seguintes opcoes:");
		printf ("\n1 - Enfileirar elemento;");
		printf ("\n2 - Desenfileirar elemento;");
		printf ("\n3 - Verificar se a fila esta vazia;");
		printf ("\n4 - Verificar o tamanho da fila;");
		printf ("\n5 - Apagar a fila;");
		printf ("\n6 - Preencher fila com aleatorios\n");
		printf ("\n7 - Sair do programa\n");
		scanf ("%d",&opcao_menu);
		
		switch(opcao_menu)
		{
		case 1:
			printf ("\nDigite o elemento que deseja enfileirar: ");
			scanf ("%d",&valor_fila);
			if (addFila(Fila,valor_fila) == 1)
				printf ("\nO valor %d foi adicionado a fila com sucesso\n",valor_fila);
			else printf ("\nA fila esta cheia, remova um item antes de inserir outro\n");
			break;
		case 2:
			valor_fila = removeFila(Fila);
			if (valor_fila == 0)
				printf ("\nNao ha elementos na fila para desenfileirar\n");
			else printf ("\nValor desenfileirado: %d\n",valor_fila);
			break;
		case 3:
			if (isFilaVazia(Fila) == 1)
				printf ("\nA Fila esta vazia\n");
			else printf ("\nA Fila nao esta vazia\n");
			break;
		case 4:
			printf ("\nTamanho da Fila: %d elemento(s)\n",tamanhoFila(Fila));
			break;
		case 5:
			apagarFila(Fila);			
			printf ("\nFila apagada com sucesso\n");			
			break;
		case 6:
			while (isFilaVazia == 0)
			{
				addFila(Fila,rand()%100 +1);
			}
		break;
		case 7:
			apagarFila(Fila);
			break;
		default:
			printf ("\nOpcao invalida, tente novamente\n");
			break;
		}
	}
	return 0;
}