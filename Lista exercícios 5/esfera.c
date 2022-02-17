#include <math.h>
#include <stdlib.h>

struct esfera
{
	float diametro;
};

typedef struct esfera tipo_esfera;

tipo_esfera *cria_esfera (float dia)
{	
	tipo_esfera *esf;
	esf= (tipo_esfera*) malloc (sizeof (tipo_esfera));
	esf->diametro=dia;
	return esf;
}
float raio_esfera (tipo_esfera *esf)
{
	float raio;
	raio=esf->diametro/2;
	return raio;
}
float area_esfera (tipo_esfera *esf)
{
	float area_esf;
	area_esf=4*M_PI*pow(raio_esfera (esf),2); //M_PI é o valor de PI definido na math.h
	return area_esf;
}
float volume_esfera (tipo_esfera *esf)
{
	float volume_esf;
	volume_esf=4*M_PI*pow(raio_esfera (esf),3)/3; //M_PI é o valor de PI definido na math.h
	return volume_esf;
}