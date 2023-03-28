#include <iostream>
#include <sstream>
#include <exception>
#include <array>
#include <string>
#include <stdlib.h>

using namespace std;

const int MAX_ARRAY_SIZE = 100;

bool exitCreateMatrixFlag = true;
bool exitMenuFlag = false;

void fillMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);
void printMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);
void menuFunction(int choice, float matrix1[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float matrix2[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
                    float resultMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);

void addMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);
void subMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);
void multMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);

int main() {
    cout << "\nWelcome to the MATRIX CALCULATOR" << endl;
    // Initialize Matrices
    float matrix1[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    float matrix2[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    float resultingMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    do {
        // reset flag
        exitCreateMatrixFlag = true;
        exitMenuFlag = false;

        cout << "\nPlease enter the size of the matrix: ";
        string garbage;
        int matrixSize = 0;
        cin >> matrixSize;
        getline(cin, garbage);

        if(matrixSize < MAX_ARRAY_SIZE) {
            // Ask user for inputs row by row
            cout << "\nNow let's enter some values into your FIRST MATRIX:\n" << endl;
            fillMatrix(matrix1, matrixSize);

            cout << "\nNow let's enter some values into your SECOND MATRIX:\n" << endl;
            fillMatrix(matrix2, matrixSize);

            // Display Menu
            do {
                cout << "Please choose the following: " << endl;
                cout << "\t1. Add your Matrices" << endl;
                cout << "\t2. Subtract your Matrices" << endl;
                cout << "\t3. Multiply your matrices" << endl;
                cout << "\t4. Change your Matrices" << endl;
                cout << "\t5. Exit" << endl;

                try {
                    int userChoice = 0;
                    cin >> userChoice;
                    if(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5) {
                        cout << "Not a valid choice! Please try again!" << endl;
                    } else {
                        // cout << "Entering menu Function" << endl;
                        menuFunction(userChoice, matrix1, matrix2, resultingMatrix, matrixSize);
                        if(resultingMatrix != nullptr) {
                            cout << "Result:" << endl;
                            printMatrix(resultingMatrix, matrixSize);
                        }
                    }
                } catch(const exception& e) {
                    cerr << e.what() << endl;
                }

            } while (!exitMenuFlag);
        } else {
            cerr << "The Size needs to be less than 100!" << endl << "Please Try Again!" << endl;
            exitCreateMatrixFlag = false;
        }

        cout << endl;
        
    } while (!exitCreateMatrixFlag);

    
    cout << endl;
    system("Pause");
    return 0;

    cout << endl;
    system("Pause");
    return 0;
}

void menuFunction(int choice, float matrix1[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float matrix2[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
                    float resultMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size) {
    switch(choice) {
        case 1: 
            addMatrix(matrix1, matrix2, resultMatrix, size);
            break;
        case 2:
            subMatrix(matrix1, matrix2, resultMatrix, size);
            break;
        case 3:
            multMatrix(matrix1, matrix2, resultMatrix, size);
            break;
        case 4:
            exitCreateMatrixFlag = false;
            exitMenuFlag = true;
            break;
        default:
            exitMenuFlag = true;
            exitCreateMatrixFlag = true;
            break;
    }
}

void fillMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size){
    string row;
    for(int i = 0; i < size; i++) {
        cout << "For ROW " << i << ": ";
        getline(cin, row);
        cout << endl;

        int elementCounter = 0;
        string element;
        stringstream input(row);
        while(getline(input, element, ' ')) {
            // If elementCounter Does not exceed the size of the row
            if(elementCounter < size) {
                matrix[i][elementCounter] = stof(element);
                elementCounter++;
            }

        }

        // If the number of elements did not reach the row size
        // Padd with zeroes
        for(int j = elementCounter; j < size; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

void printMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void addMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size) {
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            c[i][j] = 0;
            for(int k = 0; k < size; k++) {
                int temp = a[i][k] * b[k][j];
                c[i][j] += temp; 
            }
        }
    }
}