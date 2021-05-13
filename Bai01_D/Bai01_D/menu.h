void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim x - Co / Khong";
	cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
	cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
	cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n7. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
	cout << "\n8. Chen x vao dau danh sach vong";
	cout << "\n9. Chen x vao cuoi danh sach vong";
	cout << "\n10. Huy nut dau danh sach vong";
	cout << "\n11. Huy nut cuoi danh sach vong";
	cout << "\n12. Huy toan bo danh sach vong";
	cout << "\n13. Dem so nut danh sach vong";
	cout << "\n==================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LLIST &l)
{
	int kq;
	Data x;
	char filename[MAX];
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		cout << "\n1. Tao du lieu";
		do
		{
			system("cls");
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			if (!File_LLIST(filename, l))
			{
				cout << "\nLoi mo file! Nhap lai...\n";
				_getch();
			}
			else
			{
				cout << "\nDu lieu tap tin " << filename << " da duoc chuyen vao DSLK don vong l";
				cout << "\nNhap phim bat ky de tiep tuc!";
				_getch();
				break;
			}
		} while (true);
		break;
	case 2:
		cout << "\n2. Xem du lieu" << endl;
		Output_LLIST(l);
		break;
	case 3:
		cout << "\n3. Tim x - Co / Khong";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		if (Search(l, x))
		{
			cout << endl << x << " ton tai trong danh sach";
		}
		else
		{
			cout << endl << x << " khong ton tai trong danh sach";
		}
		break;
	case 4:
		cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		kq = Search_Pos_First(l, x);
		if (kq < 0)
			cout << endl << "Khong ton tai " << x << " trong danh sach";
		else
			cout << endl << x << " xuat hien dau tien tai vi tri: " << kq;
		break;
	case 5:
		cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		kq = Search_Pos_End(l, x);
		if (kq < 0)
			cout << endl << "Khong ton tai " << x << " trong danh sach";
		else
			cout << endl << x << " xuat hien cuoi cung tai vi tri: " << kq;
		break;
	case 6:
		cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		Search_All_Pos_x(l, x);
		break;
	case 7:
		cout << "\n7. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		kq = Head_New(l, x);
		if (kq == 0)
			cout << endl << "Loi! Khong thuc hien duoc chuc nang nay!";
		else
		{
			cout << endl << "Ket qua: " << endl;
			Output_LLIST(l);
		}
		break;
	case 8:
		cout << "\n8. Chen x vao dau danh sach vong";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		InsertHead(l, x);
		cout << endl << "Ket qua: " << endl;
		Output_LLIST(l);
		break;
	case 9:
		cout << "\n9. Chen x vao cuoi danh sach vong";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		InsertTail(l, x);
		cout << endl << "Ket qua: " << endl;
		Output_LLIST(l);
		break;
	case 10:
		cout << "\n10. Huy nut dau danh sach vong";
		cout << endl << "Nhan 1 phim de tiep tuc";
		RemoveHead(l);
		cout << endl << "Ket qua: " << endl;
		Output_LLIST(l);
		break;
	case 11:
		cout << "\n11. Huy nut cuoi danh sach vong";
		cout << endl << "Nhan 1 phim de tiep tuc";
		RemoveTail(l);
		cout << endl << "Ket qua: " << endl;
		Output_LLIST(l);
		break;
	case 12:
		cout << "\n12. Huy toan bo danh sach vong";
		cout << endl << "Nhan 1 phim de tiep tuc";
		RemoveLLIST(l);
		cout << endl << "Xoa thanh cong!";
		break;
	case 13:
		cout << "\n13. Dem so nut danh sach vong";
		kq = SoNut(l);
		cout << endl << "So nut cua danh sach lien ket don vong la: " << kq;
		break;
	default:
		break;
	}
}