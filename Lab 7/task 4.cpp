#include "iostream"
#include "string"
using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;
public:
    Person(string name, int id, string address, string phoneNumber, string email)
        : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {}



    virtual void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
    void updateInfo(string newAddress, string newPhoneNumber, string newEmail){
        address = newAddress;
        phoneNumber = newPhoneNumber;
        email = newEmail;
    }
    string getName() const{
        return name;
    }
};
class Student : public Person {
    string* coursesEnrolled;
    int numCourses;
    float GPA;
    int enrollmentYear;
    int maxCourses;
public:
    Student(string name, int id, string address, string phoneNumber, string email, float GPA, int enrollmentYear, int maxCourses)
        : Person(name, id, address, phoneNumber, email), GPA(GPA), enrollmentYear(enrollmentYear), numCourses(0), maxCourses(maxCourses) {
        coursesEnrolled = new string[maxCourses];
    }
    ~Student(){
        delete[] coursesEnrolled; 
    }
    void addCourse(string courseName){
        if(numCourses < maxCourses){
            coursesEnrolled[numCourses] = courseName;
            numCourses++;
        }
        else{
            cout << "Cannot add more courses.Maximum number of courses reached" << endl;
        }
    }
    void displayInfo() override{
        Person::displayInfo();
        cout << "GPA: " << GPA << endl;
        cout << "Enrolment Year: " << enrollmentYear << endl;
        cout << "Courss enrolled: ";
        for(int i = 0; i < numCourses; ++i){
            cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};


class Professor : public Person{
    string department;
    string* coursesTaught;
    int numCourses;
    float salary;
    int maxCourses;
public:
    Professor(string name, int id, string address, string phoneNumber, string email, string department, float salary, int maxCourses)
        : Person(name, id, address, phoneNumber, email), department(department), salary(salary), numCourses(0), maxCourses(maxCourses) {
        coursesTaught = new string[maxCourses]; 
    }
    ~Professor(){
        delete[] coursesTaught; 
    }
    void addCourse(string courseName){
        if (numCourses < maxCourses) {
            coursesTaught[numCourses] = courseName;
            numCourses++;
        }
        else{
            cout << "Cannot add more courses. Max courses reached!" << endl;
        }
    }
    void displayInfo() override{
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "Courses Taught: ";
        for(int i = 0; i < numCourses; ++i){
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
};
class Staff : public Person{
    string department;
    string position;
    float salary;
public:
    Staff(string name, int id, string address, string phoneNumber, string email, string department, string position, float salary)
        : Person(name, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}
    void displayInfo() override{
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Course{
    string courseId;
    string courseName;
    int credits;
    Professor instructor;
    string schedule;
public:
    Course(string courseId, string courseName, int credits, Professor instructor, string schedule)
        : courseId(courseId), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule) {}
    void registerStudent(Student* student){
        cout << student->getName() << " has been registered for " << courseName << endl;
    }
    void calculateGrades(Student* student){
        cout << "Calculating grades for " << student->getName() << " in " << courseName << endl;
    }
    string calculateGrade(float GPA) {
        if (GPA >= 3.7){
            return "A";
        }
        else if(GPA >= 3.0){
            return "B";
        }
        else if(GPA >= 2.0){
            return "C";
        }
        else if(GPA >= 1.0){
            return "D";
        }
        else{
            return "F";
        }
    }
    string getCourseName(){
        return courseName;
    }
};
int main(){
    Professor prof("Dr. Smith", 101, "St 12", "123-1213", "smith@nu.edu,pk", "Computer Science", 80000, 5);
    Student student("John Doe", 201, "st79", "123-1234", "john.doe@nu.edu.pk", 3.8, 2021, 5);
    Staff staff("Alice Brown", 301, "Pine St", "123-5928", "alice@nu.edu.pk", "Admin", "Secretary", 45000);
    Course course("CS1001", "Introduction to ComputerScience", 3, prof, "Mon,Wed,Fri - 9:00 AM to 10:30 AM");
    course.registerStudent(&student);
    course.calculateGrades(&student);
    student.displayInfo();
    prof.displayInfo();
    staff.displayInfo();
    return 0;
}
