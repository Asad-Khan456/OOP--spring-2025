#include "iostream"
#include "string"
using namespace std;
class manager;
class Book{
    private:
    string title;
    int price;
    public:
    Book(string title,int price): title(title), price(price){}
    void display(){
        cout << " Book Details:" << endl;
        cout << "title :"  << title << endl;
        cout << " price:" << price << endl;
    }
    friend class manager;
};
class manager{
    public:
    
    void display(Book& obj){
        obj.display();
    }
    void discount(Book& obj,int a){
        float newprice;
        cout << "Discount of" << a << "% being applied" << endl;
        newprice = obj.price - (obj.price * a/100);
        cout << "Discounted Price:" << newprice << endl; 
    }
};
int main(){
    Book b("harry potter", 45);
    manager a;
    a.display(b);
    a.discount(b,9);
    return 0;
}
