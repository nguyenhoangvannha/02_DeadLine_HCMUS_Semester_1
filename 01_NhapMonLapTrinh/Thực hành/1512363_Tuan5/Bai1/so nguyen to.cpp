/*B�i 1. � 1: Vi?t h�m ki?m tra s? nguy�n d??ng n c� ph?i l� s? nguy�n t? hay kh�ng?
		 � 2: S? d?ng h�m n�y vi?t h�m cho ph�p in ra t?t c? c�c s? nguy�n t? b� h?n gi� tr? M cho tr??c.*/

#include "stdio.h"
#include "conio.h"
#include "math.h"
int kt_snt(int skt)//thu?t to�n ki?m tra snt ??t bi?n kt n?u kt=1 th� n l� snt ,kt=0 th� n kh�ng l� snt
{
	int kt=3,tam=0,i;
	float x;
	if (skt == 0 || skt % 2 == 0) kt = 0;		// b1:n?u n = 1 ho?c n chia h?t cho 2 th� n kh�ng l� snt
	if (skt == 2) kt = 1;			//b2:n?u n = 2 th� n l� snt
	x = sqrt(skt);					//b??c ph? :d�ng bi?n t?m ?? l?u gi� tr? nguy�n g?n c?n n nh?t 
	if (kt > 2)						//d�ng t?m ?? ch?y v?ng l?p for ? d??i b3 v�
	{
	
		while (tam <= x) ++tam;
		--tam;
		for (i = 3; i <= tam; i += 2)//b3:cho i l� c�c s? l? ch?y t? 3 ??n s? nguy�n g?n c?n n nh?t(?�y l� nguy�n nh�n d�ng bi?n tam)
		{								//n?u n chia h?t cho i th� n kh�ng s? nguy�n t? v� ng??c l?i
			if ((skt % i) == 0) kt = 0;
			break;
		}
		if (kt > 2) kt = 1;
	}
	return kt;//tr? v? cho h�m kt_snt = kt 
}
void in(int soin)
{
	int i;
	for (i = 2; i < soin; i++)
		if (kt_snt(i) == 1) printf(" \n %d \t", i);//� 2 :cho i ch?y t? 2 ??n  nm n?u i l� snt th� in ra 
}
void main()
{
	int skt, soin,da,luachon;
menu:
	printf("\n------------menu------------\n-nhan 1:kiem tra so nguyen to\n-nhan 2:in day cac so nguyen to\n");
	scanf_s("%d", &luachon);//t?o ra menu n?u ch?n 1 th� th?c hi?n y�u c?u 1 ch?n 2 l�m y�u c?u 2
	switch (luachon)
	{
	case 1: 
		printf("\n Nhap vao so can kiem tra :");
		scanf_s("%d", &skt);
		da = kt_snt(skt);
		if (da == 0) printf("\n Khong la snt");
		if (da == 1) printf("\n La snt");
		break;
	case 2:
		printf("\n Nhap vao so can in day so nguyen to :");
		scanf_s("%d", &soin);
		in(soin);
		break;
	default: printf(" \n Nhap sai moi nhap lai");
	}
	
	goto menu;
	_getch();
}