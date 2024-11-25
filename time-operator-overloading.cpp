#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize time to 0
    Time() : hours(0), minutes(0), seconds(0) {}

    // Constructor to initialize time with fixed values
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        normalize(); // Normalize when initializing
    }

    // Function to display time in HH:MM:SS format
    void display() const
    {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    // Overload the + operator to add two Time objects
    Time operator+(const Time &t) const
    {
        // Sum hours, minutes, and seconds, and return a new Time object
        return Time(this->hours + t.hours, this->minutes + t.minutes, this->seconds + t.seconds);
    }

    // Normalize function to adjust time values
    void normalize();
};

void Time::normalize()
{
    // Normalize seconds
    if (seconds >= 60)
    {
        minutes += seconds / 60; // Convert excess seconds to minutes
        seconds %= 60;           // Keep only the remainder seconds
    }

    // Normalize minutes
    if (minutes >= 60)
    {
        hours += minutes / 60; // Convert excess minutes to hours
        minutes %= 60;         // Keep only the remainder minutes
    }
}

int main()
{
    Time t1(10, 30, 45); // 10:30:45
    Time t2(2, 45, 30);  // 2:45:30

    // Use operator overloading to add two Time objects
    Time t3 = t1 + t2; // This will call the overloaded + operator

    cout << "Time after addition: ";
    t3.display(); // Display the result of the addition

    return 0;
}