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
//Tim kiem theo ten
void Tim_TheoTen(SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].ten, "Hoa") == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co ten sinh vien : " << "Hoa";
	else
	{
		cout << "\nthong tin sinh vien trong danh sach co ten " << "Hoa";

		Xuat_TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].ten, "Hoa") == 0)
			{
				cout << endl;
				Xuat_1SV(a[i]);
			}
	}
}
// TimKiem theo lop va so tin chi
void Tim_TheoLopVaSoTinChi(SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].lop, "CTK37") ==0&&(a[i].tichLuy)>41)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\ncac hoc vien thuoc lop CTK37 va co so tin chi tich luy > 41 ";
	else
	{
		cout << "\ncac hoc vien thuoc lop CTK37 va co so tin chi tich luy > 41";

		Xuat_TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].lop, "CTK37") == 0 && (a[i].tichLuy)>41)
			{
				cout << endl;
				Xuat_1SV(a[i]);
			}
	}
}
void Tim_TheoNamSinhVaDiemTrungBinh(SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++) 
	
		if ((a[i].namSinh > 1993) && (a[i].dtb) <= 6.2)
		{
		kq = 1;
		break;
		}
	
	if (kq == -1)
		cout << "\ncac hoc vien thuoc lop CTK37 va co so tin chi tich luy > 41 ";
	else
	{
		cout << "\ncac hoc vien thuoc lop CTK37 va co so tin chi tich luy > 41";

		Xuat_TieuDe();
		for (i = 0; i < n; i++)
			if ((a[i].namSinh > 1993) && (a[i].dtb <= 6.2))
			{
			cout << endl;
			Xuat_1SV(a[i]);
			}

	}

}