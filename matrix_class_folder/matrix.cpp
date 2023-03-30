#include <iostream>
#include <stdio.h>
#include <ctime>

#include "matrix.h"

using namespace std;


Matrix::Matrix() {
    this->values = nullptr;
    this->size = 0;
}

Matrix::Matrix(const Matrix& m) {
    this->values = new float*[m.size];
    this->size = m.size;
    for(int i = 0; i < m.size; i++) {
        *(this->values + i) = new float[m.size];
        for(int j = 0; j < m.size; j++) {
            *(*(this->values + i) + j) = *(*(m.values + i) + j);
        }
    }
}

Matrix::Matrix(float **f, int size) {
    this->size = size;
    this->values = new float*[size];

    for(int i = 0; i < size; i++) {
        *(this->values + i) = new float[size];
        for(int j = 0; j < size; j++) {
            *(*(this->values + i) + j) = *(*(f + i) + j);
        }
    }
}

void Matrix::setElement(int row, int col, int element) {
    *(*(this->values + row) + col) = element;
}

Matrix Matrix::operator+(const Matrix& m) {
    if(this->size == m.size) {
        float **f = new float*[this->size];
        for(int i = 0; i < this->size; i++) {
            *(f + i) = new float[this->size];
            for(int j = 0; j < this->size; j++) {
                *(*(f + i) + j) = *(*(this->values + i) + j) + *(*(m.values + i) + j);
            }
        }
        Matrix result(f, this->size);
        
        for(int i = 0; i < this->size; i++) {
            delete[] *(f + i);
        }

        delete[] f;
        return result;
    } else {
        throw 20;
    }

}

Matrix Matrix::operator-(const Matrix& m) {
    if(this->size == m.size) {
        float **f = new float*[this->size];
        for(int i = 0; i < this->size; i++) {
            *(f + i) = new float[this->size];
            for(int j = 0; j < this->size; j++) {
                *(*(f + i) + j) = *(*(this->values + i) + j) - *(*(m.values + i) + j);
            }
        }
        Matrix result(f, this->size);
        
        for(int i = 0; i < this->size; i++) {
            delete[] *(f + i);
        }

        delete[] f;
        return result;
    } else {
        throw 20;
    }

}

Matrix Matrix::operator*(const Matrix& m) {
    if(this->size == m.size) {
        float **f = new float*[this->size];
        for(int i = 0; i < this->size; i++) {
            *(f + i) = new float[this->size];
            for(int j = 0; j < this->size; j++) {
                *(*(f + i) + j) = 0.0;
                for(int k = 0; k < this->size; k++) {
                    float temp1 = *(*(this->values + i) + k);
                    float temp2 = *(*(m.values + k) + j);
                    *(*(f + i) + j) += temp1 * temp2;
                }
                
            }
        }
        Matrix result(f, this->size);
        
        for(int i = 0; i < this->size; i++) {
            delete[] *(f + i);
        }

        delete[] f;
        return result;
    } else {
        throw 20;
    }

}

void Matrix::operator=(const Matrix& m) {
    // cout << "Assignment operator" << endl;
    if(this->values != nullptr) {
        this->~Matrix();
    }
    
    this->values = new float*[m.size];
    this->size = m.size;
    if(this->size == m.size) {
        for(int i = 0; i < m.size; i++) {
            *(this->values + i) = new float[m.size];
            for(int j = 0; j < m.size; j++) {
                *(*(this->values + i) + j) = *(*(m.values + i) + j);
            }
        }
        // for(int i = 0; i < this->size; i++) {
        //     delete[] *(this->values + i);
        //     // *(this->values + i) = nullptr;
        // }

        // delete[] this->values;
        // // this->values = nullptr;

        // this->values = m.values;
    } else {
        throw 20;
    }
}

float Matrix::getElement(int row, int col) {
    return *(*(this->values + row) + col);
}

float** Matrix::getValues() {
    return values;
}

int Matrix::getSize() {
    return this->size;
}

Matrix::~Matrix() {
    // cout << "Destructor called" << endl;
    for(int i = 0; i < this->size; i++) {
        delete[] *(this->values + i);
        // *(this->values + i) = nullptr;
    }

    delete[] this->values;
    // this->values = nullptr;

}

std::ostream & operator<<(std::ostream &out, const Matrix &m) {
    for(int i = 0; i < m.size; i++) {
        for(int j = 0; j < m.size; j++) {
            out << *(*(m.values + i) + j) << " ";
        }
        out << std::endl;
    }
    return out;
}
