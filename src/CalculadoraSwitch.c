/*
-------------------------------------
Creado por Victor D. Montero Adames.
20150569
--------------------------------------
Desarrollar un programa en C que
Seleccione una operacion aritmetica
y arroje un resultado. Debe entrar
dos numeros.
 */
#include<stdio.h>

int main()
{

	float a,b,r;
	int op;

	printf("Introduzca dos numeros \n");
	printf("1> ");
	scanf("%f",&a);
	printf("2> ");
	scanf("%f",&b);
	printf("\n\nIntroduzca una operacion\n");
	printf("1)Suma\n2)Resta\n3)Producto\n4)Division\n");
	printf("op> ");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
			r=a+b;
			printf("%f+%f=%f",a,b,r);
		break;
		
		case 2:
			r=a-b;
			printf("%f-%f=%f",a,b,r);
		break;
		
		case 3:
			r=a*b;
			printf("%f*%f=%f",a,b,r);
		break;
		
		case 4:
				r=a/b;
			printf("%f/%f=%f",a,b,r);
		break;
		
		default:
			printf("operacion invalida\n");
			
			
	}

}
