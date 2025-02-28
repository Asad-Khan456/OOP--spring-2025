#include "iostream"
#include "string"
using namespace std;
class professor{
    string name;
    string department;
public:
    professor(string a, string b){
        name = a;
        department = b;
    }
    void profDetails(){
        cout << "Name of Professor: " << name << endl;
        cout << "Department of Professor: " << department << endl;
    }
};
class university{
    string uniName = "FAST University";
    professor** profs;
    int cap;
    int numProfs;
public:
    university(int a){
        cap = a;
        numProfs = 0;
        profs = new professor*[cap];
    }
    ~university(){
        for (int i = 0; i < numProfs; ++i) {
            delete profs[i];
        }
        delete[] profs;
    }
    void addProfessor(string name, string department){
        if (numProfs < cap) {
            profs[numProfs] = new professor(name, department);
            numProfs++;
        } else {
            cout << "Cannot add more professors, capacity reached!" << endl;
        }
    }
    void displayUniversityDetails(){
        cout << "University Name: " << uniName << endl;
        cout << "Professors: " << endl;
        for (int i = 0; i < numProfs; ++i) {
            profs[i]->profDetails();  
            cout << endl;
        }
    }
};
int main(){
    university uni(3);
    uni.addProfessor("Prof. Talha Shahid", "Computer Science");
    uni.addProfessor("Prof. Sara", "AI & DS");
    uni.addProfessor("Prof. Ahmed", "Software Engineering");
    uni.addProfessor("Prof. John", "Electrical Engineering");
    uni.displayUniversityDetails();
    return 0;
}
