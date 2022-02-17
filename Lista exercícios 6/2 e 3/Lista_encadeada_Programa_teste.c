#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"
#include <time.h>

void imprimirlista (tipo_lista *lista);

int main()
{
	tipo_lista *lista_1,*lista_2;
	int num,opt=1;
	lista_1 = CriarListaVazia(); 	
	lista_2 = CriarListaVazia();
	
	srand (time(NULL)); //preencher lista 2 com randomicos
	for (num=0;num<10;num++)
		InserirElemento(lista_2,rand()%100);
		
	while (opt!=0)
	{
		printf ("\n\n                 MENU:                   \n");
		printf ("1- Incluir um elemento no final da lista\n");		
		printf ("2- Excluir um elemento da lista\n");
		printf ("3- Verificar se a lista esta vazia\n");
		printf ("4- Obter quantidade de elementos da lista\n");
		printf ("5- Apagar lista\n");
		printf ("6- Obter e imprimir elementos da lista\n");
		printf ("7- Concatenar listas\n");
		printf ("8- Apagar elementos iguais\n");
		printf ("9- Calcular media dos elementos\n");
		printf ("10- Verificar profundidade de um elemento\n");
		printf ("11- Comparar listas\n");
		printf ("12- Inserir elemento ordenado\n");	
		printf ("13- Copiar lista\n");	
		printf ("0- Encerrar programa\n\n");
		printf ("Digite sua opcao: ");
		scanf ("%d",&opt);
		switch(opt)
		{
		case 1:
			printf ("\n\nDigite o valor a incluir no final da lista: ");
			scanf ("%d",&num);
			InserirElemento(lista_1,num);
			break;
		case 2:
			printf ("\n\nDigite o valor a excluir da lista: ");
			scanf ("%d",&num);
			ExcluirElemento(lista_1,num);
			break;
		case 3:
			if (listaVazia(lista_1)==1 || lista_1==NULL)
				printf ("\nA lista esta vazia");			
			else printf ("\nA lista nao esta vazia");
			break;
		case 4:		
			printf ("\nQuantidade de elementos na lista: %d", quantidadeElementosLista(lista_1));			
			break;
		case 5:
			apagarLista(lista_1);			
			printf ("\nLista apagada com sucesso");			
			break;
		case 6:
			imprimirlista(lista_1);	
			break;
		case 7:
			lista_1=concatenarListas(lista_1,lista_2);		
			printf ("\nLista concatenada:");
			imprimirlista(lista_1);								
			break;
		case 8:
			printf ("\nDigite o elemento repetido que deseja retirar da lista: \n");
			scanf ("%d",&num);	
			excluirIguais(lista_1,num);
			printf ("\nNova lista sem o elemento %d: ",num);
			imprimirlista(lista_1);					
			break;
		case 9:
			printf ("\nMedia dos elementos: %.2f",calcularMedia(lista_1));
			break;
		case 10:
			printf ("\nDigite o elemento que desejas consultar a profundidade: \n");
			scanf ("%d",&num);			
			printf ("\nProdundidade do elemento %d = %d",num,verificarProfundidade(lista_1,num));
			break;
		case 11:
			if (compararListas(lista_1,lista_2)==1)
				printf ("\nListas iguais");
			else printf ("\nListas diferentes");
			break;
		case 12:
			printf ("\n\nDigite o valor a incluir ordenadamente na lista: ");
			scanf ("%d",&num);
			inserirElementoOrdenado(lista_1,num);
			break;
		case 13:
			CopiarLista(lista_2,lista_1);	
		break;
		case 0:
			apagarLista(lista_1);
			apagarLista(lista_2);
			printf ("\nPrograma finalizado com sucesso\n\n");
			break;
		default:
			printf ("\nOpcao invalida, tente novamente\n\n");
			break;
		}
	}	
	return 0;	
}

void imprimirlista (tipo_lista *lista)
{
	int i=0, *ponteiroimprimirlista;
	ponteiroimprimirlista = obterElementosLista(lista);
	printf ("\nElementos na lista:\n");
	for (i=0;i<quantidadeElementosLista(lista);i++)
		printf ("%d, ",ponteiroimprimirlista[i]);		
	printf ("\b\b  ");					
}