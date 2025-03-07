#include "iostream"
#include "string"
using namespace std;
class Device{
protected:
    int deviceID;
    bool status;
public:
    Device(int a, bool b){
        deviceID = a;
        status = b;
    }
    virtual void displayDetails(){
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "Active" : "Inactive") << endl;
    }
};
class Smartphone:public Device{
protected:
    float screenSize;
public:
    Smartphone(int a, bool b, float c) : Device(a, b), screenSize(c){}
    void displayDetails() override{
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};
class SmartWatch : public Device{
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int a, bool b, bool c) : Device(a, b), heartRateMonitor(c) {}
    void displayDetails() override{
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};
class SmartWearable : public Smartphone, public SmartWatch {
private:
    int stepCounter;
public:
    SmartWearable(int a, bool b, float c, bool d, int e)
        : Smartphone(a, b, c), SmartWatch(a, b, d), stepCounter(e) {}
    void displayDetails() override {
        Smartphone::displayDetails();
        SmartWatch::displayDetails();
        cout << "Step Counter: " << stepCounter << " steps" << endl;


    }
};
int main() {
    int deviceID;
    bool status;
    float screenSize;
    bool heartRateMonitor;
    int stepCounter;
    cout << "Enter Device Details" << endl;
    cout << "Device ID: ";
    cin >> deviceID;
    cout << "Status (1 for Active, 0 for Inactive): ";
    cin >> status;
    cout << "Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;
    cout << "Step Counter (Number of steps): ";
    cin >> stepCounter;
    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    cout << "\nDevice Specifications:" << endl;
    wearable.displayDetails();
    return 0;
}
