#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main() 
{
	SoPhuc a, b;
	SoPhuc sum, Hieu, Tich, Thuong;

	cin >> a >> b;
	cout << a << endl;
	cout << b << endl;

	sum = a + b;
	Hieu = a - b;
	Tich = a * b;
	cout << "Tong = " << sum << endl;
	cout << "Hieu = " << Hieu << endl;
	cout << "Tich = " << Tich << endl;


	if (b == 0)
	{
		cout << "Khong the thuc hien phep chia";
	}
	else
	{
		Thuong = a / b;
		cout <<"Thuong = "<< Thuong << endl;
	}

	if (a == b)
		cout << "So phuc a = so phuc b";
	if (a != b)
		cout << "So phuc a khong = so phuc b";
}
