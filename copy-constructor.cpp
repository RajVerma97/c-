#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    int age;
    static int counter;

public:
    Student(int r, int a)
    {
        this->rollNo = r;
        this->age = a;
    }

    Student(const Student &obj)
    {
        this->rollNo = obj.rollNo;
        this->age = obj.age;
    }

    void display()
    {
        cout << this->rollNo << " " << this->age << endl;
    }
};

int Student::counter = 0;

int main()
{

    Student s1(34, 2); // parameterized constructor called

    s1.display();

    Student s2 = s1; // copy constructor  called
    s2.display();
    Student s3(s2); // copy constrcturo called
    s3.display();

    return 0;
}