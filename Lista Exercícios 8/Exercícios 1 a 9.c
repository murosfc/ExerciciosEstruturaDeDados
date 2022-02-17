#include<stdio.h>
#include"tadArvoreBB3.h"

int main()
{
    tipo_no_arvore arvore;    
	
	arvore = inicializar_arvore(arvore);

    incluir_no_arvore(arvore, 100);
    incluir_no_arvore(arvore, 50);
    incluir_no_arvore(arvore, 150);
    incluir_no_arvore(arvore, 25);
    incluir_no_arvore(arvore, 75);      
    incluir_no_arvore(arvore, 45);
    incluir_no_arvore(arvore, 35);    
    incluir_no_arvore(arvore, 48);
    incluir_no_arvore(arvore, 150);
    incluir_no_arvore(arvore, 175);
    incluir_no_arvore(arvore, 165);
    incluir_no_arvore(arvore, 160); 	
    printf("\nListagem em ordem:\n");
    percurso_em_ordem(arvore);
    printf("\nListagem em pre-ordem:\n");
    percurso_em_pre_ordem(arvore);
    printf("\nListagem em pos-ordem:\n");
    percurso_em_pos_ordem(arvore);	
    printf("\nEncontrar 45: %d", encontrar_elemento(arvore, 45));
    printf("\nEncontrar 44: %d", encontrar_elemento(arvore, 44));    
    printf("\nMenor elemento excluido: %d", excluir_menor(arvore));
    printf("\nExcluir 45: %d", excluir_elemento(arvore, 45));
    printf("\nExcluir 44: %d\n", excluir_elemento(arvore, 44));
    percurso_em_ordem(arvore);
    
    printf ("\nMenor elemento da arvore: %d",menor_elemento(arvore)); // Exercício 1     
   
    printf ("\nSoma dos elementos da arvore: %d", soma_elementos(arvore));  // Exercício 2    
    
    printf ("\nQuantidade de nos da arvore: %d", conta_nos (arvore));  //Exercicio 3 
	
	printf ("\nMedia dos valores da arvore: %d", media_arvore (arvore));  //Exercicio 4      
	
	printf ("\nQuantidade de folhas na arvore: %d", conta_folhas (arvore));  //Exercicio 5  
	
	printf ("\nQuantidade de 'NULL' presentes na arvore: %d", conta_nulls(arvore));  //Exercicio 6  
    
    printf ("\nAltura da arvore: %d", calcula_altura(arvore));  //Exercicio 7
	
	
	printf ("\nQuantidade de multiplos de %d presentes na arvore: %d",3,conta_multiplos(arvore, 3)); // Exercicio 8  
	
	int aux = 150, teste=conta_multiplos(arvore, 3); //Exercicio 9
	if (teste == 0)
		printf ("\nO elemento %d nao foi encontrado na arvore");
	else  printf ("\nO elemento %d  foi encontrado apos %d comparacoes",aux,encontrar_elemento_plus(arvore, aux));
    
    printf("\n");
    return 0;
}
