#include<stdio.h>
#include<stdlib.h>

main()
{
	int i,j;
	for(i=0;i<=26;++i)
	{
		switch(i%2)
		{
			case 0:
				printf("%d Par\n",i);
			break;
			
			default:
			case 1:
				printf("%d Impar\n",i);
			break;	
		}		
	}
}
