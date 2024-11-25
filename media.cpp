#include <iostream>
#include <string>

using namespace std;

// Base class for all media items
class Media
{
public:
    string title;
    string author;
    string id;

    virtual void add() = 0;     // Pure virtual function for adding new item
    virtual void issue() = 0;   // Pure virtual function for issuing item
    virtual void deposit() = 0; // Pure virtual function for depositing item

    Media(string t, string a, string i) : title(t), author(a), id(i) {}
};

// Derived class for books
class Book : public Media
{
public:
    int pages;

    Book(string t, string a, string i, int p) : Media(t, a, i), pages(p) {}

    void add() override
    {
        cout << "Adding book: " << title << endl;
        // Implementation for adding book to library
    }

    void issue() override
    {
        cout << "Issuing book: " << title << endl;
        // Implementation for issuing book to user
    }

    void deposit() override
    {
        cout << "Depositing book: " << title << endl;
        // Implementation for depositing book back to library
    }
};

// Derived class for tapes
class Tape : public Media
{
public:
    int duration;

    Tape(string t, string a, string i, int d) : Media(t, a, i), duration(d) {}

    void add() override
    {
        cout << "Adding tape: " << title << endl;
        // Implementation for adding tape to library
    }

    void issue() override
    {
        cout << "Issuing tape: " << title << endl;
        // Implementation for issuing tape to user
    }

    void deposit() override
    {
        cout << "Depositing tape: " << title << endl;
        // Implementation for depositing tape back to library
    }
};

int main()
{
    Book b1("C++ Primer", "Stanley B. Lippman", "B001", 500);
    Tape t1("Star Wars", "George Lucas", "T001", 120);

    // Using polymorphism to call add, issue, and deposit for both book and tape
    b1.add();
    b1.issue();
    b1.deposit();

    t1.add();
    t1.issue();
    t1.deposit();

    return 0;
}