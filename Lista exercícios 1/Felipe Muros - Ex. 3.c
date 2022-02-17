/* 3. Crie uma nova vers˜ao do programa anterior fazendo uso de uma fun¸c˜ao
para descobrir o maior valor. A fun¸c˜ao dever´a receber os ponteiros para
as var´aveis m e n por parˆametro.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rtnmaior (int *n, int *m){
	if (*n>*m)
		return *n;
	else return *m;
}

int main (){
	int n,m,*ptrn,*ptrm, aux;
	srand (time(NULL));
	ptrn = &n;
	ptrm = &m;
	n = rand()%100+1;
	m = rand()%100+1;
	aux = rtnmaior (ptrn,ptrm);
	if (aux == n)
		printf ("n=%d eh maior que m=%d\n",*ptrn,*ptrm);
	else printf ("m=%d eh maior que n=%d\n",*ptrm,*ptrn);
	return 0;
}