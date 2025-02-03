#include "iostream"
#include "string"
using namespace std;
struct Book
{
    int BookID;
    string title;
    string author;
    bool isAvailable;
};
void Add(Book *books, int num)
{
    cout << "Enter details for book " << num + 1 << endl;
    cout << "Book ID: ";
    cin >> books[num].BookID;
    cin.ignore();
    cout << "Title: ";
    getline(cin, books[num].title);
    cout << "Author: ";
    getline(cin, books[num].author);
    cout << "is the book available? type 1 for yes and 0 for no:  ";
    cin >> books[num].isAvailable;
}
void Remove(Book *books, int id, int num)
{
    for (int i = 0;i < num;i++)
    {
        if (books[i].BookID == id)
        {
            cout << "Book with the ID" << id << " removed" << endl;
            books[i].BookID = 0;
            books[i].title = "";
            books[i].author = "";
            return;
        }
    }
    cout << "Could not find a book with the provided ID" << endl;
}
void Search(Book *books, int id, int num)
{
    for (int i = 0;i < num;i++)
    {
        if (books[i].BookID == id)
        {
            cout << "Displaying details for this book: " << endl;
            cout << "Book ID: " << books[i].BookID << endl;
            cout << "Book title: " << books[i].title << endl;
            cout << "Book author: " << books[i].author << endl;
            cout << "Books availability: " << books[i].isAvailable << endl;
            return;
        }
    }
    cout << "Could not find a book with the provided ID" << endl;
}
int main()
{
    int num;
    int i = 0;
    cout << "How many books  can be stored in the library?" << endl;
    cin >> num;
    Book *books = new Book[num];
    int choice = 0;
    while (choice != 4)
    {
        cout << "What would you like to do?" << endl;
        cout << "1) Add a book" << endl << "2) Remove a book" << endl << "3) Search for a book using Book ID" << endl << "4) exit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            if (i == num)
            {
                cout << "The library is full, no more books can be added" << endl;
            }
            else
            {
                Add(books, i);
                i = i + 1;
            }
            break; 
            case 2:
            int ID;
            cout << "Enter the ID of the book you want to remove" << endl;
            cin >> ID;
            Remove(books, ID, i);
            break;
            case 3:
            int ID2;
            cout << "Enter the ID of the book you want to search" << endl;
            cin >> ID2;
            Search(books, ID2, i);
            break;           
            case 4:
            cout << "Exiting the library management system" << endl;
            break;           
            default:
            cout << "Please enter a valid choice between 1 and 4" << endl;
            break;
        }
    }
    



}
