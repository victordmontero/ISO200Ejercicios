/*
Creado por Victor D. Montero Adames.
Matricula - 20150569.
---------------------------------------------------------------------------
a) - Desarrollar una aplicación en Lenguaje C, que lea una cadena de un
máximo de 50 caracteres y que no lea más caracteres del límite
establecido vía teclado.

b) Funcionalidades:
	
	b.1 Desarrollar una función que se combine con la sección a, que
		dada esa misma cadena, se presente un tablero resumen más
		abajo que imprima un conteo de la cantidad de caracteres que
		hay de cada uno de los que se escriben en la cadena.
	
	b.2 Desarrollar una función que se combine con la sección a y b, que
		dada esa misma cadena, se presente un tablero resumen más
		abajo que imprima un conteo de la cantidad de números
		solamente que componen la cadena o que han sido introducidas
		en la misma.	
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>


 void leer(char texto[])
 {
 	int i;
 	printf("-> ");
 	for(i=0;(texto[i]=getchar())!='\n';++i)
		if(strlen(texto)>=50)
		{
			break;
		}
	
 }
  
 main()
{
	char salir='n';
	int i;
	char texto[51];
	int numdenum=0;
	int numdestr[28];
 
	system("cls");
	system("color 17");
	
	while(salir!='y')
	{
		printf("\nEscriba algun texto\n");
		leer(texto);
		system("cls");
		numdenum=0;
		for(i=0;i<=26;++i)
			{
				numdestr[i]=0;
			}
		for(i=0;i<=strlen(texto);++i){
	switch(texto[i])
		{
			case 'A':
			case 'a':
				numdestr[0]+=1;
			break;
			
			case 'B':
			case 'b':
				numdestr[1]+=1;
			break;
			
			case 'C':
			case 'c':
				numdestr[2]+=1;
			break;
			
			case 'D':
			case 'd':
				numdestr[3]+=1;
			break;
			
			case 'E':
			case 'e':
				numdestr[4]+=1;
			break;
			
			case 'F':
			case 'f':
				numdestr[5]+=1;
			break;
			
			case 'G':
			case 'g':
				numdestr[6]+=1;
			break;
			
			case 'H':
			case 'h':
				numdestr[7]+=1;
			break;
			
			case 'I':
			case 'i':
				numdestr[8]+=1;
			break;
			
			case 'J':
			case 'j':
				numdestr[9]+=1;
			break;
			
			case 'K':
			case 'k':
				numdestr[10]+=1;
			break;
			
			case 'L':
			case 'l':
				numdestr[11]+=1;
			break;
			
			case 'M':
			case 'm':
				numdestr[12]+=1;
			break;

			case 'N':
			case 'n':
				numdestr[13]+=1;
			break;
			
			case 'Ñ':
			case 'ñ':
				numdestr[14]+=1;
			break;

			case 'O':
			case 'o':
				numdestr[15]+=1;
			break;
			
			case 'P':
			case 'p':
				numdestr[16]+=1;
			break;

			case 'Q':
			case 'q':
				numdestr[17]+=1;
			break;

			case 'R':
			case 'r':
				numdestr[18]+=1;
			break;

			case 'S':
			case 's':
				numdestr[19]+=1;
			break;
			
			case 'T':
			case 't':
				numdestr[20]+=1;
			break;

			case 'U':
			case 'u':
				numdestr[21]+=1;
			break;

			case 'V':
			case 'v':
				numdestr[22]+=1;
			break;

			case 'W':
			case 'w':
				numdestr[23]+=1;
			break;
			
			case 'X':
			case 'x':
				numdestr[24]+=1;
			break;

			case 'Y':
			case 'y':
				numdestr[25]+=1;
			break;
			
			case 'Z':
			case 'z':
				numdestr[26]+=1;
			break;
			
			default:
				if(isdigit(texto[i])==1)
				{
					numdenum++;
				}
		}
	}	
		system("cls");
		printf("\n-----------------");
		printf("------------------");
		printf("------------------\n");
		printf("%s\nCaracteres: %d",texto,strlen(texto));
		printf("\na=%d\t",numdestr[0]);
		printf("b=%d\t",numdestr[1]);
		printf("c=%d\t",numdestr[2]);
		printf("d=%d\t",numdestr[3]);
		printf("e=%d\t",numdestr[4]);
		printf("f=%d\n\n",numdestr[5]);
		printf("g=%d\t",numdestr[6]);
		printf("h=%d\t",numdestr[7]);
		printf("i=%d\t",numdestr[8]);
		printf("j=%d\t",numdestr[9]);
		printf("k=%d\t",numdestr[10]);
		printf("l=%d\n\n",numdestr[11]);
		printf("m=%d\t",numdestr[12]);
		printf("n=%d\t",numdestr[13]);
		printf("ñ=%d\t",numdestr[14]);
		printf("o=%d\t",numdestr[15]);
		printf("p=%d\t",numdestr[16]);
		printf("q=%d\n\n",numdestr[17]);
		printf("r=%d\t",numdestr[18]);
		printf("s=%d\t",numdestr[19]);
		printf("t=%d\t",numdestr[20]);
		printf("u=%d\t",numdestr[21]);
		printf("v=%d\t",numdestr[22]);
		printf("w=%d\n\n",numdestr[23]);
		printf("x=%d\t",numdestr[24]);
		printf("y=%d\t",numdestr[25]);
		printf("z=%d\n\n",numdestr[26]);
		printf("Numeros=%d\n\n",numdenum);
		
		printf("Desea Salir?[y/n] ");
			salir=getch();
		system("cls");
	}
	
	
}



