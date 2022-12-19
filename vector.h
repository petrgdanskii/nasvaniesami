#include <iostream>
using namespace std;
#ifndef VECTOR_H
#define VECTOR_H

class matrix;

class vector {
    friend class matrix;
    friend vector operator + (vector a, vector b);
    friend vector operator * (double a, vector v);
    friend vector operator - (vector v1, vector v2);
    friend vector multiply(matrix &m, vector v);
    friend vector solver(matrix M, vector v, double eps);
    int v_size;
    std::string v_id;
    double* v_data;
public:
    vector(int v_size, std::string v_id);
    void print();
    void set_data(int v_size, double* v_data);
    double norm2();
};

#endif
