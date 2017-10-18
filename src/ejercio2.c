/*
Creado por Victor D. Montero A.
Matricula:- 20150569
--------------------------------
Desarrollar una aplicación que permita imprimir 4 características de 5 marcas
distintas de camionetas, que se seleccione a través de un menú de marcas.
Estas son Nissan, Toyota, Isuzu, Ford y Mitsubishi. Al seleccionar una de ellas
debe presentar un mensaje con varias características como: Tamaño,
combustible, capacidad de carga, cilindraje, tamaño del motor.

C. Debe establecerse un menú de opciones para realizar la operación
deseada. La aplicación debe mantenerse en ejecución hasta tanto se
elija alguna opción de salir.

*/

#include<stdio.h>

main()
{
	int op;
	char d='y';
	float tamaniomotor;
	float tamanio;
	float combustible;
	int cilindraje;
	float cpdcrg;
	do{
	system("cls"); 
	printf("Programa que imprime 4 características de 5 marcas distintas de camionetas:\n");
	printf("Nissan, Toyota, Isuzu, Ford y Mitsubishi");
	printf("Introduzca la operacion\n");
	printf("1)Nissan\n2)Toyota\n3)Isuzu\n4)Ford\n5)Mitsubishi\n");
	printf("0)Salir\n\n");
	printf("~> ");
	scanf("%d",&op);
		
		switch(op)
		{
			case 0:
				d='n';
			break;

			case 1:
				combustible=60;
				cpdcrg=2000;
				tamanio=7957.60;
				cilindraje=1598;
				tamaniomotor=1348;

				system("cls");
				printf("Marca: Nissan\nTamanio: %.2fm3\n",tamanio);
				printf("combustible: %.2f l\n",combustible);
				printf("Capacidad de Carga: %.2fkgkg\n",cpdcrg);
				printf("Cilindraje: %d cm3\n ",cilindraje);
				printf("Tamanio de Motor: %.2fcm3\n",tamaniomotor);
				system("pause");

			break;

			case 2:
				combustible=70;
				cpdcrg=2300;
				tamanio=8000.30;
				cilindraje=1598;
				tamaniomotor=1356;

				system("cls");
				printf("Marca: Toyota\nTamanio: %.2f m3\n",tamanio);
				printf("combustible: %.2f l\n",combustible);
				printf("Capacidad de Carga: %.2f kg\n",cpdcrg);
				printf("Cilindraje: %d cm3\n ",cilindraje);
				printf("Tamanio de Motor: %.2fcm3\n",tamaniomotor);
				system("pause");
				
			break;

			case 3:
				combustible=90;
				cpdcrg=2500;
				tamanio=8200.10;
				cilindraje=1600;
				tamaniomotor=1543;

				system("cls");
				printf("Marca: Isuzu\nTamanio: %.2fm3\n",tamanio);
				printf("combustible: %.2f l\n",combustible);
				printf("Capacidad de Carga: %.2f kg\n",cpdcrg);
				printf("Cilindraje: %d cm3\n ",cilindraje);
				printf("Tamanio de Motor: %.2fcm3\n",tamaniomotor);
				system("pause");
		        
			break;

			case 4:
				combustible=70;
				cpdcrg=2100;
				tamanio=7800.20;
				cilindraje=1400;
				tamaniomotor=1500;

				system("cls");
				printf("Marca: Ford\nTamanio: %.2fm3\n",tamanio);
				printf("combustible: %.2f l\n",combustible);
				printf("Capacidad de Carga: %.2f kg\n",cpdcrg);
				printf("Cilindraje: %d cm3\n ",cilindraje);
				printf("Tamanio de Motor: %.2fcm3\n",tamaniomotor);
				system("pause");
			

			break;

			case 5:
				combustible=80;
				cpdcrg=2000;
				tamanio=7500.40;
				cilindraje=1300;
				tamaniomotor=1400;

				system("cls");
				printf("Marca: Mitsubishi\nTamanio: %.2fm3\n",tamanio);
				printf("combustible: %.2f l\n",combustible);
				printf("Capacidad de Carga: %.2f kg\n",cpdcrg);
				printf("Cilindraje: %d cm3\n ",cilindraje);
				printf("Tamanio de Motor: %.2fcm3\n",tamaniomotor);
				system("pause");
			break;	
		
			default:
				printf("\n\nOperacion Invalida\n\n");
				system("pause");		
		}
	}while(d=='y');	

}