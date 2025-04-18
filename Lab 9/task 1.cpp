#include "iostream"
#include "string"
using namespace std;
class Vehicle{
    protected:
    string model;
    double rate;
    public:
    Vehicle(string model,double rate) : model(model),rate(rate) {}
    virtual double getDailyrate() = 0;
    virtual void displayDetails() = 0;
};
class Car : public Vehicle{
    public:
    Car(string m,double r) : Vehicle(m,r){}
    double getDailyrate() override{
        return rate;
    }
    void displayDetails() override{
        cout << "Model:" << model << endl;
        cout << "Rate:" << rate << endl;
    }
};
class Bike : public Vehicle{
    public:
    Bike(string m,double r) : Vehicle(m,r){}
    double getDailyrate() override{
        return rate;
    }
    void displayDetails() override{
        cout << "Model:" << model << endl;
        cout << "Rate:" << rate << endl;
    }
};
int main(){
    Car c1("Corolla", 39.00);
    Bike b1("Suzuki 150",12.00);
    c1.getDailyrate();
    c1.displayDetails();
    b1.getDailyrate();
    b1.displayDetails();
    return 0;
}
