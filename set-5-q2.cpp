#include <iostream>
using namespace std;


//int & means that the function returns a   reference to an int.
int &fun()
{
    static int a = 10; // Declare a static variable 'a' initialized to 10
    return a;          // Return a reference to 'a'
}

int main()
{
    int &y = fun();        // Call 'fun()', which initializes 'a' and returns a reference to it
    y = y + 30;            // Modify 'a' via the reference 'y'
    cout << fun() << endl; // Call 'fun()' again and print the value of 'a'
    return 0;
}

//. Static Variable Initialization :
//	• The function fun() contains a static variable a, which is initialized to 10. A static variable retains its value between function calls .2. Returning a Reference :
//	• The function returns a reference to the static variable a.This means that any changes made to a via its reference will affect the original variable a .3. First Call to fun() :
//	• In int &y = fun();
// the fun() function is called.Since a is static and initialized to 10, y becomes a reference to a .4. Modifying the Variable :
//	• The line y = y + 30;
//effectively updates the value of a.This operation can be broken down as follows :
//	• y + 30 computes 10 + 30, which equals 40.
//	• Then, y(which is a reference to a) is assigned this new value, resulting in a now being 40. 5. Second Call to fun() :
//	• The statement cout << fun() << endl;
//calls fun() again.This time, since a is static and its value has been modified to 40, the function will return a reference to a, which now holds 40.