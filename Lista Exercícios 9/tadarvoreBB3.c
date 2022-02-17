#include<stdio.h>
#include<stdlib.h>

struct reg_no_arvore
{
    struct reg_no_arvore *ptrEsquerda;
    int chave;
    struct reg_no_arvore *ptrDireita;
};
typedef struct reg_no_arvore **tipo_no_arvore;


tipo_no_arvore inicializar_arvore(tipo_no_arvore sub_raiz)
{
    sub_raiz = (struct reg_no_arvore**)malloc(sizeof(struct reg_no_arvore*));
    *sub_raiz = NULL;
}

void incluir_no_arvore(tipo_no_arvore sub_raiz, int chave)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = malloc(sizeof(struct reg_no_arvore));
        (*sub_raiz)->chave = chave;
        (*sub_raiz)->ptrEsquerda = NULL;
        (*sub_raiz)->ptrDireita = NULL;
    }
    else
    {
        if (chave < (*sub_raiz)->chave)
        {
            incluir_no_arvore(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                incluir_no_arvore(&((*sub_raiz)->ptrDireita), chave);
            }
        }
    }
}

void percurso_em_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_ordem(&((*sub_raiz)->ptrEsquerda));
        printf("%d ", (*sub_raiz)->chave);        
        percurso_em_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pre_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_pre_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pre_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pos_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_pos_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pos_ordem(&((*sub_raiz)->ptrDireita));
        printf("%d ", (*sub_raiz)->chave);
    }
}

int encontrar_elemento(tipo_no_arvore sub_raiz, int chave)
{
    if ((*sub_raiz) == NULL)
    {
        return 0;
    }
    else
    {
        if (chave == (*sub_raiz)->chave)
        {
            return 1;
        }
        else
        {
            if (chave < (*sub_raiz)->chave)
            {
                return encontrar_elemento(&((*sub_raiz)->ptrEsquerda), chave);
            }
            else
            {
                if (chave > (*sub_raiz)->chave)
                {
                    return encontrar_elemento(&((*sub_raiz)->ptrDireita), chave);
                }
            }
        }
    }
}

int excluir_menor(tipo_no_arvore sub_raiz)
{
    struct reg_no_arvore *auxiliar;
    int chave;

    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptrEsquerda != NULL)
        {
            return excluir_menor(&((*sub_raiz)->ptrEsquerda));
        }
        else
        {
            auxiliar = *sub_raiz;
            chave = auxiliar->chave;
            *sub_raiz = (*sub_raiz)->ptrDireita;
            free(auxiliar);
            return chave;
        }
    }
    else
    {
        return -1;
    }
}

