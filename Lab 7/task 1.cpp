#include "iostream"
#include "string"
using namespace std;

class Account {
protected:
    int accNum;
    float balance;
    string accHolder;
    string accType;
public:
    Account(int a, float b, string c, string h){
        accNum = a;
        balance = b;
        accHolder = c;
        accType = h;
    }
    void deposit(float d){
        balance += d;
        cout << "Deposited: " << d << endl;
    }
    virtual void withdraw(float e){
        if (e > balance) {
            cout << "Insufficient funds for withdrawal!" << endl;
        } else {
            balance -= e;
            cout << "Withdrew: " << e << endl;
        }
    }
    virtual void calcInterest(){
        float interest = balance * 0.03;
        cout << "Interest earned: " << interest << endl;
    }
    virtual void printStatement(){
        cout << "----------Transaction History----------" << endl;
    }
    void accInfo(){
        cout << "Account Number: " << accNum << endl;
        cout << "Account Balance: " << balance << endl;
        cout << "Account Holder: " << accHolder << endl;
        cout << "Account Type: " << accType << endl;
    }
};
class SavingsAcc : public Account {
    float interestRate;
    float minBalance;
public:
    SavingsAcc(int a, float b, string c, string d, float rate, float minBal)
        : Account(a, b, c, d), interestRate(rate), minBalance(minBal) {}
    void calcInterest() override{
        float interest = balance * interestRate / 100;
        cout << "Interest earned on Savings Account: " << interest << endl;
    }
    void withdraw(float e) override{
        if (balance - e < minBalance){
            cout << "Cannot withdraw. Minimum balance of " << minBalance << " required!" << endl;
        }
        else{
            balance -= e;
            cout << "Withdrew from Savings Account: " << e << endl;
        }
    }
    void printStatement() override{
        cout << "Transaction History for Savings Account" << endl;
    }
};
class CheckingAcc : public Account {
    float overdraftLimit;
public:
    CheckingAcc(int a, float b, string c, string d, float overdraft)
        : Account(a, b, c, d), overdraftLimit(overdraft) {}
    void withdraw(float e)override{
        if(balance - e < -overdraftLimit){
            cout << "Overdraft limit exceeded! Cannot withdraw." << endl;
        }
        else{
            balance -= e;
            cout << "Withdrew from Checking Account: " << e << endl;
        }
    }
    void calcInterest() override{
        float interest = balance * 0.01;
        cout << "Interest earned on Checking Account: " << interest << endl;
    }
    void printStatement()override{
        cout << "Transaction History for Checking Account" << endl;
    }
};
class FixedDepositAcc : public Account {
    float fixedInterestRate;
    string maturityDate;
public:
    FixedDepositAcc(int a, float b, string c, string d, float rate, string maturity)
        : Account(a, b, c, d), fixedInterestRate(rate), maturityDate(maturity) {}

    void calcInterest()override{
        float interest = balance * fixedInterestRate / 100;
        cout << "Interest earned on Fixed Deposit Account: " << interest << endl;
    }
    void withdraw(float e)override{
        cout << "Withdrawal not allowed before maturity date: " << maturityDate << endl;
    }
    void printStatement()override{
        cout << "Transaction History for Fixed Deposit Account" << endl;
    }
};
int main(){
    SavingsAcc savings(1001, 1500, "John Doe", "Savings", 3.5, 500);
    CheckingAcc checking(1002, 2000, "Jane Doe", "Checking", 1000);
    FixedDepositAcc fixedDeposit(1003, 5000, "Mary Jane", "Fixed Deposit", 5.0, "2026-12-31");
    savings.accInfo();
    savings.deposit(100);
    savings.withdraw(1000);
    savings.calcInterest();
    savings.printStatement();
    checking.accInfo();
    checking.deposit(200);
    checking.withdraw(2500);
    checking.calcInterest();
    checking.printStatement();
    fixedDeposit.accInfo();
    fixedDeposit.deposit(500);
    fixedDeposit.withdraw(1000);
    fixedDeposit.calcInterest();
    fixedDeposit.printStatement();
    return 0;
}
