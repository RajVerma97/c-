#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    // Constructor to initialize person details
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    // Function to compare two persons and return the eldest using `this` pointer
    Person &findEldest(Person *p)
    {
        if (p->age > this->age)
        {
            return *p;
        }
        else
        {
            return *this;
        }
    }

    // Function to compare two persons and return the youngest using `this` pointer
    Person *findYoungest(Person *p)
    {
        if (p->age < this->age)
        {
            return p;
        }
        else
        {
            return this;
        }
    }

    // Function to display the person details
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    // Creating records of three people
    Person person1("Alice", 25);
    Person person2("Bob", 35);
    Person person3("Cap", 45);

    // Finding the eldest person
    Person &eldest = person1.findEldest(&person2);
    eldest = eldest.findEldest(&person3);

    // Finding the youngest person
    Person *youngest = person1.findYoungest(&person2);
    youngest = youngest->findYoungest(&person3);

    // Displaying the eldest personwwq`q    
    cout << "The eldest person is: ";
    eldest.display();

    // Displaying the youngest person
    cout << "The youngest person is: ";
    youngest->display();

    return 0;
}