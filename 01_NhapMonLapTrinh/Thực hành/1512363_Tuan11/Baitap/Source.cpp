#include <stdio.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Hocsinh HOCSINH;

struct Hocsinh
{
	char MaSo[6];
	char HoTen[31];
	int NamSinh;
	float Toan, Ly, Hoa;
	float DiemTrungBinh;
	char* XepLoai;
};

float DTB_HS(HOCSINH hs)
{
	float diem = (float)(hs.Toan + hs.Ly + hs.Hoa) / 3;
	return diem;
}

void DS_DTB(HOCSINH a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].DiemTrungBinh = DTB_HS(a[i]);
	}
}

char* XEPHANG_HS(HOCSINH hs)
{
	char* kq;
	float d = DTB_HS(hs);
	if (d >= 9)
	{
		kq = "Xuat Sac!";
	}
	else if (8 <= d)
	{
		kq = "Gioi!";
	}
	else if (6.5 <= d)
	{
		kq = "Kha!";
	}
	else if (5 <= d)
	{
		kq = "Trung Binh!";
	}
	else
	{
		kq = "Yeu!";
	}
	return kq;
}

void DSXepLoai(HOCSINH a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].XepLoai = XEPHANG_HS(a[i]);
	}

}

void Nhap(HOCSINH a[], char* filename, int &n)
{
	FILE* FileIn = fopen(filename, "rt");
	if (!FileIn)
	{
		printf("\nFile khong ton tai!");
		return;
	}
	fscanf(FileIn, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(FileIn, "%s\n", a[i].MaSo);
		fgets(a[i].HoTen, 31, FileIn);
		fscanf(FileIn, "%d", &a[i].NamSinh);
		fscanf(FileIn, "%f", &a[i].Toan);
		fscanf(FileIn, "%f", &a[i].Ly);
		fscanf(FileIn, "%f", &a[i].Hoa);

	}
	fclose(FileIn);
}

int DTB_MAX(HOCSINH a[], int n)
{
	int vitri;
	float max = a[0].DiemTrungBinh;
	for (int i = 1; i < n; i++)
	{
		if (max <a[i].DiemTrungBinh)
		{
			max = a[i].DiemTrungBinh;
			vitri = i;
		}
	}
	return vitri;
}

void XuatMAX_TB(HOCSINH a[], int i, char* filename)
{
	FILE* f = fopen(filename, "at");
	fprintf(f, "\n\t\tHOC SINH CO DIEM TRUNG BINH CAO NHAT LA\n\n");
	fprintf(f, "Maso\tHoten\t\tNamsinh\tToan\tLi\tHoa\tDiemTB\tXepLoai\n");
	fprintf(f, "%s", a[i].MaSo);
	fprintf(f, "\t%s\t\t", a[i].HoTen);
	fprintf(f, "\t%d", a[i].NamSinh);
	fprintf(f, "\t%.2f\t%.2f\t%.2f", a[i].Toan, a[i].Ly, a[i].Hoa);
	fprintf(f, "\t%.2f", a[i].DiemTrungBinh);
	fprintf(f, "\t%s\n", a[i].XepLoai);
	fclose(f);
}

void HSYeu(HOCSINH a[], int n, char *Filename)
{
	FILE *f = fopen(Filename, "at");
	fprintf(f, "\n\n\t\t\tDANH SACH HOC SINH YEU\n\n");
	fprintf(f, "Maso\tHoten\t\tNamsinh\tToan\tLi\tHoa\tDiemTB\tXepLoai\n");
	for (int i = 0; i < n; i++)
		if (a[i].DiemTrungBinh < 5)
		{
			fprintf(f, "%s", a[i].MaSo);
			fprintf(f, "\t%s\t\t", a[i].HoTen);
			fprintf(f, "\t%d", a[i].NamSinh);
			fprintf(f, "\t%.2f\t%.2f\t%.2f", a[i].Toan, a[i].Ly, a[i].Hoa);
			fprintf(f, "\t%.2f", a[i].DiemTrungBinh);
			fprintf(f, "\t%s\n", a[i].XepLoai);
		}
	fclose(f);
}

void Xuat(HOCSINH a[], char* filename, int n)
{
	FILE* FileOut = fopen(filename, "wt");
	fprintf(FileOut, "\n\t\t\tDANH SACH HOC SINH THEO MAU\n\n");
	fprintf(FileOut, "Maso\tHoten\t\tNamsinh\tToan\tLi\tHoa\tDiemTB\tXepLoai\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(FileOut, "%s", a[i].MaSo);
		fprintf(FileOut, "\t%s\t\t", a[i].HoTen);
		fprintf(FileOut, "\t%d", a[i].NamSinh);
		fprintf(FileOut, "\t%.2f\t%.2f\t%.2f", a[i].Toan, a[i].Ly, a[i].Hoa);
		fprintf(FileOut, "\t%.2f", a[i].DiemTrungBinh);
		fprintf(FileOut, "\t%s\n", a[i].XepLoai);
	}
	fclose(FileOut);
}

void main()
{
	HOCSINH a[31];
	int n;

	Nhap(a, "INPUT.txt", n);
	DSXepLoai(a, n);
	DS_DTB(a, n);
	Xuat(a, "OUTPUT.txt", n);
	XuatMAX_TB(a, DTB_MAX(a, n), "OUTPUT.txt");
	HSYeu(a, n, "OUTPUT.txt");
	_getch();
}