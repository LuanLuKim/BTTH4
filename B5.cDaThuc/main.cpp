#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main()
{
    cDaThuc f1, f2;
    cin >> f1 >> f2;
    cout << f1 << f2;

    cout << f1 + f2;
    cout << f1 - f2;
    cout << f1 * f2;
    int x;
    cout << "Nhap gia tri x de tinh: "; cin >> x;
    cout << "f1(" << x << ") = " << f1.tinhGiaTri(x) << endl;
    cout << "f2(" << x << ") = " << f2.tinhGiaTri(x) << endl;

    return 0;
}
