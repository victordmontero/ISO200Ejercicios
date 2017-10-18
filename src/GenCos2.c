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
#define DEMANDA 5000

typedef struct
{
	char generadora[30];
	char tipo[10];
	char estado;
	float circuito[4];
}genco;

//--prototipo-----------------------
void addgenco(genco generadora[]);
genco cgenco(genco *generadora);
//---------------------------------
//--Declaraciones-globales---------
FILE *rdgendb;

int main()
{
	int opc,i,c=0;
	float total[5]={0,0,0,0,0};
	char DB[100]="rdgendb.txt";
	genco rdgen[100];
	genco *gencoactual;
	gencoactual=&rdgen[0];
	if((rdgendb=fopen(DB,"a+b"))==NULL)
	{
		printf("No se pudo Abrir la base de datos\n");
		printf("No se guardara nada\n");
	}
	for(i=0;i<99;++i)
	{
		strcpy(rdgen[i].generadora," ");
		strcpy(rdgen[i].tipo," ");
		rdgen[i].estado=' ';
		rdgen[i].circuito[0]=0;
		rdgen[i].circuito[1]=0;
		rdgen[i].circuito[2]=0;
		rdgen[i].circuito[3]=0;
	}
	for(i=0;i<100;++i)
	{
		fread(&rdgen[i],sizeof(genco),1,rdgendb);
	}
	while(1)
	{
		system("cls");
		printf("Generadora: %s\t",gencoactual->generadora);
		printf("%s\t%c\n",gencoactual->tipo,gencoactual->estado);
		printf("--------------------------------------\n");
		printf("\t\t\tGenCos\n");
		printf("1-Entra nueva generadora\n");
		printf("2-Cambiar de generadora\n");
		printf("3-Cambiar datos de generadoras\n");
		printf("4-Generar Datos\n5-Salir\n-> ");
		opc=getch();
		switch(opc)
		{
			case '1':
				addgenco(rdgen);
				gencoactual=&rdgen[c];
			break;
			
			case '2':
				printf("Seleccione su generadora\n");
				for(i=0;i<15;++i)
				{
					fprintf(stdout,"%d-%-10s\t%-10s\t%c\n",i,rdgen[i].generadora,rdgen[i].tipo,rdgen[i].estado);
					
				}
				scanf("%d",&opc);
				gencoactual=&rdgen[opc];
				c=opc;
			break;
			
			case '3':
				gencoactual=&rdgen[c];
				cgenco(gencoactual);
			break;
			
			case '4':
				printf("\n");
				for(i=0;i<15;++i)
				{
						printf(" %-10s %11s %c\t",rdgen[i].generadora,rdgen[i].tipo,rdgen[i].estado);
						printf("|%7.2fMw|%7.2fMw|%7.2fMw|%7.2fMw|\n",rdgen[i].circuito[0],rdgen[i].circuito[1],rdgen[i].circuito[2],rdgen[i].circuito[3]);
				}
				
				for(i=0;i<10;++i)
				{
					total[0]+=rdgen[i].circuito[0];
					total[1]+=rdgen[i].circuito[1];
					total[2]+=rdgen[i].circuito[2];
					total[3]+=rdgen[i].circuito[3];
				}
				printf("\t\t\t\t");
				for(i=0;i<4;++i)
				{
					total[4]+=total[i];
					printf("|%7.2fMw",total[i]);
				}
				
				printf("|\n\tTotal Mw: %10.2fMw\t",total[4]);
				for(i=0;i<5;++i)
					memset((total+i),0,sizeof(float));
				getch();
			break;
			
			case '5':
				rdgendb=fopen(DB,"wb");
				for(i=0;i<100;++i)
					fwrite(&rdgen[i],sizeof(genco),1,rdgendb);
				fclose(rdgendb);
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
	if(strcmp(generadora[i].generadora," ")!=0)
	{
		++i;
		addgenco(generadora);
	}
	else{
	printf("Entre el nombre de la generadora: ");
	gets(generadora[i].generadora);
	printf("Seleccione el tipo de generacion:\n");
	printf("1-Diesel\n");
	printf("2-GN\n");
	printf("3-EE\n");
	printf("4-Hidrogeneracion\n");
	printf("5-Carb�n\n");
	printf("6-Nuclear\n-> ");
	
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
	printf("Entre datos en MW:\n");
	for(j=0;j<=3;++j)
	{
		printf("%d->",j+1);
		scanf("%f",&generadora[i].circuito[j]);
	}
	++i;
	fflush(stdin);
	}
}

genco cgenco(genco *generadora)
{
	fflush(stdin);
	char opc;
	printf("Valor que desea cambiar:\n");
	printf("1-Nombre\n");
	printf("2-Tipo\n");
	printf("3-Estado\n-> ");
	opc=getch();
	if(opc=='1')
	{
		printf("Nuevo Nombre: ");
		gets(generadora->generadora);
	}
	else if(opc=='2')
	{
		printf("Nuevo Tipo:\n");
		printf("Seleccione el tipo de generacion:\n");
		printf("1-Diesel\n");
		printf("2-GN\n");
		printf("3-EE\n");
		printf("4-Hidrogeneracion\n");
		printf("5-Carb�n\n");
		printf("6-Nuclear\n-> ");
	
		opc=getch();
		switch(opc)
		{
			case '1':
				strcpy(generadora->tipo,"Diesel");
			break;
		
			case '2':
				strcpy(generadora->tipo,"GN");
			break;
		
			case '3':
				strcpy(generadora->tipo,"EE");
			break;
		
			case '4':
				strcpy(generadora->tipo,"Hidrogeneracion");
			break;
		
			case '5':
				strcpy(generadora->tipo,"Carbon");
			break;
		
			case '6':
				strcpy(generadora->tipo,"Nuclear");
			break;
		
		}
	}
	else if(opc=='3')
	{
		printf("Nuevo Estado:\n");
		printf("Especifique el Tipo:\n");
		printf("1-Activa\n2-Inactiva\n");
		opc=getch();
		if (opc=='1')
		{
			generadora->estado='A';
		}
		else if(opc=='2')
		{
			generadora->estado='I';
		}
	}
	return *generadora;
}
