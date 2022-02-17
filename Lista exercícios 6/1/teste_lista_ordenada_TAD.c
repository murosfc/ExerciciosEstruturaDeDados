/*
. Adicione no TAD de lista ordenada j´a desenvolvido as funcionalidades abaixo.
(a) calcularMedia: retorna a m´edia aritm´etica simples dos elementos da lista
(b) verificarProfundidade: a profundidade de uma c´elula c em uma lista encadeada ´e o n´umero de passos
do ´unico caminho que vai da primeira c´elula da lista at´e c. Entrar com um valor e apresentar a sua
profundidade na lista.
(c) compararListas: retorna se duas listas encadeadas s˜ao iguais, ou melhor, se tˆem o mesmo conte´udo.
*/

#include<stdio.h>
#include"lista_ordenada_TAD.h"

void imprimirLista(tipo_lista* listaOrdenada)
{
    int *elementosLista, posicao;
    elementosLista = obterElementosLista(listaOrdenada);
    for (posicao = 0; posicao < quantidadeElementosLista(listaOrdenada); posicao++)
    {
        printf("%d ", elementosLista[posicao]);
    }
    printf("\n");
}

int main()
{
    tipo_lista* listaOrdenada, *listaOrdenada2;
    int procurar_valor;

    listaOrdenada = criarListaVazia();
    listaOrdenada2 = criarListaVazia();
    
    
    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5); 
	printf ("\nLista 1: ");   
    imprimirLista(listaOrdenada);
    
   
	inserirElementoOrdenado(listaOrdenada2, 20);
    inserirElementoOrdenado(listaOrdenada2, 10);
    inserirElementoOrdenado(listaOrdenada2, 15);
    inserirElementoOrdenado(listaOrdenada2, 1);
    inserirElementoOrdenado(listaOrdenada2, 5);
	printf ("\nLista 2: ");
    imprimirLista(listaOrdenada2);
    
    if (compararListas(listaOrdenada,listaOrdenada2) == 1)
    	printf ("\nAs listas possuem o mesmo conteudo");
    else printf ("\nAs listas possuem o conteudo distinto");
    
    printf ("\nMedia dos elementos= %.2f\n",calcularMedia(listaOrdenada));
    printf ("\nDigite o valor a buscar na lista: ");
    scanf ("%d",&procurar_valor);
    printf ("\nProfundidade do valor digitado: %d\n",verificarProfundidade(listaOrdenada,procurar_valor));

    excluirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 1);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 20);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 15);

    excluirElementoOrdenado(listaOrdenada, 10);
    imprimirLista(listaOrdenada);

    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);
    printf("%d\n", quantidadeElementosLista(listaOrdenada));
    excluirElementoOrdenado(listaOrdenada, 10);
    printf("%d\n", quantidadeElementosLista(listaOrdenada));
    printf ("\nMedia dos elementos= %.2f\n",calcularMedia(listaOrdenada));
    listaOrdenada = apagarLista(listaOrdenada);
    listaOrdenada2 = apagarLista(listaOrdenada2);
    if (!listaOrdenada)
    {
        printf("Lista apagada!");
    }
    else
    {
        printf("A lista ainda existe!");
    }
    return 0;
}
