#include "iostream"
#include "string"
using namespace std;
class Book{
    private:
        string title;
        float price;
        int stock; 
    public:

        Book(string bookTitle, float bookPrice, int bookStock) {
            title = bookTitle;
            price = bookPrice;
            if (bookStock >=0){
                stock = bookStock;
            }
            else{
                stock = 0;
            }
    }

    float applyDiscount(int quantity){
        float discount = 0.0;
        if (quantity > 10) 
        {
            discount = 0.10;  
        } else if (quantity > 5){
            discount = 0.05;  
        }
        return price * (1 - discount); 
    }
    void purchaseBook(){
        int num;
        cout << "How many copies of " << title << " would you like to buy? (1-" << stock << "): ";
        cin >> num;
        if (num > stock || num <= 0){
            cout << "Invalid purchase, Only " << stock << " copies available" << endl;
            return;
        }
        float finalPrice = applyDiscount(num) * num;  
        stock = stock - num;
        cout << "Purchase sucessful, total cost: $" << finalPrice << endl;
        cout << "Remianing stock: " << stock << " copies" << endl;
        if (stock < 5){
            cout << "Warning: Low stock level" << endl;
        }
    }
};
int main() {
    Book b1("Winpy Kid", 34.56, 30);
    Book b2("Chroniucles of Narnia", 24.56, 20);
    b1.purchaseBook();
    b2.purchaseBook();
    return 0;
}
