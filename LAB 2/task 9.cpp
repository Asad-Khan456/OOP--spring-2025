#include "iostream"
#include "string"
using namespace std;
struct student {
    string name;
    int roll;
    int marks;
};
void inputstudent(student* std) {
    cout << "Enter student ID: ";
    cin >> std->roll;
    cout << "Enter Name: ";
    cin >> std->name;
    
    
        cout << "Input marks of Stufent " ;
        cin >> std->marks;
    
}
void displaystudents(student* students, int n) {
    if (n == 0) {
        cout << "No students available.\n";
        return;
    }
    student topStudent = students[0]; 
    for (int i = 1; i < n; i++) {
        if (students[i].marks > topStudent.marks) {
            topStudent = students[i];
        }
    }
    cout << "\nHighest acheiver:\n";
    cout << "ID: " << topStudent.roll << "\n";
    cout << "Name: " << topStudent.name << "\n";
    cout << "Marks: " << topStudent.marks << "\n";
}

int main() {
    int n;
    cout << "Input number of students: ";
    cin >> n;
    student* students = new student[n]; 
    int c = 0; 
    while (true) {
        cout << "\nMenu:\n1. Enter student details\n2 to display the highest acheiver\n3. Exit\nEnter choice: ";
        cin >> c;
        switch (c) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for student " << (i + 1) << ":\n";
                    inputstudent(&students[i]);
                }
                break;
            case 2:
                
                for (int i = 0; i < n; i++) {
                    displaystudents(students, n);
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
