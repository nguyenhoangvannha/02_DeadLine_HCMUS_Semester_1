/*Bài 1. ý 1: Vi?t hàm ki?m tra s? nguyên d??ng n có ph?i là s? nguyên t? hay không?
		 ý 2: S? d?ng hàm này vi?t hàm cho phép in ra t?t c? các s? nguyên t? bé h?n giá tr? M cho tr??c.*/

#include "stdio.h"
#include "conio.h"
#include "math.h"
int kt_snt(int skt)//thu?t toán ki?m tra snt ??t bi?n kt n?u kt=1 thì n là snt ,kt=0 thì n không là snt
{
	int kt=3,tam=0,i;
	float x;
	if (skt == 0 || skt % 2 == 0) kt = 0;		// b1:n?u n = 1 ho?c n chia h?t cho 2 thì n không là snt
	if (skt == 2) kt = 1;			//b2:n?u n = 2 thì n là snt
	x = sqrt(skt);					//b??c ph? :dùng bi?n t?m ?? l?u giá tr? nguyên g?n c?n n nh?t 
	if (kt > 2)						//dùng t?m ?? ch?y v?ng l?p for ? d??i b3 vì
	{
	
		while (tam <= x) ++tam;
		--tam;
		for (i = 3; i <= tam; i += 2)//b3:cho i là các s? l? ch?y t? 3 ??n s? nguyên g?n c?n n nh?t(?ây là nguyên nhân dùng bi?n tam)
		{								//n?u n chia h?t cho i thì n không s? nguyên t? và ng??c l?i
			if ((skt % i) == 0) kt = 0;
			break;
		}
		if (kt > 2) kt = 1;
	}
	return kt;//tr? v? cho hàm kt_snt = kt 
}
void in(int soin)
{
	int i;
	for (i = 2; i < soin; i++)
		if (kt_snt(i) == 1) printf(" \n %d \t", i);//ý 2 :cho i ch?y t? 2 ??n  nm n?u i là snt thì in ra 
}
void main()
{
	int skt, soin,da,luachon;
menu:
	printf("\n------------menu------------\n-nhan 1:kiem tra so nguyen to\n-nhan 2:in day cac so nguyen to\n");
	scanf_s("%d", &luachon);//t?o ra menu n?u ch?n 1 thì th?c hi?n yêu c?u 1 ch?n 2 làm yêu c?u 2
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