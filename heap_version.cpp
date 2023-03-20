#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 10;

void fillMatrix(int** matrix);
void printMatrix(int** matrix);

int** addMatrix(int** a, int** b);
int** subMatrix(int** a, int** b);
int** multMatrix(int** a, int** b);

int main() {
    srand(time(NULL));

    // Initialize Matrices
    int **matrix1 = new int*[ARRAY_SIZE];
    int **matrix2 = new int*[ARRAY_SIZE];
    int **sumMatrixResult;
    int **diffMatrixResult;
    int **productMatrixResult;

    // Add matix columns
    for(int i = 0; i < ARRAY_SIZE; i++) {
        matrix1[i] = new int[ARRAY_SIZE];
        matrix2[i] = new int[ARRAY_SIZE];
    }

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    cout << "Matrix 1" << endl;
    printMatrix(matrix1);

    cout << endl;

    cout << "Matrix 2" << endl;
    printMatrix(matrix2);
    cout << endl;

    cout << "Sum Matrix" << endl;
    sumMatrixResult = addMatrix(matrix1, matrix2);
    printMatrix(sumMatrixResult);
    cout << endl;

    cout << "Difference Matrix" << endl;
    diffMatrixResult = subMatrix(matrix1, matrix2);
    printMatrix(diffMatrixResult);
    cout << endl;

    cout << "Product Matrix" << endl;
    productMatrixResult = multMatrix(matrix1, matrix2);
    printMatrix(productMatrixResult);
    cout << endl;

    // Deallocate Memory
    for(int i = 0; i < ARRAY_SIZE; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] sumMatrixResult[i];
        delete[] diffMatrixResult[i];
        delete[] productMatrixResult[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] sumMatrixResult;
    delete[] diffMatrixResult;
    delete[] productMatrixResult;

    cout << endl;
    system("Pause");
    return 0;
}

void fillMatrix(int** matrix){
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            *(*(matrix + i) + j) = rand() % 9 + 1;
        }
    }
}

void printMatrix(int** matrix) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }

        cout << endl;
    }
}

int** addMatrix(int** a, int** b) {
    int** result = new int*[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = new int[ARRAY_SIZE];
    }

    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            *(*(result + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
        }
    }

    return result; 
}

int** subMatrix(int** a, int** b) {
    int** result = new int*[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = new int[ARRAY_SIZE];
    }

    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            *(*(result + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);
        }
    }

    return result;
}

int** multMatrix(int** a, int** b) {
    int** result = new int*[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = new int[ARRAY_SIZE];
    }

    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            for(int k = 0; k < ARRAY_SIZE; k++) {
                *(*(result + i) + j) += *(*(a + k) + j) * *(*(b + i) + k); 
            }
        }
    }

    return result;
}