#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void main(){
 int n=0;	
 char x[55];
 char *name;
 char texto[60],nombre1[15],nombre2[15],apellido1[15],apellido2[25],aux[25];
 char *pt1; //Declare un Puntero char
 char *tabla[5]={nombre1,nombre2,apellido1,apellido2,aux};
 printf(" Introduzca el nombre: \n");
 fgets(x,55,stdin);
 printf("\n Converting... \n\n");

 name = strtok (x," ");
  while (name != NULL)
  {
  if(strlen(name)<3 && (strcmpi(name,"del")==0 && (strcmpi(name,"la")==0)==1))
  {
    //printf(" %s",name);
  	switch(n)
  	{
  		case 0:
  			strcpy(name,nombre1);
  			name = strtok (NULL, " ");
		break;
		
		case 1:
  			strcpy(name,nombre2);
  			name = strtok (NULL, " ");
		break;
		
		case 2:
  			strcpy(name,apellido1);
  			name = strtok (NULL, " ");
		break;
		
		case 3:
  			strcpy(name,apellido2);
  			name = strtok (NULL, " ");
		break;
	}
  
  }else{
  	//printf (" %s\n",name);
  	//name = strtok (NULL, " ");
  	
  	switch(n)
  	{
  		case 0:
  			strcpy(name,nombre1);
  			name = strtok (NULL, " ");
		break;
		
		case 1:
  			strcpy(name,nombre1);
  			name = strtok (NULL, " ");
		break;
		
		case 2:
  			strcpy(name,nombre1);
  			name = strtok (NULL, " ");
		break;
		
		case 3:
  			strcpy(name,nombre1);
  			name = strtok (NULL, " ");
		break;
	}
  }
  n++;
  }
 system("PAUSE");
 
 
}
