#include <iostream>
#include <exception>
using namespace std;
class InsufficientFundsException : public exception{
private:
    double deficit;
public:
    InsufficientFundsException(double deficit) : deficit(deficit) {}
    const char* what() const noexcept override{
        return "Insufficient funds for this withdrawal";
    }
    double getDeficit() const{
        return deficit;
    }
};
template <typename T>
class BankAccount{
private:
    T balance;
public:
    BankAccount(T initialBalance) : balance(initialBalance) {}
    T getBalance() const{
        return balance;
    }

    void withdraw(T amount){
        if (amount > balance){
            throw InsufficientFundsException(amount - balance);
        }
        balance -= amount;
    }
};
int main(){
    BankAccount<double> account(500.00);
    cout << "Balancce: $" << account.getBalance() << endl;
    double amountToWithdraw = 600.00;
    cout << "Withdraw$" << amountToWithdraw << ": ";
    try
    {
        account.withdraw(amountToWithdraw);
    }
    catch (const InsufficientFundsException& e)
    {
        cout << e.what() << endl;
        cout << "Deficit: $" << e.getDeficit() << endl;
    }
    return 0;
}
