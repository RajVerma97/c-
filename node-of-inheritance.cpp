// C++ program to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A
{
public:
    int x;

protected:
    int y;

private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

int main()
{

    A a;
    a.x = 10; // Accessible because x is public in A
    // a.y = 20;   // Not accessible because y is protected in A
    // a.z = 30;   // Not accessible because z is private in A

    B b;
    b.x = 10; // Accessible because x is public in B (inherited publicly)
    // b.y = 20;   // Not accessible because y is protected in B (inherited publicly)
    // b.z = 30;   // Not accessible because z is private in A (not inherited)

    C c;
    // c.x = 10;   // Not accessible because x is protected in C (inherited protectedly)
    // c.y = 20;   // Not accessible because y is protected in C
    // c.z = 30;   // Not accessible because z is private in A (not inherited)

    D d;
    // d.x = 10;   // Not accessible because x is private in D (inherited privately)
    // d.y = 20;   // Not accessible because y is private in D
    // d.z = 30;   // Not accessible because z is private in A (not inherited)

    return 0;
}