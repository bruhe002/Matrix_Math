#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    public:
        // Constructor
        Matrix();

        // Overloaded Arithmetic Operation
        Matrix operator+(const Matrix& m);
        Matrix operator-(const Matrix& m);
        Matrix operator*(const Matrix& m);

        // Get Function
        int** getValues();

        // Destructor
        ~Matrix();

    private:
        int** values;
};

#endif

// Overloaded insertion operator
ostream& operator<<(ostream &out, const Matrix &m);