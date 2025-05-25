#include "PhanSo.h"
// Ham tìm UCLN
// Input: 2 so nguyen a, b
// Output: UCLN giua 2 so
// Huong giai quyet: Dung thuat toan Euclid
int gcd(int a, int b)
{
	a = abs(a); b = abs(b);
	while (a != 0 && b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a + b;
}
// Ham rut gon phan so
// Input: Phan so
// Output: Phan so khi da duoc rut gon
// Huong giai quyet: Tim UCLN roi chia voi tu mau de rut gon
void PhanSo::rutGon()
{
	int g = gcd(tu, mau);
	tu = tu / g;
	mau = mau / g;
	if (mau < 0)
	{
		tu *= -1;
		mau *= -1;
	}
}
//Toan tu cong
//Input: 2 phan si
//Outpu : Ket qua phep cong phan so
PhanSo PhanSo:: operator +(const PhanSo& other) const
{
	PhanSo Tong;
	Tong.tu = tu * other.mau + other.tu * mau;
	Tong.mau = mau * other.mau;
	Tong.rutGon();

	return Tong;
}
//Toan tu tru
//Input: 2 phan si
//Outpu : Ket qua phep tru phan so
PhanSo PhanSo:: operator -(const PhanSo& other) const
{
	PhanSo Hieu;
	Hieu.tu = tu * other.mau - other.tu * mau;
	Hieu.mau = mau * other.mau;
	Hieu.rutGon();

	return Hieu;
}
//Toan tu nhan
//Input: 2 phan si
//Outpu : Ket qua phep nhan phan so
PhanSo PhanSo:: operator *(const PhanSo& other) const
{
	PhanSo Tich;
	Tich.tu = tu * other.tu;
	Tich.mau = mau * other.mau;

	Tich.rutGon();
	return Tich;
}
//Toan tu chia
//Input: 2 phan si
//Outpu : Ket qua phep chia phan so (sau khi da xu ly ngoai le)
PhanSo PhanSo:: operator /(const PhanSo& other) const
{
	PhanSo Thuong;
	Thuong.tu = tu * other.mau;
	Thuong.mau = mau * other.tu;

	Thuong.rutGon();
	return Thuong;
}
//Toan tu so sanh bang
//Input: 2 phan si
//Outpu : Ket qua phep so sanh bang
bool PhanSo:: operator == (const PhanSo& other) const
{
	return(tu == other.tu && mau == other.mau);
}
//Toan tu so sanh khong bang
//Input: 2 phan si
//Outpu : Ket qua phep so sanh khong bang
bool PhanSo:: operator != (const PhanSo& other) const
{
	return !(*this == other);
}
//Toan tu nhap
//Input: Tu so va mau so
//Outpu : Phan so
istream& operator >> (istream& in, PhanSo& This)
{
	cout << "Nhap tu so: "; in >> This.tu;
	while (true)
	{
		cout << "Nhap mau so: "; in >> This.mau;
		if (This.mau == 0)
			cout << "Phan so khong thoa, nhap lai mau so." << endl;
		else
		{
			This.rutGon();
			return in;
		}
	}
}
//Toan tu xuat
//Input: Phan so
//Outpu : Phan so da duoc chuan hoa
ostream& operator << (ostream& out, const PhanSo& This)
{
	if (This.tu == 0) out << 0;
	else
	{
		out << This.tu;
		if (This.mau != 1)
			out << '/' << This.mau;
	}
	return out;
}