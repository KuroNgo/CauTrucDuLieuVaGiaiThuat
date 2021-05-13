#define MAX 30
typedef char Data[MAX];
struct tagNode
{
	Data info;
	tagNode* pNext;

};
typedef tagNode NODE;
struct LLIST
{
	NODE* pHead;
	NODE* pTail;

};
NODE* GetNode(Data x);
void CreateLLIST(LLIST &l);
void InsertTail(LLIST &l, Data x);
void Output_Llist(LLIST l);
int File_LLIST(char *f, LLIST &l);
NODE* GetNode(Data x)
{
	NODE *p;
	p = new NODE;
	if (p != NULL)
	{
		strcpy_s(p->info, x);
		p->pNext = NULL;

	}
	return p;

}


void CreateLLIST(LLIST &l)

{
	l.pHead = l.pTail = NULL;
}
void InsertTail(LLIST &l, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "Loi cap nhat bo nho! khong thuc hien duoc thao tac nay";
		return;

	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
		l.pTail->pNext = l.pHead;


	}
	else
		new_ele->pNext = l.pHead;
	l.pTail->pNext = new_ele;
	l.pTail = new_ele;
}
void Output_Llist(LLIST l)
{
	NODE* p;
	if (l.pHead == NULL)
	{
		cout << "\n Danh sach don vong rong!\n";
		return;

	}
	p = l.pHead;
	do
	{
		cout << p->info << '\t';
		p = p->pNext;
	} while (p != l.pHead);

}
int File_LLIST(char *f,LLIST &l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreateLLIST(l);
	Data x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);

	}
	in.close();
	return 1;
}