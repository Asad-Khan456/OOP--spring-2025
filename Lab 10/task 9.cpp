#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream outFile("large_log.txt");
    outFile << "This is a sample log file with multiple lines.\nSecond line here.\nThird line here.";
    outFile.close();
    ifstream inFile("large_log.txt");
    if(!inFile){
        cerr << "Error opening file!" << endl;
        return 1;
    }
    char buffer[11] = {};
    inFile.read(buffer, 10);
    cout << "After reading first 10 chars, position: " << inFile.tellg() << endl;
    inFile.read(buffer, 10);
    cout << "After reading next 10 chars, position: " << inFile.tellg() << endl;
    inFile.close();
    return 0;
}
