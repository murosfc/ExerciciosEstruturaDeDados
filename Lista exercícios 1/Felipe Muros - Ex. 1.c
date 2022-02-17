/*
1. Faça um programa que implemente os passos a seguir.
(a) Declare uma vari´avel inteira n e um ponteiro ptrn para essa vari´avel
(b) Atribua um valor para n
(c) Imprima o valor de n a partir de ptrn
(d) Imprima o endere¸co de n e de ptrn
(e) Incremente o valor de n usando o ponteiro ptrn
(f) Imprima o novo valor de n para confirmar se est´a correto
*/

#include <stdio.h>

int main() {
	int n, *ptrn;	
	ptrn = &n;
	n=5;
	printf ("Valor de n= %d\n",*ptrn);
	printf ("Endereco de n= %p\n",ptrn);
	printf ("Endereco de prtn= %p\n",&ptrn);
	*ptrn+=1;
	printf ("Valor de n= %d\n",*ptrn);
}

