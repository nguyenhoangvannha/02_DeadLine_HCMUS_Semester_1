#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#define Max 10000
void NhapLaiMang(int A[], int &n)
{
	int i;
	printf("\nNhap so phan tu cua mang :");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nNhap A[%d] : ", i);
		scanf_s("%d", &A[i]);
	}
	printf("\n");
}
void XuatMang(int A[], int n)
{
	int i;
	printf("\n Mang ban nhap: ");
	for (i = 0; i < n; i++) printf(" %d ", A[i]);
	printf("\n");
}
int KTSoNguyenTo(int a)
{
	int kt = 1,x,i;
	double can;
	if (a == 0 || a % 2 == 0||a==1) kt = 0;
	if (a == 2) kt = 1;
	can = sqrt(a);
	x = (int)can;
	for (i = 3; i <= x;i+=2)
		if (a%x == 0)
		{
			kt = 0;
			break;
		}
	return kt;
}
void LietKeSNT(int A[],int n)
{
	int i;
	printf("\n Cac so nguyen to co trong mang gom : \n");
	for (i = 0; i < n; i++) if (KTSoNguyenTo(A[i])==1) printf("\t %d",A[i]);
	printf("\n");
}
void KiemTra(int A[], int n)
{
	int kt=0,i,x;
	printf("\n Nhap so can kiem tra : ");
	scanf_s("%d", &x);
	for (i = 0; i < n; i++) if (x == A[i])
	{
		kt = 1;
		break;
	}
	if (kt == 1) printf("\n So %d thuoc mang.\n ", x); else printf("\n So %d khong thuoc mang.\n", x);
}
int KTSoHoanThien(int a)
{
	int kt=1, tong=0, i;
	for (i = 1; i < a; i++)
		if (a%i == 0) tong += i;
	if (tong > a) kt = 0;
	return kt;
}
void HoanThienMax(int A[], int n)
{
	int max = 3 , i;
	for (i = 0; i < n; i++)
	{
		if (KTSoHoanThien(A[i]) == 1 && (A[i]>max)) max = A[i];
	}
	if (max != 3)	printf("\n So hoan thien lon nhat la : %d \n", max); else printf("\n Mang ban nhap khong co so hoan then nao!\n");
}
int KTSoDoiXung(int a)
{
	int b=0,tam=a,kt=0;
	while (tam != 0)
	{
		b = b * 10 + (tam % 10);
		tam /= 10;
	}
	if (a == b&& a > 9) kt = 1;
	return kt;
}
void TongSoDoiXung(int A[], int n)
{
	int i, Tong=0;
	for (i = 1; i < n; i++)
	{
		if (KTSoDoiXung(A[i]) == 1) Tong += A[i];
	}
	if (Tong != 0) printf("\n Tong cac so doi xung la : %d \n", Tong); else printf("\n Mang ban nhap khong co so doi xung nao\n");
}
void SoLuongSoMax(int A[], int n)
{
	int i, soluong=0,max=0;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			soluong = 0;
		}
		if (A[i] == max) soluong++;
	}
	printf("\nSo luong so lon nhat la : %d \n", soluong);
}
int KTSoChinPhuong(int a)
{
	float can;
	int i,kt=1;
	can = sqrt(a);
	i = (int)can;
	if ((can - i) != 0) kt = 0;
	return kt;
}
void TBCongSoChinhPhuong(int A[], int n)
{
	int i, SoSCP=0, tong=0;
	float TBC;
	for (i = 0; i < n; i++)
		if (KTSoChinPhuong(A[i]) == 1)
		{
			SoSCP++;
			tong += A[i];
		}
	TBC = tong / SoSCP;
	printf("\n TB cong cac so chin phuong la : %f ", TBC);
}
void main()
{
	int A[Max] = {1,7,5,6,4,81,6,9,9,6};
	int n=10, chon;
menu:
	printf("\n -----------------------------------------------------------------------------");
	printf("\n\n\t=========== Menu ============\n\t1. Nhap lai mang.\n\t2. Xuat mang.\n\t3. Liet ke cac so nguyen to co trong mang.\n");
	printf("\t4. Kiem tra gia tri x co thuoc mang hay khong.\n\t5. Tim gia tri hoan thien lon nhat.");
	printf("\n\t6. Tinh tong cac so doi xung co trong mang.\n\t7. Dem so luong so lon nhat trong mang.\n\t8. TB con cac so chin phuong trong mang");
	printf("\n\t9. Thoat.\n\t== == == == == == == == == == == == ==\n\t\tChon :");
	scanf_s("%d",&chon);
	switch (chon)
		{
		case 1: NhapLaiMang(A, n); break;
		case 2: XuatMang(A, n); break;
		case 3: LietKeSNT(A, n); break;
		case 4: KiemTra(A, n); break;
		case 5: HoanThienMax(A, n); break;
		case 6: TongSoDoiXung(A, n); break;
		case 7: SoLuongSoMax(A, n); break;
		case 8: TBCongSoChinhPhuong(A, n); break;
		case 9: exit(0); 
		default: printf("\n Ban nhap sai moi nhap lai "); goto menu;
		}
	printf("\n -----------------------------------------------------------------------------");
	_getch();
}