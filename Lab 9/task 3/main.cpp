#include <iostream>
#include "Book.h"
using namespace std;
int main(){
    Book book("1984", "George Orwell", "1234567890");
    cout << "Book Details:" << endl;
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "ISBN: " << book.getISBN() << endl;
    return 0;
}
