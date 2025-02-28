#include "iostream"
#include "string"
using namespace std;
class Movie{
    private:
    string title;
    string director;
    int duration; 
    public:
    Movie() {} 
    Movie(string movieTitle, string movieDirector, int movieDuration){
        title = movieTitle;
        director = movieDirector;
        duration = movieDuration;
    }
    void displayDetails(){
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};
class CinemaHall{
private:
    string hallName;
    Movie movies[5];  
    int movieCount;
public:
    CinemaHall(string name, Movie movieList[], int count) : hallName(name), movieCount(count){
        for (int i = 0; i < movieCount; i++) 
        {
            movies[i] = movieList[i];

        }
    }
    void displayCinemaDetails(){
        cout << "Cinema Hall: " << hallName << endl;
        cout << "Movies Currently Screening:" << endl;
        for (int i = 0; i < movieCount; i++){
            movies[i].displayDetails();
        }
    }
};
int main(){
    Movie movieList[] = {
        Movie("Inception", "Christopher Nolan", 138),
        Movie("Interstellar", "Christopher Nolan", 199),
        Movie("Avengers", "James Gunn", 165),
        Movie("The Matrix", "Lana Wachowski & Lilly Wachowski", 136),
        Movie("Harry Potter", "Jafar Shah", 122)
    };
    CinemaHall hall("Nueplex", movieList, 5);
    hall.displayCinemaDetails();
    return 0;
}
