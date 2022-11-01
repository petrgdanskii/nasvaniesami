#include <iostream>
using namespace std;
#include "matrix.h"


matrix :: matrix (int m_rows, int m_cols, std::string m_id = "unknown"){

    this->m_rows = m_rows;
    this->m_cols = m_cols;
    this->m_id = m_id;

    m_data = new double* [m_rows];
    for (int i = 0; i < m_rows; i++){
        m_data[i] = new double[m_cols];
        for (int j = 0; j < m_cols; j++){
            m_data[i][j] = 0;
        };

    };
};

void matrix :: print (){
    cout << m_id << " size: " << m_rows << " x " << m_cols << std::endl;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << m_data[i][j] << " ";
        };
        cout << endl;
    };

};

void matrix :: set_data(int m_rows, int m_cols, double** m_data){

    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_cols; j++){
            this->m_data[i][j] = m_data[i][j];
        };

    };
};
