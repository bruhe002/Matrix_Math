#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 10;

void fillMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE]);
void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE]);

void addMatrix(int a[ARRAY_SIZE][ARRAY_SIZE], int b[ARRAY_SIZE][ARRAY_SIZE], int c[ARRAY_SIZE][ARRAY_SIZE]);
void subMatrix(int a[ARRAY_SIZE][ARRAY_SIZE], int b[ARRAY_SIZE][ARRAY_SIZE], int c[ARRAY_SIZE][ARRAY_SIZE]);
void multMatrix(int a[ARRAY_SIZE][ARRAY_SIZE], int b[ARRAY_SIZE][ARRAY_SIZE], int c[ARRAY_SIZE][ARRAY_SIZE]);

int main() {
    srand(time(NULL));
    
    int matrix1[ARRAY_SIZE][ARRAY_SIZE];
    int matrix2[ARRAY_SIZE][ARRAY_SIZE];
    int sumMatrix[ARRAY_SIZE][ARRAY_SIZE];
    int diffMatrix[ARRAY_SIZE][ARRAY_SIZE];
    int productMatrix[ARRAY_SIZE][ARRAY_SIZE];

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    cout << "Matrix 1" << endl;
    printMatrix(matrix1);

    cout << endl;

    cout << "Matrix 2" << endl;
    printMatrix(matrix2);

    cout << endl;
    system("Pause");
    return 0;
}

void fillMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE]){
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            matrix[i][j] = rand() % 9 + 1;
        }
    }
}

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE]) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}