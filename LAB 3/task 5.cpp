#include "iostream"
#include "string"
using namespace std;

class GroceryStore {
private:
    struct Item {
        string name;
        float price;
    };

    Item inventory[50];
    int Icount = 0;
public:
    void additem(string itemname, float Aprice) {
        if (Icount >= 50) {
            cout << "Inventory is full. Cannot add more items." << endl;
            return;
        }
        inventory[Icount].name = itemname;
        inventory[Icount].price = Aprice;
        Icount++;
        cout << "Item added. Item name: " << itemname << " item price : Rs " << Aprice << endl;
    }
    void update(string iname, float Nprice) {
        for (int i = 0; i < Icount; i++) {
            if (iname == inventory[i].name) {
                inventory[i].price = Nprice;
                cout << "Updated. Item name: " << inventory[i].name << " new price: Rs " << inventory[i].price << endl;
                return;
            }
        }
        cout << "Item not found in the inventory." << endl;
    }
    void viewinventory() {
        if (Icount == 0) {
            cout << "Inventory is empty." << endl;
            return;
        }
        for (int i = 0; i < Icount; i++) {
            cout << "Item Name: " << inventory[i].name << " Item price: Rs " << inventory[i].price << endl;
        }
    }
    void Generaterecipt() {
        if (Icount == 0) {
            cout << "No items in inventory to generate a receipt." << endl;
            return;
        }
        float total = 0;
        for (int i = 0; i < Icount; i++) {
            cout << "Item Name: " << inventory[i].name << " Item price: Rs " << inventory[i].price << endl;
            total += inventory[i].price;
        }
        cout << "Total Price: Rs " << total << endl;
    }
};

int main() {
    GroceryStore items;
    int n;
    while (true) {
        cout << "--- Grocery Store Menu ---" << endl;
        cout << "1. Add/Update Item" << endl;
        cout << "2. Update Price" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. Generate Receipt" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> n;
        switch (n) {
            case 1: {
                string Iname;
                float Iprice;
                cout << "Enter item name and price: " << endl;
                cin >> Iname >> Iprice;
                items.additem(Iname, Iprice);
                break;
            }
            case 2: {
                string Fname;
                float Nprice;
                cout << "Enter item name and its updated price: " << endl;
                cin >> Fname >> Nprice;
                items.update(Fname, Nprice);
                break;
            }
            case 3:
                items.viewinventory();
                break;
            case 4:
                items.Generaterecipt();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option." << endl;
        }
    }
}
