#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void main()
{
	int s = -1,i=0;
	char c;
	char mang[33]="";
	printf(" \n Nhap so ban muon xac dinh :");
	do
	{
		c = getchar();
		mang[i] = c;
		i++;
	} 
	while (c != '\n');
	--i;
	printf(" \n hien tai tong la : %d",i);
	printf(" \n so ban nhap la : %s", mang);
	
	_getch();
	// da co s va mangso
}
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
int kt_cachnhap(int n, int t, int nam)
{

}
void main()
{
	int ngay1, thang1, nam1, kq1;
	int ngay2, thang2, nam2, kq2;
	int kq;
menu:

	printf("\n Moi ban nhap ngay thang nam thu nhat vi du 12 06 1997  : ");
	scanf_s("%d%d%d", &ngay1, &thang1, &nam1);
	printf("\n Moi ban nhap ngay thang nam thu hai vi du 17 05 1997  : ");
	scanf_s("%d%d%d", &ngay2, &thang2, &nam2);
	printf("\n ban nhap : %d %d %d va %d %d %d ", ngay1, thang1, nam1, ngay2, thang2, nam2);
	if (ngay1<1 || ngay1 > 31 || thang1 < 1 || thang1 >12 || nam1 < 1)//tu dong nay de kiem tra cach nhap mot dung hay sai
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	if (kt_nam_nhuan(nam1) == 1 && ngay1 >29) //neu nam ban nhap la nam nhuan ma ban nhap ngay nho hon 29 thi ban nhap sai vi thang 2 co it ngay nhat = 29
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	if (kt_nam_nhuan(nam1) == 0 && ngay1 >28)//neu nam ban nhap khong phai la nam nhuan ma ban nhap ngay nho hon 29 thi ban nhap sai vi thang 2 co it ngay nhat = 28
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}//ket thuc viec kiem tra cah nhap

	if (ngay2<1 || ngay2 > 31 || thang2 < 1 || thang2 >12 || nam2 < 1)//tu dong nay de kiem tra cach nhap  hai dung hay sai
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	if (kt_nam_nhuan(nam2) == 2 && ngay2 <29) //neu nam ban nhap la nam nhuan ma ban nhap ngay nho hon 29 thi ban nhap sai vi thang 2 co it ngay nhat = 29
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}
	if (kt_nam_nhuan(nam2) == 0 && ngay2 <28)//neu nam ban nhap khong phai la nam nhuan ma ban nhap ngay nho hon 29 thi ban nhap sai vi thang 2 co it ngay nhat = 28
	{
		printf("\n Ban nhap sai moi nhap lai \n ");
		goto menu;
	}//ket thuc viec kiem tra cah nhap

	kq1 = so_ngay(ngay1, thang1, nam1);
	kq2 = so_ngay(ngay2, thang2, nam2);
	kq = kq2 - kq1;
	if (kq < 0) kq = -kq;
	printf("\n khoang canh giua hai ngayla : %d", kq);
	goto menu;
	_getch();
}