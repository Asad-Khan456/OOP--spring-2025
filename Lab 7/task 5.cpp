#include "iostream"
#include "string"
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;
public:
    Media(string title, string publicationDate, string uniqueID, string publisher)
        : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher), isCheckedOut(false) {}
    virtual void displayInfo(){
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Checked Out: " << (isCheckedOut ? "Yes" : "No") << endl;
    }


    void checkOut(){
        if(!isCheckedOut){
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        }
        else{
            cout << title << " is already checked out." << endl;
        }
    }
    void returnItem(){
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }
    static void searchByTitle(Media* media[], int size, const string& searchTitle) {
        bool found = false;
        for(int i = 0; i < size; i++){
            if(media[i]->title == searchTitle){
                media[i]->displayInfo();
                found = true;
            }
        }
        if(!found) cout << "No media found with the title: " << searchTitle << endl;
    }
    static void searchByPublisher(Media* media[], int size, const string& searchPublisher){
        bool found = false;
        for(int i = 0; i < size; i++){
            if (media[i]->publisher == searchPublisher) {
                media[i]->displayInfo();
                found = true;
            }
        }
        if (!found) cout << "No media found from publisher: " << searchPublisher << endl;
    }
    static void searchByPublicationDate(Media* media[], int size, const string& searchDate){
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (media[i]->publicationDate == searchDate) {
                media[i]->displayInfo();
                found = true;
            }
        }
        if(!found) cout << "No media found published on: " << searchDate << endl;
    }

};
class Book :public Media{
    string author;
    string ISBN;
    int numberOfPages;
public:
    Book(string title, string publicationDate, string uniqueID, string publisher, string author, string ISBN, int numberOfPages)
        : Media(title, publicationDate, uniqueID, publisher), author(author), ISBN(ISBN), numberOfPages(numberOfPages) {}
    void displayInfo() override{

        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};
class DVD : public Media{
    string director;
    int duration;
    string rating;
public:
    DVD(string title, string publicationDate, string uniqueID, string publisher, string director, int duration, string rating)
        : Media(title, publicationDate, uniqueID, publisher), director(director), duration(duration), rating(rating) {}

    void displayInfo() override{
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;


    }
};
class CD : public Media{
    string artist;
    int numberOfTracks;
    string genre;
public:
    CD(string title, string publicationDate, string uniqueID, string publisher, string artist, int numberOfTracks, string genre)
        : Media(title, publicationDate, uniqueID, publisher), artist(artist), numberOfTracks(numberOfTracks), genre(genre) {}
    void displayInfo()override{
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};
class Magazine : public Media{
    int issueNumber;
    string frequency;
public:
    Magazine(string title, string publicationDate, string uniqueID, string publisher, int issueNumber, string frequency)
        : Media(title, publicationDate, uniqueID, publisher), issueNumber(issueNumber), frequency(frequency){}
    void displayInfo() override{
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Frequency: " << frequency << endl;
    }
};
int main(){
    Book book("The C++ Programming Language", "2020-05-01", "B001", "Pearson", "Bjarne Stroustrup", "978-0321958327", 1352);

    DVD dvd("The Matrix", "1999-03-31", "D001", "Warner Bros", "Wachowski Brothers", 136, "R");

    CD cd("The Dark Side of the Moon", "1973-03-01", "C001", "EMI", "Pink Floyd", 10, "Rock");

    Magazine mag("National Geographic", "2021-11-01", "M001", "National Geographic Society", 301, "Monthly");
    
    Media* library[] = { &book, &dvd, &cd, &mag };
    book.displayInfo();
    dvd.displayInfo();
    cd.displayInfo();
    mag.displayInfo();
    book.checkOut();
    dvd.checkOut();
    cd.checkOut();
    mag.checkOut();
    cout << "\nSearch by Title: 'The Matrix'\n";
    Media::searchByTitle(library, 4, "The Matrix");
    cout << "\nSearch by Publisher: 'Warner Bros'\n";
    Media::searchByPublisher(library, 4, "Warner Bros");
    cout << "\nSearch by Publication Date: '1973-03-01'\n";
    Media::searchByPublicationDate(library, 4, "1973-03-01");
    return 0;
}
