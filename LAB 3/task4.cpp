#include "iostream"
#include "string"
using namespace std;
class Laptop{
    public:
    string brand;
    string model;
    int processor;
    int RAM;
    int storage;
    void display(){
        cout << "Laptop Specifications:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << RAM << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }
};
int main(){
    Laptop BLaptop;
    Laptop ALaptop;
    cout << "Enter details for Bilal's laptop:" << endl;
    cout << "Brand: ";
    cin >> BLaptop.brand;
    cout << "Model: ";
    cin >> BLaptop.model;
    cout << "Processor: ";
    cin >> BLaptop.processor;
    cout << "RAM (GB): ";
    cin >> BLaptop.RAM;
    cout << "Storage (GB): ";
    cin >> BLaptop.storage;
    cout << endl;

    cout << "Enter details for Ayesha's laptop:" << endl;
    cout << "Brand: ";
    cin >> ALaptop.brand;
    cout << "Model: ";
    cin >> ALaptop.model;
    cout << "Processor: ";
    cin >> ALaptop.processor;
    cout << "RAM (GB): ";
    cin >> ALaptop.RAM;
    cout << "Storage (GB): ";
    cin >> ALaptop.storage;
    cout << endl;
    cout << "Specifications of BIlal's s laptop" << endl;
    BLaptop.display();
    cout << "Specifications of Ayesha's s laptop" << endl;
    ALaptop.display();
    // comparison
    if(BLaptop.model > ALaptop.model){
        cout << "Bilal has a newer laptop" << endl;
    }
    else if(ALaptop.model > BLaptop.model){
        cout << "Ayesha has a newer laptop" << endl;
    }
    else {
        cout << "Both Laptops were launched around the same time " << endl;
    }
    if (BLaptop.RAM > ALaptop.RAM) {
        cout << "\nBilal's laptop has more RAM." << endl;
    }
    else if (ALaptop.RAM > BLaptop.RAM) {
        cout << "\nAyesha's laptop has more RAM." << endl;
    }
    else {
        cout << "\nBoth laptops have the same RAM." << endl;
    }
    if (BLaptop.storage > ALaptop.storage) {
        cout << "Bilal's laptop has more storage." << endl;
    }
    else if (ALaptop.storage > BLaptop.storage) {
        cout << "Ayesha's laptop has more storage." << endl;
    }
    else {
        cout << "Both laptops have the same storage." << endl;
    }

}
