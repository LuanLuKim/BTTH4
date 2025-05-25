#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class cVector
{
private:
	vector<double> data;
	int soChieu;
public:
	// Ham tao khong doi
	// Input: Khong co
	// Output: Thay doi chieu mac dinh thanh 0
	cVector() { soChieu = 0; }
	// Ham tao co doi
	// Input: So nguyen dim dai dien so chieu
	// Output: Thay doi chieu mac dinh thanh dim va vector thanh vector 0
	cVector(int dim):soChieu(dim), data(dim, 0.0) {}
	cVector(const cVector& other);
	friend istream& operator>>(istream& in, cVector& vec);
	friend ostream& operator<<(ostream& out,const cVector& vec);

	double& operator[](int index);
	double operator[](int index) const;

	cVector operator+(const cVector& vec) const;
	cVector operator-(const cVector& vec) const;
	cVector& operator=(const cVector& vec);
	
	// Ham lay so chieu
	// Input: Khong co
	// Output: Tra ve so nguyen dai dien cho so chieu
	int getSoChieu() const { return soChieu; }
	double tichVoHuong(const cVector& vec) const;

	~cVector() { data.clear(); }
};

