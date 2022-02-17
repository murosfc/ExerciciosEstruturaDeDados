/*Desenvolva um TAD que represente uma esfera. Inclua as fun¸c˜oes de inicializa¸c˜oes necess´arias e as
opera¸c˜oes que retornem seu raio, a sua ´area e o seu volume*/

#include <stdlib.h>
#include "esfera.h"

int main ()
{
	float diametro;
	tipo_esfera *esfera;
	printf ("\nDigite o diamentro da esfera em cm: ");
	scanf ("%f",&diametro);
	esfera=cria_esfera (diametro);
	printf("\nRaio da esfera: %.2f cm\n",raio_esfera(esfera));
	printf("\nArea da esfera: %.2f cm2\n",area_esfera(esfera));
	printf("\nVolume da esfera: %.2f cm3\n",volume_esfera(esfera));
	return 0;
}