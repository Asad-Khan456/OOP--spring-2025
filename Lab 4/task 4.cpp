#include "iostream"
#include "string"
using namespace std;
class Book
{
private:
    string title;
    float price;
    int *stock;
    float discountPerc;
public:

    Book(string bookTitle, float bookPrice, int bookStock, float discount = 0.0){
        this->title = bookTitle;
        this->price = bookPrice;
        this->discountPerc = discount;
        if (bookStock >= 0){
            this->stock = new int(bookStock);
        }
        else{
            this->stock = new int(0);
        }
    }
    Book(const Book &other){
        this->title = other.title;
        this->price = other.price;
        this->discountPerc = other.discountPerc;
        this->stock = new int(*other.stock);
    }
    ~Book(){
        cout << "Destroying book" << title << endl;
        delete stock;
    }
    void updateDetails(const string &bookTitle, float bookPrice, float discount){
        this->title = bookTitle;
        this->price = bookPrice;
        this->discountPerc = discount;
    }
    float calculatePrice(int quantity){
        float finalPrice = this->price;
        if (quantity > 10){
            finalPrice -= finalPrice * 0.10;
        }
        else if (quantity > 5){
            finalPrice -= finalPrice * 0.05;
        }
        finalPrice -= finalPrice * (this->discountPerc / 100);
        return finalPrice * quantity;
    }
    void purchaseBook(){
        int num;
        cout << "How many copies of" << title << "would you like to buy (1-" << *stock << "): ";
        cin >> num;

        if (num > *stock || num <= 0){
            cout << "Invalid purchase, Only" << *stock << "copies available" << endl;
            return;
        }
        float totalCost = calculatePrice(num);
        *stock -= num;
        cout << "Purchase successful, Total cost $" << totalCost << endl;
        cout << "Remaining stock" << *stock << "copies" << endl;
        if (*stock < 5){
            cout << "Warning, Low stock level" << endl;
        }
    }
    void displayDetails() const{
        cout << "Title" << title << ", Price $" << price << ", Discount" << discountPerc << "%, Stock" << *stock << endl;
    }
};
int main(){
    Book originalBook("Chroniucles of Narnia", 24.57, 30, 5);
    cout << "Original Book Details" << endl;
    originalBook.displayDetails();
    Book copiedBook = originalBook;
    cout << "Copied Book Details (Before Modification)" << endl;
    copiedBook.displayDetails();
    originalBook.updateDetails("Chroniucles of Narnia - Updated Edition", 29.99, 10);
    cout << "Original Book Details (After Modification)" << endl;
    originalBook.displayDetails();
    cout << "Copied Book Details (After Original Modification, Should Remain Unchanged)" << endl;
    copiedBook.displayDetails();
    originalBook.purchaseBook();
    copiedBook.purchaseBook();
    return 0;
}
