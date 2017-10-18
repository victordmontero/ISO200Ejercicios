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
#include<time.h>
#include<math.h>
const char *arch_1="clientesdb.xls";
const char *arch_2="productosdb.xls";

typedef struct 
{
	unsigned int cantidad;
	unsigned int codigo;
	char descp[25];
	float precio;
}producto;

typedef struct
{
	unsigned int codigo;
	unsigned long long int rnc;
	char nombre[25];
	char apellido[25];
	char empresa[25];
	char tipo;
	producto carrito[100];
}cliente;
FILE *db[2];
fpos_t pos;


//----Funciones-Prototipo----------------------------------------------//
cliente addcliente(cliente dbcliente[100]);
producto addproducto(producto dbproducto[100]);
void addtocart(producto cart[100],producto dbproducto[100],int index);
char *buscar(cliente dbcliente[100]);
void *buscarint(cliente dbcliente[100]);
char *buscarp(producto dbproducto[100]);
void *buscarintp(producto dbproducto[100]);
//---------------------------------------------------------------------//

main()
{
	system("color 17");
	int opc,i=0,c=0,e=0;
	float total;
	cliente dbcliente[100];
	producto dbproducto[100];
	cliente clienteactual;
	db[0]=fopen(arch_1,"a+");
	db[1]=fopen(arch_2,"a+");
	
	//-----Blocks------//
	dbproducto[0].cantidad=100;
	dbproducto[0].codigo=1000;
	strcpy(dbproducto[0].descp,"Block");
	dbproducto[0].precio=17.00;
	
	//--Cemento-Titan--//
	dbproducto[1].cantidad=100;
	dbproducto[1].codigo=1001;
	strcpy(dbproducto[1].descp,"Cemento Titan");
	dbproducto[1].precio=260.00;
	
	//--Cemento-Panam--//
	dbproducto[2].cantidad=100;
	dbproducto[2].codigo=1002;
	strcpy(dbproducto[2].descp,"Cemento Panam");
	dbproducto[2].precio=250.00;
	
	//--Arena-itabo---//
	dbproducto[3].cantidad=100;
	dbproducto[3].codigo=1003;
	strcpy(dbproducto[3].descp,"Arena(Itabo)");
	dbproducto[3].precio=900.00;
	
	//----Varilla----//
	dbproducto[4].cantidad=100;
	dbproducto[4].codigo=1004;
	strcpy(dbproducto[4].descp,"Varilla");
	dbproducto[4].precio=270.00;

	//----Pañete-----//
	dbproducto[5].cantidad=100;
	dbproducto[5].codigo=1005;
	strcpy(dbproducto[5].descp,"Paniete");
	dbproducto[5].precio=1000.00;
	
	for(i=0;i<100;++i)
	{
		fscanf(db[0],"%d\t",&dbcliente[i].codigo);
		fscanf(db[0],"%s\t",dbcliente[i].nombre);
		fscanf(db[0],"%s\t",dbcliente[i].apellido);
		fscanf(db[0],"%s\t",dbcliente[i].empresa);
		fscanf(db[0],"%d\t",&dbcliente[i].rnc);
		fscanf(db[0],"%c\n",&dbcliente[i].tipo);
		
		fscanf(db[1],"%d",&dbproducto[i].codigo);
		fscanf(db[1],"%d",&dbproducto[i].cantidad);
		fscanf(db[1],"%s",dbproducto[i].descp);
		fscanf(db[1],"%f",&dbproducto[i].precio);
	}
	
	clienteactual=dbcliente[0];
	
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "Current local time and date: %s", asctime (timeinfo) );
	while(1){	
		system("cls");
		printf ( "Current local time and date: %s", asctime (timeinfo) );
		printf("Nombre del cliente:%-15s %-15s ",clienteactual.nombre,clienteactual.apellido);
		printf("RNC %llu\n",clienteactual.rnc);
		printf("----------------------------------------");
		printf("---------------------------------------\n");
		printf("\t\t\t\tFerreteria el Furgon\n");
		printf("----------------------------------------");
		printf("---------------------------------------\n");
		printf("1-Clientes\t\t\t2-Articulos\n\n");
		printf("3-Facturar\t\t\t4-Generar Reportes\n\n");
		printf("5-Salir\n\n-> ");
	
		opc=getch();
		switch(opc)
		{
		//Clientes===============================================================	
			case '1':
				system("cls");
				printf("1-Agregar cliente\n");
				printf("2-Buscar Clientes\n");
				printf("3-Volver al menu\n-> ");
				opc=getch();
				switch(opc)
				{
					case '1':
						system("cls");
						addcliente(&dbcliente[0]);
						clienteactual=dbcliente[c];
					break;
					
					case '2':
						system("cls");
						printf("Buscar por?:\n");
						printf("1-Por Nombre\n2-Por Codigo\n");
						printf("-> ");
						opc=getch();
						if(opc=='1')
							buscar(dbcliente);
						else if(opc=='2')
							buscarint(dbcliente);
						getche();
					break;		
				}
			break;
		//Articulos================================================================		
			case '2':
				system("cls");
				printf("1-Agregar articulos\n");
				printf("2-Agregar articulos al carrito\n");
				printf("3-Buscar Articulos\n");
				printf("4-Volver al menu\n-> ");
				opc=getch();
				if(opc=='1')
				{
					addproducto(dbproducto);	
				}
				else if(opc=='2')
				{
					system("cls");
					for(i=0;i<16;++i)
					{
						printf("%d-%-15s\tRD$%7.2f\n",i+1,dbproducto[i].descp,dbproducto[i].precio);
					}
					scanf("%d",&opc);
					--opc;
					addtocart(clienteactual.carrito,dbproducto,opc);
					}
					else if(opc=='3')
					{
						system("cls");
						printf("Buscar por?:\n");
						printf("1-Por descripcion\n2-Por Codigo");
						printf("\n-> ");
						opc=getch();
						if(opc=='1')
						{
							buscarp(dbproducto);
						}
						else if(opc=='2')
						{
							buscarintp(dbproducto);
						}
						getche();
					}
				
				
			// getche();	
			break;
		//Facturacion===========================================================================		
			case '3':
				total=0;			
				for(i=0;i<99;++i)
				{
					if(dbcliente[i].codigo==0)
					{
						++e;	
					}
				}
				
				if(e>=i)
				{		
					printf("No hay clientes Registrados");
					getche();
					e=0;
					break;
				}
				e=0;
				
				srand(100000000);	
				system("cls");
				printf("\t\t\tFactura\n\n");
				printf("\t%s\t\t\tNCF:A%d\n\n",asctime(timeinfo),rand());
				printf("\t%s %s\t\t\tRNC %d\n\n",clienteactual.nombre,clienteactual.apellido,clienteactual.rnc);
				for(i=0;i<17;++i)
				{
					printf("\t%d\t%4d\t",clienteactual.carrito[i].cantidad,clienteactual.carrito[i].codigo);
					printf("%-15s\t%7.2f\n",clienteactual.carrito[i].descp,clienteactual.carrito[i].precio);
				}
				
				for(i=0;i<100;++i)
				{
					total+=clienteactual.carrito[i].cantidad*clienteactual.carrito[i].precio;
				}
				printf("\t\t\t\tTotal %.2f\n",total);
				
				getche();
			break;
		//Reportes========================================================================================================		
			case '4':
				system("cls");
				printf("1-Reporte de Clientes\n");
				printf("2-Inventario\n");
				printf("3-Volver al menu\n-> ");
				opc=getch();
				if(opc=='1')
				{
					system("cls");
					for(i=0;i<24;++i)
					{
						printf("%04d %-10s ",dbcliente[i].codigo,dbcliente[i].nombre);
						printf("%-10s %-5s ",dbcliente[i].apellido,dbcliente[i].empresa);
						printf("\t%llu %c\n",dbcliente[i].rnc,dbcliente[i].tipo);
					}
					getche();
				}
				else if(opc=='2')
				{
					system("cls");
					for(i=0;i<24;++i)
					{
						printf("%04d %-10s ",dbproducto[i].codigo,dbproducto[i].descp);
						printf("\tRD$%7.2f %d\n",dbproducto[i].precio,dbproducto[i].cantidad);
					}
					getche();
				}
			break;
				
				
			case '5':
				system("color 0F");
				fclose(db[0]);
				fclose(db[1]);
				exit(0);
			break;
		}
	}
}

