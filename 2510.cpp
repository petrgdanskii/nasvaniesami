/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class matrix {
    int size_x;
    int size_y;
    std::string id;
    double** data;
public:
    matrix(int size_x, int size_y, std::string id);
    void print();
    void set_data(int size_x, int size_y, double** data);
};

class vector {
    int size;
    std::string id;
    double* data;
public:
    vector(int size, std::string id);
    void print();
    void set_data(int size, double* data);
    void multiply(int size_x, int size_y, vector v, matrix m);
};

vector :: vector (int size, std::string id = "unknown"){
    this->size = size;
    this->id = id;

    data = new double [size];
    for (int i=0;i<size;i++){
        data[i]=0;
    };
};

void vector :: print(){
    cout << id << " " << size << std::endl;
    for (int i=0;i<size;i++){
        cout << data[i] << std::endl;
    };
};

void vector :: set_data (int size, double* data){
    for (int i=0;i<size;i++){
        this->data[i]=data[i];
    };
};

void vector :: multiply(int size_x, int size_y, vector v, matrix m){
    data = new double [size_y];
    for (int i=0; i<size_x; i++){

        data[i] = new double[size_y+1];
        for (int j=0; j<size_y; j++){
            data[i][j]=0;
        };
};



matrix :: matrix (int size_x, int size_y, std::string id = "unknown"){

    this->size_x = size_x;
    this->size_y= size_y;
    this->id = id;

    data = new double* [size_x+1];
    for (int i=0; i<size_x; i++){
        data[i] = new double[size_y+1];
        for (int j=0; j<size_y; j++){
            data[i][j]=0;
        };

    };
};

void matrix :: print (){
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << data[i][j] << " ";
        };
        cout << endl;
    };
};

void matrix :: set_data(int size_x, int size_y, double** data){

    for (int i=0; i<size_x; i++){
        for (int j=0; j<size_y; j++){
            this->data[i][j]=data[i][j];
        };

    };
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
    cout << "Bye world!" << endl;
    return 0;
};
