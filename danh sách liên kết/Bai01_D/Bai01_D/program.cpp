#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#include"thuvien.h"
#include"menu.h"
void ChayChuongTrinh()
{
	int menu, soMenu = 18;
	LIST l;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
	} while (menu > 0);
}
int main()
{
	ChayChuongTrinh();
	return 1;
}