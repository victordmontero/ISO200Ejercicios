#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

void reordenar(int n,char *lista[]);

main()
{
	int i,n=MAX;
	char *lista[MAX];
	
	for(i=0;i<n;++i)
	{
		lista[i]=(char *)malloc(20*sizeof(char));
	}
	
	printf("Entre cadenas:\n");
	n=0;
	do{
		printf("%d-",n+1);
		gets(lista[n]);
	}while(strcasecmp(lista[n++],"Fin"));
	
	reordenar(--n,lista);
	
	printf("\nLista Reordenada\n\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d-%s\n",i+1,lista[i]);
		free(lista[i]);
	}
	printf("\a");
	getche();
}

void reordenar(int n,char *lista[])
{
	int i,elem;
	char *temp;
	
	for(elem=0;elem<n+1;++elem)
	{
		for(i=elem+1;i<n;++i)
		{
			if(strcasecmp(lista[elem],lista[i])>0)
			{
				temp=lista[elem];
				lista[elem]=lista[i];
				lista[i]=temp;
			}
		}
	}
}
