#pragma once
#include "cVector.h"

class cMatrix
{
private:
    int rows, cols;
    vector<cVector> data;
public:
    // Ham tao co doi so mac dinh
    // Input: 2 so nguyen r, c cho dong va cot
    // Output: Ma tran co dong = r va cot = c
    cMatrix(int r = 0, int c = 0) : rows(r), cols(c), data(r, cVector(c)) {}

    friend istream& operator>>(istream& in, cMatrix& m);
    friend ostream& operator<<(ostream& out,const cMatrix& m);
    cMatrix operator+(const cMatrix& other) const;
    cMatrix operator-(const cMatrix& other) const;

    cVector operator*(const cVector& vec) const;
    cMatrix operator*(const cMatrix& other) const;

    // Ham lay so dong
    // Input: Khong co
    // Output: Tra ve so nguyen dai dien cho so dong
    int getRows() const { return rows; }
    // Ham lay so cot
    // Input: Khong co
    // Output: Tra ve so nguyen dai dien cho so cot
    int getCols() const { return cols; }
    ~cMatrix(){}
};

