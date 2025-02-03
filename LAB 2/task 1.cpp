#include <iostream>
using namespace std;
void display(int *arr, int n) {
    int max = arr[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) { 
            max = arr[i];
        }
        sum += arr[i];
    }
    int avg = sum / n; 
    cout << "The Sum of elements of the array is: " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Max value in array: " << max << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    display(arr, n);
    delete[] arr;
    return 0;
}
