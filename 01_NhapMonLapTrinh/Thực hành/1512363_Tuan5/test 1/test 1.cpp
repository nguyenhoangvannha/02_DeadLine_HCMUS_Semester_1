#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void main()
{
	int s = -1, i = 0;
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

	int chia, j, kt = 1;
	if ((i % 2) == 0)
	{
		chia = i / 2;
		for (j = 0; j <= (chia-1); j++)
		{
			printf("\n i-j bang %d", i - j);
			printf("\n mang[j] va  mang[i-j] bang %c va %c", mang[i - j]);
			printf("\n ky tu thu %d va thu %d la %c va %c ", j, i - j+1, mang[j], mang[i-j+1]);
			if (mang[j] != mang[i - j +1])
			{
				kt = 0;
			}
		}
	}
	printf("\n KT  bang %d ", kt);

	/*if (( i%2 ) == 1)
	{
	printf("\n Phan 2");
	chia = (i / 2);
	for (j = 1; j <= chia; j++)
	{

	if (mang[j] == mang[i - j + 1]) kt = 1; else kt = 0;
	}
	}*/

	_getch();
}
