#include "stdio.h"
#include "conio.h"
#include "math.h"
int kt_scp(int skt)
{
	int tam=0,kt;
	float can;
	can = sqrt(skt);
	while (tam <= can) tam++;
	tam--;
	if ((can - tam) == 0) kt = 1; else kt = 0;
	return kt;
}
void in_scp(int a, int b)
{
	int i;
	printf("\n Cac so chin phuong trong doan tu %d den %d la :\n", a, b);
	for (i = a; i <= b; i++)
		if (kt_scp(i) == 1) printf(" %d \t ", i);
}
void main()
{
	int luachon, skt, a,b;
menu:
	printf("\n-----------------menu-----------------\n-nhan 1: kiem tra so chin phuong \n-nhan 2: in so chin phuong trong khoang tu a den b\n-lua chon: ");
	scanf_s("%d", &luachon);
	switch (luachon)
	{
	case 1:
		printf("\n Nhap so ban muon kiem tra tinh chin phuong :");
		scanf_s("%d", &skt);
		if (kt_scp(skt) == 1) printf("\n So ban nhap la so chin phuong "); else printf("\n So ban nhap khong phai so chin phuong");
		break;
	case 2:
		printf("\n nhap hai so a va b :");
		scanf_s("%d%d", &a, &b);
		in_scp(a, b);
		break;
	default: printf("\n Ban nhap sai moi nhap lai :");
		break;
	}
	goto menu;
}