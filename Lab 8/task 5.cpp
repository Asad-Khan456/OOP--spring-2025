#include "iostream"
#include "string"
using namespace std;
class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(int num = 0, int denom = 1){
        if(denom == 0){
            cout << "Denominator cannot be zero!" << endl;
            denominator = 1;
        }
        else
        {
            numerator = num;
            denominator = denom;
        }
    }
    int getNumerator()const{
        return numerator;
    }
    int getDenominator()const {
        return denominator;
    }
    Fraction operator+(const Fraction& other) const{
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }


    Fraction operator-() const{
        return Fraction(-numerator, denominator);
    }


    Fraction operator-(const Fraction& other) const{
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction operator*(const Fraction& other) const{
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction operator/(const Fraction& other) const{
        if(other.numerator == 0){
            cout << "Error: Division by zero!" << endl;
            return Fraction(0, 1);
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
    friend ostream& operator<<(ostream& os, const Fraction& frac){
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};
int main(){
    Fraction f1(3, 4);
    Fraction f2(2, 5);
    Fraction f3(1, 6);
    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction quot = f1 / f2;
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f1 + f2 = " << sum << endl;
    cout << "f1 - f2 = " << diff << endl;
    cout << "f1 * f2 = " << prod << endl;
    cout << "f1 / f2 = " << quot << endl;

    return 0;
}
