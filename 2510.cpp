#include <iostream>

using namespace std;

class vector;
class matrix;

class vector {
    friend class matrix;
    friend vector operator + (vector a, vector b);
    friend vector multiply(matrix &m, vector v); 
    int v_size;
    std::string v_id;
    double* v_data;
public:
    vector(int v_size, std::string v_id);
    void print();
    void set_data(int v_size, double* v_data);
};

class matrix {
    friend class vector;
    friend vector multiply(matrix &m, vector v); 
    int m_rows;
    int m_cols;
    std::string m_id;
    double** m_data;
public:
    matrix(int m_rows, int m_cols, std::string m_id);
    void print();
    void set_data(int m_rows, int m_cols, double** m_data);
};

vector :: vector (int v_size, std::string v_id = "unknown"){
    this->v_size = v_size;
    this->v_id = v_id;

    v_data = new double [v_size];
    for (int i = 0; i < v_size; i++){
        v_data[i]=0;
    };
};

void vector :: print(){
    cout << v_id << " size: " << v_size << std::endl;
    for (int i = 0; i < v_size; i++){
        cout << v_data[i] << std::endl;
    };
};

void vector :: set_data (int v_size, double* v_data){
    for (int i = 0; i < v_size; i++){
        this->v_data[i]=v_data[i];
    };
};



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
