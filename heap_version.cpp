#include <iostream>
#include <sstream>
#include <exception>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_ARRAY_SIZE = 100;

bool exitMenuFlag = false;
bool exitCreateMatrixFlag = true;

void fillMatrix(float** matrix, int row, int col);
void printMatrix(float** matrix, int row, int col);

void deleteMatrix(float** matrix, int row);

float** menuFunction(int choice, float** matrix1, float** matrix2, int firstRow, int firstCol, int secondRow, int secondCol);

float** addMatrix(float** a, float** b, int firstRow, int firstCol, int secondRow, int secondCol);
float** subMatrix(float** a, float** b, int firstRow, int firstCol, int secondRow, int secondCol);
float** multMatrix(float** a, float** b, int firstRow, int firstCol, int secondRow, int secondCol);

void randomMatrix(float m[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int size);
void measureMultiplication();

int main() {
    cout << "\nWelcome to the MATRIX CALCULATOR" << endl;
    srand(time(NULL));
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

        // Initialize Matrices
            float **matrix1 = new float*[firstRow];
            float **matrix2 = new float*[secondRow];

            // Add matix columns
            for(int i = 0; i < firstRow; i++) {
                *(matrix1 + i) = new float[firstCol];
            }

            for(int i = 0; i < secondRow; i++) {
                *(matrix2 + i) = new float[secondCol];
            }

        if(firstRow < MAX_ARRAY_SIZE && firstCol < MAX_ARRAY_SIZE && secondRow < MAX_ARRAY_SIZE && secondCol < MAX_ARRAY_SIZE) {
            // Ask user for inputs row by row
            cout << "\nNow let's enter some values into your FIRST MATRIX:\n" << endl;
            fillMatrix(matrix1, firstRow, firstCol);


            cout << "\nNow let's enter some values into your SECOND MATRIX:\n" << endl;
            fillMatrix(matrix2, secondRow, secondCol);

            float **resultingMatrix;
            // Display Menu
            do {
                cout << "Please choose the following: " << endl;
                cout << "\t1. Add your Matrices" << endl;
                cout << "\t2. Subtract your Matrices" << endl;
                cout << "\t3. Multiply your matrices" << endl;
                cout << "\t4. Change your Matrices" << endl;
                cout << "\t5. Measure Multiplication" << endl;
                cout << "\t6. Exit" << endl;

                try {
                    int userChoice = 0;
                    cin >> userChoice;
                    if(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5 && userChoice != 6) {
                        cout << "Not a valid choice! Please try again!" << endl;
                    } else {
                        // cout << "Entering menu Function" << endl;
                        resultingMatrix = menuFunction(userChoice, matrix1, matrix2, firstRow, firstCol, secondRow, secondCol);
                        if(userChoice != 5 && userChoice != 6) {
                            cout << "Result:" << endl;
                            printMatrix(resultingMatrix, firstRow, secondCol);
                            deleteMatrix(resultingMatrix, firstRow);
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
        
        // Deallocate Memory
        deleteMatrix(matrix1, firstRow);
        deleteMatrix(matrix2, secondRow);
        // deleteMatrix(resultingMatrix, matrixSize);
        
    } while (!exitCreateMatrixFlag);

    
    cout << endl;
    system("Pause");
    return 0;
}

void deleteMatrix(float** matrix, int row) {
    for(int i = 0; i < row; i++) {
        delete[] *(matrix + i);
        *(matrix + i) = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;
}

float** menuFunction(int choice, float** matrix1, float** matrix2, int firstRow, int firstCol, int secondRow, int secondCol) {
    switch(choice) {
        case 1:
            // cout << "case 1" << endl; 
            return addMatrix(matrix1, matrix2, firstRow, firstCol, secondRow, secondCol);
            break;
        case 2:
            // cout << "case 2" << endl;
            return subMatrix(matrix1, matrix2, firstRow, firstCol, secondRow, secondCol);
            break;
        case 3:
            // cout << "case 3" << endl;
            return multMatrix(matrix1, matrix2, firstRow, firstCol, secondRow, secondCol);
            break;
        case 4:
            exitCreateMatrixFlag = false;
            exitMenuFlag = true;
            return nullptr;
            break;
        case 5:
            measureMultiplication();
            break;
        default:
            // cout << "Case 5" << endl;
            exitMenuFlag = true;
            exitCreateMatrixFlag = true;
            return nullptr;
            break;
    }
}

void fillMatrix(float** matrix, int row, int col){
    string rowElements;
    for(int i = 0; i < row; i++) {
        cout << "For ROW " << i << ": ";
        getline(cin, rowElements);
        cout << endl;

        int elementCounter = 0;
        string element;
        stringstream input(rowElements);
        while(getline(input, element, ' ')) {
            // If elementCounter Does not exceed the size of the row
            if(elementCounter < col) {
                *(*(matrix + i) + elementCounter) = stof(element);
                elementCounter++;
            }

        }

        // If the number of elements did not reach the row size
        // Padd with zeroes
        for(int j = elementCounter; j < col; j++) {
            *(*(matrix + i) + j) = 0.0;
        }
    }
}

void printMatrix(float** matrix, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }

        cout << endl;
    }
}

float** addMatrix(float** a, float** b, int firstRow, int firstCol, int secondRow, int secondCol) {
    if(firstRow == secondRow && firstCol == secondCol) {
        float** result = new float*[firstRow];
        for(int i = 0; i < firstRow; i++) {
            result[i] = new float[firstCol];
            for(int j = 0; j < firstCol; j++) {
                    *(*(result + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
            }
        }
        return result; 

    } else {
        throw 20; // Throw error code if sizes don't match
    }
}

float** subMatrix(float** a, float** b, int firstRow, int firstCol, int secondRow, int secondCol) {
    if(firstRow == secondRow && firstCol == secondCol) {
        float** result = new float*[firstRow];
        for(int i = 0; i < firstRow; i++) {
            result[i] = new float[firstCol];
            for(int j = 0; j < firstCol; j++) {
                    *(*(result + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);
            }
        }
        return result; 

    } else {
        throw 20; // Throw error code if sizes don't match
    }
}

float** multMatrix(float** a, float** b, int firstRow, int firstCol, int secondRow, int secondCol) {
    if(firstCol == secondRow) {
        float** result = new float*[firstRow];
        for(int i = 0; i < firstRow; i++) {
            result[i] = new float[secondCol];
        }

        for(int i = 0; i < firstRow; i++) {
            for(int j = 0; j < secondCol; j++) {
                *(*(result + i) + j) = 0;
                for(int k = 0; k < firstCol; k++) {
                    float temp2 = *(*(b + k) + j);
                    float temp1 = *(*(a + i) + k);
                    *(*(result + i) + j) = *(*(result + i) + j) + temp1 * temp2; 
                }
            }
        }

        return result;
    } else {
        throw 20; // Throw error code if sizes don't match
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

    float** matrix1 = randomMatrix(matrixSize);
    float** matrix2 = randomMatrix(matrixSize);

    cout << "Multiplying matrices...\n" << endl;
    auto start = high_resolution_clock::now();
    try {
        float** result = multMatrix(matrix1, matrix2, matrixSize, matrixSize, matrixSize, matrixSize);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "\nTIME OF COMPLETION: " <<  duration.count() << "ns\n" << endl;
        deleteMatrix(result, matrixSize);
    } catch (const exception& e) {
        cerr << "ERROR: " << e.what() << endl;
    }
    
    deleteMatrix(matrix1, matrixSize);
    deleteMatrix(matrix2, matrixSize);
    
}