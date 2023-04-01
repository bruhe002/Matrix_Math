#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

const int MAX_ARRAY_SIZE = 100;

class Matrix {
    public:
        // Friend Function
        friend std::ostream& operator<<(std::ostream &out, const Matrix &c);

        // Constructor
        Matrix();
        Matrix(const Matrix& m);
        Matrix(float **f, int row, int col);

        void setElement(int row, int col, int element);

        // Overloaded Arithmetic Operation
        Matrix operator+(const Matrix& m);
        Matrix operator-(const Matrix& m);
        Matrix operator*(const Matrix& m);
        void operator=(const Matrix& m);

        // Get Function
        float getElement(int, int);
        float** getValues();
        int getRow();
        int getCol();

        // Destructor
        ~Matrix();

    private:
        float **values;
        int row;
        int col;
};

#endif

