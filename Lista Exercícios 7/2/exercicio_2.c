#include <stdio.h>

#include "pilha_fila.h"

int main ()
{
	tipo_fila *Fila;
	int valor_fila, opcao_menu=0;
	Fila=criarFila();
	while (opcao_menu != 6)
	{
		printf ("\nDigite um das seguintes opcoes:");
		printf ("\n1 - Enfileirar elemento;");
		printf ("\n2 - Desenfileirar elemento;");
		printf ("\n3 - Verificar se a fila esta vazia;");
		printf ("\n4 - Verificar o tamanho da fila;");
		printf ("\n5 - Apagar a fila;");
		printf ("\n6 - Sair do programa\n");
		scanf ("%d",&opcao_menu);
		
		switch(opcao_menu)
		{
		case 1:
			printf ("\nDigite o elemento que deseja enfileirar: ");
			scanf ("%d",&valor_fila);
			if (addFila(Fila,valor_fila) == 1)
				printf ("\nO valor %d foi adicionado a fila com sucesso\n",valor_fila);
			else printf ("\nOcorreu um erro ao alocar memoria, nao foi possivel enfileirar o valor inserido\n");
			break;
		case 2:
			valor_fila = removeFila(Fila);
			if (valor_fila == NULL)
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
			if (isFilaVazia(Fila) == 1)
				printf ("\nFila apagada com sucesso\n");
			else printf ("\nOcorreu um erro ao tentar apagar a Fila\n");
			break;
		case 6:
			apagarFila(Fila);
			break;
		default:
			printf ("\nOpcao invalida, tente novamente\n");
			break;
		}
	}
	return 0;
}