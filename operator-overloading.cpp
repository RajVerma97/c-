#include <iostream>

using namespace std;

// C++ allows operators to have user-defined meanings for specific data types.
// This feature is known as operator overloading.
// In this example, we demonstrate operator overloading for a Complex class,
// enabling the use of +, -, and * operators to add, subtract, and multiply complex numbers.

class Complex
{
private:
    int real; // Real part of the complex number
    int imag; // Imaginary part of the complex number

public:
    // Constructor to initialize real and imaginary parts of the complex number
    Complex(int r, int i)
    {
        this->real = r; // Set the real part
        this->imag = i; // Set the imaginary part
    }

    // Method to display the complex number in the form a + bi
    void display()
    {
        // Display the real and imaginary parts with appropriate sign
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }

    // Overloading the + operator to add two complex numbers
    Complex operator+(const Complex &c)
    {
        // Return a new Complex object with the summed real and imaginary parts
        return Complex(this->real + c.real, this->imag + c.imag);
    }

    // Overloading the - operator to subtract two complex numbers
    Complex operator-(const Complex &c)
    {
        // Return a new Complex object with the difference of the real and imaginary parts
        return Complex(this->real - c.real, this->imag - c.imag);
    }

    // Overloading the * operator to multiply two complex numbers
    Complex operator*(const Complex &c)
    {
        // Return a new Complex object with the product calculated using the formula:
        // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
        return Complex(this->real * c.real - this->imag * c.imag,
                       this->real * c.imag + this->imag * c.real);
    }
};

int main()
{
    // Create two Complex number objects
    Complex c1(3, 4); // c1 = 3 + 4i
    c1.display();

    Complex c2(5, 6); // c2 = 5 + 6i
    c2.display();

    // Adding two complex numbers using the overloaded + operator
    Complex c3 = c1 + c2; // c3 = c1 + c2
    cout << "Addition of c1 and c2" << endl;
    c3.display();

    // Subtracting two complex numbers using the overloaded - operator
    Complex c4 = c1 - c2; // c4 = c1 - c2
    cout << "Subtraction of c1 and c2" << endl;
    c4.display();

    // Multiplying two complex numbers using the overloaded * operator
    Complex c5 = c1 * c2; // c5 = c1 * c2
    cout << "Multiplication of c1 and c2" << endl;
    c5.display();

    return 0;
}