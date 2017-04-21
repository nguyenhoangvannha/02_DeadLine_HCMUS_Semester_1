#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int kt_tdx()
{
	int i = 0;
	char c;
	char mang[] = "";
	printf(" \n Nhap so ban muon xac dinh :");
	do
	{
		c = getchar();
		mang[i] = c;
		printf("\t %c", c);
		i++;
	} while (c != '\n');
	--i;
	printf(" \n hien tai tong la : %d", i);
	printf(" \n so ban nhap la : %s", mang);

	/*int chia, j, kt = 1;
	if ((i % 2) == 0)
	{
		chia = (i / 2) -1;
		for (j = 0; j <= chia; j++)
		{
			printf("\n ky tu thu %d va thu %d la %c va %c ", j, i - j, mang[j], mang[i - j]);
			if (mang[j] != mang[i - j])
			{
				kt = 0;
				break;
			}
		}
	}
	printf("\n KT  bang %d ", kt);*/

	/*if (( i%2 ) == 1)
	{
	printf("\n Phan 2");
	chia = (i / 2);
	for (j = 1; j <= chia; j++)
	{

	if (mang[j] == mang[i - j + 1]) kt = 1; else kt = 0;
	}
	}*/

	return kt;
}
void main()
{
	int m;
	m = kt_tdx();
	if (m == 1) printf(" \ So ban nhap co tinh doi xung ");
	else printf("\n So ban nhap khong co tinh doi xung \n");

	_getch();
}