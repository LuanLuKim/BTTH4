#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class CTime
{
private:
	int hour, minute, second;
	void ChuanHoa();
public:
	// Ham tao co doi so mac dinh
	// Input: 3 so nguyen gio, phut, giay
	// Output: CTime da duoc chuan hoa
	CTime(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) 
	{
		this->ChuanHoa();
	}
	CTime operator+(int sec) const;
	CTime operator-(int sec) const;
	CTime& operator++();
	CTime operator++(int);
	CTime& operator--();
	CTime operator--(int);

	friend istream& operator>>(istream& in, CTime& t);
	friend ostream& operator<<(ostream& out,const CTime& t);
	~CTime(){}
};

