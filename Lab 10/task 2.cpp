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
        if(line.empty() || line[0] == '#')continue;
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
        cout << "------------------------" << endl;
    }
    inFile.close();
    return 0;
}
