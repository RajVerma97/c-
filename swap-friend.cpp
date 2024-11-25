#include <iostream>
using namespace std;

class Swap
{

private:
    int a;
    int b;

public:
    Swap(int x, int y) : a(x), b(y) {}

    friend void swap(Swap &obj);
    void display();
};

void swap(Swap &obj)
{
    int temp = obj.a;
    obj.a = obj.b;
    obj.b = temp;
}

void Swap::display()
{

    cout << "a = " << a << endl
         << "b = " << b << endl;
}

int main()
{

    Swap obj(4, 5);

    cout << "\n Before Swapping\n";
    obj.display();

    swap(obj);
    
    cout << "\nAfter Swapping\n";
    obj.display();
    return 0;
}