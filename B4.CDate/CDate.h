#pragma once
#include <iostream>

using namespace std;
class CDate
{
private:
	int day, month, year;
    bool isLeapYear() const;
    int daysInMonth() const;
    int toJulianDay() const;
    void fromJulianDay(int jd);
    bool isValid() const;
public:
    CDate(){}

    friend istream& operator>>(istream& in, CDate& d);
    friend ostream& operator<<(ostream& out, const CDate& d);

    CDate operator+(int days) const;
    CDate operator-(int days) const;
    int operator-(const CDate& other) const;

    CDate& operator++();
    CDate& operator--();

    CDate operator++(int);
    CDate operator--(int);
    ~CDate() {}
};

