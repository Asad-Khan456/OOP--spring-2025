#include "iostream"
#include "string"
using namespace std;
class Teacher;
class Student{
    string name;
    int grades[3];
public:
    Student(string n, int g1, int g2, int g3):name(n){
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }
    void display(){
        cout << name << "'s Grades:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Grade " << (i + 1) << ": " << grades[i] << endl;
        }
    }
    friend float calcAvgGrade(Student& s);
    friend class Teacher;
};
class Teacher{
public:
    void displayGrades(Student& s){
        s.display();
    }
    void updateGrade(Student& s, int index, int newGrade) {
        if(index >= 0 && index < 3){
            s.grades[index] = newGrade;
            cout << "Grade " << (index + 1) << " updated to: " << newGrade << endl;
        }
        else
        {
            cout << "Invalid grade index!" << endl;
        }
    }
};

float calcAvgGrade(Student& s){
    int sum = 0;
    for (int i = 0; i < 3; ++i){
        sum += s.grades[i];
    }
    return sum / 3; 
}

int main() {
    Student s("Haris", 83, 99, 78);
    Teacher t;
    t.displayGrades(s);
    cout << endl;
    cout << "Average Grade: " << calcAvgGrade(s) << endl;
    cout << endl;
    t.updateGrade(s, 1, 92);
    cout << endl;
    t.displayGrades(s);
    cout << endl;
    cout << "New Average Grade: " << calcAvgGrade(s) << endl;
    return 0;
}
