// In single inheritance, a class is allowed to inherit from only one class.i.e.one base class is inherited by one derived class only.
//  C++ program to demonstrate how to implement the Single inheritance

#include <iostream>
using namespace std;

// base class
class Vehicle
{
public:
    Vehicle() { cout << "This is a Vehicle\n"; }
};

// sub class derived from a single base classes
class Car : public Vehicle
{
public:
    Car() { cout << "This Vehicle is Car\n"; }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes
    Car obj;
    return 0;
}
