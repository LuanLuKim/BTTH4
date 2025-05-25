#include "DonThuc.h"
#include <cmath>
#include <iostream>

using namespace std;
// Ham tinh gia tri cua da thuc tai x
// Input: Gia tri x la so thuc
// Output: Gia tri cua da thuc sau khi thay x vao
// Huong giai quyet: Thay vao don thuc de tinh
float DonThuc::tinhGiaTri(float x) const 
{
    return heSo * pow(x, soMu);
}
// Toan tu cong hai don thuc
// Input: Doi tuong don thuc b
// Output: Don thuc moi la tong cua hai da thuc
// Huong giai quyet: Neu cung so mu thi tra ve don thuc co he so bang tong 2 he so
//                   Neu khac so mu thi tra ve DonThuc this
DonThuc DonThuc::operator+(const DonThuc& dt) const 
{
    if (soMu == dt.soMu)
        return DonThuc(heSo + dt.heSo, soMu);
    return *this;
}
// Toan tu tru hai don thuc
// Input: Doi tuong don thuc b
// Output: Don thuc moi la hieu cua hai da thuc
// Huong giai quyet: Neu cung so mu thi tra ve don thuc co he so bang hieu 2 he so
//                   Neu khac so mu thi tra ve DonThuc this
DonThuc DonThuc::operator-(const DonThuc& dt) const
{
    if (soMu == dt.soMu)
        return DonThuc(heSo - dt.heSo, soMu);
    return *this;
}
// Toan tu doi dau don thuc
// Input: Khong co
// Output: Don thuc moi la nghich dao dau
// Huong giai quyet: Doi dau he so
DonThuc DonThuc::operator-() const
{
    return DonThuc(-1*heSo, soMu);
}
// Toan tu nhan 2 don thuc
// Input: Doi tuong don thuc b
// Output: Don thuc moi la tich cua hai da thuc
// Huong giai quyet: Lay he so nhan he so, so mu nhan so mu
DonThuc DonThuc::operator*(const DonThuc& dt) const
{
    return DonThuc(heSo * dt.heSo, soMu + dt.soMu);
}
// Toan tu nhap
// Input: Doi tuong don thuc can nhap
// Output: Don thuc duoc nhap
istream& operator>>(istream& in, DonThuc& dt) {
    std::cout << "Nhap he so: ";
    in >> dt.heSo;
    std::cout << "Nhap bac: ";
    in >> dt.soMu;
    return in;
}
// Toan tu xuat
// Input: Doi tuong don thuc can xuat
// Output: Don thuc duoc xuat tren man hinh
ostream& operator<< (ostream& out, const DonThuc& dt)
{
    if (dt.soMu == 0)
        out << dt.heSo;
    else
    {
        if (dt.heSo != 1 && dt.heSo != -1)
        {
            if (dt.soMu == 1)
                cout << dt.heSo << "x";
            else
                cout << dt.heSo << "x^" << dt.soMu;
        }
        else if (dt.heSo == -1)
        {
            if (dt.soMu == 1)
                out << "-x";
            else
                out << "-x^" << dt.soMu;
        }
        else
        {
            if (dt.soMu == 1)
                out << "x";
            else
                out << "x^" << dt.soMu;
        }
    }
    return out;
}

