/*
Creado por Victor D. Montero Adames.
Matrícula - 20150569.
---------------------------------------------------------------------------
Desarrollar una aplicación que permita la venta de galones de
combustible en 4 categorías, gasolina regular, gasolina Premium y gasoil
regular y Premium. Cada combustible tendrá un precio estándar, y el sistema
proporcionara un menú que permita seleccionar el tipo de combustible y la
cantidad comprada. El sistema debe tener una opción que imprima el
acumulado de los galones de combustible vendidos por cada renglón, en una
opción del menú.
*/

#include<stdio.h>

int menu()
{
	int opc;
	system("cls");
	printf("Seleccione una opcion:\n");
	printf("1-Gasolina Premium\n2-Gasolina Regular\n");
	printf("3-Gasoil Premium\n4-Gasoil Regular\n");
	printf("5-Historial de Ventas\n0-Salir\n-> ");
	scanf("%d",&opc);
	return opc;
}

float combustible(float precio,float galones)
{
	float vendido;
	vendido=precio*galones;
	return vendido;
}

main()
{
	float vendido,cantidad;
	int gp,gr,goilp,goilr,total;
	int opc,d=1;
	gp=gr=goilp=goilr=0;
	
	do{
		opc=menu();

	switch(opc)
	{
		case 0:
			d=0;
		break;

		case 1:
			printf("Entre cantidad comprada\n-> ");
			scanf("%f",&cantidad);
			vendido=combustible(295.90,cantidad);
			printf("El total de galones de gasolina Premium comprados: %2.2f\n",vendido);
			gp++;
			system("pause");
		break;

		case 2:
			printf("Entre cantidad comprada\n-> ");
			scanf("%f",&cantidad);
			vendido=combustible(204.50,cantidad);
			printf("El total de galones de gasolina Regular comprados: %2.2f\n",vendido);
			gr++;
			system("pause");
		break;

		case 3:
			printf("Entre cantidad comprada\n-> ");
			scanf("%f",&cantidad);
			vendido=combustible(147.70,cantidad);
			printf("El total de galones de gasoil Premium comprados: %2.2f\n",vendido);
			goilp++;
			system("pause");
		break;

		case 4:
			printf("Entre cantidad comprada\n-> ");
			scanf("%f",&cantidad);
			vendido=combustible(166.70,cantidad);
			printf("El total de galones de gasoil Regular comprados: %2.2f\n",vendido);
			goilr++;
			system("pause");
		break;

		case 5:
			printf("Total de ventas de galones de gasolina Premium:%d\n",gp);
			printf("Total de ventas de galones de gasolina Regular:%d\n",gr);
			printf("Total de ventas de galones de gasoil Premium:%d\n",goilp);
			printf("Total de ventas de galones de gasoil Regular:%d\n",goilr);
			total=gp+gr+goilp+goilr;
			printf("Total de ventas de galones :%d\n",total);
			system("pause");
		break;

		default:
			printf("opcion no valida\n");
			system("pause");

	}
	}while(d!=0);
		
}

	


