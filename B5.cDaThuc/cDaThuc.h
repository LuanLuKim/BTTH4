#pragma once
#include "DonThuc.h"
#include <algorithm>
#include <map>

using namespace std;

class cDaThuc : public DonThuc
{
private:
	vector<DonThuc> dt;
	int soLuong;
	void rutGon();
public:
	cDaThuc() { soLuong = 0; }
	cDaThuc(const cDaThuc& other);
	cDaThuc& operator=(const cDaThuc& other);
	~cDaThuc() { dt.clear(); }

	friend istream& operator>>(istream& in, cDaThuc dth);
	friend ostream& operator<<(std::ostream& out, const cDaThuc& dth);

	float tinhGiaTri(float x) const;

	cDaThuc operator +(const cDaThuc& b) const;
	cDaThuc operator -(const cDaThuc& b) const;
	cDaThuc operator*(const cDaThuc& dt) const;
};

