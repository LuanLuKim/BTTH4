#include <iostream>
#include "CTime.h"
#include <ctime>

using namespace std;
// Ham thay doi vi tri xuat
// Input: Toa do x, y cua vi tri muon xuat thong tin
// Output: Vi tri xuat thay doi
void gotoXY(int x, int y) {
	cout << "\033[" << y << ";" << x << "H";
}
// Ham in dong ho
// Input: Thoi gian muon in
// Output: Thoi gian can in o ben phai goc tren
void printClock(const CTime& timeStr) {
    int consoleWidth = 120;
    int x = consoleWidth - 8 + 1;
    int y = 1;
    gotoXY(x, y);
    cout << timeStr << flush;
}

int main() 
{
    CTime now(4,20,12);
    for (int i = 0; i < 10; ++i) {
        printClock(now);
        ++now;
        _Thrd_sleep_for(1000);
    }
	return 0;
}
