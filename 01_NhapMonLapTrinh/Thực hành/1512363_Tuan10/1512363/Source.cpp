#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "stdlib.h"
typedef int MANG2D[100][100];
void Nhap(MANG2D a, int &d, int &c)
{
	printf("\nNhap so dong: ");
	scanf_s(" %d", &d);
	printf("\nNhap so cot: ");
	scanf_s("%d", &c);
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			printf(" \nNhap phan tu thu [%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
}
void Xuat(MANG2D a, int d, int c)
{
	printf("\nNoi dung ma tran:\n");
	for (int i = 0; i < d; i++)
	{
			for (int j = 0; j < c; j++)
				printf(" \t %d ", a[i][j]);
		printf("\n");
	}
}
int KTSoNguyenTo(int a)
{
	int kt = 1, x, i;
	double can;
	if (a == 0 || a % 2 == 0 || a == 1) kt = 0;
	if (a == 2) kt = 1;
	can = sqrt(a);
	x = (int)can;
	for (i = 3; i <= x; i += 2)
		if (a%x == 0)
		{
			kt = 0;
			break;
		}
	return kt;
}
void lietke_dongchuasnt(MANG2D a, int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (KTSoNguyenTo(a[i][j]) == 1)
			{
				printf("\nDong thu %d co so nguyen to.", i + 1);
				break;
			}
}
void lietke_tongcotsole(MANG2D a, int d, int c)
{
	int s=0;
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < d; i++) s = s + a[i][j];
		if (s % 2 == 1) printf("\n Cot thu %d co tong le.", j + 1);
		s = 0;
	}
}
void timmaxcot(MANG2D a, int d,int c)
{
	int cot,max;
menu1:
	printf("\n Nhap vao cot muon tim : ");
	scanf_s("%d",&cot);
	if (cot >= c || cot < 0) goto menu1;
	else
	{
		max = a[0][cot];
		for (int i = 1; i < d; i++)
			if (a[i][cot]>max) max = a[i][cot];
	}
	printf("\nSo lon nhat cua cot %d la: %d", cot, max);
}
int timmaxdong(MANG2D a, int d, int c,int dong)
{
	int  max;
	max = a[dong][0];
	for (int i = 1; i < d; i++)
		if (a[dong][i]>max) max = a[dong][i];
	return max;
}
void trungbinh_maxdong(MANG2D a, int d, int c)
{
	int tong = 0;
	float trungbinh;
	for (int i = 0; i < d; i++)
		tong += timmaxdong(a, d, c, i);
	trungbinh = tong / d;
	printf("\n gia tri trung binh cua cac gia tri lon nhat tren cac dong la : %0.1f",trungbinh);
}
void swap(MANG2D a, int cot, int i, int j)
{
	int tam;
	tam = a[i][cot];
	a[i][cot] = a[j][cot];
	a[j][cot] = tam;
}
void quicksortdong(MANG2D a, int d,int c,int cot)
{
	int x = a[(0 + d - 1) / 2][cot];
	int i = 0, j = d-1;
	do
	{
		while (a[i][cot] < x) i++;
		while (a[j][cot] > x) j--;
		if (i <= j)
		{
			swap(a,cot, i, j);
			i++;
			j--;
		}
	} while (i < j);
	if (0 < j)quicksortdong(a, 0, j,cot);
	if (i < d) quicksortdong(a, i, d,cot);
}
void quicksortcot(MANG2D a, int d, int c, int dong)
{
	int x = a[(0 + c) / 2][0];
	int i = 0, j = c - 1;
	do
	{
		while (a[dong][i] < x) i++;
		while (a[dong][j] > x) j--;
		if (i <= j)
		{
			swap(a, dong, i, j);
			i++;
			j--;
		}
	} while (i < j);
	if (0 < j)quicksortdong(a, 0, j, dong);
	if (i < c) quicksortdong(a, i, c, dong);
}
void cau7(MANG2D a, int d, int c)
{
	quicksortdong(a, d, c, 0);
	quicksortdong(a, d, c, c - 1);
	quicksortcot(a, d, c, 0);
	quicksortcot(a, d, c, d - 1);
}
int KTMT_vuong(MANG2D a, int d, int c)
{
	int kt=0;
	if (d == c)
	{
		kt = 1;
		printf("\n Ma tran nay vuong!");
	}
	else printf("\n Ma tran nay khong vuong!");
	return kt;
}
int TinhTong(MANG2D a, int d, int c)
{
	int tong = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			tong += a[i][j];
	return tong;
}
void tinhtong2matranvuong()
{
	MANG2D X, Y;
	int tong;
	int d1, d2, c1, c2;
	Nhap(X, d1, c1);
	Nhap(Y, d2, c2);
	tong = TinhTong(X, d1, c1) + TinhTong(Y, d2, c2);
	printf("\n Tong hai ma tran vuong ban nhap la: %d", tong);
}
void tong_duongcheochinh(MANG2D a, int d, int c)
{
	int s = 0;

	if (KTMT_vuong(a, d, c) == 1)
	{
		for (int i = 0; i < d; i++)
			s += a[i][i];
		printf("\n Tong tren duong cheo chinh la: %d", s);
	}
	else printf("\n Ma tran ban nhap khong phai ma tran vuong");
}
void TBcongduongcheophu(MANG2D a, int d, int c)
{
	int i, s = 0, dong = 0;
	float tb;
	if (KTMT_vuong(a, d, c) == 1)
	{
		for (int i = (c - 1); i >= 0; i--)
		{
			s += a[dong][i];
			dong++;
		}
		tb = s / d;
		printf("\n Trung binh cong cua cac phan tu tren duong cheo phu cua ma tran vuong la %f", tb);
	}
	else printf("\n Ma tran nay khong vuong.");
}
void main()
{
	MANG2D a;
	int chon, d, c;

menu:
	printf("\n== == == == == == == Menu == == == == == == == =\n1.Nhap lai ma tran");
	printf("\n2.Xuat ma tran\n3.Liet ke cac chi so dong chua so nguyen to");
	printf("\n4.Liet ke cac chi so cot co tong gia tri tren cot la mot so le\n5.Tim gia tri lon nhat cua cot c nhap tu ban phim");
	printf("\n6.Tim gia tri trung binh cua cac gia tri lon nhat tren cac dong");
	printf("\n7.Sap xep cac phan tu tren duong bien cua ma tran tang dan\n8.Kiem tra ma tran co vuong khong");
	printf("\n9.Nhap hai ma tran vuong cung cap,tinh tong hai ma tran");
	printf("\n10.Tinh tong cac gia tri tren duong cheo chinh cua ma tran vuong");
	printf("\n11.Tinh trung binh cong cua cac phan tu tren duong cheo phu cua ma tran vuong");
	printf("\n12.Tinh tong cac phan tu thuoc tam giac tren cua ma tran vuong");
	printf("\n13.Sap xep tang dan cac phan tu tren duong cheo chinh cua ma tran vuong\n14.Thoat");
	printf("\n== == == == == == == == == == == == == == == == == ==\n\tChon: ");
	scanf_s("%d", &chon);
	switch (chon)
	{
	case 1: Nhap(a, d, c); break;
	case 2: Xuat(a, d, c); break;
	case 3: lietke_dongchuasnt(a, d, c); break;
	case 4: lietke_tongcotsole(a, d, c); break;
	case 5: timmaxcot(a, d, c); break;
	case 6: trungbinh_maxdong(a, d, c); break;
	case 7: cau7(a, d, c); break;
	case 8:KTMT_vuong(a, d, c); break;
	case 9: tinhtong2matranvuong(); break;
	case 10: tong_duongcheochinh(a, d, c); break;
	case 11: TBcongduongcheophu(a, d, c); break;
	case 14: exit(0);
	default: printf("\n Ban nhap sai moi nhap lai"); goto menu;
	}
	goto menu;
}
/*
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "stdlib.h"
typedef int MANG2D[100][100];
void Nhap(MANG2D a, int &d, int &c)
{
printf("\nNhap so dong: ");
scanf_s(" %d", &d);
printf("\nNhap so cot: ");
scanf_s("%d", &c);
for (int i = 0; i < d; i++)
for (int j = 0; j < c; j++)
{
printf(" \na[%d][%d] = ", i, j);
scanf_s("%d", &a[i][j]);
}
}
void Xuat(MANG2D a, int d, int c)
{
printf("\nNoi dung ma tran:\n");
for (int i = 0; i < d; i++)
{
for (int j = 0; j < c; j++)
printf(" \t %d ", a[i][j]);
printf("\n");
}
}
int KTSoNguyenTo(int a)
{
int kt = 1, x, i;
double can;
if (a == 0 || a % 2 == 0 || a == 1) kt = 0;
if (a == 2) kt = 1;
can = sqrt(a);
x = (int)can;
for (i = 3; i <= x; i += 2)
if (a%x == 0)
{
kt = 0;
break;
}
return kt;
}
void lietke_dongchuasnt(MANG2D a, int d, int c)
{
for (int i = 0; i < d; i++)
for (int j = 0; j < c; j++)
if (KTSoNguyenTo(a[i][j]) == 1)
{
printf("\nDong thu %d co so nguyen to.", i + 1);
break;
}
}
void lietke_tongcotsole(MANG2D a, int d, int c)
{
int s = 0;
for (int j = 0; j < c; j++)
{
for (int i = 0; i < d; i++) s = s + a[i][j];
if (s % 2 == 1) printf("\n Cot thu %d co tong le.", j + 1);
s = 0;
}
}
void timmaxcot(MANG2D a, int d, int c)
{
int cot, max;
menu1:
printf("\n Nhap vao cot muon tim : ");
scanf_s("%d", &cot);
if (cot >= c || cot < 0) goto menu1;
else
{
max = a[0][cot];
for (int i = 1; i < d; i++)
if (a[i][cot]>max) max = a[i][cot];
}
printf("\nSo lon nhat cua cot %d la: %d", cot, max);
}
int timmaxdong(MANG2D a, int d, int c, int dong)
{
int  max;
max = a[dong][0];
for (int i = 1; i < d; i++)
if (a[dong][i]>max) max = a[dong][i];
return max;
}
void trungbinh_maxdong(MANG2D a, int d, int c)
{
int tong = 0;
float trungbinh;
for (int i = 0; i < d; i++)
tong += timmaxdong(a, d, c, i);
trungbinh = tong / d;
printf("\n gia tri trung binh cua cac gia tri lon nhat tren cac dong la : %0.1f", trungbinh);
}
void swap(MANG2D a, int cot, int i, int j)
{
int tam;
tam = a[i][cot];
a[i][cot] = a[j][cot];
a[j][cot] = tam;
}
void quicksortdong(MANG2D &a, int d, int c, int cot)
{
int x = a[(0 + d - 1) / 2][cot];
int i = 0, j = d - 1;
do
{
while (a[i][cot] < x) i++;
while (a[j][cot] > x) j--;
if (i <= j)
{
swap(a, cot, i, j);
i++;
j--;
}
} while (i < j);
if (0 < j)quicksortdong(a, 0, j, cot);
if (i < d) quicksortdong(a, i, d, cot);
}
void quicksortcot(MANG2D &a, int d, int c, int dong)
{
int x = a[(0 + c) / 2][0];
int i = 0, j = c - 1;
do
{
while (a[dong][i] < x) i++;
while (a[dong][j] > x) j--;
if (i <= j)
{
swap(a, dong, i, j);
i++;
j--;
}
} while (i < j);
if (0 < j)quicksortdong(a, 0, j, dong);
if (i < c) quicksortdong(a, i, c, dong);
}
void cau7(MANG2D &a, int d, int c)
{
quicksortdong(a, d, c, 0);
quicksortdong(a, d, c, c - 1);
quicksortcot(a, d, c, 0);
quicksortcot(a, d, c, d - 1);
}
int KTMT_vuong(MANG2D a, int d, int c)
{
int kt = 0;
if (d == c)
{
kt = 1;
printf("\n Ma tran nay vuong!");
}
else printf("\n Ma tran nay khong vuong!");
return kt;
}
int TinhTong(MANG2D a, int d, int c)
{
int tong = 0;
for (int i = 0; i < d; i++)
for (int j = 0; j < c; j++)
tong += a[i][j];
return tong;
}
void tinhtong2matranvuong()
{
MANG2D X, Y;
int tong;
int d1, d2, c1, c2;
Nhap(X, d1, c1);
Nhap(Y, d2, c2);
tong = TinhTong(X, d1, c1) + TinhTong(Y, d2, c2);
printf("\n Tong hai ma tran vuong ban nhap la: %d", tong);
}
void main()
{
MANG2D a;
int chon, d, c;
menu:
printf("\n== == == == == == == Menu == == == == == == == =\n1.Nhap lai ma tran");
printf("\n2.Xuat ma tran\n3.Liet ke cac chi so dong chua so nguyen to");
printf("\n4.Liet ke cac chi so cot co tong gia tri tren cot la mot so le\n5.Tim gia tri lon nhat cua cot c nhap tu ban phim");
printf("\n6.Tim gia tri trung binh cua cac gia tri lon nhat tren cac dong");
printf("\n7.Sap xep cac phan tu tren duong bien cua ma tran tang dan\n8.Kiem tra ma tran co vuong khong");
printf("\n9.Nhap hai ma tran vuong cung cap,tinh tong hai ma tran");
printf("\n10.Tinh tong cac gia tri tren duong cheo chinh cua ma tran vuong");
printf("\n11.Tinh trung binh cong cua cac phan tu tren duong cheo phu cua ma tran vuong");
printf("\n12.Tnh tong cac phan tu thuoc tam gac tren cua ma tran vuong");
printf("\n13.Sap xep tang dan cac phan tu tren duong cheo chinh cua ma tran vuong\n14.Thoat");
printf("\n== == == == == == == == == == == == == == == == == ==\n\tChon: ");
scanf_s("%d", &chon);
switch (chon)
{
case 1: Nhap(a, d, c); break;
case 2: Xuat(a, d, c); break;
case 3: lietke_dongchuasnt(a, d, c); break;
case 4: lietke_tongcotsole(a, d, c); break;
case 5: timmaxcot(a, d, c); break;
case 6: trungbinh_maxdong(a, d, c); break;
case 7: cau7(a, d, c); break;
case 8:KTMT_vuong(a, d, c); break;
case 9:
case 14: exit(0);
default: printf("\n Ban nhap sai moi nhap lai"); goto menu;
}
goto menu;
}
*/