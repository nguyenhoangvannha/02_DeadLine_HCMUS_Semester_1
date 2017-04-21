#include "stdio.h"
#include "conio.h"
int kt_nam_nhuan(int nam)
{
	int kt;
	if ((nam % 4) == 0 && (nam % 100) != 0) kt = 1; else kt = 0;
	if ((nam % 400) == 0) kt = 1;
	return kt;
}
int so_ngay(int ngay, int thang, int nam)
{
	int snth;
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
	snth += ngay;
	int s, tang;
	s = (nam - 1) * 365;
	tang = nam / 4;
	snth = snth + tang + s;
	return snth;
}
void main()
{
	int ngay, thang, nam, kq;
menu:

	printf("\n Moi ban nhap ngay thang nam vi du 12 06 1997 : ");
	scanf_s("%d%d%d", &ngay, &thang, &nam);
	if (ngay<1 || ngay > 31 || thang < 1 || thang >12 || nam < 1)//tu dong nay de kiem tra cach nhap dung hay sai
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	if (kt_nam_nhuan(nam) ==1 && ngay >29 ) //neu nam ban nhap la nam nhuan ma ban nhap ngay nho hon 29 thi ban nhap sai vi thang 2 co it ngay nhat = 29
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	if (kt_nam_nhuan(nam) == 0 && ngay >28)//neu nam ban nhap khong phai la nam nhuan ma ban nhap ngay nho hon 29 thi ban nhap sai vi thang 2 co it ngay nhat = 28
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}//ket thuc viec kiem tra cah nhap
	kq = so_ngay(ngay, thang, nam);
	printf("\n STT cua ngay ban nhap tinh tu 1/1/1 la : %d", kq);
	goto menu;
	_getch();
}