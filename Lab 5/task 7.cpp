#include "iostream"
#include "string"
using namespace std;
class Product{
    int id;
    string name;
    double price;
public:
    Product() {}
    Product(int productId, string productName, double productPrice) {
        id = productId;
        name = productName;
        price = productPrice;
    }
    double getPrice(){
        return price;
    }
    string getName(){
        return name;
    }
    void displayDetails(){
        cout << "Product ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};
class Inventory{
private:
    Product products[100];  
    int productCount;
public:
    Inventory(){
        productCount = 0;
    }
    void addProduct(int id, string name, double price){
        if (productCount < 100){
            products[productCount] = Product(id, name, price);
            productCount++;
        } 
        else{
            cout << "Inventory is full" << endl;
        }
    }
    void sortProductsByPrice(){
        for (int i = 0; i < productCount - 1; i++)  
        {
            for (int j = 0; j < productCount - i - 1; j++)  
            {
                if (products[j].getPrice() > products[j + 1].getPrice())  
                {
                    swap(products[j], products[j + 1]);  
                }
            }
        }
    }
    void searchProductByName(string searchName){
        for (int i = 0; i < productCount; i++)  
        {
            if (products[i].getName() == searchName)  
            {
                cout << "Product found" << endl;
                products[i].displayDetails();
                return;
            }
        }
        cout << "Product not found" << endl;
    }
    void displayInventory(){
        cout << "Inventory List:" << endl;
        for (int i = 0; i < productCount; i++)  
        {
            products[i].displayDetails();

        }
    }
};
int main(){
    Inventory storeInventory;
    storeInventory.addProduct(101, "Laptop", 500.50);
    storeInventory.addProduct(102, "Shirt", 29.99);
    storeInventory.addProduct(103, "Fruits", 10.00);
    storeInventory.addProduct(104, "phone", 799.99);
    storeInventory.addProduct(105, "Jewellry", 149.99);
    cout << "Before Sorting:" << endl;
    storeInventory.displayInventory();
    storeInventory.sortProductsByPrice();
    cout << "After Sorting by Price in Ascending Order:" << endl;
    storeInventory.displayInventory();
    cout << "Searching for 'Smartphone':" << endl;
    storeInventory.searchProductByName("Smartphone");
    cout << "Searching for 'Tablet':" << endl;
    storeInventory.searchProductByName("Tablet");
    return 0;
}
