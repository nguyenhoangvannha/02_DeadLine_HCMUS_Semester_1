#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void kt_tdx(char skt[])
{
	int i = 1, s = 0;
	while (skt[i] != EOF)
	{		
		s++; i++;
	}
	printf("\n so chu la: %d", s);
}
void main()
{
	char skt[] = "";
	printf(" \n Nhap so ban muon xac dinh :");
	scanf_s("%s",skt);
	kt_tdx(skt);
	_getch();
}