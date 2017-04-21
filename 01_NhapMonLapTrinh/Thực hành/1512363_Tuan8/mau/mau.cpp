#include "stdio.h"
#include "conio.h"
#include "windows.h"
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void main()
{
	int n;
	for (n = 1; n < 256; n++)
	{
		TextColor(n);
		printf(" $Ma %d$|@|", n);
		if (n % 10 == 0) printf("\n");
	}
	_getch();
}
