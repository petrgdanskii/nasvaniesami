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

vector operator * (double a, vector v){
	vector temp(v.v_size, "mult double");
	for (int i = 0; i < v.v_size; i++){
		temp.v_data[i] = a * v.v_data[i];
        }
        return temp;
};

vector operator - (vector v1, vector v2) {
	vector temp(v1.v_size, "minus vector");
	for (int i = 0; i < v1.v_size; i++){
		temp.v_data[i] = v1.v_data[i]-v2.v_data[i];
	}
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


vector solver(matrix M, vector v, double eps)
{
    double tau = 2 / M.norm_frob();
    vector hz(M.m_rows, "timeble");
    
    hz.set_data(v.v_size, v.v_data);
    
    vector sol_1(M.m_rows, "solution");
    sol_1.set_data(v.v_size, v.v_data);
    sol_1 = 40.0*sol_1;
    vector solution(M.m_rows, "solution");
    while ((sol_1 - solution).norm2() > eps){
        sol_1 = solution;
        solution = solution - tau * multiply(M, solution) + tau*v;

    }
    return solution;
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
    
    cout << "lets solve smth" << endl;;
    vector v_sol(2, "sol vector(((");
    double daaata1d[] = {3,2};
    v_sol.set_data(2, daaata1d);
    v_sol.print();
    
    matrix m_sol(2, 2, "sol matrix((");
    double** daaata2d;
    daaata2d = new double* [2];
    for (int i=0; i<2; i++){
        daaata2d[i] = new double[2];
    }
    daaata2d[0][0]=1;
    daaata2d[0][1]=1;
    daaata2d[1][0]=0;
    daaata2d[1][1]=1;
    m_sol.set_data(2, 2, daaata2d);
    m_sol.print();
    
    vector v_imtired = solver(m_sol, v_sol, 1e-5);
    v_imtired.print();

    cout << "Bye world!" << endl;
    return 0;
};
