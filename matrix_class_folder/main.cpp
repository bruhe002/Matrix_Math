#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <chrono>

#include "matrix.h"

using namespace std;
using namespace std::chrono;

bool exitCreateMatrixFlag = true;
bool exitMenuFlag = false;

// const int MAX_ARRAY_SIZE = 100;

void fillMatrix(Matrix& m, int row, int col);

float** randomMatrix(int size);
void measureMultiplication();

// void menuFunction(int choice, const Matrix& m1, const Matrix& m2, const Matrix& m3);

int main() {
    srand(time(NULL));
    cout << "\nWelcome to the MATRIX CALCULATOR" << endl;
    float **firstMatrix;
    float **secondMatrix;
    float **thirdMatrix;
    // Initialize Matrices
    do {
        exitCreateMatrixFlag = true;
        exitMenuFlag = false;

        cout << "\nPlease enter the # of ROWS for the FIRST MATRIX: ";
        string garbage;
        int firstRow = 0;
        cin >> firstRow;
        getline(cin, garbage);

        cout << "\nPlease enter the # of COLUMNS for the FIRST MATRIX: ";
        int firstCol = 0;
        cin >> firstCol;
        getline(cin, garbage);

        cout << "\nPlease enter the # of ROWS for the SECOND MATRIX: ";
        int secondRow = 0;
        cin >> secondRow;
        getline(cin, garbage);

        cout << "\nPlease enter the # of COLUMNS for the SECOND MATRIX: ";
        int secondCol = 0;
        cin >> secondCol;
        getline(cin, garbage);

        if(firstRow < MAX_ARRAY_SIZE && firstCol < MAX_ARRAY_SIZE && secondRow < MAX_ARRAY_SIZE && secondCol < MAX_ARRAY_SIZE) {
            firstMatrix = new float*[firstRow];
            for(int i = 0; i < firstRow; i++) {
                *(firstMatrix + i) = new float[firstCol];
            }
            Matrix matrix1(firstMatrix, firstRow, firstCol);

            secondMatrix = new float*[secondRow];
            for(int i = 0; i < secondRow; i++) {
                *(secondMatrix + i) = new float[secondCol];
            }
            Matrix matrix2(secondMatrix, secondRow, secondCol);

            Matrix resultMatrix;

            // Ask user for inputs row by row
            cout << "\nNow let's enter some values into your FIRST MATRIX:\n" << endl;
            fillMatrix(matrix1, firstRow, firstCol);

            cout << "\nNow let's enter some values into your SECOND MATRIX:\n" << endl;
            fillMatrix(matrix2, secondRow, secondCol);

            // Matrix difMatrix = matrix1 - matrix2;
            // Matrix prodMatrix = matrix1 * matrix2;

             // Display Menu
            do {
                cout << "Please choose the following: " << endl;
                cout << "\t1. Add your Matrices" << endl;
                cout << "\t2. Subtract your Matrices" << endl;
                cout << "\t3. Multiply your matrices" << endl;
                cout << "\t4. Change your Matrices" << endl;
                cout << "\t5. Change your Matrices" << endl;
                cout << "\t6. Exit" << endl;

                try {
                    int userChoice = 0;
                    cin >> userChoice;
                    if(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5 && userChoice != 6) {
                        cout << "Not a valid choice! Please try again!" << endl;
                    } else {
                        // cout << "Entering menu Function" << endl;
                        switch(userChoice) {
                            case 1:
                                resultMatrix = matrix1 + matrix2;
                                cout << "\nSum: \n" << resultMatrix << endl;
                                break;
                            case 2:
                                resultMatrix = matrix1 - matrix2;
                                cout << "\nDifference: \n" << resultMatrix << endl;
                                break;
                            case 3:
                                resultMatrix = matrix1 * matrix2;
                                cout << "\nProduct: \n" << resultMatrix << endl;
                                break;
                            case 4:
                                exitCreateMatrixFlag = false;
                                exitMenuFlag = true;
                                break;
                            case 5:
                                measureMultiplication();
                                break;    
                            case 6:
                                exitCreateMatrixFlag = true;
                                exitMenuFlag = true;
                                break;
                        }
                        
                    }
                } catch(int x) {
                    if(x == 20) {
                        cerr << "ERROR 20: Sizes are not compatible with operation. Please Try Again!" << endl;
                        exitMenuFlag = false;
                    }
                }

            } while (!exitMenuFlag);
        } else {
            cerr << "The Size needs to be less than 100!" << endl << "Please Try Again!" << endl;
            exitCreateMatrixFlag = false;
        }

        cout << endl;

    } while(!exitCreateMatrixFlag);

    cout << endl;
    system("Pause");
    return 0;
}

void fillMatrix(Matrix& m, int row, int col) {
    string rowValues;
    for(int i = 0; i < row; i++) {
        cout << "For ROW " << i << ": ";
        getline(cin, rowValues);
        cout << endl;

        int elementCounter = 0;
        string element;
        stringstream input(rowValues);
        while(getline(input, element, ' ')) {
            // If elementCounter Does not exceed the size of the row
            if(elementCounter < col) {
                m.setElement(i, elementCounter, stof(element));
                elementCounter++;
            }
        }

        // If the number of elements did not reach the row size
        // Padd with zeroes
        for(int j = elementCounter; j < col; j++) {
            m.setElement(i, j, 0.0);
        }
    }
}

float** randomMatrix(int size) {
    float** matrix = new float*[size];
    for(int i = 0; i < size; i++) {
        *(matrix + i) = new float[size];
        for(int j = 0; j < size; j++) {
            *(*(matrix + i) + j) = float(rand() % 9);
        }
    }

    return matrix;
}

void measureMultiplication() {
    cout << "Please enter in a matrix size (The Matrices will be square): ";
    int matrixSize = 0;
    cin >> matrixSize;
    string garbage;
    getline(cin, garbage);

    Matrix matrix1(randomMatrix(matrixSize), matrixSize, matrixSize);
    Matrix matrix2(randomMatrix(matrixSize), matrixSize, matrixSize);

    cout << "Multiplying matrices..." << endl;
    auto start = high_resolution_clock::now();
    try {
        Matrix result = matrix1 * matrix2;
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "TIME OF COMPLETION: " <<  duration.count() << "ns" << endl;
    } catch (const exception& e) {
        cerr << "ERROR: " << e.what() << endl;
    }
    
    
}

