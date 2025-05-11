#include <iostream>
#include <exception>
using namespace std;
class InvalidValueException : public exception{
public:
    const char* what() const noexcept override{
        return "Invalid age: Age must be between 0 and 120";
    }
};
void validateAge(int age){
    if (age < 0 || age > 120){
        throw InvalidValueException();
    }
    cout << "Valid age entreed : " << age << endl;
}
int main(){
    int age;
    cout << "Enterage: ";
    cin >> age;
    try{
        validateAge(age);
    }
    catch (const InvalidValueException& e){
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
