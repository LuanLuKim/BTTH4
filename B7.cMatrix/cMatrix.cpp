#include "cMatrix.h"

// Toan tu nhap
// Input: Kich thuoc va gia tri tung phan tu trong ma tran tu ban phim
// Output: Khong co
istream& operator>>(istream& in, cMatrix& m)
{
    cout << "Nhap so dong: "; in >> m.rows;
    cout << "Nhap so cot: "; in >> m.cols;
    m.data.resize(m.rows, cVector(m.cols));
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < m.rows; ++i) 
    {
        cout << "Dong " << i << ":\n";
        in >> m.data[i];
    }

    return in;
}
// Toan tu xuat
// Input: Ban than cMatrix
// Output: cMatrix ra man hinh theo chuan
ostream& operator<<(ostream& out, const cMatrix& m)
{
    for (int i = 0; i < m.rows; ++i)
        out << m.data[i] << endl;

    return out;
}
// Toan tu cong
// Input: 1 cMatrix m
// Output: 1 cMatrix la tong 2 ma tran
// Huong giai quyet: Neu cung kich thuoc thi cong cac phan tu o vi tri tuong uong cho nhau
//                   Neu khac so chieu thi dua ra loi "Ma tran khong cung kich thuoc"
cMatrix cMatrix:: operator+(const cMatrix& other) const 
{
    if (rows != other.rows || cols != other.cols)
        throw runtime_error("Ma tran khong cung kich thuoc");
    cMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        result.data[i] = data[i] + other.data[i];
    return result;
}
// Toan tu tru
// Input: 1 cMatrix m
// Output: 1 cMatrix la hieu 2 ma tran
// Huong giai quyet: Neu cung kich thuoc thi tru cac phan tu o vi tri tuong uong cho nhau
//                   Neu khac so chieu thi dua ra loi "Ma tran khong cung kich thuoc"
cMatrix cMatrix:: operator-(const cMatrix& other) const 
{
    if (rows != other.rows || cols != other.cols)
        throw runtime_error("Ma tran khong cung kich thuoc");
    cMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        result.data[i] = data[i] - other.data[i];
    return result;
}
// Toan tu nhan ma tran voi vector
// Input: 1 cVector vec
// Output: 1 cVector
// Huong giai quyet: Neu so cot ma tran bang so chieu vector thi tinh theo cong thuc
//                   Neu khac thi dua ra loi:
//                   "Khong nhan duoc: so cot A khong bang chieu vector"
cVector cMatrix:: operator*(const cVector& vec) const 
{
    if (cols != vec.getSoChieu())
        throw runtime_error("Khong nhan duoc: so cot A khong bang chieu vector");
    cVector result(rows);
    for (int i = 0; i < rows; ++i)
        result[i] = data[i].tichVoHuong(vec);
    return result;
}
// Toan tu nhan ma tran voi ma tran
// Input: 1 cMatrix m
// Output: 1 cMatrix
// Huong giai quyet: Neu so cot ma tran bang A so dong B thi tinh theo cong thuc
//                   Neu khac thi dua ra loi:
//                   "Khong nhan duoc: so cot cua A khong bang so dong cua B"
cMatrix cMatrix:: operator*(const cMatrix& other) const 
{
    if (cols != other.rows)
        throw runtime_error("Khong nhan duoc: So cot cua A khong bang so dong cua B");
    cMatrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j) 
        {
            double sum = 0;
            for (int k = 0; k < cols; ++k)
                sum += data[i][k] * other.data[k][j];
            result.data[i][j] = sum;
        }
    return result;
}