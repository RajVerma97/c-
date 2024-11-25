#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
//if any constructor is not defined, compiler automatically generates a default copy constructor
//here we have defined a copy constructor
//hence the compiler is not generating a default constructor
    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
    }
    void setX(int i) { x = i; }
    void setY(int j) { y = j; }
    int getX() { return x; }
    int getY() { return y; }
    void print() { cout << "x = " << getX() << ", y = " << getY(); }
};

int main()
{
 //This happens because the compiler automatically provides a default constructor
 // when no other constructors are defined. However, this behavior changes when 
 //you define any constructor (like a copy constructor or parameterized constructor), 
 //because once you define a constructor, the compiler no longer generates the default 
 //constructor for you.

    Point p1;
    p1.setX(10);
    p1.setY(20);
    Point p2 = p1;
    p2.print();
    return 0;
}
