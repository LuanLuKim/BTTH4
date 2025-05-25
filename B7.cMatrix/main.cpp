#include <iostream>
#include "cMatrix.h"

using namespace std;

int main()
{
    cMatrix A, B;
    cout << "Nhap ma tran A:\n"; cin >> A;
    cout << "\nNhap ma tran B:\n"; cin >> B;

    try 
    {
        cMatrix sum, dif;
        sum = A + B; dif = A - B;
        cout << "\nA + B:\n" << sum;
        cout << "\nA - B:\n" << dif;

        if (A.getCols() == B.getRows()) 
        {
            cout << "\nA * B:\n";
            cMatrix C = A * B;
            cout << C;
        }

        if (B.getCols() > 0) 
        {
            cout << "\nNhap vector co " << B.getCols() << " chieu:\n";
            cVector v(B.getCols());
            cin >> v;
            cout << "\nB * v:\n";
            cout << (B * v);
        }
    } catch (const exception& e) 
    {
        cout << "Loi: " << e.what() << endl;
    }

    return 0;
}