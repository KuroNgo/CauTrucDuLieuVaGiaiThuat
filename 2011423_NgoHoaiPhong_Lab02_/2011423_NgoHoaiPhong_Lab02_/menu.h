void XuatMenu()
{
	cout << "===============HE THONG CHUC NANG=====================";
	cout << "\n0. Thoat khoi chuc nang";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim kiem tuyen tinh- Tra ve chi so dau tien";
	cout << "\n4. Tim kiem tuyen tinh- Tra ve chi so dau tien,neu co(co linh canh)";
	cout << "\n5. Tim kiem tuyen tinh- Tra ve chi so cuoi cung,neu co";
	cout << "\n6. Tra ve tat ca chi so i, neu co";

}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so(0<=" << soMenu << ") dew chon menu,stt= ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, int a[MAX], int &n)
{
	int x;
	int kq;
	char filename[MAX];
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << "\n Thoat khoi chuong trinh";
		break;
	case 1:
		cout << "\n1. Tao du lieu";
		do {
			cout << "\nNhap ten tep tin filename:";
			cin >> filename;
			kq = TapTin_Mang1C(filename, a, n);
		} while (!kq);

		cout << "\nMang vua tao la: \n";
		XuatMang(a, n);
		cout << endl;

		break;
	case 2:
		cout << "\n2. Xem du lieu";
		cout << "\nMang vua tao la: \n";
		XuatMang(a, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3. Tim kiem tuyen tinh- Tra ve chi so dau tien";
		cout << "\n Mang du lieu ban dau: ";

		XuatMang(a, n);
		cout << "\n Nhap x: ";
		cin >> x;
		kq = TKTT_DauTien(a, n, x);
		if (kq == -1)
			cout << endl << "khong co trong mang ";
		else
			cout << endl << x << "xuat hien tai vi tri dau tien la: " << kq;
		cout << endl;
		break;
	case 4:
		cout << "\n4. Tim kiem tuyen tinh- Tra ve chi so dau tien, co linh canh";
		cout << "\n Mang du lieu ban dau: ";

		XuatMang(a, n);
		cout << "\n Nhap x: ";
		cin >> x;
		kq = TKTT_DauTien_LC(a, n, x);
		if (kq == -1)
			cout << endl << "khong co trong mang ";
		else
			cout << endl << x << "xuat hien tai vi tri dau tien la: " << kq;
		cout << endl;
		break;
	case 5:
		cout << "\n5. Tra ve chi so cuoi cung,neu co";
		cout << "\n Mang du lieu ban dau: ";

		XuatMang(a, n);
		cout << "\n Nhap x: ";
		cin >> x;
		kq = TKTT_CuoiCung(a, n, x);
		if (kq == -1)
			cout << endl << "khong co trong mang ";
		else
			cout << endl << x << "xuat hien tai vi tri dau tien la: " << kq;
		cout << endl;
		break;
	case 6:
		cout << "\n6. Tra ve tat ca chi so i, neu co";
		cout << "\n Mang du lieu ban dau: ";

		XuatMang(a, n);
		cout << "\n Nhap x: ";
		cin >> x;
	TKTT_CacChiSo(a, n, x);
		
		cout << endl;
		break;

	}
	_getch();
}
