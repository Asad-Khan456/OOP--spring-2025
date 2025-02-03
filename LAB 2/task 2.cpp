#include <iostream>
using namespace std;
void Matrixinput(int* matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(matrix + i * cols + j);
        }
    }
}
void Matrixdisplay(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(matrix + i * cols + j) << " ";
        }
        cout << endl;
    }
}
void addMatrices(int* A, int* B, int* result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(A + i * cols + j) + *(B + i * cols + j);
        }
    }
}
void subtractMatrices(int* A, int* B, int* result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(A + i * cols + j) - *(B + i * cols + j);
        }
    }
}
void multiplyMatrices(int* A, int* B, int* result, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            *(result + i * colsB + j) = 0;
            for (int k = 0; k < colsA; k++) {
                *(result + i * colsB + j) += *(A + i * colsA + k) * *(B + k * colsB + j);
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter dimensions of Matrix A (rows and columns): ";
    cin >> rowsA >> colsA;
    int* A = new int[rowsA * colsA];
    Matrixinput(A, rowsA, colsA);
    cout << "Enter dimensions of Matrix B (rows and columns): ";
    cin >> rowsB >> colsB;
    int* B = new int[rowsB * colsB];
    Matrixinput(B, rowsB, colsB);
    cout << "Matrix A:\n";
    Matrixdisplay(A, rowsA, colsA);
    cout << "Matrix B:\n";
    Matrixdisplay(B, rowsB, colsB);
    if (rowsA == rowsB && colsA == colsB) {
        int* sum = new int[rowsA * colsA];
        addMatrices(A, B, sum, rowsA, colsA);
        cout << "Addition of Matrices:\n";
        Matrixdisplay(sum, rowsA, colsA);
        delete[] sum;
        int* diff = new int[rowsA * colsA];
        subtractMatrices(A, B, diff, rowsA, colsA);
        cout << "Subtraction of Matrices:\n";
        Matrixdisplay(diff, rowsA, colsA);
        delete[] diff;
    } else {
        cout << "Addition and Subtraction not possible due to different dimensions\n";
    }
    if (colsA == rowsB) {
        int* product = new int[rowsA * colsB];
        multiplyMatrices(A, B, product, rowsA, colsA, colsB);
        cout << "Multiplication of Matrices:\n";
        Matrixdisplay(product, rowsA, colsB);
        delete[] product;
    } else {
        cout << "Multiplication not possible due to different dimensions\n";
    }
    delete[] A;
    delete[] B;
    return 0;
}
