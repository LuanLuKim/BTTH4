#include "CTime.h"
// Ham chuan hoa thoi gian
// Input: Thoi gian
// Output: Thoi gian khi da chuan hoa theo chuan
void CTime::ChuanHoa()
{
	int totalSeconds = hour * 3600 + minute * 60 + second;
	totalSeconds = (totalSeconds % 86400 + 86400) % 86400;

	hour = totalSeconds / 3600;
	totalSeconds %= 3600;

	minute = totalSeconds / 60;
	second = totalSeconds % 60;
}
// Toan tu cong
// Input: So nguyen x giay
// Output: Thoi gian khi da qua x giay
CTime CTime:: operator+(int sec) const
{
	CTime temp = *this;
	temp.second += sec;
	temp.ChuanHoa();
	return temp;
}
// Toan tu tru
// Input: So nguyen x giay
// Output: Thoi gian khi truoc do x giay
CTime CTime:: operator-(int sec) const
{
	CTime temp = *this;
	temp.second -= sec;
	temp.ChuanHoa();
	return temp;
}
// Toan tu tang tien to
// Input: Khong co
// Output: Thoi gian khi troi qua 1 giay
CTime& CTime:: operator++()
{
	second++;
	ChuanHoa();
	return *this;
}
// Toan tu tang hau to
// Input: 1 input gia
// Output: Tra ve thoi gian hien tai, sau do tang thoi gian len 1 giay
CTime CTime:: operator++(int)
{
	CTime temp = *this;
	this->second++;
	this->ChuanHoa();
	return temp;
}
// Toan tu giam tien to
// Input: Khong co
// Output: Thoi gian khi truoc do 1 giay
CTime& CTime:: operator--()
{
	second--;
	ChuanHoa();
	return *this;
}
// Toan tu giam hau to
// Input: Khong co
// Output: Tra ve thoi gian hien tai, sau do giam thoi gian xuong 1 giay
CTime CTime:: operator--(int)
{
	CTime temp = *this;
	this->second--;
	this->ChuanHoa();
	return temp;
}
// Toan tu nhap
// Input: Gio, phut, giay
// Output: Nhap gia tri cho CTime
istream& operator>>(istream& in, CTime& t)
{
	cout << "Nhap gio: "; in >> t.hour;
	cout << "Nhap phut: "; in >> t.minute;
	cout << "Nhap giay: "; in >> t.second;
	return in;
}
// Toan tu xuat
// Input: CTime
// Output: Thoi gian da chuan hoa theo gio:phut:giay
ostream& operator<<(ostream& out, const CTime& t)
{
	out << setfill('0') << setw(2) << t.hour << ":"
		<< setw(2) << t.minute << ":"
		<< setw(2) << t.second;
	return out;
}
