/*
Creado por Victor D. Montero Adames.
Matrícula - 20150569.
-------------------------------------------------------------------------
Desarrollar una aplicación utilizando un bucle que dado un numero entero
cualquiera lo pueda multiplicar N veces que se introduzca en el programa.
Por ejemplo: entramos el número 5, para multiplicarlo 5 veces seria
5*5*5*5*5.
*/
#include<stdio.h>

main()
{
	int n,r,i;
	int d=1;
	do{
		r=0;
		system("cls");
		printf("Introduzca un numero\n-> ");
		scanf("%d",&n);
		for (i = 1; i <=n; ++i)
		{
			r=n*n;
		}
		printf("\n%d multiplicado %d es %d\n",n,n,r);
		printf("Intentar nuevamente?: [\"1\" : si |\"0\" : no]\n-> ");
		scanf("%d",&d);
	}while(d!=0);
	
}