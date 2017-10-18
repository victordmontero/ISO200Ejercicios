#include<stdio.h>
#include<stdlib.h>

main()
{
	float salario;
	float impuesto;
	printf("Introduzca salario :");
	scanf("%f",&salario);
		
	if(salario>35000 && salario<=42000)
	{
		impuesto=salario*0.15;
	}
	else if(salario>42000 && salario<=50000)
	{
		impuesto=salario*0.20;	
	}
	else if(salario>50000)
	{
		impuesto=salario*0.20;
	}
	else
	{
		impuesto=salario*0.5;
	}
	printf("El impuesto a pagar es RD$%.2f",impuesto);
}
