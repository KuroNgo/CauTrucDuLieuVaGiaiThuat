//Định nghĩa hằng
#define MAX 100
//Định nghĩa kiểu dữ liệu
typedef int Data;// Thành phần dữ liệu của nút
struct tagNode
{
	Data info;
	tagNode* pNext;
};
//Đổi lại tên kiểu nút
typedef tagNode NODE;
//Kiểu danh sách liên kết đơn
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};
//=========================== KHAI BÁO NGUYÊN MẪU HÀM ===========================
//1. Khởi tạo danh sách liên kết
NODE* GetNode(Data x);
void CreateList(LIST &l);
int KT_Rong(LIST l);
int File_List(char *f, LIST &l);
void XuatDanhSachLienKet(LIST l);
//2. Thao tác tìm kiếm trên danh sách liên kết
NODE *Search_FirstNode(LIST l, Data x);
int Search_FirstIndex(LIST l, Data x);
NODE *Search_LastNode(LIST l, Data x);
int Search_LastIndex(LIST l, Data x);
void Search_Index(LIST l, Data x);
//3.Thao tác chèn trong danh sách liên kết
void Add_Head(LIST &l, NODE *new_ele);
void InsertHead(LIST &l, Data x);
void Add_Tail(LIST &l, NODE *new_ele);
void InsertTail(LIST &l, Data x);
void Insert_After_Node(LIST&l, NODE*q, Data x);
void Insert_After_First_y(LIST &l, Data y, Data x);
void Insert_After_Last_y(LIST &l, Data y, Data x);
//4. Thao tác hủy nút (xóa phần tử) trong danh sách liên kết
void Remove_Node_Head(LIST &l);
void Remove_Node_Tail(LIST &l);
int Remove_First_X(LIST &l, Data x);
int Remove_Last_X(LIST &l, Data x);
void Remove_X(LIST&l, Data x);
void Remove_List(LIST &l);
//5. Thao tác sắp xếp trong danh sách liên kết
void Selection_Sort_Swap_Data(LIST &l);
void Selection_Sort_Swap_Link(LIST &l);
//6. Một số chức năng khác
void Swap_Data(Data &a, Data &b);
int Count_Node(LIST l);
void Copy_List(LIST &l1, LIST l);
//===============================================================================
//Hàm tạo nút có dữ liệu x, có next trỏ tới NULL
NODE* GetNode(Data x)
{
	NODE *p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}
//Tạo danh sách rỗng 
void CreateList(LIST &l)
{
	l.pHead = l.pTail = NULL;
}
//Hàm kiểm tra danh sách có rỗng
int KT_Rong(LIST l)
{
	if (l.pHead == NULL)//Danh sách rỗng
		return 1;
	return 0;
}
//Ghi dữ liệu vào danh sách từ file -> Dùng chèn cuối
int File_List(char *f, LIST &l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreateList(l);
	Data x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}
//Xuất danh sách liên kết
void XuatDanhSachLienKet(LIST l)
{
	NODE *p;
	if (KT_Rong(l))
	{
		cout << endl << "Danh sach rong!";
		return;
	}
	p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}
