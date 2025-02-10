#include "iostream"
#include "string"
using namespace std;
class MarkerPen{
    private:
    string brand;
    string color;
    int inklvl;
    int refill;
    public:
    void penDetails(const string& b, const string& c, int ink, int r) {
        brand = b;
        color = c;
        inklvl = ink;
        refill = r;

    }

    void write(){
        if(inklvl == 0){
            cout << "Marker hass no ink.Please Refill" << endl;
        }
        else if(inklvl < 30){
            cout << "the marker will run out of ink soon";
        }
        else{
            inklvl = inklvl - 10;
            cout << "Maker of colour " << color << "has been writtten" << endl;

        }
    }
    void refillink(){
        if(refill == 1){
            inklvl = 100;
            cout << " marker of clour " << color << "has been refilled" << endl;
            
        }
        else {
            cout << " marker cannot be refilled";
        }
        
    }
};
int main() {
    MarkerPen marker1;
    MarkerPen marker2;
    marker1.penDetails("Pilot", "Blue", 50, 1);
    marker2.penDetails("Steadler", "Red", 100, 0);
    marker1.write();
    marker2.write();
    marker1.refillink();
    marker2.refillink();
    return 0;
}
