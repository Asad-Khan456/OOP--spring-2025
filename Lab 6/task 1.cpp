#include <iostream>
#include <string>
using namespace std;
class Employee{
    string name;
    float salary;
   
    public:
    Employee(string a, float b){
        name = a;
        salary = b;
       
    }
    void display(){
        cout << "name:" << name << endl;
        cout << "SalarY:" << salary << endl;
    }
   
};
class Manager : public Employee{
   
    float bonus;
    public:
    Manager(string n, float s, float bonus) : Employee(n,s),bonus(bonus){}
    void display(){
        Employee::display();
        cout << "Bonus:" << bonus << endl;
       
    }
};
int main() {
    Manager m1("asad",1200.5,100.0);
    m1.display();
    return 0;
}
