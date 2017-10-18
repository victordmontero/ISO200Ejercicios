#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

const char SALIDA='5';

typedef struct lelem
{
	unsigned int codigo;
	char nombre[30];
	char decanato[30];
}empleado;

//--prototipos-----
char menu();
void generarreporte(empleado p[]);
empleado *registrar(empleado p[]);
void vaciar(empleado p[]);

time_t hora[2];
struct tm *horaactual[2];

main()
{
	empleado personal[100];
	char opc;
	vaciar(personal);
	do 
	{
		
		opc=menu();
		switch(opc)
		{
			case '1':
				registrar(personal);
			break;
		
			case '2':
			
			break;
		
			case '3':
				printf("Codigo\tNombre y Apellido\tDecanato\n");
				generarreporte(personal);
				getche();
			break;
		
			case '4':
			
			break;
		
			default:
				printf("Cerrando...\n");
				sleep(1);
				exit(0);
		}	
	}while(1);
}

char menu()
{
	char opc;
	do{
		hora[0]=time(&hora[0]);
		horaactual[0]=localtime(&hora[0]);
		system("cls");
		printf("<<--------");
		printf("----------");
		printf("--------->>\n");
		printf(" 1-Regristrar empleado\n 2-Remover empleado\n");
		printf(" 3-Generar Reporte de empleados\n");
		printf(" 4-Generar Reporte de horas\n 5-Salir\n->");
		
		if (kbhit()==1)
			opc=getch();
		if(opc<'1' || opc>SALIDA)
		{
			printf("Opcion invalida\n");
			getche();
		}
	}while(opc<'1' || opc>SALIDA);
	return(opc);
}

empleado *registrar(empleado p[])
{
	static int i;
	if(p[i].codigo!=0)
	{
		++i;
		registrar(p);
	}
	else
	{
		p[i].codigo = (i>0)?p[i-1].codigo+1:1;
		printf("Entre su nombre completo\n-> ");
		fflush(stdin);
		gets(p[i].nombre);
		printf("Entre el nombre de tu decanato\n-> ");
		fflush(stdin);
		gets(p[i].decanato);
	}
}

void generarreporte(empleado p[])
{
	
	static int i;
	if (p[i].codigo!=0)
	{
		printf("%0-5d\t",p[i].codigo);
		printf("%20s\t",p[i].nombre);
		printf("%20s\n",p[i].decanato);
		++i;
		generarreporte(p);
	}
	else
	{
		i=0;
		return;
	}
}

void vaciar(empleado p[])
{
	int i;
	for(i=0;i<sizeof(p);++i)
	{
		p[i].codigo=0;
		strcpy(p[i].nombre," ");
		strcpy(p[i].decanato," ");
	}
}

void punchar(empleado *p)
{
	
}


empleado *buscarp(empleado px[100])
{
	fflush(stdin);
	int i;
	char *p;
	empleado *resultado;
	char busqueda[25];
	printf("\nNombre a buscar: ");
	gets(busqueda);
	for(i=0;i<100;++i)
	{
		p=strstr(px[i].nombre,busqueda);
		if(p!=NULL)
		{
			break;
		}
	}
	if(p==NULL)
	{
		printf("No se encontro el empleado\n");
	}
	else
	{
		printf("Codigo:\t\t%-04d\n",px[i].codigo);
		printf("Nombre:\t%-15s\n",px[i].nombre);
	}
	resultado=&px[i];
	return resultado;
}
