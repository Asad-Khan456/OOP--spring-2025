#include "iostream"
#include "string"
using namespace std;
class vehicle{
    string brand;
    int speed;
    public:
    vehicle(string a,int b){
        brand = a;
        speed =b;

    }
    void displaydetails(){
        cout << "Brand:" << brand << endl;
        cout << "Speed:" << speed << endl;
    }
};
class car:public vehicle{
    int seats;
    public:
    car(string a, int b, int seats) : vehicle(a,b), seats(seats){}
    void display(){
        vehicle :: displaydetails();
        cout << "Number of seats: " << seats << endl;
    }
};
class ElectricCar: public car{
    int batterylife;
    public:
    ElectricCar(string a, int b, int c,int batterylife): car(a,b,c),batterylife(batterylife){}
    void displaydeTAILS(){
        car :: display();
        cout << "BAttery LIfe:" << batterylife << endl;
    }
};
int main(){
    ElectricCar c1("TOyota",77,5,45);
    c1.displaydeTAILS();
    ElectricCar c2("Honda",80,7,89);
    c2.displaydeTAILS();
    return 0;
}
