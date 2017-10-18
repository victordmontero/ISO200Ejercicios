#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void getmatr(int matriz[2][2]);
void showmatriz(int matriz[2][2]);
void matrizadd(int matriz1[2][2],int matriz2[2][2],int matrizr[2][2]);
void matrizless(int matriz1[2][2],int matriz2[2][2],int matrizr[2][2]);
void matrizproducto(int matriz1[2][2],int matriz2[2][2],int matrizr[2][2]);

int main()
{
	int mat1[2][2]={{0}};
	int mat2[2][2]={{0}};
	int matr[2][2]={{0}};
	int i,j;
 	int opc;
	int salir;
		
	system("cls");
	system("color 17");
	getmatr(mat1);
	getmatr(mat2);	
	system("cls");

	while(salir!=5){
		printf("1-Entrar Datos\n2-Sumar Matrices\n3-Restar Matrices\n");
		printf("4-Multiplicar Matrices\n5-Salir\n-> ");
		opc=getch();

		switch(opc)
		{		
			case '1':
				system("cls");			
				getmatr(mat1);
	 			getmatr(mat2);
			break;

			case '2':
				system("cls");
				matrizadd(mat1,mat2,matr);
				showmatriz(matr);
			break;
                                                
                        case '3':
				system("cls");
				matrizless(mat1,mat2,matr);
				showmatriz(matr);
			break;
			
			case '4':
				system("cls");
				matrizproducto(mat1,mat2,matr);
				showmatriz(matr);
			break
; 
			case '5':
				salir=5;
				system("cls");
				system("color 0F");
			break;
		}

	}
	
	
}

void getmatr(int matriz[2][2]){
	int i,j;
	printf("Entre los elementos de la matriz\n");
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			printf("[%d][%d]-> ",i+1,j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
}

void showmatriz(int matriz[2][2]){
	int i,j;
	for(i=0;i<2;++i)
	{
		printf(" \n ");
		for(j=0;j<2;++j)
		{
			printf("%d\t",matriz[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");
}


void matrizadd(int matriz1[2][2],int matriz2[2][2],int matrizr[2][2])
{
	int i,j;	
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			matrizr[i][j]=matriz1[i][j]+matriz2[i][j];
		}
	}
}


void matrizless(int matriz1[2][2],int matriz2[2][2],int matrizr[2][2])
{
	int i,j;	
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			matrizr[i][j]=matriz1[i][j]-matriz2[i][j];
		}
	}
}

void matrizproducto(int matriz1[2][2],int matriz2[2][2],int matrizr[2][2])
{
	int i,j,z;	
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			for(z=0;z<2;++z)
	                {	
			matrizr[i][j]=matrizr[i][j]+matriz1[i][z]*matriz2[z][j];
			}
		}
	}
}
