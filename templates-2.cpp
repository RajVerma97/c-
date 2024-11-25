#include <iostream>
#include <iomanip>

using namespace std;

template <class T>

class Calculator
{

private:
    T num1;
    T num2;

public:
    Calculator(T a, T b)
    {

        num1 = a;
        num2 = b;
    }

    T Add()
    {
        return num1 + num2;
    }
    T Subtract()
    {
        return num1 - num2;
    }
    T Multiply()
    {
        return num1 * num2;
    }
    T Divide()
    {
        return num1 / num2;
    }
};

int main()
{
    Calculator<int> c1(10, 50);
    cout << c1.Add() << endl;

    Calculator<double> c2(10.8, 50.5);
    cout << c2.Add() << endl;

    Calculator<float> c3(10.8f, 50.5f);
    cout << c3.Add() << endl;

    return 0;
}