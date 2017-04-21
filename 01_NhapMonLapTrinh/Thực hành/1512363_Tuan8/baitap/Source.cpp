#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "windows.h"
#include "time.h"
#define MAX 100
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void NhapMang(int A[], int &n)
{
	printf("\n Nhap so phan tu cua mang : ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap phan tu thu %d : ", i + 1);
		scanf_s("%d", &A[i]);
	}
}
void XuatMang(int A[], int n)
{
	srand(time(NULL));
	printf("\n\t Cac phan tu cua mang: ");
	for (int i = 0; i < n; i++)
	{
		TextColor((rand() % (256 - 1 + 1)) + 1);
		printf("\t %d", A[i]);
	}

}
void KT_TinhChatSong(int A[], int n)
{
	int i = 0, kt = 1;
	if (n == 1 || n == 2)  kt = 0;
	if (n == 3 && ~(A[i] < A[i++]) && ~(A[i++] > A[i + 2])) kt = 0;
	if (n == 3 && ~(A[i] > A[i++]) && ~(A[i++] < A[i + 2])) kt = 0;
	if (n>3)
		for (i = 1; i < (n - 2); i++)
		{
			if (((A[i - 1]<A[i]) && (A[i + 1]<A[i])) || ((A[i - 1]>A[i]) && (A[i + 1]>A[i])))  kt = 1;
			else { kt = 0; break; }
		}
	if (kt == 0) printf("\n Mang khong co tinh chat song "); else printf("\n Mang co tinh chat song ");
}
int kt_snt(int skt)
{
	int kt = 3, tam = 0, i;
	float x;
	if (skt == 0 || skt % 2 == 0 || skt == 1) kt = 0;
	if (skt == 2) kt = 1;
	x = sqrt(skt);
	if (kt > 2)
	{
		tam = (int)x;
		for (i = 3; i <= tam; i += 2)
		{
			if ((skt % i) == 0) kt = 0;
			break;
		}
		if (kt > 2) kt = 1;
	}
	return kt;
}
void KT_SNT_Trong_Mang(int A[], int n, int &SoSNT)
{
	int kt = 0;
	SoSNT = 0;
	for (int i = 0; i < n; i++) if (kt_snt(A[i]) == 1) { kt = 1;  SoSNT++; printf("\n snt : %d ", A[i]); };
	if (kt == 1) printf("\n Trong mang co SNT "); else printf("\n Trong mang khong co SNT");
}
void Xoa_SNT(int A[], int &n)
{
	int i = 0, j;
	while (kt_snt(A[n - 1]) == 1)
	{
		n--;
	}
	while (i < (n - 1))
	{
		if (kt_snt(A[i]) == 1)
		{
			for (j = i; j < n; j++) A[j] = A[j + 1];
			n--;
		}
		if (kt_snt(A[i]) == 0) i++;
	}
}
void ChenSo(int A[], int &n, int vitri, int so)
{
	n++; int i;
	for (i = (n - 1); i > vitri; i--) A[i] = A[i - 1];
	A[vitri] = so;
}
void AmDuong(int A[], int &n)
{
	int i = 0;
	while (i<(n - 1))
	{
		if ((A[i] >= 0) && (A[i + 1] >= 0)) ChenSo(A, n, i + 1, -1);
		if ((A[i] < 0) && (A[i + 1] < 0)) ChenSo(A, n, i + 1, 1);
		if (A[i] * A[i + 1] < 0) i++;
	}
	printf("\n Mang sau khi chen :"); XuatMang(A, n);
}
void swap(int A[], int i, int j)
{
	int tam;
	tam = A[i];
	A[i] = A[j];
	A[j] = tam;
}
void quicksorttang(int A[], int L, int R)
{
	int x = A[(L + R) / 2];
	int i = L, j = R;
	do
	{
		while (A[i] < x) i++;
		while (A[j] > x) j--;
		if (i <= j)
		{
			swap(A, i, j);
			i++;
			j--;
		}
	} while (i < j);
	if (L < j)quicksorttang(A, L, j);
	if (i < R) quicksorttang(A, i, R);
}
void quicksortgiam(int A[], int L, int R)
{
	int x = A[(L + R) / 2];
	int i = L, j = R;
	do
	{
		while (A[i] > x) i++;
		while (A[j] < x) j--;
		if (i <= j)
		{
			swap(A, i, j);
			i++;
			j--;
		}
	} while (i < j);
	if (L < j)quicksortgiam(A, L, j);
	if (i < R) quicksortgiam(A, i, R);
}
void chanle(int A[])
{
	int i = 0, j = 9;
	while (i < j)
	{
		while ((A[i] % 2) == 0)  i++;
		while ((A[j] % 2) != 0)  j--;
		if (i <= j) swap(A, i, j);
		i++;
		j--;
	}
}
void Xep_Chan_Le(int A[], int n, int &vitricl)
{
	chanle(A);
	int i = 0;
	while (A[i] % 2 == 0) i++;
	vitricl = i;
	quicksorttang(A, 0, i - 1);
	quicksortgiam(A, i, n - 1);
}
void Chen(int A[], int &n, int vitricl)
{
	Xep_Chan_Le(A, n, vitricl);
	printf("\n Mang ban dau : "); XuatMang(A, n);
	int x, chan = 0, le = vitricl + 1;
	n++;
	printf("\n Nhap so ban muon chen : ");
	scanf_s("%d", &x);
	if (x % 2 == 0)
	{
		while (A[chan] < x) chan++;
		ChenSo(A, n, chan, x);
		n--;
	}
	if (x % 2 == 1)
	{
		while (A[le] > x) le++;
		ChenSo(A, n, le, x);
		n--;
	}
	printf("\n Mang sau khi chen : ");  XuatMang(A, n);
}
int next[12061997];
int dump[12061997];
int rslt[12061997];