//I. Thuật giải tìm kiếm trên danh sách lien kết đơn
//Tìm con trỏ chứa địa chỉ nút đầu tiên của x	
NODE *Search_FirstNode(LIST l, Data x)
{
	NODE *p;
	p = l.pHead;
	while ((p != NULL) && (p->info != x))
		p = p->pNext;
	return p;
}
//Tìm vị trí đầu tiên của phần tử x
int Search_FirstIndex(LIST l, Data x)
{
	NODE*p = l.pHead;
	int i = 0;
	while ((p != NULL) && (p->info != x))
	{
		p = p->pNext;
		i++;
	}
	if (p == NULL)
		i = -1;
	return i;
}
//Tìm con trỏ chứa địa chỉ nút cuối cùng của x
NODE *Search_LastNode(LIST l, Data x)
{
	NODE *p = l.pHead, *q = NULL;
	while (p != nullptr)
	{
		if (p->info == x)
			q = p;
		p = p->pNext;
	}
	return q;
}
//Tìm vị trí cuối cùng của phần tử x trong danh sách
int Search_LastIndex(LIST l, Data x)
{
	NODE *p = l.pHead;
	int kq = -1;
	int i = 0;
	while (p != NULL)
	{
		if (p->info == x)
			kq = i;
		i++;
		p = p->pNext;
	}
	return kq;
}
//Tìm tất cả các vị trí của x trong danh sách
void Search_Index(LIST l, Data x)
{
	NODE *p = Search_FirstNode(l, x);
	int i = 0;
	if (p == NULL)
	{
		cout << endl << "Phan tu " << x << " khong co trong danh sach";
		return;
	}
	cout << endl << "Phan tu " << x << " xuat hien tai vi tri: ";
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			cout << i << '\t';
		i++;
		p = p->pNext;
	}
}
//II. Thuật giải chèn phân tử vào danh sách
//Chèn nút vào đàu danh sách
void Add_Head(LIST &l, NODE *new_ele)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}
//Chèn phần tử x vào đầu danh sách
void InsertHead(LIST &l, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << endl << "Loi cap phat bo nho! Khong thuc hien duoc thao tac nay!";
		return;
	}
	Add_Head(l, new_ele);
}
//Chèn nút vào cuối danh sách
void Add_Tail(LIST &l, NODE *new_ele)
{
	if (KT_Rong(l))
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}
//Chèn phần tử x vào cuối danh sách
void InsertTail(LIST &l, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << endl << "Loi cap phat bo nho!";
		return;
	}
	Add_Tail(l, new_ele);
}
//Chèn phần tử vào sau 1 nút
void Insert_After_Node(LIST&l, NODE*q, Data x)
{
	NODE *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << endl << "Loi cap phat bo nho! Khong thuc hien duoc chuc nang nay";
		return;
	}
	if (q != NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if (q == l.pTail)
			l.pTail = new_ele;
	}
	else
		Add_Head(l, new_ele);
}
//Chèn phần tử x vào sau phần tử y đầu tiên
void Insert_After_First_y(LIST &l, Data y, Data x)
{
	NODE *q = Search_FirstNode(l, y);
	Insert_After_Node(l, q, x);

}
//Chèn phần tủ x vào sau phần tử y cuối cùng
void Insert_After_Last_y(LIST &l, Data y, Data x)
{
	NODE *q = Search_LastNode(l, y);
	Insert_After_Node(l, q, x);
}
//III. Thuật giải hủy nút (xóa phần tử) trong danh sách liên kết
//Hủy nút đầu tiên
void Remove_Node_Head(LIST&l)
{
	NODE *p;
	if (l.pHead == NULL)
	{
		cout << endl << "Danh sach rong! Khong thuc hien duoc thao tac nay!";
		return;
	}
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if (l.pHead == NULL)
		l.pTail = NULL;
}
//Hủy nút cuối cùng
void Remove_Node_Tail(LIST &l)
{
	if (l.pHead == NULL)
	{
		cout << endl << "Danh sach rong! Khong thuc hien duoc thao tac nay!";
		return;
	}
	NODE *p = l.pHead, *q = NULL;
	while (p != l.pTail)
	{
		q = p;
		p = p->pNext;
	}
	l.pTail = q;
	delete p;
	if (l.pTail == NULL)
		l.pHead = NULL;
	else
		l.pTail->pNext = NULL;
}
//Hủy nút đầu tiên chứa x
int Remove_First_X(LIST &l, Data x)
{
	NODE *p = l.pHead;
	NODE *q = NULL;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
	}
	if (q == NULL)
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}
//Hủy nút cuối cùng chứa x
int Remove_Last_X(LIST &l, Data x)
{
	NODE *p = l.pHead;
	NODE *q = NULL;
	NODE *r = NULL;
	NODE *t = NULL;
	while (p != NULL)
	{
		if (p->info == x)
		{
			r = p;
			t = q;
		}
		q = p;
		p = p->pNext;
	}
	if (r == NULL)
		return 0;
	if (t != NULL)
	{
		if (r == l.pTail)
			l.pTail = t;
		t->pNext = r->pNext;
	}
	else
	{
		l.pHead = r->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete r;
	return 1;
}
//Hủy toàn bộ nút chứa x
void Remove_X(LIST&l, Data x)
{
	while (Remove_First_X(l, x));
}
//Hủy toàn bộ danh sách
void Remove_List(LIST &l)
{
	NODE *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
}
//IV. Thuật giải sắp xếp trên danh sách liên kết đơn
//Sắp xếp chọn trực tiếp: Hoán đổi dữ liệu
void Selection_Sort_Swap_Data(LIST &l)
{
	NODE *min;
	NODE *p, *q;
	for (p = l.pHead; p != l.pTail; p = p->pNext)
	{
		min = p;
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			if (q->info < min->info)
				min = q;
		}
		Swap_Data(p->info, min->info);
	}
}
//Sắp xếp chọn trực tiếp: Hoán đổi liên kết
void Selection_Sort_Swap_Link(LIST &l)
{
	LIST lRes;
	NODE *min, *minprev;
	NODE *p, *q;
	CreateList(lRes);
	while (l.pHead != NULL)
	{
		p = l.pHead;
		q = p->pNext;
		min = p;
		minprev = NULL;
		while (q != NULL)
		{
			if (q->info < min->info)
			{
				min = q;
				minprev = p;
			}
			p = q;
			q = q->pNext;
		}
		if (minprev != NULL)
			minprev->pNext = min->pNext;
		else
			l.pHead = min->pNext;
		min->pNext = NULL;
		Add_Tail(lRes, min);
	}
	Copy_List(l, lRes);
}
//V. Một số thao tác đặc biệt
//Hàm hoán vị (Swap)
void Swap_Data(Data &a, Data &b)
{
	Data temp = a;
	a = b;
	b = temp;
}
//Hàm đếm số nút trong danh sách
int Count_Node(LIST l)
{
	NODE *p = l.pHead;
	int i = 0;
	while (p != NULL)
	{
		p = p->pNext;
		i++;

	}
	return i;
}
//Hàm sao chép danh sách liên kết l sang danh sách liên kết l1
void Copy_List(LIST &l1, LIST l)
{
	CreateList(l1);
	if (KT_Rong(l))
	{
		cout << endl << "Danh sach rong!";
		return;
	}
	NODE *p;
	Data x;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		x = p->info;
		InsertTail(l1, x);
	}
}