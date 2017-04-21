#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int kt_tdx()
{
	int s = -1, i = 0;
	char c;
	char mang[255] = "";
	printf(" \n Nhap so ban muon xac dinh :");
	do
	{
		c = getchar();
		mang[i] = c;
		i++;
	} while (c != '\n');
	--i;
	int chia,j,kt=1;
	if ((i % 2) == 0)
	{
		chia = (i / 2);
		for (j = 1; j <= chia; j++)
			if (mang[j-1] != mang[i - j])
			{
				kt = 0;
				break;
			}
	}

	if (( i%2 ) == 1)
	{
		kt = 1;
		chia = (i / 2);
		for (j = 1; j <= chia; j++)
		{

			if (mang[j-1] != mang[i - j])   
			{
				kt = 0;
				break;
			}
		}
	}

	return kt;
}
void main()
{
	int m;
menu:
	int i;
	m = kt_tdx();
	if (m == 1) printf(" \nSo ban nhap co tinh doi xung "); 
	if (m == 0) printf("\n So ban nhap khong co tinh doi xung \n");
	goto menu;
	_getch();
}