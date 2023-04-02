#include <iostream>
#include <sstream>
#include <exception>
#include <array>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_ARRAY_SIZE = 100;

bool exitCreateMatrixFlag = true;
bool exitMenuFlag = false;

void fillMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col);
void printMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col);
void menuFunction(int choice, float matrix1[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float matrix2[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
                    float resultMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int firstRow, int firstCol, int secondRow, int secondCol);

void addMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], 
                int firstRow, int firstCol, int secondRow, int secondCol);
void subMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], 
                int firstRow, int firstCol, int secondRow, int secondCol);
void multMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], 
                int firstRow, int firstCol, int secondRow, int secondCol);

void randomMatrix(float m[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);
void measureMultiplication();

int main() {
    cout << "\nWelcome to the MATRIX CALCULATOR" << endl;
    srand(time(NULL));
    // Initialize Matrices
    float matrix1[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    float matrix2[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    float resultingMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    do {
        // reset flag
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
            // Ask user for inputs row by row
            cout << "\nNow let's enter some values into your FIRST MATRIX:\n" << endl;
            fillMatrix(matrix1, firstRow, firstCol);

            cout << "\nNow let's enter some values into your SECOND MATRIX:\n" << endl;
            fillMatrix(matrix2, secondRow, secondCol);

            // Display Menu
            do {
                cout << "Please choose the following: " << endl;
                cout << "\t1. Add your Matrices" << endl;
                cout << "\t2. Subtract your Matrices" << endl;
                cout << "\t3. Multiply your matrices" << endl;
                cout << "\t4. Change your Matrices" << endl;
                // cout << "\t5. Measure Multiplication" << endl;
                cout << "\t5. Exit" << endl;

                try {
                    int userChoice = 0;
                    cin >> userChoice;
                    if(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5 && userChoice != 6) {
                        cout << "Not a valid choice! Please try again!" << endl;
                    } else {
                        // cout << "Entering menu Function" << endl;
                        menuFunction(userChoice, matrix1, matrix2, resultingMatrix, firstRow, firstCol, secondRow, secondCol);
                        if (userChoice != 5 && userChoice != 6) {
                            if(resultingMatrix != nullptr) {
                                cout << "Result:" << endl;
                                printMatrix(resultingMatrix, firstRow, secondCol);
                            }
                        }
                        
                    }
                } catch (int x) {
                    if(x == 20) {
                        cerr << "ERROR 20: Rows and Columns are NOT consistent with operation" << endl;
                        exitMenuFlag = false;
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
                    float resultMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    switch(choice) {
        case 1: 
            addMatrix(matrix1, matrix2, resultMatrix, firstRow, firstCol, secondRow, secondCol);
            break;
        case 2:
            subMatrix(matrix1, matrix2, resultMatrix, firstRow, firstCol, secondRow, secondCol);
            break;
        case 3:
            multMatrix(matrix1, matrix2, resultMatrix, firstRow, firstCol, secondRow, secondCol);
            break;
        case 4:
            exitCreateMatrixFlag = false;
            exitMenuFlag = true;
            break;
        // case 5:
        //     measureMultiplication();
        //     break;    
        default:
            exitMenuFlag = true;
            exitCreateMatrixFlag = true;
            break;
    }
}

void fillMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col){
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
                matrix[i][elementCounter] = stof(element);
                elementCounter++;
            }

        }

        // If the number of elements did not reach the row size
        // Padd with zeroes
        for(int j = elementCounter; j < col; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

void printMatrix(float matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void addMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], 
                int firstRow, int firstCol, int secondRow, int secondCol) {
    if(firstRow == secondRow && firstCol == secondCol) {
        for(int i = 0; i < firstRow; i++) {
            for(int j = 0; j < firstCol; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    } else {
        throw 20;
    }

}

void subMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], 
                int firstRow, int firstCol, int secondRow, int secondCol) {
    if(firstRow == secondRow && firstCol == secondCol) {
        for(int i = 0; i < firstRow; i++) {
            for(int j = 0; j < firstCol; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    } else {
        throw 20;
    }
}

void multMatrix(float a[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float b[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], float c[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], 
                int firstRow, int firstCol, int secondRow, int secondCol) {
    if(firstCol == secondRow) {
        for(int i = 0; i < firstRow; i++) {
            for(int j = 0; j < secondCol; j++) {
                c[i][j] = 0;
                for(int k = 0; k < firstCol; k++) {
                    int temp = a[i][k] * b[k][j];
                    c[i][j] += temp; 
                }
            }
        }
    }

}


// void randomMatrix(float m[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size) {
//     for(int i = 0; i < size; i++) {
//         for(int j = 0; j < size; j++) {
//             m[i][j] = float(rand() % 9);
//         }
//     }
// }

// void measureMultiplication() {
//     cout << "Please enter in a matrix size (The Matrices will be square): ";
//     int matrixSize = 0;
//     cin >> matrixSize;
//     string garbage;
//     getline(cin, garbage);

//     float matrix1[5000][5000];
//     float matrix2[5000][5000];
//     float result[5000][5000];

//     cout << "Multiplying matrices...\n" << endl;
//     auto start = high_resolution_clock::now();
//     try {
//         multMatrix(matrix1, matrix2, result, matrixSize, matrixSize, matrixSize, matrixSize);
//         auto end = high_resolution_clock::now();

//         auto duration = duration_cast<nanoseconds>(end - start);
//         cout << "\nTIME OF COMPLETION: " <<  duration.count() << "ns\n" << endl;
//     } catch (const exception& e) {
//         cerr << "ERROR: " << e.what() << endl;
//     }
    
    
//}