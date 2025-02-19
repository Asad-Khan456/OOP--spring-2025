#include "iostream"
#include "string"
using namespace std;

class car{
    int RN;
    string model;
    string owner_name;
    public:
    car(int a,string b, string c){
        RN = a;
        model = b;
        owner_name = c;
    }
    car(car& obj){
        RN = obj.RN;
        model = obj.model;
        owner_name = obj.owner_name;
    }
    void dispay(){
        cout << "Reg Number:" << RN << endl;
        cout << "Model name:" << model << endl;
        cout << "Owner name:" << owner_name << endl;
    }
    void update(string newowmner){
        owner_name = newowmner;
    }
};
int main(){
    car car1(746,"Toyota yaris","John");
    car car2(526,"Honda Civic","Jackson");
    cout << "oringinal details" << endl;
    car1.dispay();
    car2.dispay();
    car rentedcar1 = car1;
    rentedcar1.update("Bob");
    car rentedcar2 = car2;
    rentedcar2.update("Noah");
    cout << "New owners:" << endl;
    rentedcar1.dispay();
    rentedcar2.dispay();
    return 0;
    
}