cliente addcliente(cliente *dbcliente)
{
	static int i=-1;
	++i;
	int j;
	if(dbcliente[i].codigo!=0)
	{
		addcliente(dbcliente);
	}
	else
	{
	db[0]=fopen(arch_1,"a+");
	fflush(stdin);
	printf("Datos del Nuevo Cliente\n");
	fflush(stdin);
	dbcliente[i].codigo+=i+1;
	fprintf(db[0],"%d\t",dbcliente[i].codigo);
	printf("Nombre: ");
	gets(dbcliente[i].nombre);
	fprintf(db[0],"%s\t",dbcliente[i].nombre);
	fflush(stdin);
	printf("Apellido: ");
	gets(dbcliente[i].apellido);
	fprintf(db[0],"%s\t",dbcliente[i].apellido);
	fflush(stdin);
	printf("Empresa: ");
	gets(dbcliente[i].empresa);
	fprintf(db[0],"%s\t",dbcliente[i].empresa);
	fflush(stdin);
	
	while(1)
	{
	printf("Tipo[E:empresa/F:persona fisica]: ");
	dbcliente[i].tipo=getchar();
	fflush(stdin);
	if(dbcliente[i].tipo=='F')
	{
		printf("RNC(Sin Guiones): ");
		scanf("%11llu",&dbcliente[i].rnc);
		fprintf(db[0],"%d\t",dbcliente[i].rnc);
		fprintf(db[0],"%c\n",dbcliente[i].tipo);
		fflush(stdin);
		fclose(db[0]);
		break;
	}
	else if(dbcliente[i].tipo=='E')
	{
		printf("RNC(Sin Guiones): ");
		scanf("%9llu",&dbcliente[i].rnc);
		fprintf(db[0],"%d\t",dbcliente[i].rnc);
		fprintf(db[0],"%c\n",dbcliente[i].tipo);
		fflush(stdin);
		fclose(db[0]);
		break;
	}
	else
	{
		printf("Identificador Invalido\n");
		fflush(stdin);
		continue;
	}
	}
	}
}

