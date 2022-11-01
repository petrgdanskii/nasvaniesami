#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace std;

class vector;
class matrix;


vector operator + (vector a, vector b){
    vector temp(a.v_size, "sum");
    for (int i=0; i < a.v_size; i++){
        temp.v_data[i] = a.v_data[i]+b.v_data[i];
    };
    return temp;
};


vector multiply(matrix &m, vector v) {
    vector temp(m.m_rows, "mult");
    for (int i=0; i < m.m_rows; i++){
        temp.v_data[i] = 0;
        for (int j = 0; j < m.m_cols; j++){
            temp.v_data[i] = temp.v_data[i] + m.m_data[i][j]*v.v_data[j];
            };
        };
    return temp;
};

int main(){
    cout << "Hello world!" << endl;
    vector v1(5, "first vector!");
    matrix m1(3, 5, "first matrix!");
    double data1d[] = {1,2,3,4,5};
    v1.set_data(5, data1d);
    v1.print();

    double** data2d;
    data2d = new double* [3];
    for (int i=0; i<3; i++){
        data2d[i] = new double[5];
        for (int j=0; j<5; j++){
            data2d[i][j]=i;
        };
    };
    m1.set_data(3, 5, data2d);
    m1.print();

    cout << "lets sum v1 + v1. ";
    vector v2 = v1 + v1;
    v2.print();

    cout << "lets multiply m1 * v1. ";
    vector v3 = multiply(m1, v1);
    v3.print();

    cout << "Bye world!" << endl;
    return 0;
};
