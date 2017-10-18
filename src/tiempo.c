#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

const char SALIDA='6';

typedef struct lelem
{
	unsigned int PIN;
	char nombre[30];
}empleado;

time_t hora[2];
struct tm *horaactual[2];
main()
{
	char opc;
	printf("%d",hora[0]);
	hora[1]=1565554;
	do
	{
		system("cls");
		hora[0]=time(&hora[0]);
		horaactual[0]=localtime(&hora[0]);
		printf(" %d:",horaactual[0]->tm_hour-12);
		printf("%d:",horaactual[0]->tm_min);
		printf("%d ",horaactual[0]->tm_sec);
		printf(" %d:",horaactual[1]->tm_hour-12);
		printf("%d:",horaactual[1]->tm_min);
		printf("%d ",horaactual[1]->tm_sec);
		printf("presione 6 para salir");
		
		if(kbhit()==1)
		{
			opc=getche();
			if(opc==6)
				exit(0);
			else
			{
					
			}
		}
	}while(1);
		
}
