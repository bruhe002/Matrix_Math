#include <iostream>
#include <sstream>
#include <exception>
#include <array>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

bool exitMenuFlag = false;
bool exitCreateMatrixFlag = true;

void fillMatrix(float** matrix, int size);
void printMatrix(float** matrix, int size);

void deleteMatrix(float** matrix, int size);

float** menuFunction(int choice, float** matrix1, float** matrix2, int& size);

float** addMatrix(float** a, float** b, int size);
float** subMatrix(float** a, float** b, int size);
float** multMatrix(float** a, float** b, int size);

int main() {
    cout << "\nWelcome to the MATRIX CALCULATOR" << endl;
    do {
        // reset flag
        exitCreateMatrixFlag = true;
        exitMenuFlag = false;
    
        cout << "\nPlease enter the size of the matrix: ";
        string garbage;
        int matrixSize = 0;
        cin >> matrixSize;
        getline(cin, garbage);



        // Initialize Matrices
        float **matrix1 = new float*[matrixSize];
        float **matrix2 = new float*[matrixSize];

        // Add matix columns
        for(int i = 0; i < matrixSize; i++) {
            *(matrix1 + i) = new float[matrixSize];
            *(matrix2 + i) = new float[matrixSize];
        }

        if(matrixSize < 100) {
            // Ask user for inputs row by row
            cout << "\nNow let's enter some values into your FIRST MATRIX:\n" << endl;
            fillMatrix(matrix1, matrixSize);


            cout << "\nNow let's enter some values into your SECOND MATRIX:\n" << endl;
            fillMatrix(matrix2, matrixSize);

            float **resultingMatrix;
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
                        resultingMatrix = menuFunction(userChoice, matrix1, matrix2, matrixSize);
                        if(resultingMatrix != nullptr) {
                            cout << "Result:" << endl;
                            printMatrix(resultingMatrix, matrixSize);
                            deleteMatrix(resultingMatrix, matrixSize);
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
        // Deallocate Memory
        deleteMatrix(matrix1, matrixSize);
        deleteMatrix(matrix2, matrixSize);
        // deleteMatrix(resultingMatrix, matrixSize);
        
    } while (!exitCreateMatrixFlag);

    
    cout << endl;
    system("Pause");
    return 0;
}

void deleteMatrix(float** matrix, int size) {
    for(int i = 0; i < size; i++) {
        delete[] *(matrix + i);
        *(matrix + i) = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;
}

float** menuFunction(int choice, float** matrix1, float** matrix2, int& size) {
    switch(choice) {
        case 1:
            // cout << "case 1" << endl; 
            return addMatrix(matrix1, matrix2, size);
            break;
        case 2:
            // cout << "case 2" << endl;
            return subMatrix(matrix1, matrix2, size);
            break;
        case 3:
            // cout << "case 3" << endl;
            return multMatrix(matrix1, matrix2, size);
            break;
        case 4:
            // cout << "Case 4" << endl;
            // deleteMatrix(matrix1, size);
            // deleteMatrix(matrix2, size);
            exitCreateMatrixFlag = false;
            exitMenuFlag = true;
            return nullptr;
            break;
        default:
            // cout << "Case 5" << endl;
            exitMenuFlag = true;
            exitCreateMatrixFlag = true;
            return nullptr;
            break;
    }
}

void fillMatrix(float** matrix, int size){
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
                *(*(matrix + i) + elementCounter) = stof(element);
                elementCounter++;
            }

        }

        // If the number of elements did not reach the row size
        // Padd with zeroes
        for(int j = elementCounter; j < size; j++) {
            *(*(matrix + i) + j) = 0.0;
        }
    }
}

void printMatrix(float** matrix, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }

        cout << endl;
    }
}

float** addMatrix(float** a, float** b, int size) {
    float** result = new float*[size];
    for(int i = 0; i < size; i++) {
        result[i] = new float[size];
    }
    try {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            *(*(result + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
        }
    }
    } catch(exception& e) {
        cerr << e.what() << endl;
    }

    return result; 
}

float** subMatrix(float** a, float** b, int size) {
    float** result = new float*[size];
    for(int i = 0; i < size; i++) {
        result[i] = new float[size];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            *(*(result + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);
        }
    }

    return result;
}

float** multMatrix(float** a, float** b, int size) {
    float** result = new float*[size];
    for(int i = 0; i < size; i++) {
        result[i] = new float[size];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            *(*(result + i) + j) = 0;
            for(int k = 0; k < size; k++) {
                float temp2 = *(*(b + k) + j);
                float temp1 = *(*(a + i) + k);
                *(*(result + i) + j) = *(*(result + i) + j) + temp1 * temp2; 
            }
        }
    }

    return result;
}