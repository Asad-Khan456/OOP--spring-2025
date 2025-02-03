#include "iostream"
#include "string"
using namespace std;
struct Product {
    int productID;
    string name;
    int quantity;
    float price;
};
void addProduct(Product*& products, int& size) {
    Product* newProducts = new Product[size + 1]; 
    for (int i = 0; i < size; i++) {
        newProducts[i] = products[i];
    }
    cout << "Enter Product ID: ";
    cin >> newProducts[size].productID;
    cout << "Enter Product Name: ";
    cin >> newProducts[size].name;
    cout << "Enter Quantity: ";
    cin >> newProducts[size].quantity;
    cout << "Enter Price: ";
    cin >> newProducts[size].price;
    delete[] products;
    products = newProducts;
    size++;

    cout << "Product added successfully!\n";
}
void removeProduct(Product*& products, int& size, int productID) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (products[i].productID == productID) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Product not found!\n";
        return;
    }
    Product* newProducts = new Product[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newProducts[j++] = products[i];
        }
    }
    delete[] products;
    products = newProducts;
    size--;
    cout << "Product removed successfully!\n";
}
void updateProduct(Product* products, int size, int productID) {
    for (int i = 0; i < size; i++) {
        if (products[i].productID == productID) {
            cout << "Enter new Quantity: ";
            cin >> products[i].quantity;
            cout << "Enter new Price: ";
            cin >> products[i].price;
            cout << "Product updated successfully!\n";
            return;
        }
    }
    cout << "Product not found!\n";
}
void displayProducts(Product* products, int size) {
    if (size == 0) {
        cout << "No products in inventory.\n";
        return;
    }
    cout << "\nInventory List:\n";
    cout << "ID\tName\tQuantity\tPrice\n";
    for (int i = 0; i < size; i++) {
        cout << products[i].productID << "\t"
             << products[i].name << "\t"
             << products[i].quantity << "\t\t"
             << products[i].price << "\n";
    }
}
void calculateTotalValue(Product* products, int size) {
    float totalValue = 0;
    for (int i = 0; i < size; i++) {
        totalValue += products[i].price * products[i].quantity;
    }
    cout << "Total Inventory Value: $" << totalValue << "\n";
}
int main() {
    Product* products = nullptr;
    int size = 0;
    int choice, productID;
    while (true) {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n2. Remove Product\n3. Update Product\n";
        cout << "4. Display Products\n5. Calculate Total Value\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addProduct(products, size);
                break;
            case 2:
                cout << "Enter Product ID to remove: ";
                cin >> productID;
                removeProduct(products, size, productID);
                break;
            case 3:
                cout << "Enter Product ID to update: ";
                cin >> productID;
                updateProduct(products, size, productID);
                break;
            case 4:
                displayProducts(products, size);
                break;
            case 5:
                calculateTotalValue(products, size);
                break;
            case 6:
                delete[] products; 
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
