#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char nombre[20];
	char apellido[20];
	char completo[40];
	system("color 17");
	
	printf("\n--------");
	printf("--------");
	printf("--------");
	printf("--------");
	printf("--------");
	printf("--------");
	printf("--------\n");
	
	printf("Escriba su nombre\n-> ");
	scanf("%s",nombre);
	printf("Escriba su apellido\n-> ");
	scanf("%s",apellido);
		
	strcpy(completo,nombre);
	
	strcat(completo," ");
	strcat(completo,apellido);
	
	strupr(completo); 
			
	printf("\n----------\n%s\n",completo);
	printf("Caracteres %d\n",strlen(completo));
	
	strrev(nombre);
	strrev(apellido);
	
	strcpy(completo,nombre);
	strcat(completo," ");
	strcat(completo,apellido);
	strupr(completo);
	
	
	printf("\n--------------\n%s\n",completo);
	
	system("pause");
	
	
}
