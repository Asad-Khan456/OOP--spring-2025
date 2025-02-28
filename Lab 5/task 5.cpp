#include "iostream"
#include "string"
using namespace std;
class TourGuide{
    private:
    string name;
    int experience;
    string specialization;
    public:
    TourGuide(string guideName, int exp, string spec) {
        name = guideName;
        experience = exp;
        specialization = spec;
    }
    void displayDetails(){
        cout << "Name: " << name << endl;
		cout << "Experience: " << experience << endl;
        cout << " Specialization in years: " << specialization << endl;
    }
};
class TravelAgency{
    private:
    string agencyName;
    TourGuide* guides[100]; 
    int guideCount;
    public:
    TravelAgency(string name){
        agencyName = name;
        guideCount = 0;
    }
    void addTourGuide(TourGuide* guide){
        guides[guideCount++] = guide;
    }
    void displayAgencyDetails()  {
        cout << "Travel Agency: " << agencyName << endl;
        cout << "Tour Guides Associated: " << endl;
        for (int i = 0; i < guideCount; i++) 
        {
            guides[i]->displayDetails();

        }
    }
};
int main() {
    TourGuide guide1("Akon", 5, "Historical places");
    TourGuide guide2("Jahanzaib", 8, "Northern Areas");
    TourGuide guide3("Rizwan", 3, "Lahore");
    TravelAgency agency("Global Travels");
    agency.addTourGuide(&guide1);
    agency.addTourGuide(&guide2);
    agency.addTourGuide(&guide3);
    agency.displayAgencyDetails();
    return 0;
}
