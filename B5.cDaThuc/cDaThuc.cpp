#include "cDaThuc.h"
// Ham khoi tao sao chep
// Input: Mot doi tuong da thuc other
// Output: Tao doi tuong moi sao chep cac don thuc cua other
// Huong giai quyet: Cap phat mang moi va sao chep tung don thuc trong other sang doi tuong hien tai
cDaThuc::cDaThuc(const cDaThuc& other) 
{
    dt.clear();
    soLuong = other.soLuong;
    for (int i = 0; i < soLuong; ++i) 
        dt.push_back( other.dt[i]);
}
// Ham rut gon da thuc
// Input: Khong co
// Output: Khong co
// Huong giai quyet: Rut gon da thuc cung so mu lai thanh 1
void cDaThuc::rutGon() 
{
    map<int, double, greater<int>> bacToHeSo;

    for (const auto& d : dt) {
        bacToHeSo[d.getSoMu()] += d.getHeSo();
    }

    dt.clear();
    for (const auto& d : bacToHeSo) {
        if (d.second != 0) 
        {
            dt.push_back(DonThuc(d.second, d.first));
        }
    }
}
// Toan tu gan
// Input: Mot doi tuong da thuc other
// Output: Gan cac gia tri va don thuc cua other cho doi tuong hien tai
// Huong giai quyet: Neu khong tu gan thi xoa mang cu cap phat lai mang moi va sao chep tung don thuc tu other
cDaThuc& cDaThuc::operator=(const cDaThuc& other) 
{
    if (this == &other) return *this;

    soLuong = other.soLuong;
    dt.clear();
    for (int i = 0; i < soLuong; ++i)
        dt.push_back(other.dt[i]);
    return *this;
}
// Toan tu nhap da thuc
// Input: So luong don thuc va tung he so so mu cua don thuc do tu ban phim
// Output: Mang cac don thuc duoc cap phat va luu vao doi tuong hien tai
// Huong giai quyet: Xoa mang cu neu co sau do cap phat mang moi roi lan luot nhap cac don thuc thong qua phuong thuoc nhap cua don thuc
istream& operator>>(istream& in, cDaThuc dth)
{
    dth.dt.clear();
    cout << "Nhap so don thuc: ";
    cin >> dth.soLuong;
    dth.dt.resize(dth.soLuong);

    for (int i = 0; i < dth.soLuong; i++)
    {
        cout << "Don thuc thu " << i + 1 << ":\n";
        in >> dth.dt[i];
    }
    return in;
}
// Toan tu xuat da thuc ra man hinh
// Input: Khong co
// Output: In ra bieu thuc da thuc theo dinh dang toan hoc
// Huong giai quyet: Bo qua don thuc co he so bang 0.
//                   Don thuc dau tien xuat binh thuong thong qua phuong thuc xuat cua don thuc va cac dau cong tru theo chuan
ostream& operator<<(std::ostream& out, const cDaThuc& dth) {
    bool first = true;
    for (int i = 0; i < dth.soLuong; i++)
    {
        if (dth.dt[i].getHeSo() == 0) continue;

        if (first)
        {
            first = false;
            out<<dth.dt[i];
        }
        else
        {
            if (dth.dt[i].getHeSo() > 0)
                out << '+';
            out<<dth.dt[i];
        }
    }
    if (first) out << 0;
    out << endl;
    return out;
}
// Ham tinh gia tri cua da thuc tai x
// Input: Gia tri x la so thuc
// Output: Gia tri cua da thuc sau khi thay x vao
// Huong giai quyet: Duyet tung don thuc tinh gia tri tai x roi cong vao bien tong
float cDaThuc::tinhGiaTri(float x) const {
    float tong = 0;
    for (int i = 0; i < soLuong; i++) {
        tong += dt[i].tinhGiaTri(x);
    }
    return tong;
}
// Toan tu cong hai da thuc
// Input: Doi tuong da thuc b
// Output: Doi tuong da thuc moi la tong cua hai da thuc
// Huong giai quyet: Duyet dong thoi hai mang don thuc gop chung cac don thuc co cung so mu va cong he so con lai giu nguyen.
//                   Sau do cat bo don thuc co he so bang 0
cDaThuc cDaThuc:: operator +(const cDaThuc& b) const
{
    cDaThuc tong;

    int i = 0, j = 0;

    while (i < soLuong && j < b.soLuong)
    {
        if (dt[i].getSoMu() > b.dt[j].getSoMu())
            tong.dt.push_back( dt[i++]);
        else if (dt[i].getSoMu() < b.dt[j].getSoMu())
            tong.dt.push_back(b.dt[j++]);
        else
        {
            tong.dt.push_back( dt[i] + b.dt[i]);
            i++, j++;
        }
    }

    while (i < soLuong)
        tong.dt.push_back(dt[i++]);
    while (j < b.soLuong)
        tong.dt.push_back(b.dt[j++]);

    tong.soLuong = dt.size();
    return tong;
}
// Toan tu tru hai da thuc
// Input: Doi tuong da thuc b
// Output: Doi tuong da thuc moi la hieu cua hai da thuc
// Huong giai quyet: Duyet dong thoi hai mang don thuc gop chung cac don thuc co cung so mu va tru he so.
//                   Neu khac so mu thi giu nguyen hoac doi dau tuong ung.
//                   Cuoi cung cat bo don thuc co he so bang 0
cDaThuc cDaThuc:: operator -(const cDaThuc& b) const
{
    cDaThuc hieu;

    int i = 0, j = 0;

    while (i < soLuong && j < b.soLuong)
    {
        if (dt[i].getSoMu() > b.dt[j].getSoMu())
            hieu.dt.push_back(dt[i++]);
        else if (dt[i].getSoMu() < b.dt[j].getSoMu())
        {
            hieu.dt.push_back(-b.dt[i]);
        }
        else
        {
            hieu.dt.push_back(dt[i] - b.dt[i]);
            i++, j++;
        }
    }

    while (i < soLuong)
        hieu.dt.push_back(dt[i++]);
    while (j < b.soLuong)
    {
        DonThuc temp(-1 * b.dt[j].getHeSo(), b.dt[j++].getSoMu());
        hieu.dt.push_back(temp);
    }

    hieu.soLuong = dt.size();
    return hieu;
}
// Toan tu nhan hai da thuc
// Input: Doi tuong da thuc b
// Output: Doi tuong da thuc moi la tich cua hai da thuc
// Huong giai quyet: Duyet lan luot tung don thuc trong da thuc nay nhan lan luot tung don thuc trong da thuc other
//                   Dua vao da thuc tich va rut gon
cDaThuc cDaThuc::operator*(const cDaThuc& other) const
{
    cDaThuc tich;

    for (const auto& dt1 : this->dt) {
        for (const auto& dt2 : other.dt) {
            DonThuc donThucTich = dt1 * dt2;
            tich.dt.push_back(donThucTich);
        }
    }

    tich.rutGon();
    return tich;
}