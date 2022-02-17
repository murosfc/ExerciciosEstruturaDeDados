#include <stdio.h>
#include "pilha_fila.h"

int main ()
{
	tipo_pilha *Pilha;
	int valor_pilha, opcao_menu=0;
	Pilha=criarPilha();
	while (opcao_menu != 6)
	{
		printf ("\nDigite um das seguintes opcoes:");
		printf ("\n1 - Empilhar elemento;");
		printf ("\n2 - Desempilhar elemento;");
		printf ("\n3 - Verificar se a pilha esta vazia;");
		printf ("\n4 - Verificar o tamanho da pilha;");
		printf ("\n5 - Apagar a pilha;");
		printf ("\n6 - Sair do programa\n");
		scanf ("%d",&opcao_menu);
		
		switch(opcao_menu)
		{
		case 1:
			printf ("\nDigite o elemento que deseja empilhar: ");
			scanf ("%d",&valor_pilha);
			push(Pilha,valor_pilha);
			printf ("\n");
			break;
		case 2:
			valor_pilha=pull(Pilha);
			if (valor_pilha == NULL)
				printf ("\nNao ha elementos na pilha para desempilhar\n");
			else printf ("\nValor desempilhado: %d\n",valor_pilha);
			break;
		case 3:
			if (isPilhaVazia(Pilha) == 1)
				printf ("\nA pilha esta vazia\n");
			else printf ("\nA pilha nao esta vazia\n");
			break;
		case 4:
			printf ("\nTamanho da pilha: %d elemento(s)\n",tamanhoPilha(Pilha));
			break;
		case 5:
			apagarPilha(Pilha);
			if (isPilhaVazia(Pilha) == 1)
				printf ("\nPilha apagada com sucesso\n");
			else printf ("\nOcorreu um erro ao tentar apagar a pilha\n");
			break;
		case 6:
			apagarPilha(Pilha);
			break;
		default:
			printf ("\nOpcao invalida, tente novamente\n");
			break;
		}
	}
	return 0;
}