int lis(int A[], int n) {
	int r = 0, i, j;
	for (i = 1; i <= n; i++)
		if (r == 0 || A[i]>A[dump[r]]) { next[i] = (r == 0 ? 0 : dump[r]); dump[++r] = i; }
		else {
			int ll = 1, rr = r, j = (ll + rr) / 2;
			while (ll != j && j != rr) {
				if (A[i] <= A[dump[j]]) rr = j;
				else ll = j;
				j = (ll + rr) / 2;
			}
			for (j = ll; j <= rr; j++) {
				if (A[i] <= A[dump[j]])
				{
					next[i] = dump[j - 1]; dump[j] = i; break;
				}
			}
		}

		j = r;
		for (i = dump[r]; i != 0; i = next[i]) rslt[j--] = i;
		return r;
}

void in(int A[], int n)
{
	int i;
	int r = lis(A, n);
	printf("%d\n", r);
	printf("\n");
	for (i = 1; i <= r; i++)
		printf("%d\t", A[rslt[i]]);
}
void DaoMang(int a[], int &n, int dao[])
{
	int nb = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		dao[nb] = a[i];
		nb++;
	}
}
void DayConTangDaiNhat(int a[], int n, int dao[], int &nb)
{
	int k, pre[MAX], l[MAX], b[MAX];
	for (int i = 0; i < n; i++)
		pre[i] = -1; //
	for (int i = 0; i < n; i++)
	{
		l[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[i] > a[j] && l[j] + 1 > l[i])
			{
				l[i] = l[j] + 1;
				pre[i] = j;
			}
	}
	k = 0;
	for (int j = 0; j < n; j++)
		if (l[j] > l[k])
			k = j;
	nb = 0;
	while (k != -1)
	{
		b[nb] = a[k];
		nb++;
		k = pre[k];
	}
	DaoMang(b, nb, dao);
	printf("\n");
}

void main()
{
	//TextColor(253);
	const int MAX = 10;
	int A[MAX] = { 1,5,3,16,5,14,7,91,9,1 },
		B[MAX] = {};
	int n = MAX, chon, SoSNT, vitricl = 0;
	printf("\n\t== == == == == == == == == == == == Menu == == == == == == == == == == == ==");
	printf("\n\t\t1.Nhap lai mang\n\t\t2.Xuat Mang\n\t\t3.Kiem tra mang co tinh chat song hay khong");
	printf("\n\t\t4.Kiem tra mang co so nguyen to khong\n\t\t5.Xoa tat ca cac so nguyen to co trong mang");
	printf("\n\t\t6.Chen cac phan tu -1 va 1 de mang co tinh chat am duong xen ke");
	printf("\n\t\t7.Xep mang sao cho cac so chan tang dan so le giam dan");
	printf("\n\t\t8.Chen mot phan tu x(Nhap vao tuban phim) \n\t\tsao cho van du duoc tinh chat tang/giam cua mang");
	printf("\n\t\t9.Tao mang b tu mang a sao cho cac phan tu cua mang b\n\t\t  duoc xep tang dan ma van du duoc thu tu cac phan tu\n\t\t  trong mang a va so luong phan tu cua mang b la nheu nhat ");
	printf("\n\t\t10.Thoat");
menu:
	printf("\n\t== == == == == == == == == == == == $$$$ == == == == == == == == == == == ==\n\t\t\tChon: ");
	scanf_s("%d", &chon);
	switch (chon)
	{
	case 1: NhapMang(A, n); goto menu;
	case 2: XuatMang(A, n); goto menu;
	case 3: KT_TinhChatSong(A, n); goto menu;
	case 4: KT_SNT_Trong_Mang(A, n, SoSNT); goto menu;
	case 5: if (SoSNT > 0)  Xoa_SNT(A, n); else printf("\n Mang ban nhap khong co SNT de xoa! "); goto menu;
	case 6: AmDuong(A, n); goto menu;
	case 7: Xep_Chan_Le(A, n, vitricl); goto menu;
	case 8: Chen(A, n, vitricl); goto menu;
	case 9: in(A, n); goto menu;
	case 10: exit(0);
	default: printf("\n Ban nhap sai moi nhap lai "); goto menu;
	}
	printf("\n\n");
	if (chon != 10) goto menu;
	_getch();
}