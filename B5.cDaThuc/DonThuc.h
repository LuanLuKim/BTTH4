#pragma once
#include <iostream>
#include <vector>
using namespace std;
class DonThuc
{
protected:
    float heSo;
    int soMu;

public:
    // Ham khoi tao co doi
    // Input: 2 so hs va sm
    // Output: Tao don thuc voi he so = hs va so mu = sm
    DonThuc(float hs = 0, int sm = 0) : heSo(hs), soMu(sm) {}

    // Ham lay he so
    // Input: Khong co
    // Output: Gia tri cua he so
    float getHeSo() const { return heSo; }
    // Ham lay so mu
    // Input: Khong co
    // Output: Gia tri cua so mu
    int getSoMu() const { return soMu; }

    float tinhGiaTri(float x) const;
    DonThuc operator+(const DonThuc& dt) const;
    DonThuc operator-(const DonThuc& dt) const;
    DonThuc operator*(const DonThuc& dt) const;
    DonThuc operator-() const;
    friend ostream& operator<< (ostream& out, const DonThuc& dt);
    friend istream& operator>>(istream& in, DonThuc& dt);
    ~DonThuc() {}
};

