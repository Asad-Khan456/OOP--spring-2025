#include <iostream>
#include <exception>
using namespace std;
class NegativeNumberException : public exception{
public:
    const char* what() const noexcept override{
        return "NegativeNumberException - Input must be non-negative";
    }
};
class InvalidTypeException : public exception{
public:
    const char* what() const noexcept override{
        return "InvalidTypeException - Non-numeric type detected";
    }
};
double sqrtCustom(int num){
    if (num < 0){
        throw NegativeNumberException();
    }

    double result = num / 2.0;
    double last = 0;
    while (result != last){
        last = result;
        result = (result + num / result) / 2;
    }

    return result;
}

double sqrtCustom(double num){
    if (num < 0){
        throw NegativeNumberException();
    }
    double result = num / 2.0;
    double last = 0;
    while (result != last){
        last = result;
        result = (result + num / result) / 2;
    }

    return result;
}
double sqrtCustom(string){
    throw InvalidTypeException();
}

int main(){
    try
    {
        cout << "sqrt(-4): ";
        cout << sqrtCustom(-4) << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "sqrt(\"hello\"): ";
        cout << sqrtCustom("hello") << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "sqrt(25): ";
        cout << sqrtCustom(25) << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
