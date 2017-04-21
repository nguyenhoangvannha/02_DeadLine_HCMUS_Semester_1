#include "conio.h"
#include "stdio.h"
void main()
{
	int x,n,i,mau;
	float s=0;
	printf("nhap vao so x=");
	scanf_s("%d",&x);
	printf("nhap vao so n=");
	scanf_s("%d",&n);
	mau=1;
	for (i=2;i<=n;i++)
		{
			s=s+x/mau;
			mau=mau+i;
			x=x*x;

		}
	printf("tong la = %f",s);
	_getch();
}