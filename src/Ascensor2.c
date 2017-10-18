#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
int leer();

int main()
{
	int i,j,k,h;
	char table[11][5];
	k=11;
	h=0;
	h=leer();
	while(1)
	{	
		for(i=0;i<11;++i)
		{
			for(j=0;j<5;++j)
			{
				table[i][j]='0';
				table[k][2]='E';
			}
		}
	
		sleep(1);
		system("cls");
		--k;
		
		for(i=0;i<11;++i)
		{
			for(j=0;j<5;++j)
			{	
				putchar(table[i][j]);
			}
			printf("\n");
		}
		
		if(k==h)
		{
			
			system("cls");
			h=leer();	
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
