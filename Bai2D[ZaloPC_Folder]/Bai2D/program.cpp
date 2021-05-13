#include<iostream>
#include<conio.h>
#include<iomanip>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#include"Header.h"
#include"thuvien.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;

}
void ChayChuongTrinh()
{
	LLIST l;
	char filename[MAX];
	cout << "Hay nhap tap tin";
	cin >> filename;
	if (!File_LLIST(filename, l))
	{
		cout << "Loi mo file";
		_getch();

	}
	else
	{
		cout << "Du lieu duoc chuyen" << filename << " da duoc chuyen vao"
			<< " nhan 1 phim tiep tuc";
		CryForHelp(l);
		_getch();
		
		
	}

	

}
