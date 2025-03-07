#include "iostream"
#include "string"
using namespace std;
class Account{
    int accountNum;
    float balance;
    public:
    Account(int a,float b){
        accountNum =a;
        balance = b;
    }
    void display(){
        cout << "Account Number:" << accountNum << endl;
        cout << "Balance:" << balance<< endl;

    }


};
class Savingsaccout : public Account{
    float InterestRate;
    public:
    Savingsaccout(int a,float b, float InterestRate): Account(a,b),InterestRate(InterestRate){}
    void displayDetails(){
        Account :: display();
        cout << "Interest Rate:" << InterestRate << endl;
    }
};
class CheckingAccount : public Account{
    float overdraftLimit;
    public:
    CheckingAccount(int a,float b, float overdraftlimit) : Account(a,b),overdraftLimit(overdraftLimit){}
    void displaydetails(){
        Account :: display();
        cout << "Over draft limit: " << overdraftLimit << endl;
        
    }
};
int main(){
    cout << "SAVINGS ACCOUNT" << endl;
    Savingsaccout s1(786,890.7,2.5);
    s1.displayDetails();
    cout << "CHECKING ACCOUNT" << endl;
    CheckingAccount c1(892,234.0,500.00);
    c1.displaydetails();
    return 0;
}
