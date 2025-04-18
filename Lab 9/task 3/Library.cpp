#include "Library.h"
#include <algorithm>
void Library::addBook(const Book& book) {
    books.push_back(book);
}
void Library::removeBook(const std::string& ISBN) {
    books.erase(std::remove_if(books.begin(), books.end(),
               [&](const Book& b) { return b.getISBN() == ISBN; }),
               books.end());
}
Book* Library::searchBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    return nullptr;
}
