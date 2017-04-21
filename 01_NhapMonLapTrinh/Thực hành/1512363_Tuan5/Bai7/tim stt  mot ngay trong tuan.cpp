#include "stdio.h"
#include "conio.h"
int kt_nam_nhuan(int nam)
{
	int kt;
	if ((nam % 4) == 0 && (nam % 100) != 0) kt = 1; else kt = 0;
	if ((nam % 400) == 0) kt = 1;
	return kt;
}
int so_ngay(int thu,int tuan, int thang, int nam)
{
	int snth=0;
	switch (1)
	{
	case 1: if (thang == 1) break; snth = 31;
	case 2: if (thang == 2) break;
		if (kt_nam_nhuan(nam) == 1) snth += 29;
		else snth += 28;
	case 3: if (thang == 3) break; snth += 31;
	case 4: if (thang == 4) break; snth += 30;
	case 5: if (thang == 5) break; snth += 31;
	case 6: if (thang == 6) break; snth += 30;
	case 7: if (thang == 7) break; snth += 31;
	case 8: if (thang == 8) break; snth += 31;
	case 9: if (thang == 9) break; snth += 30;
	case 10: if (thang == 10) break; snth += 31;
	case 11: if (thang == 11) break; snth += 30;
	case 12: if (thang == 12) break; snth += 31;
	}
	int s, tang;
	s = (nam - 1) * 365;
	tang = nam / 4;
	snth = snth + tang + s;

	int ntuan;
	ntuan = (tuan - 1) * 7 + (thu - 1);
	snth += ntuan;
	return snth;
}
void main()
{
	int thu, tuan, thang, nam, kq;
menu:

	printf("\n Moi ban nhap ngay trong tuan  vi du thu 3 tuan 4 thang 06 1997 thi nhap 3 4 6 1997: ");
	scanf_s("%d%d%d%d", &thu, &tuan, &thang, &nam);
	if (thu < 2 || thu>8 || tuan < 1 || tuan >4 || thang < 1 || thang >12 || nam < 1)
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	kq = so_ngay(thu,tuan, thang, nam);
	printf("\n STT cua thu %d tuan %d thang %d nam %d tinh tu 1/1/1 la : %d",thu,tuan,thang,nam, kq);
	goto menu;
	_getch();
}