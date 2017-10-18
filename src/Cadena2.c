/* Programa que Convierta de M a m*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

main()
{
	int i,opc;
	char texto[24],mitad1[12],mitad2[12];
	char salir='0';
	system("color 17");
	
	while(salir!='5'){
	printf("0)Entrar nuevo Texto\n1)Convertir a M\n2)Convertir a m\n");
	printf("3)Convertir mitad a m\n4)Convertir mitad a M\n");
	printf("5)Salir\n-> ");
	
	opc=getch();
	switch(opc)
	{
		
		case '0':
			system("cls");
			printf("Entre Texto\n-> ");
			gets(texto);
		break;
		
		case '1':
			system("cls");
			strupr(texto);
			printf("\n%s\n",texto);
		break;
		
		case '2':
			system("cls");
			strlwr(texto);
			printf("\n%s\n",texto);
		break;
		
		case '3':
			system("cls");
			i=strlen(texto)/2;
			strncpy(mitad1,texto,i);
			strupr(texto);
			strcpy(mitad2,texto);
			strcpy(texto,mitad2);
			memmove(texto,mitad1,i);
			printf("\n%s\n",texto);
		break;
		
		case '4':
			system("cls");
			i=strlen(texto)/2;
			strncpy(mitad1,texto,i);
			strlwr(texto);
			strcpy(mitad2,texto);
			strcpy(texto,mitad2);
			memmove(texto,mitad1,i);
			printf("\n%s\n",texto);
		break;
		
		case '5':
			salir='5';
		break;
	}
	}
	
	
	
	
}
