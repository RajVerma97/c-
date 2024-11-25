#include <iostream>

using namespace std;

union geek
{
    // Defining data members
    int age;
    char grade;
    float GPA;
};

struct Student
{

    int rollNumber;
    string name;
    int marks[3];
    int totalMarks;
    float avg;
};

int main()
{

    union geek student1;

    // Assigning values to data member of union geek and
    // printing the values of data members
    student1.age = 25;
    cout << "Age : " << student1.age << endl;

    student1.grade = 'B';
    cout << "Grade : " << student1.grade << endl;

    student1.GPA = 4.5;
    cout << "GPA : " << student1.GPA << endl;
    // struct Student s1;

    // s1.rollNumber = 1;
    // s1.name = "John";
    // s1.marks[0] = 50;
    // s1.marks[1] = 50;
    // s1.marks[2] = 70;
    // s1.totalMarks = 0;

    // for (int i = 0; i < 3; i++)
    // {
    //     s1.totalMarks += s1.marks[i];
    // }
    // s1.avg = s1.totalMarks / 3;
    // cout << s1.avg;

    cout << endl;

    return 0;
}
