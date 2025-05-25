#include <iostream>
#include "cVector.h"

using namespace std;

int main()
{
    cVector v1, v2;

    cout << "Nhap vector v1:\n";
    cin >> v1;

    cout << "Nhap vector v2:\n";
    cin >> v2;

    cout << "\nVector v1: " << v1 << endl;
    cout << "Vector v2: " << v2 << endl;

    try {
        cVector Sum = v1 + v2;
        cVector Dif = v1 - v2;
        double dot = v1.tichVoHuong(v2);
        cout << "Tong 2 vector: " << Sum<<endl;
        cout << "Hieu 2 vector" << Dif << endl;
        cout << "Tich vo huong v1.v2 = " << dot << endl;
    }
    catch (const runtime_error& e)
    {
        cout << "Loi: " << e.what()<<endl;
        cout << "Khong the thuc hien phep cong, tru hay tich vo huong."<<endl;
    }

    cout << "Kich thuoc vector v1: " << v1.length() << endl;
    cout << "Kich thuoc vector v2: " << v2.length() << endl;

    try {
        double angle = v1.angleWith(v2);
        cout << "Goc giua v1 va v2 (radian): " << angle << endl;
    }
    catch (const runtime_error& e) 
    {
        cout << "Loi: " << e.what() << endl;
        cout << "Khong the tinh goc" << endl;;
    }

    catch (...)
    {
        cout << "Khong xac dinh.";
    }
    return 0;
}