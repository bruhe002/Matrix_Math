#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <stdlib.h>

#include "matrix.h"

using namespace std;

bool exitCreateMatrixFlag = true;
bool exitMenuFlag = false;

// const int MAX_ARRAY_SIZE = 100;

void fillMatrix(Matrix& m, int size);

// void menuFunction(int choice, const Matrix& m1, const Matrix& m2, const Matrix& m3);

int main() {
    cout << "\nWelcome to the MATRIX CALCULATOR" << endl;
    float **firstMatrix;
    float **secondMatrix;
    float **thirdMatrix;
    // Initialize Matrices
    do {
        exitCreateMatrixFlag = true;
        exitMenuFlag = false;

        cout << "\nPlease enter the size of the matrix: ";
        string garbage;
        int matrixSize = 0;
        cin >> matrixSize;
        getline(cin, garbage);
        
        if(matrixSize < MAX_ARRAY_SIZE) {
            cout << "Before the matrix Creation" << endl;
            firstMatrix = new float*[matrixSize];
            secondMatrix = new float*[matrixSize];
            thirdMatrix = new float*[matrixSize];
            for(int i = 0; i < matrixSize; i++) {
                *(firstMatrix + i) = new float[matrixSize];
                *(secondMatrix + i) = new float[matrixSize];
                *(thirdMatrix + i) = new float[matrixSize];
            }
            Matrix matrix1(firstMatrix, matrixSize);
            Matrix matrix2(secondMatrix, matrixSize);
            Matrix resultMatrix;
            

            // cout << matrix1 << endl;

            // Ask user for inputs row by row
            cout << "\nNow let's enter some values into your FIRST MATRIX:\n" << endl;
            fillMatrix(matrix1, matrixSize);

            cout << "\nNow let's enter some values into your SECOND MATRIX:\n" << endl;
            fillMatrix(matrix2, matrixSize);

            // Matrix difMatrix = matrix1 - matrix2;
            // Matrix prodMatrix = matrix1 * matrix2;

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
                        switch(userChoice) {
                            case 1:
                                resultMatrix = matrix1 + matrix2;
                                cout << "\nSum: \n" << resultMatrix << endl;
                                break;
                            case 2:
                                resultMatrix = matrix1 - matrix2;
                                cout << resultMatrix << endl;
                                break;
                            case 3:
                                resultMatrix = matrix1 * matrix2;
                                cout << resultMatrix << endl;
                                break;
                            case 4:
                                exitCreateMatrixFlag = false;
                                exitMenuFlag = true;
                                break;
                            case 5:
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

void fillMatrix(Matrix& m, int size) {
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
                m.setElement(i, elementCounter, stof(element));
                elementCounter++;
            }
        }

        // If the number of elements did not reach the row size
        // Padd with zeroes
        for(int j = elementCounter; j < size; j++) {
            m.setElement(i, j, 0.0);
        }
    }
}

// void menuFunction(int choice, const Matrix& m1, const Matrix& m2, const Matrix& m3) {

// }

