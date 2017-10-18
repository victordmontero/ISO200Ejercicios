/*
Creado por Victor D. Montero Adames
Matricula-20150569
--------------------------------------------------------------------------
Un Centro Ferretero de Santo Domingo Este llamado El Furgón, está
interesado en Desarrollar una aplicación que permita controlar las
operaciones de facturación y de acarreo de los materiales de construcción
que se venden en este negocio. Los materiales que se ofrece en dicho centro
son: Block a 17.00 pesos, Cemento cuesta 260 pesos el Cemento Titán y 250
el Cemento Panam; arena itabo para block y piso 900 y arena para pañete el
costo es 1000 pesos y la varilla cuesta 2300 pesos el quintal.

Se Requiere desarrollar 4 Módulos:

Modulo #1: hay que capturar los datos de los materiales, código,
descripción y precio.

Hay que lograr hacer una búsqueda en la lista de materiales para
consultar dichos materiales. Por código y Por descripción del material.

Modulo #2: El sistema debe capturar los datos de los Clientes que se
registren en el sistema para comprar, estos pueden ser de dos tipos:
Personas, Físicas y Empresas, los datos a capturar del cliente serán: Código,
Nombre, Apellido, RNC, Tipo de Cliente, Nombre de la Empresa.

Hay que lograr hacer una búsqueda en la lista de los clientes por el
nombre del cliente o por el rnc. Si se escribe el RNC el sistema deba decirnos
si existe registrado este cliente, cuál es su código y cuál es su nombre.
Como en este punto tendríamos dos módulos desarrollados, necesitamos
crear un menú de opciones para acceder a cada módulo; es decir que el
menú debe manejar: Clientes, Artículos y la opción de salir.

Modulo #3: Dado los dos módulos anteriores se requiere habilitar un 3
modulo que permita la facturación de los materiales registrados en el sistema
a los clientes.

Una factura contendrá, el número de factura, la fecha, el cliente (antes
hay que consultar que exista dicho cliente) a nombre del cual se hará la
factura, NCF (Numero de Comprobante Fiscal). A su vez en una sección del
detalle de factura en la misma ventana, se requiere introducir el código de
los artículos y que se muestre la descripción y el precio, luego se introduce la
cantidad a comprar de este artículo y el sistema hace el cálculo total. Una
factura puede contener más de 1 artículo. No se puede facturar un artículo
que no exista.

Modulo #4:
El sistema debe tener una opción el menú que se creó anteriormente que
dice Facturar, para el caso del módulo #3, descrito anteriormente y otra
opción de reportes para que el sistema genere un reporte de los artículos y
otro reporte de los clientes.
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

/*
void leer(char texto[])
{
	int i;
	strncpy(texto," ",50);
	fflush(stdin);
	for(i=0;i<49 || (texto[i]=getchar())!='\n';++i)
	{
		if(isspace(texto[i])!=1)
		{
			texto[i]=getchar();
		}
		else
		{
			continue;		
		}
	}
}
*/
	int opc;
	typedef struct {
		unsigned int codigo;
		char *descp;
		float precio;
	}producto;
	
	typedef struct {
		unsigned int codigo;
		char *nombre;
		char *apellido;		
	}cliente;
	
	cliente addcliente();
	
main()
{
	cliente n1;
	
	
	producto B;
	system("color 17");
	
	while(1){
		system("cls");
		printf("----------------------------------------");
		printf("---------------------------------------\n");
		printf("\t\t\tFerreteria el Furgon\n");
		printf("----------------------------------------");
		printf("---------------------------------------\n");
		printf("\t1-Clientes\t\t\t2-Articulos\n\n");
		printf("\t3-Facturar\t\t\t4-Generar Reportes\n\n");
		printf("\t5-Salir\n\n\t-> ");
	
		opc=getch();
		switch(opc)
		{
			case '1':
				system("cls");
				printf("1-Clientes\n");
				printf("2-Buscar Clientes\n");
				printf("3-Volver al menu\n-> ");
				opc=getch();
				if(opc=='1'){
					printf("Clientes\n");
					getche();
				}
				else if(opc=='2')
				{
					printf("Buscar Clientes");					
					getche();
				}
			break;

				
			case '2':
				system("cls");
				printf("1-Articulos\n");
				printf("2-Buscar Articulos\n");
				printf("3-Volver al menu\n-> ");
				opc=getch();
				if(opc=='1'){
					
				}
				else if(opc=='2')
				{
					
				}
			break;
				
				
			case '3':
				addcliente();						
			break;
				
				case '4':
					system("cls");
					printf("1-Reporte de Clientes\n");
					printf("2-Reporte de Articulos\n");
					printf("3-Volver al menu\n-> ");
					opc=getch();
					if(opc==1)
					{
						//Funcion	
					}
					else if(opc==2)
					{
						//Funcion
					}
				break;
				
			case '5':
				system("color 0F");
				exit(0);
			break;
		}
	}
}

cliente addcliente()
{
	cliente a;
	char *p;
	p=a.nombre;
	printf("Codigo de cliente[4 digitos max]: ");
	scanf("%4d",&a.codigo);
	printf("Nombre: ");
	scanf("%s",p);
}
