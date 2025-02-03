#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int employeeID;
    char name[20];
    char department[50];
    float salary;
};

void inputEmployee(Employee* emp) {
    cout << "Enter Employee ID: ";
    cin >> emp->employeeID;
    cout << "Enter Name: ";
    cin >> emp->name;
    cout << "Enter Department: ";
    cin >> emp->department;
    cout << "Enter Salary: ";
    cin >> emp->salary;
}

void displayEmployee(const Employee* emp) {
    cout << "Employee ID: " << emp->employeeID << endl;
    cout << "Name: " << emp->name << endl;
    cout << "Department: " << emp->department << endl;
    cout << "Salary: $" << emp->salary << endl;
    cout << "---------------------------" << endl;
}

void searchEmployee(Employee* employees, int n, int id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].employeeID == id) {
            displayEmployee(&employees[i]);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cout << "Employee with ID " << id << " not found" << endl;
    }
}
int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    int c;
    Employee* employees = new Employee[n]; 
    while (c != 4)
    {
        cout << "Enter 1 to enter details\n2 to display employees\n3 to search for an employee\n 4 to exit"<< endl;
        cin >> c;
        switch (c)
    {
    case 1:
        for (int i = 0; i < n; i++) {
        cout << "\nEnter details for employee " << (i + 1) << ":" << endl;
        inputEmployee(&employees[i]);
        }
        break;
    case 2:
        cout << "\nAll Employee Details:\n";
        for (int i = 0; i < n; i++) {
            displayEmployee(&employees[i]);
        }
        break;
    case 3:
        int searchID;
        cout << "\nEnter Employee ID to search: ";
        cin >> searchID;
        searchEmployee(employees, n, searchID);
        break;
    case 4:
        delete[] employees;
        return 0;
        break;
    default:
        break;
    }
    }
    
}
