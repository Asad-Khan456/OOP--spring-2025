#include <iostream>
#include <exception>

using namespace std;
class StackOverflowException : public exception{
public:
    const char* what() const noexcept override{
        return "Stack is full!";
    }
};

class StackUnderflowException : public exception{
public:
    const char* what() const noexcept override{
        return "Stack is empty!";
    }
};


template <typename T>
class Stack{
private:
    T arr[3];
    int top;

public:
    Stack(){
        top = -1;
    }
    void push(T value){
        if (top == 2){
            throw StackOverflowException();
        }
        arr[++top] = value;
    }
    T pop(){
        if (top == -1){
            throw StackUnderflowException();
        }
        return arr[top--];
    }
};
int main()
{
    Stack<int> s;
    try{
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4); 
    }
    catch (const exception& e){
        cout << e.what() << endl;
    }
    try{
        s.pop();
        s.pop();
        s.pop();
        s.pop(); 
    }
    catch (const exception& e){
        cout << e.what() << endl;
    }
    return 0;
}
