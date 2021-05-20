#define MAX 100

struct SinhVien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
};


//Nhap tu file
int File_Array(char* filename, SinhVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;

	n = 0;
	in >> maSV; strcpy_s(a[n].maSV, maSV);
	in >> hoSV; strcpy_s(a[n].hoSV, hoSV);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> lop; strcpy_s(a[n].lop, lop);
	in >> namSinh; a[n].namSinh = namSinh;
	in >> dtb; a[n].dtb = dtb;
	in >> tichLuy; a[n].tichLuy = tichLuy;

	while (!in.eof())
	{
		n++;
		in >> maSV; strcpy_s(a[n].maSV, maSV);
		in >> hoSV; strcpy_s(a[n].hoSV, hoSV);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> lop; strcpy_s(a[n].lop, lop);
		in >> namSinh; a[n].namSinh = namSinh;
		in >> dtb; a[n].dtb = dtb;
		in >> tichLuy; a[n].tichLuy = tichLuy;
	}
	n++;
	in.close();
	return 1;
}

//Xuat duong ke don
void Xuat_KeDon()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << '-';
	cout << ':';
}

//Xuat duong ke doi
void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << '=';
	cout << ':';
}

//Hàm xuất dữ liệu
//Xuat tieu de(Heading)
void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma SV"
		<< ':'
		<< setw(11) << "Ho"
		<< ':'
		<< setw(11) << "Ten lot"
		<< ':'
		<< setw(11) << "Ten"
		<< ':'
		<< setw(6) << "Lop"
		<< ':'
		<< setw(6) << "NSinh"
		<< ':'
		<< setw(5) << "DTB"
		<< ':'
		<< setw(5) << "TL"
		<< ':';
	Xuat_KeDoi();
}

//Xuat 1sinh vien(Output_Struct)
void Xuat_1SV(SinhVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << a.maSV
		<< ':'
		<< setw(11) << a.hoSV
		<< ':'
		<< setw(11) << a.tenLot
		<< ':'
		<< setw(11) << a.ten
		<< ':'
		<< setw(6) << a.lop
		<< ':'
		<< setw(6) << a.namSinh
		<< ':'
		<< setw(5) << a.dtb
		<< ':'
		<< setw(5) << a.tichLuy
		<< ':';

}

//Xuat ds sinh vien(Output_Arry)
void Xuat_DS(SinhVien a[MAX], int n)
{
	Xuat_TieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat_1SV(a[i]);
		if ((i + 1) % 5 == 0)
			Xuat_KeDon();
	}
	Xuat_KeDoi();
	cout << endl;
}
////Hàm hoán vị
//void HoanVi(int& a, int& b)
//{
//	int tam = a;
//	a = b;
//	b = tam;
//}

//Copy a sang b
void Copy(SinhVien b[MAX], SinhVien a[MAX], int n) 
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void Partition(SinhVien a[MAX], int l, int r)
{
	int i, j; 
		SinhVien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (a[i].dtb < x.dtb)
			i++;
		while (a[j].dtb > x.dtb)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}


//Quick sort
void QuickSort(SinhVien a[MAX], int &n)
{
	Partition(a, 0, n - 1);
}

//Heap sort
void Shift(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	i = l; j = 2 * i + 1;
	x = a[i];
	while (j <= r)
	{
		if (j < r)
			if (a[j].dtb < a[j + 1].dtb)
				j = j + 1;
		if (a[j].dtb <= x.dtb)
			return;
		else
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
			a[i] = x;
		}
	}
}

//CreateHeap
void Create_Heap(SinhVien a[MAX], int &n)
{
	int l;
	l = (n - 1) / 2;
	while (l >= 0)
	{
		Shift(a, l, n - 1);
		l = l - 1; 
	}
}

//HeapSort
void HeapSort(SinhVien a[MAX], int &n)
{
	int r, i = 0;
	Create_Heap(a, n);
	r = n - 1;
	while (r > 0)
	{
		i++;
		swap(a[0], a[r]);
		r = r - 1;
		Shift(a, 0, r);
	}
}

//*************************
//Distribution
void Distribution(SinhVien F[MAX], int n, SinhVien F1[MAX], int& h1, SinhVien F2[MAX], int& h2, int p)
{
	int i, k = 1, l = 0;
	h1 = 0; h2 = 0;
	do
	{
		i = 1;
		while (i <= p && l < n)
		{
			if (k == 1)
			{
				F1[h1++] = F[l];
			}
			else
			{
				F2[h2++] = F[l];
			}
			i++;
			l++;
		}
		k = 3 - k;
	} while (l < n);
}

//****************************
//Merge
void Merge(SinhVien F1[MAX], int h1, SinhVien F2[MAX], int h2, SinhVien F[MAX], int p)
{
	int i1 = 0, i2 = 0, r1, r2;
	int h = 0;
	while (i1 < h1 && i2 < h2)
	{
		r1 = r2 = 1;
		while ((r1 <= p) && (r2 <= p) && i1 < h1 && i2 < h2)
		{
			if (F1[i1].dtb <= F2[i2].dtb)
			{
				F[h++] = F1[i1];
				r1++;
				i1++;
			}
			else
			{
				F[h++] = F2[i2];
				r2++;
				i2++;
			}
		}
		while (i1 < h1 && r1 <= p)
		{
			F[h++] = F1[i1];
			i1++; r1++;
		}
		while (i2 < h2 && r2 <= p)
		{
			F[h++] = F2[i2];
			i2++; r2++;
		}
	}
	while (i1 < h1)
	{
		F[h++] = F1[i1];
		i1++;
	}
	while (i2 < h2)
	{
		F[h++] = F2[i2];
		i2++;
	}
}

//MergeSort
void MergeSort(SinhVien F[MAX], int n)
{
	int p = 1, h1, h2;
	SinhVien F1[MAX], F2[MAX];
	int i = 1;
	while (p < n)
	{
		Distribution(F, n, F1, h1, F2, h2, p);
		Merge(F1, h1, F2, h2, F, p);
		i++;
		p = p * 2;
	}
}