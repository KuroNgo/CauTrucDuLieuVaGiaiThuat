#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
#include"thuvien.h"
#include"menu.h"
void ChayChuongTrinh()
{
	int soMenu = 6, menu;
	int a[MAX], n = 0;
	do {
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("pause");
	} while (menu > 0);
}
int main()
{
	ChayChuongTrinh();
	return 1;
}