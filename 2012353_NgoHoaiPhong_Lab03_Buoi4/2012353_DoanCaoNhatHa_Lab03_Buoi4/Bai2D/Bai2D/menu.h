void XuatMenu()
{
	cout << "\n========== He thong menu =========";
	cout << "\n0. Thoat khoi chuong trinh.";
	cout << "\n1. Tao du lieu.";
	cout << "\n2. Xem du lieu.";
	cout << "\n3. QuickSort";
	cout << "\n4. HeapSort";
	cout << "\n5. MergeSort";
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
	int kq;
	char filename[MAX];
	SinhVien b[MAX];
	Copy(b, a, n);
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << endl << "0. Thoat khoi chuong trinh.\n";
		cout << "\nCam on vi da su dung.";
		break;

	case 1:
		system("CLS");
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
		system("CLS");
		cout << endl << "2. Xem du lieu.\n";
		cout << "\nDay hien hanh:\n";
		Xuat_DS(a, n);
		break;

	case 3:
		system("cls");
		cout << "\n3. Quick sort\n";
		cout << "\nDanh sach truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sau khi sap xep theo diem trung binh : \n";
		QuickSort(b, n);
		Xuat_DS(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Heap sort\n";
		cout << "\nDanh sach truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sau khi sap xep theo diem trung binh : \n";
		HeapSort(b, n);
		Xuat_DS(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Merge Sort\n";
		cout << "\nDanh sach truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sau khi sap xep theo diem trung binh : \n";
		MergeSort(b, n);
		Xuat_DS(b, n);
		break;
	default:
		cout << "\Nhap mot phim bat ky de tiep tuc";
		break;
	}
}