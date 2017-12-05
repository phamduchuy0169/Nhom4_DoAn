#pragma once
#include"TAIKHOAN.h"
#include <iostream>
using namespace std;
class ATM
{
private:
	TAIKHOAN TK[100];
	int n; //so luong tai khoan sau khi doc file
	string ten, mk;
public:
	void setTK();
	ATM(void);
	~ATM(void);
	int DangNhap();
	void ghiFile ();
	int chiSoI(string ten, string mk);
	void ChuyenTien();
	void RutTien();
	void Menu();
	
};

