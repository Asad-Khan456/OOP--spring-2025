#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inFile("data_records.txt");
    if(!inFile){
        cerr << "Error opening file." << endl;
        return 1;
    }
    streampos offset = 18;
    inFile.seekg(offset, ios::beg);
    string record;
    getline(inFile, record);
    cout << "Third record: " << record << endl;
    inFile.close();
    return 0;
}
