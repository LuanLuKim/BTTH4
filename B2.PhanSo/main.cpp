#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() 
{
	PhanSo a, b;
	PhanSo tong, hieu, tich;
	cin >> a >> b;
	cout << a << endl;
	cout << b << endl;

	tong = a + b;
	hieu = a - b;
	tich = a * b;
	cout << "Tong = " << tong << endl;
	cout << "Hieu = " << hieu << endl;
	cout << "Tich = " << tich << endl;

	if (b == 0)
		cout << "Khong the thuc hien phep chia."<<endl;
	else
	{
		PhanSo thuong;
		thuong = a / b;
		cout <<"Thuong = "<< thuong << '\n';
	}

	if (a == b)
		cout << "Phan so a = phan so b";
	if (a != b)
		cout << "Phan so a khong bang phan so b";

	return 0;
}
