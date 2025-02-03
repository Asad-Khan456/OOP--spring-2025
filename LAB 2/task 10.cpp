#include <iostream>
using namespace std;
int* allocateMatrix(int rows, int cols) {
    return new int[rows * cols];
}
void inputMatrix(int* matrix, int rows, int cols) {
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(matrix + i * cols + j);
        }
    }
}
int* transposeMatrix(int* matrix, int rows, int cols) {
    int* transposed = allocateMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(transposed + j * rows + i) = *(matrix + i * cols + j); 
        }
    }
    return transposed;
}
void displayMatrix(int* matrix, int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(matrix + i * cols + j) << " "; 
        }
        cout << endl;
    }
}
void deallocateMatrix(int* matrix) {
    delete[] matrix;  
}
int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    int* matrix = allocateMatrix(rows, cols);
    inputMatrix(matrix, rows, cols);
    int* transposed = transposeMatrix(matrix, rows, cols);
    cout << "Original Matrix:\n";
    displayMatrix(matrix, rows, cols);
    cout << "Transposed Matrix:\n";
    displayMatrix(transposed, cols, rows);
    deallocateMatrix(matrix);
    deallocateMatrix(transposed);
    return 0;
}
