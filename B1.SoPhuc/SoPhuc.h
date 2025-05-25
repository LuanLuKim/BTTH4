#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class SoPhuc
{
private:
	double Thuc;
	double Ao;
public:
	SoPhuc(int a = 0) 
	{
		Thuc = a;
		Ao = 0; 
	}
	SoPhuc operator +(const SoPhuc& other) const;
	SoPhuc operator -(const SoPhuc& other) const;
	SoPhuc operator *(const SoPhuc& other) const;
	SoPhuc operator /(const SoPhuc& other) const;
	bool operator == (const SoPhuc& other) const;
	bool operator != (const SoPhuc& other) const;

	friend istream& operator >> (istream& in, SoPhuc& This);
	friend ostream& operator << (ostream& out,const SoPhuc& This);
	~SoPhuc(){}
};

