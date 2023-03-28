#include <iostream>
#include <stdio.h>
#include <ctime>

#include "matrix.h"

using namespace std;

Matrix::Matrix() {
    this->values = new float*[100];
    for(int i = 0; i < 100; i++) {
        *(this->values + i) = new float[100];
    }

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            *(*(this->values + i) + j) = 0;
        }
    } 
}

Matrix::Matrix(int size) {
    this->size = size;
    this->values = new float*[size];
    for(int i = 0; i < size; i++) {
        *(this->values + i) = new float[size];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            *(*(this->values + i) + j) = 0;
        }
    } 

}

void Matrix::setElement(int row, int col, int element) {
    *(*(this->values + row) + col) = element;
}

Matrix Matrix::operator+(const Matrix& m) {
    Matrix result(this->size);
    
    if(this->size == m.size) {
        for(int i = 0; i < this->size; i++) {
            for(int j = 0; i < this->size; j++) {
                *(*(result.values + i) + j) = *(*(this->values + i) + j) + *(*(m.values + i) + j);
            }
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& m) {
    Matrix result(this->size);
    
    if(this->size == m.size) {
        for(int i = 0; i < this->size; i++) {
            for(int j = 0; i < this->size; j++) {
                *(*(result.values + i) + j) = *(*(this->values + i) + j) - *(*(m.values + i) + j);
            }
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& m) {
    Matrix result(this->size);
    
    if(this->size == m.size) {
        for(int i = 0; i < this->size; i++) {
            for(int j = 0; i < this->size; j++) {
                for(int k = 0; k < this->size; k++) {
                    int temp1 = *(*(this->values + i) + k);
                    int temp2 = *(*(m.values + k) + j);
                    *(*(result.values + i) + j) +=  temp1 * temp2;
                }
                
            }
        }
    } else {
        throw 20;
    }

    return result;
}

void Matrix::operator=(const Matrix& m) {
    if(this->size == m.size) {
        for(int i = 0; i < m.size; i++) {
            for(int j = 0; i < m.size; j++) {
                *(*(this->values + i) + j) = *(*(m.values + i) + j);
            }
        }
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
    for(int i = 0; i < this->size; i++) {
        delete[] *(this->values + i);
        *(this->values + i) = nullptr;
    }

    delete[] this->values;
    this->values = nullptr;

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
