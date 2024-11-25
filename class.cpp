#include <iostream>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    static int totalCount; // static data member
    int marks[5];          // Array to store marks of 5 subjects
    int *pointer;          // Pointer data member

public:
    // Default constructor
    Student();

    // Parameterized Constructor to initialize rollNo and name
    Student(int rollNo, string name);

    // Copy constructor for deep copying
    Student(const Student &other);

    // Destructor to deallocate memory
    ~Student();

    void setMarks(int m[]);                  // Function to set marks
    void displayMarks();                     // Function to display marks
    static void showTotalCount();            // Static member function
    void displayStudent();                   // Function to display student details
    void showStudentByValue(Student s);      // Function to display student details by value
    void showStudentByReference(Student &s); // Function to display student details by reference
};

// Static data member initialization
int Student::totalCount = 0;

// default  constructor
Student::Student() : rollNo(0), name("No Name"), pointer(nullptr)
{
    pointer = new int(0); // Dynamically allocate memory for the pointer
    totalCount++;
}

// Parameterized Constructor to initialize rollNo and name
Student::Student(int _rollNO, string _name) : rollNo(_rollNO), name(_name)
{
    pointer = new int(100); // Dynamically allocate memory with a value
    totalCount++;
}

// Copy constructor for deep copying
Student::Student(const Student &other) : rollNo(other.rollNo), name(other.name)
{
    pointer = new int(*other.pointer); // Deep copy of pointer
    for (int i = 0; i < 5; ++i)
    {
        marks[i] = other.marks[i]; // Copy marks array
    }
    totalCount++;
}

// Destructor to free the dynamically allocated memory
Student::~Student()
{
    cout << "Deleting the pointer" << endl;
    delete pointer;    // Free the memory to prevent memory leaks
    pointer = nullptr; // Nullify the pointer for safety
}

void Student::setMarks(int m[])
{
    for (int i = 0; i < 5; ++i)
    {
        marks[i] = m[i]; // Copy marks to the data member array
    }
}

void Student::displayStudent()
{
    cout << "Roll No: " << rollNo << endl;
    cout << "Name: " << name << endl;
    cout << "Pointer Value: " << *pointer << endl; // Dereferencing the pointer
}

void Student::displayMarks()
{
    cout << "Marks of " << name << " (Roll No: " << rollNo << "): " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Subject " << i + 1 << ": " << marks[i] << endl;
    }
}

// Function to show student details by value (creates a copy)
void Student::showStudentByValue(Student s)
{
    cout << "Student Details (by value): " << endl;
    s.displayStudent(); // Displays the copied object
}

// Function to show student details by reference (no copy)
void Student::showStudentByReference(Student &s)
{
    cout << "Student Details (by reference): " << endl;
    s.displayStudent(); // Displays the referenced object (no copy)
}

void Student::showTotalCount()
{
    cout << "Total number of students: " << totalCount << endl;
}

int main()
{
    // Create a student object using parameterized constructor
    Student s1(101, "Rajneesh Verma");

    // Array of marks to pass to the student
    int marks[5] = {85, 90, 78, 88, 92};

    // Set and display marks
    s1.setMarks(marks);
    s1.displayMarks();

    // Display student details
    s1.displayStudent();

    // Demonstrate passing object by value
    s1.showStudentByValue(s1);

    // Demonstrate passing object by reference
    s1.showStudentByReference(s1);

    // Show total student count
    Student::showTotalCount();

    return 0;
}