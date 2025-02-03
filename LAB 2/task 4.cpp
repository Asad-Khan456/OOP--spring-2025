#include "iostream"
#include "string"
using namespace std;
struct student {
    string name;
    int roll;
    int marks[5];
};
void inputstudent(student* std) {
    cout << "Enter student ID: ";
    cin >> std->roll;
    cout << "Enter Name: ";
    cin >> std->name;
    
    for (int i = 0; i < 5; i++) {
        cout << "Input marks of Subject " << (i + 1) << ": ";
        cin >> std->marks[i];
    }
}

void displaystudents(student* std) {
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += std->marks[i];
    }  
    float average = total / 5;    
    char grade;
    if (average >= 80) grade = 'A';
    else if (average >= 70) grade = 'B';
    else if (average >= 60) grade = 'C';
    else if (average >= 50) grade = 'D';
    else grade = 'F';   
    cout << "\nStudent ID: " << std->roll
         << "\nName: " << std->name
         << "\nAverage Marks: " << average
         << "\nGrade: " << grade << "\n";
}

int main() {
    int n;
    cout << "Input number of students: ";
    cin >> n;
    student* students = new student[n]; 
    int c = 0; 
    while (true) {
        cout << "\nMenu:\n1. Enter student details\n2. Display student grades\n3. Exit\nEnter choice: ";
        cin >> c;
        switch (c) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for student " << (i + 1) << ":\n";
                    inputstudent(&students[i]);
                }
                break;
            case 2:
                cout << "\nAll Student Details:\n";
                for (int i = 0; i < n; i++) {
                    displaystudents(&students[i]);
                }
                break;
            case 3:
                delete[] students; 
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
}
