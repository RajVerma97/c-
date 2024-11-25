#include <iostream>

using namespace std;

class Shape// Abstract class (not able to create object directly)
{
public:
    double dimension1, dimension2;

    void getdata()
    {
        cout << "Enter dimension 1: ";
        cin >> dimension1;
        cout << "Enter dimension 2: ";
        cin >> dimension2;
    }

    virtual void display_area() = 0; //pure virtual function
};

class Triangle : public Shape
{
public:
    void display_area() override
    {
        double area = 0.5 * dimension1 * dimension2;
        cout << "Area of triangle: " << area << endl;
    }
};

class Rectangle : public Shape
{
public:
    void display_area() override
    {
        double area = dimension1 * dimension2;
        cout << "Area of rectangle: " << area << endl;
    }
};

int main()
{
    Shape *shapePtr;

    Triangle triangle;
    shapePtr = &triangle;
    shapePtr->getdata();
    shapePtr->display_area();

    Rectangle rectangle;
    shapePtr = &rectangle;
    shapePtr->getdata();
    shapePtr->display_area();

    return 0;
}