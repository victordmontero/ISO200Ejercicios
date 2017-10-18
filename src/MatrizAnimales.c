/*
Creado por Victor D. Montero Adames.
Matrícula - 20150569.
--------------------------------------------------------------------------------
Desarrollar una aplicacion en C que imprima 12 nombre de animales en forma de matriz.
*/
#include<stdio.h>

void matriz()
{
	int x,y;
	char arreglo[3][4][15];
	for(x=0;x<3;++x)
	{
		for(y=0;y<4;++y)
		{
			printf("%d%d-> ",x+1,y+1);
			scanf("%s",&arreglo[x][y]);
		}
	}
	for(x=0;x<3;++x)
	{
		printf(" \n ");
		for(y=0;y<4;++y)
		{
			printf("%s\t",arreglo[x][y]);
			
		}
		printf(" \n ");
	}
}

main()
{	
	char y;
	printf("\nEntre una serie de nombre de animales\n");
	matriz();
	printf("Salir?[y/n] ");
	scanf("%s",&y);
	if(y=='n') 
		system("cls");
		main();
	
}

