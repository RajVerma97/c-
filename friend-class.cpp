#include <iostream>
using namespace std;
// In C++, a friend class is a class that is granted access to the private and protected members of another class.
// This allows the friend class to access data and functions that are otherwise hidden from other classes, 
//preserving encapsulation while still permitting certain exceptions.
class A
{
private:
    int privateValue;

public:
    A() : privateValue(42) {} // constructor initializing privateValue
    friend class B;           // Declaring class B as a friend
};

class B
{
public:
    void accessA(A &obj)
    {
        // Accessing private member of class A
        cout << "Private value of A: " << obj.privateValue << endl;
    }
};

int main()
{
    A objA;
    B objB;
    objB.accessA(objA); // B can access private data of A
    return 0;
}