#include <iostream>
#include <exception>
#include <string>
using namespace std;
class FileException : public exception{
public:
    virtual const char* what() const noexcept override{
        return "FileException occurred.";
    }
};

class FileNotFoundException : public FileException{
public:
    const char* what() const noexcept override{
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException{
public:
    const char* what() const noexcept override{
        return "PermissionDeniedException - Access denied!";
    }
};
void readFile(const string& filename){
    if (filename == "missing.txt"){
        throw FileNotFoundException();
    }
    else if (filename == "secret.txt"){
        throw PermissionDeniedException();
    }
    else{
        cout << "Reading file: " << filename << endl;
    }
}
int main(){
    string files[] = {"data.txt", "missing.txt", "secret.txt"};
    for (const string& file : files){
        try
        {
            cout << "Reading '" << file << "': ";
            readFile(file);
        }
        catch (const PermissionDeniedException& e)
        {
            cout << e.what() << endl;
        }
        catch (const FileNotFoundException& e)
        {
            cout << e.what() << endl;
        }
        catch (const FileException& e)
        {
            cout << e.what() << endl;
        }
    }

    return 0;
}
