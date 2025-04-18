#include "iostream"
#include "string"
using namespace std;
class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() = 0;
    virtual ~SmartDevice() {}
};
class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;
public:
    LightBulb() : isOn(false), brightness(0) {}
    void turnOn() override{
        isOn = true;
        brightness = 50;
    }
    void turnOff() override{
        isOn = false;
        brightness = 0;
    }
    string getStatus() override{
        string status;
        if(isOn){
            status = "On, Brightness: " + to_string(brightness) + "%";
        }
        else{
            status = "Off";
        }
        return status;
    }
};
class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;
public:
    Thermostat(): isOn(false), temperature(22.0) {}
    void turnOn() override{
        isOn = true;
    }
    void turnOff() override{
        isOn = false;
    }
    string getStatus() override{
        string status;
        if(isOn){
            status = "On, Temperature: " + to_string(temperature) + " Celcius";
        }
        else{
            status = "Off";
        }
        return status;
    }
};
void showDeviceStatus(SmartDevice* device){
    cout << device->getStatus() << endl;
}
int main() {
    LightBulb bulb;
    Thermostat thermostat;
    bulb.turnOn();
    thermostat.turnOn();
    cout << "Light Bulb Status: ";
    showDeviceStatus(&bulb);
    cout << "Thermostat Status: ";
    showDeviceStatus(&thermostat);
    bulb.turnOff();
    thermostat.turnOff();
    cout << "\nAfter turning off devices:\n";
    cout << "Light Bulb Status: ";
    showDeviceStatus(&bulb);
    cout << "Thermostat Status: ";
    showDeviceStatus(&thermostat);
    return 0;
}