int excluir_elemento(tipo_no_arvore sub_raiz, int chave)
{
    struct reg_no_arvore *auxiliar;

    if (*sub_raiz != NULL)
    {
        if (chave < (*sub_raiz)->chave)
        {
            return excluir_elemento(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                return excluir_elemento(&((*sub_raiz)->ptrDireita), chave);
            }
            else
            {
                if ((*sub_raiz)->ptrEsquerda == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->ptrDireita;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->ptrDireita == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->ptrEsquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->chave = excluir_menor(&((*sub_raiz)->ptrDireita));
                    }
                }
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}

// 1. Construir uma fun¸c˜ao para retornar o menor valor presente em uma ´arvore.
int menor_elemento (tipo_no_arvore sub_raiz) 
{
    if ((*sub_raiz)->ptrEsquerda == NULL)
        return (*sub_raiz)->chave;
    else 
    {
        return menor_elemento (&(*sub_raiz)->ptrEsquerda);
    }
}

// Construir uma fun¸c˜ao para retornar a soma dos valores dos n´os.
int soma_elementos(tipo_no_arvore sub_raiz)
{
    int soma=0;
	if (*sub_raiz == NULL)
    	return 0;
    soma = ((*sub_raiz)->chave) + (soma_elementos(&((*sub_raiz)->ptrEsquerda))) + (soma_elementos(&((*sub_raiz)->ptrDireita)));
    return soma;		        
}


//3. Construir uma fun¸c˜ao para retornar o n´umero de n´os de uma ´arvore.
int conta_nos(tipo_no_arvore sub_raiz){
    
	if (*sub_raiz == NULL)
    	return 0;
    else return 1 + (conta_nos(&((*sub_raiz)->ptrEsquerda))) + (conta_nos(&((*sub_raiz)->ptrDireita)));    	        
}

//4. Construir uma fun¸c˜ao para retornar a m´edia dos valores presentes em uma ´arvore.
int media_arvore (tipo_no_arvore sub_raiz)
{
	return soma_elementos(sub_raiz)/conta_nos(sub_raiz);
}

// Construir uma fun¸c˜ao para retornar o n´umero de folhas de uma ´arvore
int conta_folhas (tipo_no_arvore sub_raiz)
{
	if (*sub_raiz == NULL)
		return 0;
	else if ( (*sub_raiz)->ptrEsquerda == NULL && (*sub_raiz)->ptrDireita == NULL)
		return 1;
	return conta_folhas(&((*sub_raiz)->ptrEsquerda)) + conta_folhas(&((*sub_raiz)->ptrDireita));
}

//6. Construir uma fun¸c˜ao para retornar o n´umero de NULLs presentes em uma ´arvore.
int conta_nulls (tipo_no_arvore sub_raiz)
{
	int conta=0;
	if (*sub_raiz == NULL)
		return 0;
	else 
	{
		if ((*sub_raiz)->ptrEsquerda == NULL && (*sub_raiz)->ptrDireita == NULL)
			conta=2;
		else 
		{
			if ((*sub_raiz)->ptrEsquerda == NULL || (*sub_raiz)->ptrDireita == NULL)
				conta=1;						   	
		}
	}
	return conta + (conta_nulls(&((*sub_raiz)->ptrEsquerda)) + conta_nulls(&((*sub_raiz)->ptrDireita)));
}


//7. Construir uma fun¸c˜ao para retornar a altura de uma ´arvore.
int calcula_altura (tipo_no_arvore sub_raiz)
{
	if (*sub_raiz == NULL)
		return 0;
	else
	{
		int altura_esquerda=0, altura_direita=0;
		altura_esquerda = calcula_altura(&((*sub_raiz)->ptrEsquerda));
		altura_direita = calcula_altura(&((*sub_raiz)->ptrDireita));
		if (altura_esquerda > altura_direita)
			return altura_esquerda + 1;
		else return altura_direita + 1;			
	}
}

//8. Construir uma fun¸c˜ao para retornar o n´umero de n´os cujos valores s˜ao m´ultiplos de trˆes
int conta_multiplos (tipo_no_arvore sub_raiz, int num)
{
	if (*sub_raiz == NULL)
		return 0;
	else if (((*sub_raiz)->chave % num) == 0)	
		return 1;
	return conta_multiplos(&((*sub_raiz)->ptrEsquerda),num)+conta_multiplos(&((*sub_raiz)->ptrDireita),num);
		
}
/*9. Crie uma nova vers˜ao da fun¸c˜ao de busca de um elemento na ´arvore para que a mesma entregue o n´umero
de compara¸c˜oes necess´arias para encontrar o respectivo elemento. Fa¸ca uso dessa nova fun¸c˜ao de busca
no programa principal e imprima alguns resultados */
int encontrar_elemento_plus(tipo_no_arvore sub_raiz, int chave)
{
    if ( encontrar_elemento(&(*sub_raiz), chave) == 1)
	{
		int conta=1;
		if ((*sub_raiz) == NULL)
	    {
	        return 0;
	    }
	    else
	    {
	        if (chave == (*sub_raiz)->chave)
	        {
	            return 1;
	        }
	        else
	        {
	            if (chave < (*sub_raiz)->chave)
	            {                
					return 1 + conta + encontrar_elemento(&((*sub_raiz)->ptrEsquerda), chave);
	            }
	            else
	            {
	                if (chave > (*sub_raiz)->chave)
	                {                    
						return 1 + conta + encontrar_elemento(&((*sub_raiz)->ptrDireita), chave);
	                }
	            }
	        }
	    }	
	}
	else return 0;
}
