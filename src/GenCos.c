/*
------------------------------------------------------------------------
-----------------------------------------------------------------------
Creado por Victor D. Montero Adames
Matricula 20150569
------------------------------------------------------------------------
------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct
{
	char generadora[30];
	char tipo[10];
	char estado;
	float circuito[4];
}genco;

//--prototipo-----------------------
void addgenco(genco generadora[]);
void cgenco(genco generadora);
//---------------------------------

int main()
{
	int opc,i,c=0;
	genco rdgen[100];
	genco gencoactual;
	
	while(1)
	{
		system("cls");
		printf("Generadora: %s\n",gencoactual.generadora);
		printf("--------------------------------------\n");
		printf("\t\t\tGenCos\n");
		printf("1-Entra nueva generadora\n");
		printf("2-Cambiar Generadora\n");
		printf("3-Cambiar datos de generadoras\n4-Salir\n-> ");
		opc=getch();
		switch(opc)
		{
			case '1':
				addgenco(rdgen);
				gencoactual=rdgen[0];
			break;
			
			case '2':
				printf("Seleccione su generadora\n");
				for(i=0;i<15;++i)
				{
					printf("%d-%-10s\t%-10s\t%c\n",i,rdgen[i].generadora,rdgen[i].tipo,rdgen[i].estado);
				}
				scanf("%d",&opc);
				c=opc;
				gencoactual=rdgen[c];
			break;
			
			case '3':
				system("cls");
				cgenco(gencoactual);
				rdgen[c]=gencoactual;
			break;
			
			case '4':
				exit(0);
			break;
		}
	}
}

void addgenco(genco generadora[])
{
	system("cls");
	fflush(stdin);
	static int i,j,opc;
	printf("Entre el nombre de la generadora: ");
	gets(generadora[i].generadora);
	printf("Seleccione el tipo de generacion:\n");
	printf("1-Diesel\n");
	printf("2-GN\n");
	printf("3-EE\n");
	printf("4-Hidrogeneracion\n");
	printf("5-Carbon\n-> ");
	printf("6-Nuclear\n");
	opc=getch();
	switch(opc)
	{
		case '1':
			strcpy(generadora[i].tipo,"Diesel");
		break;
		
		case '2':
			strcpy(generadora[i].tipo,"GN");
		break;
		
		case '3':
			strcpy(generadora[i].tipo,"EE");
		break;
		
		case '4':
			strcpy(generadora[i].tipo,"Hidrogeneracion");
		break;
		
		case '5':
			strcpy(generadora[i].tipo,"Carbon");
		break;
		
		case '6':
			strcpy(generadora[i].tipo,"Nuclear");
		break;
		
	}
	system("cls");
	printf("Especifique el Tipo:\n");
	printf("1-Activa\n2-Inactiva\n");
	opc=getch();
	if (opc=='1')
	{
		generadora[i].estado='A';
	}
	else if(opc=='2')
	{
		generadora[i].estado='I';
	}
	printf("Entre datos en MW: ");
	for(j=0;j<=3;++j)
	{
		printf("%d->",j+1);
		scanf("%f",&generadora[i].circuito[j]);
	}
	++i;
	fflush(stdin);
}

void cgenco(genco generadora)
{
	fflush(stdin);
	int opc;
	printf("Valor que desea cambiar:\n");
	printf("1-Nombre\n");
	printf("2-Tipo\n");
	printf("3-Estado\n-> ");
	opc=getch();
	system("cls");
	switch(opc)
	{
		case '1':
			printf("Nuevo Nombre: ");
			gets(generadora.generadora);
		break;
		
		case '2':
			printf("Nuevo Tipo: ");
			gets(generadora.tipo);
		break;
		
		case '3':
			printf("Nuevo Estado\n");
			printf("Especifique el Tipo:\n");
			printf("1-Activa\n2-Inactiva\n");
			opc=getch();
			if (opc=='1')
			{	
				generadora.estado='A';
			}
			else if(opc=='2')
			{
				generadora.estado='I';
			}		
		break;
	}
	return;
}
