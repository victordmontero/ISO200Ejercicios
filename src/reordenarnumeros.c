#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#define MAX 15

void reordenar(int n,int *x);

main()
{
	int i,n,*x;
	
	printf("Entre hasta 10 numeros.");
	printf(" Si no quiere introducir mas\n");
	printf("solo presione una tecla que no sea numero\n\n");
	
	x=(int *)malloc(15*sizeof(int));
	if(x==NULL)
	{	
		printf("\n¡Rayos!\n");
		exit(0);
	}
	
	printf("¿Cuantos numeros desea introducir?: ");
	scanf("%d",&n);
	if(n>15)
		n=15;
	
	for(i=0;i<n;++i)
	{
		printf("[%d]-> ",i+1);
		scanf("%d",(x+i));
	}
	
	reordenar(n,x);
	
	printf("\nLista reordenada:\n\n");
	
	for(i=0;i<n;++i)
	{
		printf("%d-%d\n",i+1,*(x+i));
	}
	free(x);
	
}

void reordenar(int n,int *x)
{
	int i,elem,temp;
	for(elem=0;elem<n+1;++elem)
	{
		for(i=elem+1;i<n;++i)
		{
			if(*(x+elem)>*(x+i))
			{
				temp=*(x+elem);
				*(x+elem)=*(x+i);
				*(x+i)=temp;
			}
		}
	}
}
