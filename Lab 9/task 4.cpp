#include "iostream"
#include "string"
using namespace std;
class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;  
    virtual ~PaymentMethod() {} 
};
class CreditCard : public PaymentMethod {
    string cardNumber;
    double availableBalance;
public:
    CreditCard(const string &cardNumber, double availableBalance)
        : cardNumber(cardNumber), availableBalance(availableBalance) {}
    bool processPayment(double amount) override{
        if(availableBalance >= amount){
            availableBalance -= amount;
            cout << "Credit Card payment of $" << amount << " processed successfully." << endl;
            cout << "Remaining balance: $" << availableBalance << endl;
            return true;
        }
        else{
            cout << "Credit Card payment failed: Insufficient balance." << endl;
            return false;
        }
    }
};
class DigitalWallet : public PaymentMethod {
    double balance;
public:
    DigitalWallet(double balance) : balance(balance) {}
    bool processPayment(double amount) override{
        if(balance >= amount){
            balance -= amount;
            cout << "Digital Wallet payment of $" << amount << " processed successfully." << endl;
            cout << "Remaining balance: $" << balance << endl;
            return true;
        }
        else{
            cout << "Digital Wallet payment failed: Insufficient balance." << endl;
            return false;
        }
    }
};
void simulatePayment(PaymentMethod *paymentMethod, double amount){
    if(paymentMethod->processPayment(amount)){
        cout << "Payment was successful!" << endl;
    }
    else{
        cout << "Payment failed." << endl;
    }
}
int main(){
    CreditCard myCreditCard("1234-5678-9876-5432", 500.0); 
    DigitalWallet myWallet(300.0);  
    cout << "Simulating Credit Card Payment..." << endl;
    simulatePayment(&myCreditCard, 100.0);
    cout << "\nSimulating Digital Wallet Payment..." << endl;
    simulatePayment(&myWallet, 200.0);
    cout << "\nSimulating Digital Wallet Payment (Exceeds Balance)..." << endl;
    simulatePayment(&myWallet, 350.0);
    return 0;
}
