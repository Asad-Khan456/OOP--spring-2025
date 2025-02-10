#include "iostream"
#include "string"
using namespace std;
class TeaMug{
    private:
    string brand;
    string color;
    int capacity;
    int currentfilllevel;
    public:
    void mugDetails(const string& b, const string& c, int tea, int r) {
        brand = b;
        color = c;
        currentfilllevel = tea;
        capacity = r;

    }

    void sip(){
        if(currentfilllevel == 0){
            cout << "Cup has no tea please refill" << endl;
        }
        else{
            currentfilllevel = currentfilllevel - 10;
            cout << "sip taken. AMount of tea remaining: "<< currentfilllevel << "%" << endl;

        }
    }
    void refillmug(){
        if(capacity == 0){
            currentfilllevel = 100;
            cout << "tea has been refilled in the "<< color <<" mug" << endl;
            
        }
        else {
            cout << " tea can not be refilled" << endl;
        }
        
    }
};
int main(){
    TeaMug mug1;
    TeaMug mug2;
    mug1.mugDetails("Tapal","bluu",80,1);
    mug2.mugDetails("Lipton","red",20,0);
    mug1.sip();
    mug2.sip();
    mug1.refillmug();
    mug2.refillmug();
    return 0;

}
