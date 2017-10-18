#include<stdio.h>
#include<stdlib.h>
#include<libxl.h>
#include<conio.h>
const char *Libro="Booky.xls";

BookHandle book;

void escribir(SheetHandle sheet,int i,char *palabra)
{
	book=xlCreateBook();
	if(xlBookLoad(book,Libro)==0)
	{
		printf("no se pudo cargar\n");
		printf("Creando uno nuevo\n");
		xlBookSave(book,Libro);
		sheet = xlBookAddSheet(book,"Clientes",0);
		xlSheetWriteStr(sheet,i,0,palabra,NULL);
		xlSheetWriteNum(sheet,i,1,1000,NULL);
	}
	else
	{
		printf("libro cargado\n");
		sheet = xlBookGetSheet(book,0);
		if(sheet)
		{
			xlSheetWriteStr(sheet,i,0,palabra,NULL);
			xlSheetWriteNum(sheet,i,1,1000,NULL);
		}
		else
			puts(xlBookErrorMessage(book));
	}
	
}

int main()
{
	char *wordy=(char *)malloc(30*sizeof(char));
	int x;
	SheetHandle s1;
	printf("Entre un nombre que quiera grabar\n-> ");
	gets(wordy);
	printf("fila-> ");
	scanf("%d",&x);
	escribir(s1,x,wordy);
	xlBookSave(book,Libro);
	xlBookRelease(book);
	printf("Revisa el xls generado ");
	printf("por este programa");
	getche();
}
