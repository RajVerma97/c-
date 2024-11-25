
// C++ Program to demonstrate Virtual Functions

// A virtual function is a member function that is declared in the base class
// using the keyword 'virtual' and is re-defined (overridden) in the derived class.

// Some Key Points About Virtual Functions:
// - Virtual functions enable runtime polymorphism.
// - They are defined by inserting the keyword 'virtual' inside a base class and are
//   overridden in a derived class.
// - A virtual function is called based on the actual object type during runtime, not compile-time.

#include <iostream>
using namespace std;

// Declaring a Base class
class GFG_Base
{
public:
    // Virtual function to allow dynamic (runtime) binding
    virtual void display()
    {
        cout << "Called virtual Base Class function\n\n";
    }

    // Non-virtual function, no polymorphism (static binding)
    void print()
    {
        cout << "Called GFG_Base print function\n\n";
    }
};

// Declaring a Derived (Child) Class
class GFG_Child : public GFG_Base
{
public:
    // Overriding the virtual function from the base class
    void display() override
    {
        cout << "Called GFG_Child Display Function\n\n";
    }

    // Overriding the non-virtual function, but no polymorphism here
    void print()
    {
        cout << "Called GFG_Child print Function\n\n";
    }
};

int main()
{
    // Create a pointer of the base class type
    GFG_Base *base;

    // Create an object of the derived (child) class
    GFG_Child child;

    // Point the base class pointer to the derived class object
    base = &child;

    // This will call the overridden version of the virtual function
    // from the derived class due to runtime polymorphism
    base->display(); // Output: Called GFG_Child Display Function

    // This will call the base class version of the non-virtual function
    // because non-virtual functions are bound at compile time (static binding)
    base->print(); // Output: Called GFG_Base print function

    return 0;
}