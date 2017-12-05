#pragma once
#include <string>
using namespace std;
class TAIKHOAN
{
private:
	string cID, cTenTK, cMaPIN;
	float dTK; // bien chua so tien trong tai khoan
public:
	void setcID(string tam);
	void setcTenTK(string tam);
	void setcMaPIN(string tam);
	void setdTK(string tam);
	string getID();
	string getTenTK();
	string getMaPIN();
	float getTK();
	TAIKHOAN(void);
	~TAIKHOAN(void);
	friend class ATM;
};

