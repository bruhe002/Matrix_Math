#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    public:
        // Constructor
        Matrix();
        Matrix(int size);

        void setValue(int row, int col, int element);

        // Overloaded Arithmetic Operation
        Matrix operator+(const Matrix& m);
        Matrix operator-(const Matrix& m);
        Matrix operator*(const Matrix& m);
        void operator=(const Matrix& m);

        // Get Function
        float getElement(int, int);
        float** getValues();
        int getSize();

        // Destructor
        ~Matrix();

    private:
        float **values;
        int size;
};

#endif

// Overloaded insertion operator
ostream& operator<<(ostream &out, const Matrix &m);