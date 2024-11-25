#include <iostream>

using namespace std;

struct Student
{
    int id;
    string name;
    int rollNo;
};


class Demo {

    private:
        int *ptr;
        int *arr;

    public:

    Demo(){
        ptr=new int(10);
        arr= new int[5];

        for(int i=0;i<5;i++)
        {
            arr[i]=i;
            cout<<arr[i]<<endl;
        }

        cout<<"\nptr value is "<<*ptr<<endl;

    }

    int getData()  {

    }

    ~Demo(){
        delete ptr;
        ptr=nullptr;

        delete[] arr;
        arr=nullptr;
    }
};

void printTriangle(int arr[100][100], int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void swap(int *a, int *b)
{

    // int temp = a;
    // a = b;
    // b = temp;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void printStudentDetails(struct Student s)
{

    cout << "\nStudent Details\n";
    cout << "id = " << s.id << endl;
    cout << "name = " << s.name << endl;
    cout << "rollNo = " << s.rollNo << endl;
}

int main()
{

    // int a = 10;
    // int b = 20;

    // cout << "\nBefore Swapping\n";
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    // swap(&a, &b);

    // cout << "\nAfter Swapping\n";
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    // int arr[100][100] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // struct Student s[100];
    // struct Student s1 = {1, "rahj", 10};
    // struct Student *ptr;

    // int a = 5;
    // int &b = a;

    // ptr = &s[0];

    // ptr->id = 1;
    // ptr->name = "raj";
    // ptr->rollNo = 10;

    // s[1].id = 2;
    // s[1].name = "verma";
    // s[1].rollNo = 20;

    // printStudentDetails(s1);
    // printStudentDetails(s[1]);
    //  printTriangle(arr, 3, 3);

    // int *arr= new int[5];
    // int *ptr  = new int(10);// default value is 10

  
    // for(int i=0;i<5;i++)
    // {
    //     arr[i]=i;
    //     cout<<arr[i]<<endl;
    // }
    // cout<<*ptr<<endl;

    // delete ptr;
    // ptr = nullptr;
    
    // delete[] arr;
    // arr= nullptr;

    Demo d;
    const Demo d2;
   



    return 0;
}