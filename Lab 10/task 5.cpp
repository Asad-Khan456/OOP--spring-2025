#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    ifstream inFile("vehicles.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Could not open the file 'vehicles.txt'." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty() || line[0] == '#') continue;

        istringstream ss(line);
        string type, id, name, year, extraData, certification;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "CErtification: " << certification << endl;
        if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':');
            if(colonPos != string::npos){
                string valueStr = extraData.substr(colonPos + 1);
                float softwareVersion = stof(valueStr);
                cout << "Software Version: " << softwareVersion << endl;
            }
            else{
                cout << "Warning: Invalid ExtraData format for AutonomousCar." << endl;
            }
        }
        else if(type == "ElectricVehicle"){
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos){
                string valueStr = extraData.substr(colonPos + 1);
                int batteryCapacity = stoi(valueStr);
                cout << "Battery Capacity: " << batteryCapacity << endl;
            }
            else{
                cout << "Warning: Invalid ExtraData format for ElectricVehicle." << endl;
            }
        }
        else if(type == "HybridTruck"){
            size_t colonPos1 = extraData.find(':');
            size_t pipePos = extraData.find('|');
            size_t batteryPos = extraData.find("Battery:");

            if(colonPos1 != string::npos && pipePos != string::npos && batteryPos != string::npos){
                string cargoStr = extraData.substr(colonPos1 + 1, pipePos - colonPos1 - 1);
                int cargoValue = stoi(cargoStr);

                string batteryStr = extraData.substr(batteryPos + 8); // 8 = length of "Battery:"
                int batteryValue = stoi(batteryStr);

                cout << "Cargo Capacity: " << cargoValue << endl;
                cout << "Battery Capacity: " << batteryValue << endl;
            }
            else{
                cout << "Warning: Invalid ExtraData format for HybridTruck." << endl;
            }
        }
        else{
            cout << "Warning: Unknown vehicle type." << endl;
        }
        cout << "------------------------" << endl;
    }
    inFile.close();
    return 0;
}
