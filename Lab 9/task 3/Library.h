#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "Book.h"
class Library{
private:
    std::vector<Book> books;
public:
    void addBook(const Book& book);
    void removeBook(const std::string& ISBN);
    Book* searchBook(const std::string& title);
};
#endif
