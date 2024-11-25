// The capability of a class to derive properties and characteristics from another class is called Inheritance.
// Inheritance is one of the most important features of Object Oriented Programming in C++. In this article, we will learn about inheritance in C++, its modes and types along with the information about how it affects different properties of the class.

// In the above program, the ‘Child’ class is publicly inherited
// from the ‘Parent’ class so the public data members of the class ‘Parent’ will also be inherited by the class ‘Child’.

#include <iostream>
using namespace std;

class Base
{
public:
    int id_p;

    void printId_p()
    {
        cout << "Base class id_p: " << id_p << endl;
    }
};

class Child : public Base
{

public:
    int id_c;
    void printId_c()
    {
        cout << "Child class id_c: " << id_c << endl;
    }
};

int main()
{
    Child c;
    c.id_p = 20;
    c.printId_p();

    c.id_c = 50;
    c.printId_c();

    return 0;
}