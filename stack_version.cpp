#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>

using namespace std;

void fillMatrix(int matrix[100][100]);
void printMatrix(int matrix[100][100]);

void addMatrix(int a[100][100], int b[100][100], int c[100][100]);
void subMatrix(int a[100][100], int b[100][100], int c[100][100]);
void multMatrix(int a[100][100], int b[100][100], int c[100][100]);

int main() {

    int matrix1[100][100];
    int matrix2[100][100];
    int sumMatrix[100][100];
    int diffMatrix[100][100];
    int productMatrix[100][100];

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

void fillMatrix(int matrix[100][100]){
    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            matrix[i][j] = rand() % 9 + 1;
        }
    }
}

void printMatrix(int matrix[100][100]) {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}