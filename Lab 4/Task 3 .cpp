#include "iostream"
#include "string"
using namespace std;
class Book
{
private:
    string title;
    float price;
    int *stock;
public:

    Book(string bookTitle, float bookPrice, int bookStock){
        title = bookTitle;
        price = bookPrice;
        if (bookStock >= 0){
            stock = new int(bookStock);
        }
        else{
            stock = new int(0);
        }
    }
    Book(const Book &other){
        title = other.title;
        price = other.price;
        stock = new int(*other.stock);
    }
    ~Book(){
        cout << "book destroyed" << title << endl;
        delete stock;
    }
    void updateDetails(const string &bookTitle, float bookPrice){
        title = bookTitle;
        price = bookPrice;
    }
    void purchaseBook(){
        int num;
        cout << "How many copies of" << title << "would you like to buy (1-" << *stock << "): ";
        cin >> num;

        if (num > *stock || num <= 0){
            cout << "Invalid purchase, only" << *stock << "copies available" << endl;
            return;
        }
        *stock -= num;
        cout << "Purchase successful, rmeaining stock" << *stock << "copies" << endl;
        if(*stock < 5){
            cout << "Warning, Low stock level" << endl;
        }
    }
    void displayDetails() const{
        cout << "Title" << title << ", price $" << price << ", stock" << *stock << endl;
    }
};
int main(){
    Book originalBook("Chronicles of Narnia", 24.57, 30);
    cout << "Original Book Details" << endl;
    originalBook.displayDetails();
    Book copiedBook = originalBook;
    cout << "Copied Book Details (Before Modification)" << endl;
    copiedBook.displayDetails();
    originalBook.updateDetails("Chroniucles of Narnia - Updated Edition", 29.99);
    cout << "Original Book Details (After Modification)" << endl;
    originalBook.displayDetails();
    cout << "Copied Book Details (After original modification, should remain unchanged)" << endl;
    copiedBook.displayDetails();
    return 0;
}
