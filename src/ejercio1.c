/*
Creado por Victor D. Montero A.
Matricula:- 20150569
--------------------------------
Desarrollar una aplicación que permita realizar cambio de Pesos a Diferentes
tipos de moneda, como Dólar, Euro, Franco, Dólar Canadiense, Libra Esterlina
y Yen de manera simultánea.

A. Debe establecerse un menú de opciones para realizar la operación
deseada. La aplicación debe mantenerse en ejecución hasta tanto se
elija alguna opción de salir.

B. Debe llevar una estadística de la cantidad de operaciones que se
hayan realizado con cada tipo de moneda, y que el usuario tenga
alternativa para verla.
*/

#include<stdio.h>

main()
{
	float rd,usd,eur,fr,cad,gbp,jpy,m;
	int op,c,i,z;
	char d;
	float dbf[16],dbrd[16];
	d='\0';
	usd=44.90; //Dolares Americanos
	eur=49.71; //Moneda Europea(Euros)
	fr= 47.83; //Francos
	cad=38.33; //Dolares Canadienses
	gbp=69.63; //Libra Esterlina
	jpy=2.70; // Yenes
	c=0;
	z=0;
	//asigna 0 a todos los elementos de la tabla
	do{
		dbrd[z]=0;
		dbf[z]=0;
		++z;
	}while(z<=16);
	
		// Limpia la consola e imprime un encabezado
	system("cls");
	do{
		system("cls");
		//system("cls");
		//Lista de Opciones----------------------------------------
		printf("Programa que Convierte de RD$ a:\n");
		printf("Dolares, eurros, Francos, Dolares Canadiense");
		printf(", Libra Esterlina y Yen\n");	
		printf("Introduzca la operacion\n");
		printf("1)Pesos->Dolares\n2)Pesos->Euros\n");
		printf("3)Pesos->Francos\n4)Pesos->Dolares Canadiense\n");
		printf("5)Pesos->Libra Esterlina\n6)Pesos->Yen\n7)Historial\n");
		printf("0)Salir\n\n");
		printf("~> ");
		scanf("%d",&op);
		
		switch(op)
		{
			case 0:
				d='y';
			break;

			case 1:
				system("cls");
				printf("Introduzca moneda en RD$> ");
		        scanf("%f",&rd);
				m=rd/usd;
				printf("\n\n%4.2f en Dolares es: %4.2f \n\n",rd,m);
				dbf[c]=m;
				dbrd[c]=rd;
				c++;
				system("pause");
			break;

			case 2:
				system("cls");
				printf("Introduzca moneda en RD$> ");
		        scanf("%f",&rd);
				m=rd/eur;
				printf("\n\n%4.2f en Euros es: %4.2f \n\n",rd,m);
				dbf[c]=m;
				dbrd[c]=rd;
				c++;
				system("pause");
			break;

			case 3:
				system("cls");
				printf("Introduzca moneda en RD$> ");
		        scanf("%f",&rd);
				m=rd/fr;
				printf("\n\n%4.2f en Francos es: %4.2f \n\n",rd,m);
				dbf[c]=m;
				dbrd[c]=rd;
				c++;
				system("pause");
			break;

			case 4:
				system("cls");
				printf("Introduzca moneda en RD$> ");
		        scanf("%f",&rd);
				m=rd/cad;
				printf("\n\n%4.2f en Dolares Canadienses es: %4.2f \n\n",rd,m);
				dbf[c]=m;
				dbrd[c]=rd;
				c++;
				system("pause");
			break;

			case 5:
				system("cls");
				printf("Introduzca moneda en RD$> ");
		        scanf("%f",&rd);
				m=rd/gbp;
				printf("\n\n%4.2f en Libra Esterlina es: %4.2f \n\n",rd,m);
				dbf[c]=m;
				dbrd[c]=rd;
				c++;
				system("pause");
			break;

			case 6:
				system("cls");
				printf("Introduzca moneda en RD$> ");
		        scanf("%f",&rd);
				m=rd/jpy;
				printf("\n\n%4.2f en Yen es: %4.2f \n\n",rd,m);
				dbf[c]=m;
				dbrd[c]=rd;
				c++;
				system("pause");
			break;			

			case 7:
				system("cls");
				i=0;
				do{
					printf("%d %4.2f %4.2f\n",i,dbrd[i],dbf[i]);
					i++;
				}while(i<c);
				system("pause");
				break;

			default:
				system("cls");
				printf("\n\nOpcion Invalida\n\n");
				system("pause");
			
		}
	}while(d!='y');	

}