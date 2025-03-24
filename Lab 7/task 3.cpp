#include "iostream"
#include "string"
using namespace std;

class Currency{
protected:
    float amt;
    int currencycode;
    string currencysymbol;
    float exchangerate;
public:
    Currency(float amt, int currencycode, string currencysymbol, float exchangerate)
        : amt(amt), currencycode(currencycode), currencysymbol(currencysymbol), exchangerate(exchangerate) {}
    virtual float convertToBase() = 0;
    virtual void display() = 0;
    void convertTo(Currency* targetCurrency) {
        float baseAmount = this->convertToBase();
        float targetAmount = baseAmount * targetCurrency->exchangerate;
        cout << "ConverteD " << currencysymbol << amt << " to " << targetCurrency->currencysymbol
             << targetAmount << endl;
    }
};
class Dollar : public Currency{
public:
    Dollar(float amt):Currency(amt, 1, "$", 1.0) {}
    float convertToBase() override {
        return amt;
    }
    void display() override {
        cout << currencysymbol << amt << " (" << currencycode << ")" << endl;
    }
};
class Euro : public Currency{
public:
    Euro(float amt) : Currency(amt, 2, "Euro,", 1.20) {}// no euro symbol in keyboard :)
    float convertToBase() override{
        return amt * exchangerate;
    }
    void display() override{
        cout << currencysymbol << amt << " (" << currencycode << ")" << endl;
    }
};
class Rupee : public Currency{
public:
    Rupee(float amt) :Currency(amt, 3, "Rs.", 286.0) {}
    float convertToBase() override{
        return amt * exchangerate;
    }
    void display() override{
        cout << currencysymbol << amt << " (" << currencycode << ")" << endl;
    }
};
int main(){
    Dollar dollar(200);
    Euro euro(78);
    Rupee rupee(4000);
    dollar.display();
    euro.display();
    rupee.display();
    dollar.convertTo(&euro);
    euro.convertTo(&rupee);
    rupee.convertTo(&dollar);
    return 0;
}
