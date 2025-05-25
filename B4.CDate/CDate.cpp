#include "CDate.h"
// Ham kiem tra nam nhuan
// Input: Nam can kiem tra
// Output: 1 - nam nhuan, 0 - khong nhuam
bool CDate::isLeapYear() const 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// Ham tinh ngay toi da trong thang
// Input: Nam va thang can tinh toan
// Output: Ngay toi da cua thang do
// Huong giai quyet: Xuat ra ngay toi da, neu la thang 2 thi kiem tra nam co nhuan khong.
//                   Neu co thi thang 2 co 29 ngay - Ko thi 28 ngay
int CDate::daysInMonth() const 
{
    static int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && this->isLeapYear()) return 29;
    return days[month - 1];
}
// Ham kiem tra ngay thang nam hop le
// Input: Khong co
// Output: 1 neu ngay thang nam hop le / 0 neu ngay thang nam khong hop le
bool CDate::isValid() const 
{
    if (year < 1 || month < 1 || month > 12 || day < 1) return false;
    if (day > daysInMonth()) return false;
    return true;
}
// Toan tu nhap
// Input: Gia tri ngay thang nam tu ban phim
// Output: Khong co
std::istream& operator>>(std::istream& in, CDate& d) 
{
    do {
        std::cout << "Nhap ngay/thang/nam (dd mm yyyy): ";
        in >> d.day >> d.month >> d.year;

        if (!d.isValid())
            std::cout << "Ngay khong hop le. Vui long nhap lai!\n";
    } while (!d.isValid());
    return in;
}
// Toan tu xuat
// Input: Gia tri ngay thang nam
// Output: Ngay thang nam theo chuan ra man hinh
std::ostream& operator<<(std::ostream& out, const CDate& d) 
{
    out << (d.day < 10 ? "0" : "") << d.day << "/"
        << (d.month < 10 ? "0" : "") << d.month << "/"
        << d.year<<endl;
    return out;
}
// Ham chuyen doi tu ngay thang nam sang ngay Julian
// Input: Khong co
// Output: Ngay Julian tuong ung
// Huong giai quyet: Dung cong thuc chuyen doi
int CDate::toJulianDay() const 
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}
// Ham chuyen doi tu ngay Julian sang ngay thang nam
// Input: Ngay Julian
// Output: Ngay thang nam tuong ung
// Huong giai quyet: Dung cong thuc chuyen doi
void CDate::fromJulianDay(int jd) 
{
    int a = jd + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (146097 * b) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;

    day = e - (153 * m + 2) / 5 + 1;
    month = m + 3 - 12 * (m / 10);
    year = 100 * b + d - 4800 + (m / 10);
}
// Toan tu cong
// Input: Gia tri ngay can tang
// Output: Ngay thang nam sau khi tang
CDate CDate::operator+(int days) const 
{
    CDate result;
    result.fromJulianDay(this->toJulianDay() + days);
    return result;
}
// Toan tu tru
// Input: Gia tri ngay can giam
// Output: Ngay thang nam sau khi giam
CDate CDate::operator-(int days) const 
{
    CDate result;
    result.fromJulianDay(this->toJulianDay() - days);
    return result;
}
// Toan tu tru
// Input: Gia tri CDate
// Output: Chenh lech giua 2 khoang thoi gian
int CDate::operator-(const CDate& other) const 
{
    return this->toJulianDay() - other.toJulianDay();
}
// Toan tu tang (tien to)
// Input: Khong co
// Output: Thoi gian sau khi tang 1 ngay
CDate& CDate::operator++() 
{
    day++;
    if (day > daysInMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }

    return *this;
}
// Toan tu tang (hau to)
// Input: Khong co
// Output: Tang thoi gian 1 ngay sau do tra ve thoi gian truoc do
CDate CDate::operator++(int) 
{
    CDate temp = *this;
    ++(*this);
    return temp;
}
// Toan tu giam (tien to)
// Input: Khong co
// Output: Thoi gian sau khi giam 1 ngay
CDate& CDate::operator--() 
{
    *this = *this - 1;
    return *this;
}
// Toan tu tang (hau to)
// Input: Khong co
// Output: Giam thoi gian 1 ngay sau do tra ve thoi gian truoc do
CDate CDate::operator--(int) 
{
    CDate temp = *this;
    --(*this);
    return temp;
}