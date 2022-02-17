#include <stdlib.h>

struct racional
{
	int dividendo;
	int divisor;
};

typedef struct racional tipo_racional;

int mmc(int a, int b);

tipo_racional *cria_racional (int dividendo,int divisor)
{
	tipo_racional *novo;
	novo = (tipo_racional*) malloc (sizeof (tipo_racional));
	novo->dividendo=dividendo;
	novo->divisor=divisor;
	return novo;
}
void soma_racional (tipo_racional *rac1, tipo_racional *rac2, int *dividendo, int *divisor)
{	
	tipo_racional *novo;
	novo = (tipo_racional*) malloc (sizeof (tipo_racional));
	novo->divisor=mmc(rac1->divisor,rac2->divisor);
	if (novo->divisor < rac1->divisor)
		novo->dividendo=((rac1->divisor/novo->divisor)*rac1->dividendo+(rac2->divisor/novo->divisor)*rac2->dividendo);
	else novo->dividendo=((novo->divisor/rac1->divisor)*rac1->dividendo+(novo->divisor/rac2->divisor)*rac2->dividendo);
	*dividendo=novo->dividendo;
	*divisor=novo->divisor;	
}
tipo_racional *multiplica_racional (tipo_racional *rac1, tipo_racional *rac2, int *dividendo, int *divisor)
{
	int i=2;	
	*dividendo=rac1->dividendo*rac2->dividendo;
	*divisor=rac1->divisor*rac2->divisor;
	for (i=2;i<10;i++)
	{
		while (*dividendo%i == 0 && *divisor%i == 0 && *dividendo/i != 0 && *divisor/i !=0) //simplificar a fração
		{
			*dividendo/=i;
			*divisor/=i;
		}
	}	
}

int racionaiscmp (tipo_racional *rac1, tipo_racional *rac2)
{
	int divd1,divs1,divd2,divs2,i=2;
	divd1=rac1->dividendo;
	divs1=rac1->divisor;
	divd2=rac2->dividendo;
	divs2=rac2->divisor;
	for (i=2;i<10;i++)
	{
		while (divd1%i == 0 && divs1%i ==0 && divd1/i != 0 && divs1/i !=0) //simplificar a fração
		{
			divd1/=i;
			divs1/=i;
		}
		while (divd2%i == 0 && divs2%i ==0 && divd2/i != 0 && divs2/i !=0) //simplificar a fração
		{
			divd2/=i;
			divs2/=i;
		}
	}
	if (divd1==divd2 && divs1==divs2)
		return 1;
	else return 0;
}

//Algoritimo para calcular MMC
int mmc(int a, int b)
{
    int i=2,mmc=1;
    for (i=2;i<10;i++)
	{
		if (a%i == 0 && b%i ==0)
		{
			mmc=mmc*i;
			a/=i;
			b/=i;
		} else if (a%i == 0)
		{
			mmc=mmc*i;
			a/=i;
		} else if (b%i == 0)
		{
			mmc=mmc*i;
			b/=i;
		}		
	}
	return mmc;
}
