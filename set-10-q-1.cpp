#include <iostream>
#include <string.h>
using namespace std;

// Definition of the String class
class String
{
public:
    char *p; // Pointer to hold the dynamically allocated character array
    int len; // Length of the string

public:
    // Constructor declaration that takes a C-style string
    String(const char *a);
};

// Constructor definition for the String class
String::String(const char *a)
{
    int length = strlen(a);                // Get the length of the input string
    p = new char[length + 1];              // Allocate memory for the string (including null terminator)
    strcpy(p, a);                          // Copy the input string to the allocated memory
    cout << "Constructor Called " << endl; // Indicate that the constructor was called
}

int main()
{
    String s1("Geeks");            // Create a String object s1 initialized with "Geeks"
    const char *name = "forGeeks"; // Create a C-style string pointing to "forGeeks"

    // Attempt to assign the C-style string name to the String object s1
    s1 = name; // This will cause undefined behavior since there is no proper assignment operator

    cout << (s1.p) << endl; // Output the value of p, which is now pointing to "forGeeks"
    return 0;               // Exit the program
}