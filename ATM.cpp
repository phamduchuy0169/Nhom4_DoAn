#include "ATM.h"
#include"TAIKHOAN.h"
#include<iostream>
#include "string"
#include <fstream>
#include <time.h>
#include<Windows.h>
#include<iomanip>
using namespace std;
void ATM::setTK()
{
	n = 0;
	int i=0;
	string tam;
	fstream f;
	f.open ("file[ID].txt", ios :: in);
	while (!f.eof())
	{
		if (i % 4 == 0)
		{
			getline (f, tam);
			TK[n].setcID (tam);
		}
		if ( i % 4 == 1)
		{
			getline (f, tam);
			TK[n].setcTenTK (tam);
		}
		if ( i % 4 == 2)
		{
			getline (f, tam );
			TK[n].setcMaPIN ( tam);
		}
		if ( i % 4 == 3)
		{
			getline  (f, tam);
			TK[n].setdTK (tam);
			n++;
		}
		i++;
	}
	f.close();
}


ATM::ATM(void)
{
}


ATM::~ATM(void)
{
}


int ATM :: DangNhap()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "****************************** DANG NHAP ****************************" << endl;
	int dem = 0;
	do {
		cout << "\nLUU Y : NHAP SAI 3 LAN TU DONG THOAT!";
		SetConsoleTextAttribute(hConsoleColor, 9);
		cout << "\t\t\n******************************";
		cout << "\t\t\n*        "; 
		SetConsoleTextAttribute(hConsoleColor, 12);
		cout << "DANG NHAP";
		SetConsoleTextAttribute(hConsoleColor, 9);
		cout << "           *";
		cout << "\t\t\n******************************";
		SetConsoleTextAttribute(hConsoleColor, 7);
		SetConsoleTextAttribute(hConsoleColor, 11);
		cout <<"Ten dang nhap :";
		getline( cin, ten);
		cout <<"Nhap ma pin :";
		getline (cin, mk);
		SetConsoleTextAttribute(hConsoleColor, 7);
		cout << "\nDang kiem tra..." << endl;
		Sleep(1000);
		for (int i=0; i< n; i++)
		{
			if ( ten == TK[i].getTenTK() && mk == TK[i].getMaPIN())
			{
				return 1;
			}
		}
		dem++;
		system("cls");
	}
	while (dem <= 3);
	cout <<"\n!!!!!!!!!!!!!!Dang Nhap Khong Thanh Cong " << endl;
	cout<<setw(10)<<"***************************************"<<endl;
	cout<<setw(10)<<" * VUI LONG! DANG NHAP LAI 1 LAN NUA *"<<endl;
	cout<<setw(10)<<"**************************************"<<endl;
	SetConsoleTextAttribute(hConsoleColor, 7);
	SetConsoleTextAttribute(hConsoleColor, 11);
	cout <<"Ten dang nhap :";
	getline( cin, ten);
	cout <<"Nhap ma pin :";
	getline (cin, mk);
	SetConsoleTextAttribute(hConsoleColor, 7);
	cout << "\nDang kiem tra..." << endl;
	Sleep(1000);
	for (int i=0; i< n; i++)
	{
		if ( ten == TK[i].getTenTK() && mk == TK[i].getMaPIN())
		{
			return 1;
		}
	}
	n++;
	system("cls");
	return -1;
}
		
int ATM::chiSoI(string ten, string mk)
{
	for (int i = 0; i < n; i++)
	{
		if (ten == TK[i].getTenTK() && mk == TK[i].getMaPIN())
		{
			return i;
		}
	}
	return -1;
}
//ghi file
void ATM ::ghiFile()
{
	fstream f;
	f.open ("file[ID].txt", ios :: out);
	for (int i=0; i<n; i++)
	{
		f << TK[i].getID() << "\n";
		f << TK[i].getTenTK() << "\n";
		f << TK[i].getMaPIN() << "\n";
		f << TK[i].getTK() << "\n";
	}
	f.close();
}

void ATM::RutTien()
{
	float tienRut;
	cout <<"\nNhap so tien can rut :";
	cin >> tienRut;
	cout << "\nLoading...";
	Sleep(1000);
	if( tienRut >= 50000 && tienRut <= TK[chiSoI(ten, mk)].getTK() - 50000 ) // dieu kien sai nhap lai
	{
		cout <<"\nRut tien thanh cong !";
		TK[chiSoI(ten, mk)].dTK  = TK[chiSoI(ten, mk)].dTK - tienRut;
	}
	else 
		cout <<"\nGiao dich that bai !";
}

void ATM::ChuyenTien()
{
	string ID;
	float tienRut;
	do {
		cout <<"\nNhap so tien can chuyen :";
		cin >> tienRut;
		cin.ignore();
		cout <<"\nNhap ID nguoi nhan tien :";
		getline (cin, ID);
		cout << "\nLoading...";
		Sleep(1000);
		if ( ID == TK[chiSoI(ten, mk)].getID())
		{
			cout <<"\nKhong the nhap ID cua ban than";
			break;
		}
		else
		{
			if (tienRut > 50000 && tienRut < TK[chiSoI(ten , mk)].getTK() - 50000)
			{
				TK[chiSoI(ten, mk)].dTK = TK[chiSoI(ten, mk)].getTK() - tienRut;
				for (int i=0; i<n; i++)
				{
					if (ID == TK[i].getID())
						TK[i].dTK += tienRut;
				}
				cout <<"\nLoading...";
				Sleep(1000);
				cout <<"\n\tChuyen tien thanh cong " << endl;
				time_t hientai = time(0);
				// chuyen doi hientai thanh dang chuoi
				char* dt = ctime(&hientai);
				cout << "Thoi gian giao dich la: " << dt << endl;
				break; //dung vong lap
			}
			else 
			{
				cout <<"\n\tGiao dich khong thanh cong";
				break;
			}
			system("cls");
		}
	}
	while (tienRut <= 50000 && tienRut >= TK[chiSoI(ten, mk)].getTK() - 50000);
}
//ham menu
void ATM :: Menu()
{
	int chon;
	string ten, mk;
	int tg = 0;
	if (DangNhap () == 1)
	{
		do {
			cout <<"\nLoading...";
			Sleep(2000);
			system("cls");
			cout << "\n***********************************************";
			cout << "\n**   ";
			cout << "CHAO MUNG BAN DEN VOI ATM LTHDT";
			cout << "    **";
			cout << "\n***********************************************";
			Sleep(1000);
			cout <<"\n1. Rut tien";
			cout <<"\n2. Chuyen tien";
			cout <<"\n0. Exit";
			cout <<"\nMoi ban chon giao dich :";
			cin >> chon;
			switch (chon)
			{
			case 1:
				RutTien ();
				ghiFile ();
				cout <<"\nSo du con lai :" << TK[chiSoI(ten, mk)].getTK() << endl;
				Sleep(2000);
				break;
			case 2:
				ChuyenTien ();
				ghiFile();
				Sleep(2000);
				break;
			case 0:
				exit (1);
			}
		}
		while (chon);
	}
}


			
		