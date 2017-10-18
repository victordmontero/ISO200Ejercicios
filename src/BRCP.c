/*
Creado Por Victor D. Montero
-----------------------------
Desarrollar un programa en C que consiste en leer 
una cadena que no exceda los 50 caracteres.  Adicional 
a esto en esta cadena se deben realizar las siguientes 
operaciones en la misma:

- Buscar

-Buscar y Reeplezar

- Cortar

- Y Pegar lo cortado.

Recuerden que cada vez que se haga una operacion sobre 
ella, debe imprimirse la cadena para confirmar que la 
operacion realizada en ella fue exitosa.

****Imcompleto*******
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<memory.h>

void leer(char texto[])
{
	int i;
	int len=strlen(texto);
	memcpy(texto," ",len);
	fflush(stdin);
	for(i=0;i<49 && (texto[i]=getchar())!='\n';++i);
	fflush(stdin);		
}

main()
{
	char texto[10];
	int opc;
	leer(texto);
	puts(texto);
	
	printf("1-Entrar texto\n2-Buscar\n3-Buscar y Reemplazar\n");
	printf("4-Cortar\n5-Pegar\n6-Salir\n-> ");
	
	switch(opc)
	{
		case '1':
		break;
			
	}
}
