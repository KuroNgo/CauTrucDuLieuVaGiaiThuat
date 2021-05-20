#define MAX 100
int TapTin_Mang1C(char *filename, int a[MAX], int &n)
{
	int i;
	fstream in(filename);
	if (!in)
		return 0;
	in >> n;
	for (i = 0; i < n; i++)
		in >> a[i];
	in.close();
	return 1;
}
void XuatMang(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
}
// Tra ve chi so dau tien neu co x
int TKTT_DauTien(int a[MAX], int n, int x)
{

	int i = 0;
	while ((i < n) && (a[i] != x))i++;
	if (i == n)
		return -1;
	return 1;
}
// Tra ve chi so dau tien co linh canh
int TKTT_DauTien_LC(int a[MAX], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)i++;
	if (i == n)
		return -1;
	return 1;
}
int TKTT_DauTien(int a[MAX], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))i++;
	if (i == n)
		return -1;
	return 1;
}
int TKTT_CuoiCung(int a[MAX], int n, int x)
{

	int i = n - 1;
	while ((i >= 0) && (a[i] != x))i--;

	return i;
}
void TKTT_CacChiSo(int a[MAX], int n, int x)
{
	int i, kq = -1;
	for (i = 0; i < n; i++) 
	{
		if (a[i] == x)
		{
			kq = 1;
			break;
		}
		if (kq == -1)
		{
			cout << endl << x << "khong co trong a";
		}
		else
		{
			cout << endl << x << "xuat hien trong a tai cac vi tri:\n";
			for (int i = 0; i < n; i++)
				if (a[i] == x)
					cout << a[i] << '\t';
		}
	}
}