producto addproducto(producto dbproducto[100])
{
	static int i=-1;
	++i;
	
	if(dbproducto[i].codigo!=0)
		addproducto(dbproducto);
	else
	{
	db[1]=fopen(arch_2,"a+");
	fflush(stdin);
	printf("Datos de nuevo producto\n");
	dbproducto[i].codigo+=dbproducto[i-1].codigo+1;
	fprintf(db[1],"%d\t",dbproducto[i].codigo);
	printf("Cantidad: ");
	scanf("%u",&dbproducto[i].cantidad);
	fprintf(db[1],"%d\t",dbproducto[i].cantidad);
	fflush(stdin);
	printf("Descripcion: ");
	gets(dbproducto[i].descp);
	fprintf(db[1],"%s\t",dbproducto[i].descp);
	fflush(stdin);
	printf("Precio: ");
	scanf("%f",&dbproducto[i].precio);
	fprintf(db[1],"%f\n",dbproducto[i].precio);
	fclose(db[1]);
	return;
	}		
}

void addtocart(producto cart[100],producto dbproducto[100],int index)
{
	static int i=0;
	int j;
	for(j=0;j<15;++j)
	{
		if(strcasecmp(cart[j].descp,dbproducto[index].descp)==0)
		{
			cart[j].cantidad++;
			return;
		}
	}
	
	cart[i].cantidad++;
	strcpy(cart[i].descp,dbproducto[index].descp);
	cart[i].codigo=dbproducto[index].codigo;
	cart[i].precio=dbproducto[index].precio;
	dbproducto[index].cantidad--;
	++i;
}

