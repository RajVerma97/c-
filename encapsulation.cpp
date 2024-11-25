#include <iostream>

using namespace std;

// Encapsulation is one of the core principles of Object-Oriented Programming (OOP),
// where data (attributes) and functions (methods) are bundled together within a class.
// It also involves restricting direct access to some of an object’s components
// to prevent accidental interference or misuse.
// This is achieved by making attributes private and providing public methods to access and modify them.

class Student
{

    // Private members: Not accessible directly outside the class
private:
    int rollNo;
    string name;

public:
    // Public setter method to set the roll number (write access)
    void setRollNo(int rollNo)
    {
        this->rollNo = rollNo;
    }

    // Public getter method to get the roll number (read access)
    int getRollNo()
    {
        return rollNo;
    }

    // Public setter method to set the name (write access)
    void setName(string name)
    {
        this->name = name;
    }

    // Public getter method to get the name (read access)
    string getName()
    {
        return name;
    }
};

int main()
{
    // Create a Student object
    Student s;

    // Set student details using setter methods (encapsulation)
    s.setName("Rajneesh Verma");
    s.setRollNo(101);

    // Get and display student details using getter methods
    cout << "Roll No: " << s.getRollNo() << endl;
    cout << "Name: " << s.getName() << endl;

    // The private attributes (name and rollNo) are hidden from the outside world.
    // Access to those attributes is provided via public methods that may include validation
    // or control over how the data is set or retrieved.

    return 0;
}