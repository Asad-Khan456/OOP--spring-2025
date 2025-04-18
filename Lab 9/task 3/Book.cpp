#include "Book.h"
Book::Book(const std::string& title, const std::string& author, const std::string& ISBN)
    : title(title), author(author), ISBN(ISBN) {}
std::string Book::getTitle() const{
    return title;
}
std::string Book::getAuthor() const{
    return author;
}
std::string Book::getISBN() const{
    return ISBN;
}
