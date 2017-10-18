#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define SALIDA '5'

const char *REPORTE_A="reporteA.doc";
const char *REPORTE_B="reporteB.doc";
const char *DB="empleados.db";

typedef struct NODO {
	char nombre[40];
	unsigned int codigo;
	struct NODO *sig,*ant;
}nodo;

//-------------Prototipo---------
char menu();
//-------------------------------

FILE *empleados,*reportes;

int main()
{
	char opc;	
	nodo *primero=NULL;
	opc=menu();
}

SYSTEMTIME str_st;

char menu()
{
	unsigned char opc;
	do
	{
		system("cls");
		printf("<<----------------------");
		printf("------------------------");
		printf("------------------------->>\n");
		opc=getch();
		if(opc<'1'||opc>SALIDA)
		{
			printf("Opción no valida\n");
			getche();
			continue;
		}
	}while(opc<'1'||opc>SALIDA);
}

void CrearNodo(nodo *pt,char nombre[], unsigned int codigo)
{
	strcpy(pt->nombre,nombre);
	pt->codigo=codigo;
	pt->sig=NULL;
	pt->ant=NULL;
}


