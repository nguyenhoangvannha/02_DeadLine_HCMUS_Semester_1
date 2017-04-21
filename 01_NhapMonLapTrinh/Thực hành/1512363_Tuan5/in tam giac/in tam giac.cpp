#include "stdio.h"
#include "conio.h"
void main()
{
	int i, j, k, cao, rong, giua;
menu:

	printf("\n Nhap vao do cao cua hinh(lon hon 2) : ");
	scanf_s("%d",&cao);
	printf("\n Nhap vao be rong (so le lon hon 2) :");
	scanf_s("%d", &rong);
	giua = (rong / 2) + 1;
	printf("\n");
	for (i = 1; i <= rong; i++)
	{
		if (i == giua) printf("*");
		if (i != giua) printf(" ");
		if (i == rong) printf("\n");
	}
	if (cao > 2)
	{
		for (i = 2; i < cao; i++)
			for (j = 1; j <= rong; j++)
			{
				if (j == (giua - i + 1)) printf("*");
				if ((j >(giua - i + 1)) && (i<2) && (j < (giua + i - 2))) printf(" ");
				if ((j > (giua - i + 1)) && (i>2) && (j < (giua + i - 2))) printf("+");
				if (j == (giua + i - 2)) printf("*");
				if ((j < (giua - i +1)) || (j > (giua + i -2 ))) printf(" ");
				if (j == rong) printf("\n");
			}
	}
	for (i = 1; i <= rong; i++)
		printf("*");
	printf("\n");
	for (i = 1; i <= rong; i++)
	{
		if (i == giua) printf("*");
		if (i != giua) printf(" ");
		if (i == rong) printf("\n");
	}
	for (i = 1; i <= rong; i++)
	{
		if(i<(giua - 1) || i >(giua + 1)) printf(" ");
		if (i == (giua-1) || i == (giua + 1)) printf("*");
		if (i == giua) printf("+");
		if (i == rong) printf("\n");
	}
	for (i = 1; i <= rong; i++)
	{
		if (i<(giua - 2) || i >(giua + 3)) printf(" ");
		if (i > (giua - 2) && i <= (giua + 3)) printf("*");
		/*if (i == giua|| i == (giua +1) || i == (giua-1)) printf("+");*/
		if (i == rong) printf("\n");
	}
	goto menu;
	_getch();
}