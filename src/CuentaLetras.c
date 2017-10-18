#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	int i,n=0;
	char texto[50];
	printf("\nIntroduzca texto->");
	gets(texto);
	printf(" %s \n",texto);
	for(i=0;i<strlen(texto);++i)
	{
		switch(texto[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++n;
			break;
		}
	}
	printf("\n%d\n",n);
	if(getch()=='0')
	{
		exit(0);
	}
	main();
}