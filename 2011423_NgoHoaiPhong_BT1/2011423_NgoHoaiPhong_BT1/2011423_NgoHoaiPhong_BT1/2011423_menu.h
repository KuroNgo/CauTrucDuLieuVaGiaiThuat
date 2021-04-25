void XuatMenu()
{
	cout << "\n========== He thong menu =========";
	cout << "\n0. Thoat khoi chuong trinh.";
	cout << "\n1. Tao du lieu.";
	cout << "\n2. Xem du lieu.";
	cout << "\n3. Tim kiem theo lop va so tin chi: Xuat cac hoc vien thuoc lop CTK37 va co so tin chi tich luy > 41";
	cout << "\n4. Tim kiem theo ten Hoa";
	cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
	cout << "\n===================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, SinhVien a[MAX], int& n)
{
	system("cls");
	int kq;
	char filename[MAX];
	SinhVien b[MAX];

	switch (menu)
	{
	case 0:
	
		cout << endl << "0. Thoat khoi chuong trinh.\n";
		cout << "\nCam on vi da su dung.";
		break;

	case 1:
		
		cout << endl << "1. Tao du lieu tu file.\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
			if (kq == 0)
				cout << "\tLoi mo file.\n";
		} while (kq == 0);
		cout << "\nMang vua tao la:\n";
		Xuat_DS(a, n);
		cout << endl;
		break;

	case 2:
	
		cout << endl << "2. Xem du lieu.\n";
		cout << "\nDay hien hanh:\n";
		Xuat_DS(a, n);
		break;
	case 3: 
		cout << ("\n3. Tim kiem theo lop va so tin chi: Xuat cac hoc vien thuoc lop CTK37 va co so tin chi tich luy > 41");
		Tim_TheoLopVaSoTinChi(a, n);
		cout << endl;
		break;
	case 4:
		cout << "\n4. Tim kiem theo ten: Hcc vien co ten la Hoa";
		Tim_TheoTen(a, n);
		cout << endl;
		break;
	case 5:
		cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
		Tim_TheoNamSinhVaDiemTrungBinh(a, n);
		cout << endl;
		break;
	}

}
