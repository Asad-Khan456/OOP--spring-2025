#include "iostream"
#include "string"
using namespace std;
class Battery{
    int capacity;
public:
    Battery(int capacity) : capacity(capacity) {}
    void display() const {
        cout << "Battery capacity: " << capacity << " mAh" << endl;
    }
};
class Smartphone{
private:
    string model;
    Battery battery;
public:
    Smartphone(const string& model,int batteryCapacity)
        : model(model), battery(batteryCapacity) {}
    void display(){
        cout << "Smartphone Model: " << model << endl;
        battery.display();
    }
};
int main(){
    Smartphone phone1("Galaxy SS22", 4500);
    Smartphone phone2("Iphone 12 Pro", 4500);
    phone1.display();
    phone2.display();
    return 0;
}
