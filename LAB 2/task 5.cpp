#include "iostream"
#include "cstring" 
using namespace std;
int main() 
{
    char *string1 = new char[300];
    char *string2 = new char[300];
    cout << "Enter the first sentence: ";
    cin.getline(string1, 300);
    cout << "Enter the second sentence: ";
    cin.getline(string2, 300);
    char *string3 = new char[strlen(string1) + strlen(string2) + 1];
    strcpy(string3, string1);
    strcat(string3, string2);
    cout << "Concatenated String: " << string3 << endl;
    int comparison = strcmp(string1, string2);
    if (comparison == 0) 
    {
        cout << "Both strings are equal" << endl;
    } else if (comparison < 0) 
    {
        cout << "The first string is smaller than the second string" << endl;
    } else 
    {
        cout << "The first string is greater than the second string" << endl;
    }
    cout << "Length of first string: " << strlen(string1) << endl;
    cout << "Length of second string: " << strlen(string2) << endl;
    delete[] string1;
    delete[] string2;
    delete[] string3;
    return 0;
}
