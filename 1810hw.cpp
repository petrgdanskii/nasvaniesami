#include <iostream>
#include <string>

using namespace std;

class matrix {
    int size_x; 
    int size_y;
    std::string id; 
    double** data;
public:
    matrix(int size_x, int size_y, std::string id);
    void print();
};

matrix :: matrix (int size_x, int size_y, std::string id = "unknown"){
     
    this->size_x = size_x;
    this->size_y= size_y;
    this->id = id;
    
    data = new double* [size_x+1];
    for (int i=0; i<size_x; i++){
        data[i] = new double[size_y+1];
        for (int j=0; j<size_y; j++){
            data[i][j]=i+j;
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

int main(){
    cout << "Hello world!" << endl; 
    matrix m1(3, 4, "first matrix!");
    matrix m2(5, 7, "second matrix!");
    m1.print();
    cout << "Hello world again!" << endl;
    m2.print();
    
    return 0;
};