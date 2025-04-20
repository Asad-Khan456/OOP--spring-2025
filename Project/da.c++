#include <iostream>
#include<string>
#include <unistd.h>
using namespace std;

class Land{
    int area;
    float pricePerArea;
    int location;
    string quality;
};
class ProfileReview{
    int like;
    string *comments;
    public:
    string like(){}
    string comment(){}
};
class profile{
    Land *l;
    ProfileReview rw;
    string password;
    string name;
};