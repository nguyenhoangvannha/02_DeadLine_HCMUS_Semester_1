#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void kt_tdx()
{
	int s=0;
	while (getchar() != EOF)
		s++;
	printf("\n so chu la: %d", s);
}
void main()
{
	printf(" \n Nhap so ban muon xac dinh :");
	kt_tdx();
	_getch();
}