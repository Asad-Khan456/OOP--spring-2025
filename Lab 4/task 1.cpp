#include "iostream"
#include "string"
using namespace std;
class Book{
private:
    string title;
    float price;
    int *stock; 
public:
    Book(){
        title = "Unknown";
        price = 0.0;
        stock = new int(30); 
    }

    ~Book(){
        delete stock;
    }
    
    void addBook(const string &booktitle, float bookprice){
        title = booktitle;
        price = bookprice;
    }
    void updateDetails(const string &booktitle, float bookprice){
        title = booktitle;
        price = bookprice;
    }

    void purchaseBook(){
        int num;
        cout << "How many copies of this book do you waant to buy? (1-" << *stock << "): ";
        cin >> num;

        if (num > *stock || num <= 0){
            cout << "Invalid, only " << *stock << " copies are available" << endl;
            return;
        }
        *stock = *stock - num; 
        cout << "Purchase successful, remaining stock: " << *stock << endl;

        if (*stock < 5){
            cout << "Warning: Low stock level" << endl;
        }
    }
};

int main(){
    Book b1;
    Book b2;
    b1.addBook("Harry Potter", 34.56);
    b2.addBook("The Chronicles", 24.56);
    b1.updateDetails("New Title", 55.67);
    b2.updateDetails("Another Title", 67.66);
    b1.purchaseBook(); 

    b2.purchaseBook();
    return 0;
}
