void XuatMenu()
{
	cout << endl << "============================ LINKED LIST ============================";
	cout << endl << "1.  Tao danh sach lien ket don";
	cout << endl << "2.  Xem danh sach hien hanh";
	cout << endl << "---------------------------------------------------------------------";
	cout << endl << "3.  Kiem tra su ton tai cua phan tu x";
	cout << endl << "4.  Tim vi tri dau tien cua x trong danh sach";
	cout << endl << "5.  Tim vi tri cuoi cung cua x trong danh sach";
	cout << endl << "6.  Tim tat ca vi tri cua x trong danh sach";
	cout << endl << "---------------------------------------------------------------------";
	cout << endl << "7.  Chen x vao dau danh sach";
	cout << endl << "8.  Chen x vao cuoi danh sach";
	cout << endl << "9.  Chen x vao danh sach sau nut co du lieu y xuat hien dau tien";
	cout << endl << "10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung";
	cout << endl << "---------------------------------------------------------------------";
	cout << endl << "11. Huy nut dau danh sach";
	cout << endl << "12. Huy nut cuoi danh sach";
	cout << endl << "13. Huy nut dau tien co x";
	cout << endl << "14. Huy nut cuoi cung co x";
	cout << endl << "15. Huy tat ca cac nut co x";
	cout << endl << "16. Huy toan bo danh sach";
	cout << endl << "---------------------------------------------------------------------";
	cout << endl << "17. Sap xep tang - Chon truc tiep (Hoan doi du lieu)";
	cout << endl << "18. Sap xep tang - Chon truc tiep (Hoan doi lien ket)";
	cout << endl << "---------------------------------------------------------------------";
	cout << endl << "0.  Thoat chuong trinh";
	cout << endl << "=====================================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << endl << "Nhap 1 so trong [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> stt;
		if (0 <= stt)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, LIST &l)
{
	char f[MAX];
	int kq;
	Data x;
	Data y;
	NODE *p;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << endl << "Thaot chuong trinh ";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc" << endl;
		break;
	case 1:
		do
		{
			system("CLS");
			cout << endl << "Tao danh sach lien ket don";
			cout << endl << "Xin hay nhap ten file can ghi: ";
			cin >> f;
			kq = File_List(f, l);
			if (kq == 0)
			{
				cout << endl << "Loi! Xin hay nhap lai ten tap tin!";
				cout << endl << "Nhan 1 phim bat ky de tiep tuc";
				_getch();
			}
		} while (kq == 0);
		cout << endl << "Nhap thanh cong! Danh sach sau khi nhap:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 2:
		cout << endl << "Danh sach lien ket hien hanh: " << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 3:
		cout << endl << "Kiem tra ton tai cua phan tu x trong danh sach.";
		cout << endl << "Xin hay nhap phan tu can tim kiem: ";
		cin >> x;
		p = Search_FirstNode(l, x);
		(l, x);
		if (p != NULL)
			cout << endl << x << " co ton tai trong danh sach!";
		else
			cout << endl << x << " khong ton tai trong danh sach!";
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 4:
		cout << endl << "Tim vi tri dau tien cua x trong danh sach";
		cout << endl << "Xin hay nhap phan tu can tim kiem: ";
		cin >> x;
		kq = Search_FirstIndex(l, x);
		if (kq > 0)
			cout << endl << "Phan tu " << x << " xuat hien dau tien o vi tri " << kq << " trong danh sach lien ket";
		else
			cout << endl << "Khong tim thay phan tu " << x << " trong danh sach lien ket";
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 5:
		cout << endl << "Tim vi tri cuoi cung cua x trong danh sach";
		cout << endl << "Xin hay nhap phan tu can tim: ";
		cin >> x;
		kq = Search_LastIndex(l, x);
		if (kq < 0)
			cout << endl << "Phan tu " << x << " khong co trong danh sach!";
		else
			cout << endl << "Phan tu " << x << " xuat hien lan cuoi cung o vi tri thu " << kq << " trong danh sach.";
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 6:
		cout << endl << "Tim tat ca vi tri cua x trong danh sach";
		cout << endl << "Xin hay nhap phan tu can tim kiem: ";
		cin >> x;
		Search_Index(l, x);
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 7:
		cout << endl << "Chen phan tu vao dau danh sach.";
		cout << endl << "Xin hay nhap phan tu can chen: ";
		cin >> x;
		InsertHead(l, x);
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 8:
		cout << endl << "Chen phan tu x vao cuoi danh sach";
		cout << endl << "Xin hay nhap phan tu can chen: ";
		cin >> x;
		InsertTail(l, x);
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 9:
		cout << endl << "Chen phan tu x vao sau phan tu y dau tien";
		cout << endl << "Xin hay nhap phan tu can chen: ";
		cin >> x;
		cout << endl << "Xin hay nhap phan tu lam vi tri chen: ";
		cin >> y;
		Insert_After_First_y(l, y, x);
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 10:
		cout << endl << "Chen phan tu x vao sau phan tu y cuoi cung";
		cout << endl << "Xin hay nhap phan tu can chen: ";
		cin >> x;
		cout << endl << "Xin hay nhap phan tu lam vi tri can chen: ";
		cin >> y;
		Insert_After_Last_y(l, y, x);
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 11:
		cout << endl << "Huy nut dau tien cua danh sach	";
		Remove_Node_Head(l);
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 12:
		cout << endl << "Huy nut cuoi cung cua danh sach";
		Remove_Node_Tail(l);
		cout << endl << "Danh sach hien hanh:" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 13:
		cout << endl << "Huy nut dau tien chua x";
		cout << endl << "Xin hay nhap phan tu can xoa: ";
		cin >> x;
		kq = Remove_First_X(l, x);
		cout << endl << "----------------------------------------------------------------";
		if (kq == 0)
			cout << endl << "Khong co" << x << " trong danh sach";
		else
		{
			cout << endl << "Xoa thanh cong! Danh sach sau khi xoa: " << endl;
			XuatDanhSachLienKet(l);
		}
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 14:
		cout << endl << "huy nut cuoi cung chua x";
		cout << endl << "Xin hay nhap phan tu can xoa: ";
		cin >> x;
		kq = Remove_Last_X(l, x);
		cout << endl << "----------------------------------------------------------------";
		if (kq == 0)
			cout << endl << "Khong co " << x << " trong danh sach";
		else
		{
			cout << endl << "Xoa thanh cong! Danh sach sau khi xoa: " << endl;
			XuatDanhSachLienKet(l);
		}
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 15:
		cout << endl << "Huy tat ca cac nut chua x";
		cout << endl << "Xin hay nhap phan tu can xoa: ";
		cin >> x;
		Remove_X(l, x);
		cout << endl << "----------------------------------------------------------------";
		cout << endl << "Danh sach sau khi xoa: " << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 16:
		cout << endl << "Huy toan bo danh sach";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		_getch();
		Remove_List(l);
		system("CLS");
		cout << endl << "Da xoa thanh cong!";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 17:
		cout << endl << "Sap xep chon truc tiep : Hoan doi du lieu";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		_getch();
		Selection_Sort_Swap_Data(l);
		cout << endl << "----------------------------------------------------------------";
		system("CLS");
		cout << endl << "Da sap xep thanh cong! Danh sach sau khi sap xep" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 18:
		cout << endl << "Sap xep chon truc tiep : Hoan doi lien ket";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		_getch();
		Selection_Sort_Swap_Link(l);
		cout << endl << "----------------------------------------------------------------";
		system("CLS");
		cout << endl << "Da sap xep thanh cong! Danh sach sau khi sap xep" << endl;
		XuatDanhSachLienKet(l);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	default:
		cout << endl << "Loi! Xin hay nhap lai!";
		break;
	}
	_getch();
}