#include <iostream>
#include "CDate.h"

using namespace std;

int main() 
{
    CDate ngayGui, ngayRut;
    double soTien, laiSuatNam;
    
    cout << "Nhap ngay gui:\n";
    cin >> ngayGui;

    cout << "Nhap ngay rut:\n";
    cin >> ngayRut;

    cout << "Nhap so tien gui (VND): ";
    cin >> soTien;

    cout << "Nhap lai suat nam (%): ";
    cin >> laiSuatNam;

    int soNgay = ngayRut - ngayGui;
    double lai = soTien * (laiSuatNam / 100) * (soNgay / 365.0);

    cout << "Bat dau gui tien vao ngay: " << ngayGui;
    cout << "Rut tien vao ngay: " << ngayRut;
    cout << "\nSo ngay gui: " << soNgay << " ngay\n";
    cout << "Tien lai nhan duoc: " << lai << " VND\n";

    return 0;
}
