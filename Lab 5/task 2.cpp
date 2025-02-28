#include "iostream"
#include "string"
using namespace std;

class Patient{
private:
    int ID;
    string name;
public:
    float* result;
    Patient(int a, string b){
        ID = a;
        name = b;   
        result = new float[5];
    }
    Patient(Patient& obj){
        ID = obj.ID;
        name = obj.name;
        result = new float[5];  
        for (int i = 0; i < 5; i++) {
            result[i] = obj.result[i];  

        }
    }
    ~Patient(){
        delete[] result;
    }
    void displayresult(){
        cout << "Patient ID: " << ID << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Test Results: ";
        for (int i = 0; i < 5; i++) {
            cout << result[i] << " ";

        }
        cout << endl;
    }
    void setTestResults(float testResults[]){
        for (int i = 0; i < 5; i++) {
            result[i] = testResults[i];
        }
    }
};
int main(){
    Patient p1(397, "Kyle Jackson");
    float testResults1[5] = {98.5, 97.8, 99.8, 100.0, 98.9};
    p1.setTestResults(testResults1);
    cout << "Original Patient Details:" << endl;
    p1.displayresult();
    Patient p2 = p1;
    cout << "\nCopied Patient Details:" << endl;
    p2.displayresult();
    p2.result[0] = 95.0;
    p2.result[1] = 98.3;
    p2.result[2] = 97.7;
    p2.result[3] = 99.1;
    p2.result[4] = 100.0;
    cout << "\nModified Copied Patient Details:" << endl;
    p2.displayresult();
    cout << "\nOriginal Patient Details After Modification:" << endl;
    p1.displayresult();
    return 0;
}
