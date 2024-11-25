#include <iostream>

using namespace std;

class Complex
{

private:
    int real;
    int imag;

public:
    Complex(int r, int i)
    {
        this->real = r;
        this->imag = i;
    }

    friend Complex add(const Complex &obj1, const Complex &obj2);
    // friend void display(const Complex &obj);
    void display();
};

Complex add(const Complex &obj1, const Complex &obj2)
{

    Complex result = Complex(obj1.real + obj2.real, obj1.imag + obj2.imag);
    return result;
}

void Complex::display()
{

    cout << this->real << "+" << this->imag << "i" << endl;
}

// void display(const Complex &obj)
// {

//     cout << obj.real << "+" << obj.imag << "i"<<endl;
// }

int main()
{

    Complex c1(2, 4);
    // display(c1);

    c1.display();

    Complex c2(4, 5);
    // display(c2);
    c2.display();

    Complex c3 = add(c1, c2);
    // display(c3);
    c3.display();

    return 0;
}