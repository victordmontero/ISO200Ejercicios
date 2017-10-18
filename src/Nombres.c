/* Creado Por Victor D. Montero
----------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

main()
{
	char salir='n';
	int n1,n2,n3,n4;
	char texto[60],nombre1[15],nombre2[15],apellido1[15],apellido2[25],aux[25]; //Declare una Variable Tipo Cadena extra para Atrapar todo lo demas
	char *pt1; //Declare un Puntero char
	char *tabla[5]={nombre1,nombre2,apellido1,apellido2,aux};   //Declaracion de un Array de Punteros
	do{
		
		
		memcpy(texto,"",25);                                        // Los array de punteros contienen en sus celdas, 
		memcpy(nombre1,"",15);                                      //direcciones de memoria de otros array,
 		memcpy(nombre1,"",15);                                      //(en este caso de tipo Cadena)
		memcpy(apellido1,"",15);                                    // Limpia la Basura de todos los arrays                                       
		memcpy(apellido2,"",25);
		memcpy(aux,"",25);
	
		printf("Entre su nombre completo: ");
		gets(texto);
	
		for(n1=0,pt1=strtok(texto," ");pt1!=NULL;pt1=strtok(NULL," "),++n1)
		{	
			if(n1>4)
			{	
				strcat(tabla[4]," ");
				strcat(tabla[4],pt1);
				continue;	
			}	
			memcpy(tabla[n1],pt1,15);
		
			
		}
	
		if((strcmp(apellido1,"")==0 && strcmp(apellido2,"")==0)==1)
		{		
			strcpy(apellido1,nombre2);
			strcpy(nombre2,"");
		}

		for(n2=0;n2<=3;++n2)
		{
			if (((strlen(tabla[n2])<4) && (strcasecmp(tabla[n2],"del")==0))==1)
			{
				strcat(tabla[n2]," ");
				strcat(tabla[n2],tabla[n2+1]);
				strcpy(apellido1,nombre2);
				strcpy(nombre2,"");
				strcpy(apellido2,"");
			}
		
			if(((strlen(tabla[n2])<3) && ((strcasecmp(tabla[n2],"de")==0) && (strcasecmp(tabla[n2+1],"la")==0))==1)==1)
			{
			
				switch(n2)
				{
					case 1:		
						strcat(tabla[n2]," ");
						strcat(tabla[n2],tabla[n2+1]);
						strcpy(apellido1,nombre2);
						strcat(tabla[n2+1]," ");
						strcat(tabla[n2+1],tabla[n2+2]);
						strcpy(tabla[n2],"");
						strcpy(tabla[n2+2],"");
						strcpy(tabla[n2+2],tabla[n2+3]);
					break;
				
				}
			}
		}
		printf("Primer Nombre:   \t %-s\n",nombre1);
		printf("Segundo Nombre:  \t %-s\n",nombre2);
		printf("Primer Apellido: \t %-s\n",apellido1);
		printf("Segundo Apellido:\t %-s\n",apellido2);
		printf("Desea Salir?[y/n] ");
			salir=getch();
		system("cls");
	}while(salir!='y');
}
