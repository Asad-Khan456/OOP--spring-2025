#include "iostream"
#include "string"
using namespace std;
class person{
    string name;
    int age;
    public:
    person(string a, int b){
        name = a;
        age = b;
    }
    void display(){
        cout <<"Name : " << name << endl;
        cout << " Age: " << age << endl;
     }
};
class teacher: public person{
    string subject;
    public:
    teacher(string a, int b , string subject): person(a,b),subject(subject){}
    void display(){
        person :: display();
        cout << "subject : "<< subject << endl;

    }

};
class  Researcher :public person{
    string researchArea;
    public:
    Researcher(string a, int b , string researchArea): person(a,b),researchArea(researchArea){}
    void display(){
        cout << "Research Area:" << researchArea << endl;
    }
};
class Professor: public teacher ,public Researcher{
    int publications;
    public:
    Professor(string a, int b ,string c,string d,int publications): teacher(a,b,c),Researcher(a,b,d),publications(publications){}
    void display(){
        teacher :: display();
        Researcher :: display();
        cout << " Publicataions:" << publications << endl;
    }
};
int main(){
    Professor p1("Jackson",35,"Physics","Quantum physics", 7);
    p1.display();
    return 0;
}
