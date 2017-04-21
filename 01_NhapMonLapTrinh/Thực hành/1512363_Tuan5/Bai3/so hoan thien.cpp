// so hoan thien n la so co tong cac uoc so cua n be hon n 
//yeu cau 1: kiem tra mot so co phai la so hoan thien hay khong 
// yeu cau 2: in ra tat ca cac so hoan thien be hon so m cho truoc
#include "stdio.h"
#include "conio.h"
int kt_sht(int skt)
{
	int kt,s=0, i;
	for (i = 1; i < skt; i++)
	{
		if ((skt % i) == 0) s += i;
		// printf("\ni bang : %d \t  S bang %d \n",i , s); dung de kiem tra 
	}
		
	if (s <= skt) kt = 1; else kt = 0;
	return kt;
}
void in_sht(int gioihan)
{
	int i;
	for (i = 2; i < gioihan; i++) if ((kt_sht(i)) == 1) printf(" %d \t ",i);
}
void main()
{
	int luachon, skt, m;
menu:
	printf("\n -------------menu--------------\n-nhan 1: kiem tra so hoan thien\n-nhan 2: in cac so hoan thien nho hon mot so bat ky \n-lua chon cua ban: ");
	scanf_s("%d", &luachon);
	switch (luachon)
	{
	case 1: 
		printf("\n Nhap so can kiem tra :");
		scanf_s("%d", &skt);
		if ((kt_sht(skt)) == 1) printf("\n So ban nhap la so hoan thien \n"); else printf("\n So ban nhap khong phai so hoan thien \n");
		break;
	case 2:
		printf("\n Nhap so gioi han m :");
		scanf_s("%d", &m);
		in_sht(m);
		break;
	default: printf("\n Nhap sai moi nhap lai ");
		break;
	}
	goto menu;
}