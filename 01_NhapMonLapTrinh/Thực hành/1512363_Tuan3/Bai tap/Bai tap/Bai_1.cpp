#include "stdio.h"
#include "conio.h"
void main()
{
	int n,i;
	float s;
	s=0;
	printf("nhap vao so n=");
	scanf("%d",&n);
	for(i=1;i<=n;i++)	s=s+1.0*1/(i*(i+1));
	printf("tong la = %f",s);
	getch();
}