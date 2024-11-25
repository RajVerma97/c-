#include <iostream>

using namespace std;

class Complex
{

private:
    int real;
    int imag;

public:
    Complex(int a, int b) : real(a), imag(b) {};
    friend Complex operator+(const Complex &obj1, const Complex &obj2);
    void display();
};

Complex operator+(const Complex &obj1, const Complex &obj2)
{

    Complex result = Complex(obj1.real + obj2.real, obj1.imag + obj2.imag);
    return result;
}

void Complex::display()
{
    cout << this->real << "+" << this->imag << "i" << endl;
}

int main()
{

    Complex c1(2, 3);
    c1.display();

    Complex c2(5, 9);
    c2.display();

    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}