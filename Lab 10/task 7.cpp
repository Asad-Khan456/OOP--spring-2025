#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ofstream ofs("sensor_log.txt");
    if(!ofs){
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string data1 = "Temperature: 22.5 C\n";
    string data2 = "Humidity: 45%\n";
    string data3 = "Pressure: 1013 hPa\n";
    ofs << data1;
    cout << "Write position after first line: " << ofs.tellp() << endl;
    ofs << data2;
    cout << "Write position after second line: " << ofs.tellp() << endl;
    ofs << data3;
    cout << "Write position after third line: " << ofs.tellp() << endl;
    ofs.close();
    return 0;
}