char *buscar(cliente dbcliente[100])
{
	fflush(stdin);
	int i;
	char *p;
	char busqueda[25];
	printf("\nCadena a buscar: ");
	gets(busqueda);
	for(i=0;i<100;++i)
	{
		p=strstr(dbcliente[i].nombre,busqueda);
		if(p!=NULL)
		{
			break;
		}
	}
	if(p==NULL)
	{
		printf("No se encontro el cliente\n");
	}
	else
	{
		printf("Codigo:\t\t%-04d\n",dbcliente[i].codigo);
		printf("Nombre:\t\t%-15s\n",dbcliente[i].nombre);
		printf("Apellido:\t%-15s\n",dbcliente[i].apellido);
		printf("Empresa:\t%-15s\n",dbcliente[i].empresa);
		printf("RNC:\t\t%-ld\n",dbcliente[i].rnc);
	}
	return p;
}

void *buscarint(cliente dbcliente[100])
{
	fflush(stdin);
	int i;
	int *p;
	int busqueda=0;
	printf("\nCodigo a buscar: ");
	scanf("%d",&busqueda);
	for(i=0;i<100;++i)
	{
		p=memchr(&dbcliente[i].codigo,busqueda,4*sizeof(int));
		if(p!=NULL)
		{
			break;
		}
	}
	if(p==NULL)
	{
		printf("No se encontro el cliente\n");
	}
	else
	{
		printf("Codigo:\t\t%-04d\n",dbcliente[i].codigo);
		printf("Nombre:\t\t%-15s\n",dbcliente[i].nombre);
		printf("Apellido:\t%-15s\n",dbcliente[i].apellido);
		printf("Empresa:\t%-15s\n",dbcliente[i].empresa);
		printf("RNC:\t\t%-ld\n",dbcliente[i].rnc);
	}
	return p;
}


char *buscarp(producto dbproducto[100])
{
	fflush(stdin);
	int i;
	char *p;
	char busqueda[25];
	printf("\nCadena a buscar: ");
	gets(busqueda);
	for(i=0;i<100;++i)
	{
		p=strstr(dbproducto[i].descp,busqueda);
		if(p!=NULL)
		{
			break;
		}
	}
	if(p==NULL)
	{
		printf("No se encontro el producto\n");
	}
	else
	{
		printf("Codigo:\t\t%-04d\n",dbproducto[i].codigo);
		printf("Descripcion:\t%-15s\n",dbproducto[i].descp);
		printf("Precio:\t\t%-6.2f\n",dbproducto[i].precio);
		printf("Cantidad:\t%-ld\n",dbproducto[i].cantidad);
	}
	return p;
}

void *buscarintp(producto dbproducto[100])
{
	fflush(stdin);
	int i;
	int *p;
	int busqueda=0;
	printf("\nCodigo a buscar: ");
	scanf("%d",&busqueda);
	for(i=0;i<100;++i)
	{
		p=memchr(&dbproducto[i].codigo,busqueda,4*sizeof(int));
		if(p!=NULL)
		{
			break;
		}
	}
	if(p==NULL)
	{
		printf("No se encontro el producto\n");
	}
	else
	{
		printf("Codigo:\t\t%-04d\n",dbproducto[i].codigo);
		printf("Descripcion:\t%-15s\n",dbproducto[i].descp);
		printf("Precio:\t\t%-6.2f\n",dbproducto[i].precio);
		printf("Cantidad:\t%-ld\n",dbproducto[i].cantidad);
	}
	return p;
}

char *imprimir(char caracter[100],int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		strncat(caracter,caracter,1);
		if(i>100) break;
	}
	return caracter;
}
