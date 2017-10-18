/*
Creado por Victor D. Montero Adames
Matricula-20150569
--------------------------------------------------------------------------------
Desarrollar una aplicación que dado 3 tipos de voltajes que maneja el
power supply de la computadora 3v, 5v y 12v, cuando se introduzca un
voltaje que valla de 3 a 4 diga que este alimenta los Chips, cuando el voltaje
es de 5 a 11 imprima que enciende el Mother Board y que si el voltaje es
entre 12, diga el disco duro. Si no es ninguno de esta escala debe decir que el
voltaje es inválido.
*/

#include<stdio.h>

void voltajeprinter(float voltaje);

main()
{
	int d=1;
	do{
		float voltaje;
		system("cls");
		printf("Introduzca un voltaje\n-> ");
		scanf("%f",&voltaje);
		voltajeprinter(voltaje);
		printf("Salir?: ");
		scanf("%d",&d);
	}while(d!=0);

}


void voltajeprinter(float voltaje)
{
	if(voltaje>=3 && voltaje<=4)
	{
		printf("El voltaje introducido alimenta los Chips\n");
	}else if(voltaje>4 && voltaje<=11)
	{
		printf("El voltaje introducido enciende el Mother Board\n");
	}else if (voltaje>11&&voltaje<=12)
	{
		printf("El voltaje introducido controla el disco duro\n");
	}
	else
	{
		printf("El voltaje introducido es invalido\n");

	}
}