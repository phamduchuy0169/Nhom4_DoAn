#include "TAIKHOAN.h"
#include"iostream"
using namespace std;
void TAIKHOAN::setcTenTK(string tam)
{
	cTenTK = tam;
}
void TAIKHOAN::setcID(string tam)
{
	cID = tam;
}
void TAIKHOAN :: setcMaPIN (string tam)
{
	cMaPIN = tam;
}
void TAIKHOAN :: setdTK (string tam)
{
	dTK = stof(tam);
}

string TAIKHOAN::getID()
{
	return cID;
}

string TAIKHOAN :: getTenTK()
{
	return cTenTK;
}

string TAIKHOAN :: getMaPIN()
{
	return cMaPIN;
}

float TAIKHOAN :: getTK()
{
	return dTK;
}

TAIKHOAN::TAIKHOAN(void)
{
}


TAIKHOAN::~TAIKHOAN(void)
{
}
