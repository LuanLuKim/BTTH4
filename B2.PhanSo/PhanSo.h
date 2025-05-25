#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class PhanSo
{
private:
	int tu;
	int mau;
	void rutGon();
public:
	PhanSo(int a = 0)
	{
		tu = a;
		mau = 1;
		this->rutGon();
	}
	PhanSo operator +(const PhanSo& other) const;
	PhanSo operator -(const PhanSo& other) const;
	PhanSo operator *(const PhanSo& other) const;
	PhanSo operator /(const PhanSo& other) const;
	bool operator == (const PhanSo& other) const;
	bool operator != (const PhanSo& other) const;

	friend istream& operator >> (istream& in, PhanSo& This);
	friend ostream& operator << (ostream& out, const PhanSo& This);
};

