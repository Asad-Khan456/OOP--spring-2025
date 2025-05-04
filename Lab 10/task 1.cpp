#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream inFile("vehicles.txt");
    if (!inFile.is_open()){
        cerr << "Error:Could not open the file 'vEhicles.txt'." << endl;
        return 1;
    }
    string line;
    while(getline(inFile, line)){
        if (line.empty() || line[0] == '#')
        {
            continue;
        }
        cout << line << endl; 
    }
    inFile.close();
    return 0;
}

