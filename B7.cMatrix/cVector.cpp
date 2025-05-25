#include "cVector.h"
// Ham tao sao chep
// Input: 1 cVector khac
// Output: Thay doi cVector nay theo cVector vec
cVector::cVector(const cVector& vec)
{
	soChieu = vec.soChieu;
    data.resize(soChieu);
	for (int i = 0; i < soChieu; i++)
		data[i] = vec.data[i];
}
// Toan tu nhap
// Input: So chieu va gia tri tung phan tu trong vector tu ban phim
// Output: Khong co
istream& operator>>(istream& in, cVector& vec) 
{
    for (int i = 0; i < vec.soChieu; ++i) 
    {
        cout << "  Phan tu " << i+1 << ": ";
        in >> vec.data[i];
    }
    return in;
}
// Toan tu xuat
// Input: Ban than cVector
// Output: cVector ra man hinh theo chuan
ostream& operator<<(ostream& out, const cVector& vec) 
{
    for (int i = 0; i < vec.soChieu; ++i)
        out << vec.data[i] << " ";
    return out;
}
// Toan tu truy cap co tham chieu
// Input: So nguyen index dai dien chi vi tri muon tro den
// Output: Gia tri phan tu tai index, cho phep thay doi
double& cVector::operator[](int index) 
{
    return data[index];
}
// Toan tu truy cap khong tham chieu
// Input: So nguyen index dai dien chi vi tri muon tro den
// Output: Gia tri phan tu tai index, khong cho phep thay doi
double cVector::operator[](int index) const 
{
    return data[index];
}
// Toan tu cong
// Input: 1 cVector vec
// Output: 1 cVector la tong 2 vector
// Huong giai quyet: Neu cung kich thuoc thi cong cac phan tu o vi tri tuong uong cho nhau
//                   Neu khac so chieu thi dua ra loi "Vector khong cung kich thuoc"
cVector cVector::operator+(const cVector& vec) const 
{
    if (soChieu != vec.soChieu)
        throw runtime_error("Vector khong cung kich thuoc");

    cVector result(soChieu);
    for (int i = 0; i < soChieu; ++i)
        result[i] = data[i] + vec.data[i];
    return result;
}
// Toan tu tru
// Input: 1 cVector vec
// Output: 1 cVector la hieu 2 vector
// Huong giai quyet: Neu cung kich thuoc thi tru cac phan tu o vi tri tuong uong cho nhau
//                   Neu khac so chieu thi dua ra loi "Vector khong cung kich thuoc"
cVector cVector::operator-(const cVector& vec) const 
{
    if (soChieu != vec.soChieu)
        throw runtime_error("Vector khong cung kich thuoc");

    cVector result(soChieu);
    for (int i = 0; i < soChieu; ++i)
        result[i] = data[i] - vec.data[i];
    return result;
}
// Toan tu gan
// Input: 1 cVector vec
// Output: Gan gia tri vec cho cVector ma this tro toi
cVector& cVector::operator=(const cVector& vec) 
{
    if (this != &vec)
        data = vec.data;
    return *this;
}
// Ham tinh tich vo huong 2 vector
// Input: 1 cVector vec
// Output: Tich vo huong cua ca 2
// Huong giai quyet: Ap dung cong thuc tich vo huong. Neu khac so chieu thi bao loi
double cVector::tichVoHuong(const cVector& vec) const 
{
    if (soChieu != vec.soChieu)
        throw runtime_error("Vector khong cung kich thuoc");

    double result = 0;
    for (int i = 0; i < data.size(); ++i)
        result += data[i] * vec.data[i];
    return result;
}