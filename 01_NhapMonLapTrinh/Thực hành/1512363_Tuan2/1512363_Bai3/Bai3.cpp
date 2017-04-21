#include "stdio.h"
#include "conio.h"
void main()
{
	float scu, smoi, sdien,tien;
	printf("Nhap chi so cu: \n");
	scanf_s("%f", &scu);
	printf("Nhap chi so moi : \n");
	scanf_s("%f", &smoi);
	sdien = smoi - scu;
	if (sdien < 0) printf("Ban nhap sai chi so");
	else
		{
			if (sdien <= 100)	tien = sdien * 1242;
			if (100 < sdien&&sdien <= 150) tien = 100 * 1242 + (sdien - 100) * 1304;
			if (150 < sdien&&sdien <= 200) tien = 100 * 1242 + 50 * 1304 + (sdien - 150) * 1651;
			if (200 < sdien&&sdien <= 300) tien = 100 * 1242 + 50 * 1304 + 50 * 1651 + (sdien - 200) * 1788;
			if (300 < sdien&&sdien <= 400) tien = 100 * 1242 + 50 * 1304 + 50 * 1651 + 100 * 1788 + (sdien - 300) * 1912;
			if (400 < sdien) tien = 100 * 1242 + 50 * 1304 + 50 * 1651 + 100 * 1788 + 100 * 1912 + (sdien - 400) * 1962;
		}
	printf("so tien phai tra la: %f", tien);
	_getch();
}