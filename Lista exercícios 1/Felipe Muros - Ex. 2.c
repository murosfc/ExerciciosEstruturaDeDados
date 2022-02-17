/*Declare duas vari´aveis inteiras m e n e dois ponteiros para elas. Atribua
valores para as vari´aveis. Descubra qual o maior valor, acessando-as somente atrav´es dos ponteiros. Imprima esse valor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	int n,m,*ptrn,*ptrm;
	srand (time(NULL));
	ptrn = &n;
	ptrm = &m;
	n = rand()%100+1;
	m = rand()%100+1;
	if (*ptrn > *ptrm)
		printf ("n=%d > m=%d\n",*ptrn,*ptrm);
		else printf ("m=%d > n=%d\n",*ptrm,*ptrn);
	return 0;
}