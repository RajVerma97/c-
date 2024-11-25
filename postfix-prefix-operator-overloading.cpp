#include <iostream>
using namespace std;

class Count
{
private:
    int value; // Private member variable to hold the count value

public:
    // Constructor to initialize count to 5
    Count() : value(5) {}

    // Overload ++ when used as prefix and return a reference to the current object

    Count operator++()
    {
        ++value;      // Increment value
        return *this; // Return reference to the current object
    }

    // Overload ++ when used as postfix, return a copy of the current object before incrementing
    Count operator++(int)
    {
        Count temp = *this; // Store the current state
        value++;            // Increment value
        return temp;        // Return the old state (copy of the current object)
    }

    // Method to display the current value of count
    void display()
    {
        cout << "Count: " << value << endl;
    }
};

int main()
{
    Count count1; // Create a Count object; value is initialized to 5

    // Call the "void operator ++ (int)" function (postfix increment)
    Count count2 = count1++; // Postfix increment; count2 gets the original value
    count2.display();        // Output: Count: 5
    count1.display();        // Output: Count: 6

    // Call the "void operator ++ ()" function (prefix increment)
    ++count1;         // Prefix increment
    count1.display(); // Output: Count: 7

    return 0;
}