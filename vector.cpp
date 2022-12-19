#include <iostream>
using namespace std;
#include "vector.h"
#include <cmath>

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

double vector :: norm2() {
	double n = 0;
	for (int i = 0 ; i < this->v_size; i++){
		n += this->v_data[i] * this->v_data[i];
	}
	return sqrt(n);
};
