/*
Creado por Victor D. Montero Adames.
Matrícula - 20150569.
-------------------------------------------------------------------------
Desarrollar un programa en c que lea 4 numeros y identifique el valor del medio.
*/
#include<stdio.h>

int media(int veces);

main()
{
	int z;
	printf("-------------------------------------\n");
	printf("Entre el tamanio del arreglo ");
	scanf("%d",&z);
	printf("El elemento medio es %d",media(z));
}

int media(int veces)
{
	int i,x;
	char arreglo[veces];
	for(i=0;i<veces;++i)
	{
		printf("\n-> ");
		scanf("%d",&x);
		arreglo[i]=x;
	}
	x=i/2;
	return arreglo[x];
	
}
