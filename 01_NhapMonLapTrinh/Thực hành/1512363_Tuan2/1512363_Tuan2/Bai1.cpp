#include "conio.h"
#include <stdio.h>
void main()
{
	float a, b, c, d, max, min;
	printf("nhap so thu 1:");
	scanf_s("%f", &a);
	printf("nhap so thu 2:");
	scanf_s("%f", &b);
	printf("nhap so thu 3:");
	scanf_s("%f", &c);
	printf("nhap so thu 4:");
	scanf_s("%f", &d);
	max = min = a;
	if (b >= max)max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	printf("so lon nhat trong bon so ban nap la: %f", max);
	printf("\n so nho nhat trong bon so ban nhap la:%f", min);
	_getch();

}
