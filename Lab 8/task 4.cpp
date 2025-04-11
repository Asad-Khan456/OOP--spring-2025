#include "iostream"
#include "string"
using namespace std;
class Currency{
    double value;
public:
    Currency(double v = 0.0) : value(v){}
    double getValue(){
        return value;
    }
    Currency operator+(const Currency& other)const{
        return Currency(value + other.value);
    }
    Currency operator-() const{
        return Currency(-value);
    }


    Currency operator-(const Currency& other) const{
        return Currency(value - other.value);
    }
    Currency& operator+=(const Currency& other){
        value += other.value;
        return *this;
    }
    Currency& operator-=(const Currency& other){
        value -= other.value;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Currency& c){
        os << "$" << c.value;
        return os;
    }
};
int main(){
    Currency c1(100.50);
    Currency c2(50.25);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << endl;
    Currency c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    Currency c4 = -c1;
    cout << "-c1 = " << c4 << endl;
    Currency c5 = c1 - c2;
    cout << "c1 - c2 = " << c5 << endl;
    c1 += c2;
    cout << "After c1 += c2, c1: " << c1 << endl;
    c1 -= c2;
    cout << "After c1 -= c2, c1: " << c1 << endl;
    Currency discount(10); 
    c1 -= discount;
    cout << "After applying a discount of $10, c1: " << c1 << endl;
    return 0;
}
