#include<stdio.h>
#include<stdlib.h>

main()
{
	int mat1[2][2]={{0}};
	int mat2[2][2]={{0}};
	int matr[2][2]={{0}};
	int i,j;
	
	
	printf("Entre los elementos de la mat1\n");
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			printf("[%d][%d]-> ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}

	
	printf("Entre los elementos de la mat2\n");
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			printf("[%d][%d]-> ",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}
	}
	
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			matr[i][j]=mat1[i][j]+mat2[i][j];
		}
	}
	
	
	for(i=0;i<2;++i)
	{
		printf(" \n ");
		for(j=0;j<2;++j)
		{
			printf("%d\t",matr[i][j]);
			
		}
		printf(" \n ");
	}
	
}
