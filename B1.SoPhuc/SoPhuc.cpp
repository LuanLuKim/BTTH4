#include "SoPhuc.h"
//Toan tu cong
//Input: 2 so phuc
//Output : Ket qua phep cong so phuc
SoPhuc SoPhuc:: operator+(const SoPhuc& other) const
{
	SoPhuc sum;
	sum.Thuc = Thuc + other.Thuc;
	sum.Ao = Ao + other.Ao;
	return sum;
}
//Toan tu tru
//Input: 2 so phuc
//Output : Ket qua phep tru so phuc
SoPhuc SoPhuc:: operator-(const SoPhuc& other) const
{
	SoPhuc minus;
	minus.Thuc = Thuc - other.Thuc;
	minus.Ao = Ao - other.Ao;
	return minus;
}
//Toan tu nhan
//Input: 2 so phuc
//Output : Ket qua phep nhan so phuc
SoPhuc SoPhuc:: operator*(const SoPhuc& other) const
{
	SoPhuc Tich;
	Tich.Thuc = Thuc * other.Thuc - Ao * other.Ao;
	Tich.Ao = Ao * other.Thuc + Thuc * other.Ao;

	return Tich;
}
//Toan tu chia
//Input: 2 so phuc
//Output : Ket qua phep chia so phuc(sau khi xu ly ngoai le).
SoPhuc SoPhuc:: operator/(const SoPhuc& other) const
{
	SoPhuc Thuong;
	Thuong.Thuc = (Thuc * other.Thuc + Ao * other.Ao) / (other.Thuc * other.Thuc + other.Ao * other.Ao);
	Thuong.Ao = (Ao * other.Thuc - Thuc * other.Ao) / (other.Thuc * other.Thuc + other.Ao * other.Ao);

	return Thuong;
}
//Toan tu so sanh bang
//Input: 2 so phuc
//Output : Ket qua phep so sanh bang
bool SoPhuc:: operator == (const SoPhuc& other) const
{
	return (Thuc == other.Thuc) && (Ao == other.Ao);
}
//Toan tu so sanh khong bang
//Input: 2 so phuc
//Output : Ket qua phep so sanh khong bang
bool SoPhuc:: operator != (const SoPhuc& other) const
{
	return (*this == other);
}
//Toan tu nhap
//Input: Gia tri phan thuc, phan ao
//Outputt : So phuc
istream& operator >> (istream& in, SoPhuc& This)
{
	cout << "Nhap phan thuc: ";
	in >> This.Thuc;
	cout << "Nhap phan ao: ";
	in >> This.Ao;
	return in;
}
//Toan tu xuat
//Input: So phuc
//Outputt : So phuc da duoc chuan hoa dau ra
ostream& operator << (ostream& out, const SoPhuc& This)
{
	if (This.Thuc == 0)
	{
		if (This.Ao == 0)
			out << 0;
		else
			out << This.Ao << 'i';
	}
	else
	{
		out << This.Thuc;
		if (This.Ao > 0)
			out << '+' << This.Ao << 'i';
		else
		{
			if (This.Ao != 0)
				out << This.Ao << 'i';
		}
	}

	return out;
}
