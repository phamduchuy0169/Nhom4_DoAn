#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <ctime>
#include <iomanip>
#include "ATM.h"
#include "TAIKHOAN.h"
using namespace std;


int main()
{
	//doi mau chu
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	ATM *p = new ATM;
	p->setTK();

	p->Menu();
	
	cout << endl;
	system("pause");
	return 0;
}
