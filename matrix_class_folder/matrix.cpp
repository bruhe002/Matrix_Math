#include <iostream>
#include <stdio.h>
#include <ctime>

#include "matrix.h"

using namespace std;

// Default Constructor
Matrix::Matrix() {
    this->values = nullptr;
    this->row = 0;
    this->col = 0;

}

// Copy Constructor
Matrix::Matrix(const Matrix& m) {
    this->values = new float*[m.row];
    this->row = m.row;
    this->col = m.col;
    for(int i = 0; i < m.row; i++) {
        *(this->values + i) = new float[m.row];
        for(int j = 0; j < m.col; j++) {
            *(*(this->values + i) + j) = *(*(m.values + i) + j);
        }
    }
}

// Overloaded Constructor
Matrix::Matrix(float **f, int row, int col) {
    this->row = row;
    this->col = col;
    this->values = new float*[row];

    for(int i = 0; i < row; i++) {
        *(this->values + i) = new float[col];
        for(int j = 0; j < col; j++) {
            *(*(this->values + i) + j) = *(*(f + i) + j);
        }
    }
}

// Set Element function
void Matrix::setElement(int row, int col, int element) {
    *(*(this->values + row) + col) = element;
}


// Overloaded + Operator
Matrix Matrix::operator+(const Matrix& m) {
    if(this->row == m.row && this->col == m.col) {
        float **f = new float*[this->row];
        for(int i = 0; i < this->row; i++) {
            *(f + i) = new float[this->col];
            for(int j = 0; j < this->col; j++) {
                *(*(f + i) + j) = *(*(this->values + i) + j) + *(*(m.values + i) + j);
            }
        }
        Matrix result(f, this->row, this->col);
        
        for(int i = 0; i < this->row; i++) {
            delete[] *(f + i);
        }

        delete[] f;
        return result;
    } else {
        throw 20;
    }

}


// Overloaded - Operator
Matrix Matrix::operator-(const Matrix& m) {
if(this->row == m.row && this->col == m.col) {
        float **f = new float*[this->row];
        for(int i = 0; i < this->row; i++) {
            *(f + i) = new float[this->col];
            for(int j = 0; j < this->col; j++) {
                *(*(f + i) + j) = *(*(this->values + i) + j) - *(*(m.values + i) + j);
            }
        }
        Matrix result(f, this->row, this->col);
        
        for(int i = 0; i < this->row; i++) {
            delete[] *(f + i);
        }

        delete[] f;
        return result;
    } else {
        throw 20;
    }

}

// Overloaded * Operator
Matrix Matrix::operator*(const Matrix& m) {
    if(this->col == m.row) {
        float **f = new float*[this->row];
        for(int i = 0; i < this->row; i++) {
            *(f + i) = new float[m.col];
            for(int j = 0; j < m.col; j++) {
                *(*(f + i) + j) = 0.0;
                for(int k = 0; k < this->col; k++) {
                    float temp1 = *(*(this->values + i) + k);
                    float temp2 = *(*(m.values + k) + j);
                    *(*(f + i) + j) += temp1 * temp2;
                }
                
            }
        }
        Matrix result(f, this->row, m.col);
        
        for(int i = 0; i < this->row; i++) {
            delete[] *(f + i);
        }

        delete[] f;
        return result;
    } else {
        throw 20;
    }

}


// Overloaded = Operator
void Matrix::operator=(const Matrix& m) {
    // cout << "Assignment operator" << endl;
    if(this->values != nullptr) {
        this->~Matrix();
    }
    
    this->values = new float*[m.row];
    this->row = m.row;
    this->col = m.col;
    
    for(int i = 0; i < m.row; i++) {
        *(this->values + i) = new float[m.col];
        for(int j = 0; j < m.col; j++) {
            *(*(this->values + i) + j) = *(*(m.values + i) + j);
        }
    }

}

// Get functions
float Matrix::getElement(int row, int col) {
    return *(*(this->values + row) + col);
}

float** Matrix::getValues() {
    return values;
}

int Matrix::getRow() {
    return this->row;
}

int Matrix::getCol() {
    return this->col;
}

// Destructor
Matrix::~Matrix() {
    // cout << "Destructor called" << endl;
    for(int i = 0; i < this->row; i++) {
        delete[] *(this->values + i);
    }

    delete[] this->values;
}


// Overloaded << operator, declared as a friend function
std::ostream & operator<<(std::ostream &out, const Matrix &m) {
    for(int i = 0; i < m.row; i++) {
        for(int j = 0; j < m.col; j++) {
            out << *(*(m.values + i) + j) << " ";
        }
        out << std::endl;
    }
    return out;
}
