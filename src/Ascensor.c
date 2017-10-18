#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
int leer();

int main()
{
	int i,j,k,h;
	k=5;
	while(1)
	{	
		char table[5][11];
		for(i=1;i<5;++i)
		{
			for(j=1;j<11;++j)
			{
				table[i][j]='0';
				table[k][3]='E';
			}
		}
	
		sleep(1);
		system("cls");
		--k;
		
		for(i=1;i<5;++i)
		{
			printf(" \n ");
			for(j=1;j<11;++j)
			{	
				putchar(table[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		if(k<=0)
		{
			break;	
		}
	
		if(kbhit()==1)
		{
			break;
		}
	}
}

int leer()
{
	int c;
	printf("Entre el numero de piso\n-> ");
	scanf("%d",&c);
	return c;
}
