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

    // Add two Time objects
    Time add(const Time &t)
    {
        // Sum hours, minutes, and seconds
        return Time(this->hours + t.hours, this->minutes + t.minutes, this->seconds + t.seconds);
    }

    void normalize()
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

        // Normalize hours (if necessary, for 24-hour format)
    }
};

int main()
{

    Time t1(10, 30, 45); // 10:30:45
    Time t2(2, 45, 30);  // 2:45:30

    Time t3 = t1.add(t2); // Add t1 and t2
    t3.normalize();       // Normalize the result before displaying
    cout << "Time after addition: ";
    t3.display(); // Display the result of the addition

    return 0;
}