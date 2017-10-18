#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char color[15];
	while(strcasecmp(color,"salir")!=0)
	{
		printf("Introduzca un color: ");
		gets(color);
		if(strstr(color,"azul")!=NULL)
		{
			printf("encontrado\n");
		}else if(strstr(color,"rojo")!=NULL)
		{
			printf("encontrado\n");
		}else if(strstr(color,"amarrillo")!=NULL)
		{
			printf("encontrado\n");
		}else if(strstr(color,"verde")!=NULL)
		{
			printf("encontrado\n");
		}else if(strstr(color,"negro")!=NULL)
		{
			printf("encontrado\n");
		}else if(strstr(color,"naranja")!=NULL)
		{
			printf("encontrado\n");
		}else if(strstr(color,"blanco")!=NULL)
		{
			printf("encontrado\n");
		}
		else
		{
			printf("no encontrado\n");
		}
		
	}
}
