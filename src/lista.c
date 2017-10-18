#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>

const char SALIDA='6';

typedef struct lelem 
{
	char elemento[30];
	struct lelem *sig;	
}nodo;

int menu();
void crear(nodo *);
nodo *insertar(nodo *pt);
nodo *eliminar(nodo *pt);
nodo *borrarlastnodo(nodo *pt);
nodo *agregarnodo(nodo *pt);
void mostrar(nodo *pt);

int main()
{
	nodo *lista;
	int opc;
	
	do
	{
		fflush(stdin);
		opc=menu();
		switch(opc)
		{
			case '1':
				lista =(nodo *)malloc(sizeof(nodo));
				crear(lista);
				printf("\n");
				mostrar(lista);
				getche();
			break;
			
			case '2':
				lista=insertar(lista);
				printf("\n");
				mostrar(lista);
				getche();
			break;
			
			case '3':
				lista=eliminar(lista);
				printf("\n");
				mostrar(lista);
				getche();
			break;
			
			case '4':
				lista=borrarlastnodo(lista);
				printf("\n");
				mostrar(lista);
				getche();
			break;
			
			case '5':
				lista=agregarnodo(lista);
				printf("\n");
				mostrar(lista);
				getche();
			break;
			
			default:
				printf("Fin de Operación.");
				sleep(2);
				
		}	
	}while(opc!=SALIDA);
}

int menu()
{
	int opc;
	do
	{
		system("cls");
		printf("-------------------");
		printf("-------------------\n");
		printf("Listas enlazadas:-\n");
		printf(" 1-Crear Nodo\n 2-Insertar nodo\n");
		printf(" 3-Eliminar nodo\n 4-Eliminar el ultimo nodo\n");
		printf(" 5-Agregar al principio\n 6-Salir\n\n->");
		opc=getch();
		if(opc<'1' || opc>SALIDA)
		{
			printf("Eleccion Incorrecta");
			getche();
		}
	
	}while(opc<'1' || opc>SALIDA);
	return(opc);
}

void crear(nodo *pt)
{
	printf("Escriba el dato para el nuevo nodo ");
	printf("[FIN] para detenerse\n-> ");
	gets(pt->elemento);
	if(strcasecmp(pt->elemento,"Fin")==0)
		pt->sig=NULL;
	else
	{
		pt->sig=(nodo *)malloc(sizeof(nodo));
		crear(pt->sig);
	}
	return;
}

void mostrar(nodo *pt)
{
	if(pt->sig!=NULL)
	{
		printf("-%s\n",pt->elemento);
		mostrar(pt->sig);	
	}
	return;
}

nodo *insertar(nodo *pt)
{
	nodo *localizar(nodo *,char[]);
	nodo *nuevoregistro;
	nodo *marca;
	char nuevo[30];
	char objetivo[30];
	
	printf("Nuevo dato: ");
	gets(nuevo);
	printf("Donde?: ");
	gets(objetivo);
	
	if(strcasecmp(pt->elemento,objetivo)==0)
	{
		nuevoregistro=(nodo *)malloc(sizeof(nodo));
		strcpy(nuevoregistro->elemento,nuevo);
		nuevoregistro->sig=pt;
		pt=nuevoregistro;
	}
	else
	{
		marca=localizar(pt,objetivo);
		if(marca==NULL)
			printf("no se encontraron coincidencias\n");
		else
		{
			nuevoregistro=(nodo *)malloc(sizeof(nodo));
			strcpy(nuevoregistro->elemento,nuevo);
			nuevoregistro->sig=marca->sig;
			marca->sig=nuevoregistro;
		}
		return(pt);
	}
}

nodo *localizar(nodo *pt,char objetivo[])
{
	if(strcasecmp(pt->sig->elemento,objetivo)==0)
		return(pt);
	else if(pt->sig->sig==NULL)
		return(NULL);
	else
		localizar(pt->sig,objetivo);
}

nodo *eliminar(nodo *pt)
{
	nodo *localizar(nodo *,char[]);
	nodo *marca;
	nodo *temp;
	char objetivo[30];
	
	printf("Dato a Borrar: ");
	scanf("%[^\n]",objetivo);
	if(strcasecmp(pt->elemento,objetivo)==0)
	{
		temp=pt->sig;
		free(pt);
		pt=temp;
	}
	else
	{
		marca = localizar(pt,objetivo);
		if(marca == NULL)
			printf("no se encontro una coincidencia\n");
		else 
		{
			temp = marca->sig->sig;
			free(marca->sig);
			marca->sig=temp;
		}
	}
	return(pt);
}

nodo *borrarlastnodo(nodo *pt)
{
	nodo *marca=pt;
	if (marca->sig->sig!=NULL)
	{
		borrarlastnodo(marca->sig);
	}
	else
	{
		free(marca->sig);
		marca->sig=marca->sig->sig;
	}
	return(pt);
}

nodo *agregarnodo(nodo *pt)
{
	nodo *temp,*nuevonodo;
	nuevonodo=(nodo *)malloc(sizeof(nodo));
	printf("Nuevo nodo: ");
	gets(nuevonodo->elemento);
	nuevonodo->sig=pt;
	pt=nuevonodo;
	
	return(pt);
}
