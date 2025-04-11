#include "iostream"
#include "string"
using namespace std;
class Currency{
private:
    double value;

public:
    Currency(double v = 0.0) :value(v){}

    double getValue()const{
        return value;
    }

    void display()const{
        cout << "Currency Value: $" << value << endl;
    }



    Currency operator+(const Currency& other)const{
        return Currency(value + other.value);
    }
    Currency operator-()const{
        return Currency(-value);
    }
    Currency operator-(const Currency& other)const{
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
};

int main() {
    Currency c1(102.50);
    Currency c2(51.25);
    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();
    cout << endl;
    Currency c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();
    Currency c4 = -c1;
    cout << "-c1 = ";
    c4.display();
    Currency c5 = c1 - c2;
    cout << "c1 - c2 = ";
    c5.display();
    c1 += c2;
    cout << "After c1 += c2, c1: ";
    c1.display();
    c1 -= c2;
    cout << "After c1 -= c2, c1: ";
    c1.display();
    return 0;
}
