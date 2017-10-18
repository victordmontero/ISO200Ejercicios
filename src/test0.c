/*
Creado por Victor D. Montero Adames
Matricula-20150569
--------------------------------------------------------------------------
Un Centro Ferretero de Santo Domingo Este llamado El Furg�n, est�
interesado en Desarrollar una aplicaci�n que permita controlar las
operaciones de facturaci�n y de acarreo de los materiales de construcci�n
que se venden en este negocio. Los materiales que se ofrece en dicho centro
son: Block a 17.00 pesos, Cemento cuesta 260 pesos el Cemento Tit�n y 250
el Cemento Panam; arena itabo para block y piso 900 y arena para pa�ete el
costo es 1000 pesos y la varilla cuesta 2300 pesos el quintal.

Se Requiere desarrollar 4 M�dulos:

Modulo #1: hay que capturar los datos de los materiales, c�digo,
descripci�n y precio.

Hay que lograr hacer una b�squeda en la lista de materiales para
consultar dichos materiales. Por c�digo y Por descripci�n del material.

Modulo #2: El sistema debe capturar los datos de los Clientes que se
registren en el sistema para comprar, estos pueden ser de dos tipos:
Personas, F�sicas y Empresas, los datos a capturar del cliente ser�n: C�digo,
Nombre, Apellido, RNC, Tipo de Cliente, Nombre de la Empresa.

Hay que lograr hacer una b�squeda en la lista de los clientes por el
nombre del cliente o por el rnc. Si se escribe el RNC el sistema deba decirnos
si existe registrado este cliente, cu�l es su c�digo y cu�l es su nombre.
Como en este punto tendr�amos dos m�dulos desarrollados, necesitamos
crear un men� de opciones para acceder a cada m�dulo; es decir que el
men� debe manejar: Clientes, Art�culos y la opci�n de salir.

Modulo #3: Dado los dos m�dulos anteriores se requiere habilitar un 3
modulo que permita la facturaci�n de los materiales registrados en el sistema
a los clientes.

Una factura contendr�, el n�mero de factura, la fecha, el cliente (antes
hay que consultar que exista dicho cliente) a nombre del cual se har� la
factura, NCF (Numero de Comprobante Fiscal). A su vez en una secci�n del
detalle de factura en la misma ventana, se requiere introducir el c�digo de
los art�culos y que se muestre la descripci�n y el precio, luego se introduce la
cantidad a comprar de este art�culo y el sistema hace el c�lculo total. Una
factura puede contener m�s de 1 art�culo. No se puede facturar un art�culo
que no exista.

Modulo #4:
El sistema debe tener una opci�n el men� que se cre� anteriormente que
dice Facturar, para el caso del m�dulo #3, descrito anteriormente y otra
opci�n de reportes para que el sistema genere un reporte de los art�culos y
otro reporte de los clientes.
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

main()
{
	//system("cls");
/*	printf("----------------------------------------");
	printf("---------------------------------------\n");
	printf("\t\t\tFerreteria el Furgon\n");
	printf("----------------------------------------");
	printf("---------------------------------------\n");
	printf("\t1-Clientes\t\t\t2-Articulos\n\n");
	printf("\t3-Facturar\t\t\t4-Generar Reportes\n\n");
	printf("\t5-Salir\n\n\t-> ");
	*/
	char dbarticulo[3][150][50],codigo[4],descp[20],precio[6];
	int x,i=1;
	printf("Codigo: ");
	gets(codigo);
	printf("Descripcion: ");
	gets(descp);
	printf("Precio: ");
	gets(precio);
	while(strncasecmp(codigo,"x",1)!=0){
	strcpy(dbarticulo[1][i],codigo);
	strcat(dbarticulo[1][i],"\t");
	strcat(dbarticulo[1][i],descp);
	strcat(dbarticulo[1][i],"\t");
	strcat(dbarticulo[1][i],precio);
	++i;
	}
	for(x=0;x<10;++x)
		printf("%s",dbarticulo[1][x]);
	
}

