#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
// recursion

void decimalToBinary(int n)
{
    if (n == 0)
    {
        return; // Base case for 0, no output needed
    }

    if (n == 1)
    {
        cout << n; // Print the last digit (1) for base case
        return;
    }

    // Recursive call to handle the higher-order bits
    decimalToBinary(n / 2);

    // Print the remainder (current bit)
    cout << n % 2;
}

int fact(int n)
{

    if (n == 0 || n == 1)
        return 1;

    return n * fact(n - 1);
}

// recursion
int fib(int n)
{

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

bool isLeapYear(int year)
{

    if (year % 400 == 0)
        return true;

    else if (year % 4 == 0 && year % 100 != 0)
        return true;
    else
        return false;

    //  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void swapUsingPointers(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapByValue(int a, int b)
{

    int temp = a;
    a = b;
    b = temp;
}

void swapByReference(int &a, int &b)
{

    int temp = a;
    a = b;
    b = temp;
}

int add(int a = 4, int b = 2, int c = 4)
{
    return a + b + c;
}

void factorialUsingFor(int);

void factorialUsingWhile(int n)
{

    int result = 1;
    int i = 1;

    while (n > 0)
    {

        result = result * i;
        i++;
        n--;
    }
    cout << result;
}
void factorialUsingDoWhile(int n)
{

    int result = 1;
    int i = 1;

    do
    {

        result = result * i;
        i++;
        n--;
    }

    while (n > 0);

    cout << result;
}

void fibUsingDoWhile(int n)
{

    int t1 = 0, t2 = 1, nextTerm = 0;

    n = 10;

    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    do
    {
        nextTerm = t1 + t2;

        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << ", ";
    } while (nextTerm <= n);
}

void fibUsingFor(int n)
{

    int t1 = 0, t2 = 1, nextTerm = 0;

    n = 10;

    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    // Starting from the third term
    for (nextTerm = t1 + t2; nextTerm <= n; nextTerm = t1 + t2)
    {
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
    }
}

void fibUsingWhile(int n)
{

    int t1 = 0, t2 = 1, nextTerm = 0;
    // cout << "Enter a positive number: ";
    // cin >> n;
    // displays the first two terms which is always 0 and 1
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";
    nextTerm = t1 + t2;
    while (nextTerm <= n)
    {
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}
void changeArray(int arr[], int n)
{

    arr[0] = 69;
}

void printArray(int arr[], int n)
{
    cout << "\nPrinting Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// const int ROWS1 = 2;
// const int COLS1 = 3;
// const int ROWS2 = 3;
// const int COLS2 = 2;

void addMatrices(const int mat1[ROWS1][COLS1], const int mat2[ROWS2][COLS2], int result[ROWS1][COLS2])
{

    for (int i = 0; i < ROWS1; ++i)
    {
        for (int j = 0; j < COLS2; ++j)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void transposeMatrix(const int mat[ROWS][COLS], int transposed[COLS][ROWS])
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            transposed[j][i] = mat[i][j];
        }
    }
}

const int ROWS1 = 2;
const int COLS1 = 3;
const int ROWS2 = 3;
const int COLS2 = 2;

// Function to multiply two matrices
void multiplyMatrices(const int mat1[ROWS1][COLS1], const int mat2[ROWS2][COLS2], int result[ROWS1][COLS2])
{
    // Check if multiplication is possible
    if (COLS1 != ROWS2)
    {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return;
    }

    for (int i = 0; i < ROWS1; ++i)
    {
        for (int j = 0; j < COLS2; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < COLS1; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(const int mat[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void towerOfHanoi(int n, char A, char B, char C)
{

    if (n == 1)
    {
        cout << "Move disk 1 from " << A << " to " << C << endl;
        return;
    }
    else
    {

        towerOfHanoi(n - 1, A, C, B);
        cout << "Move disk " << n << " from " << A << " to " << C << endl;
        towerOfHanoi(n - 1, B, A, C);
    }
}

void inputMatrix(int mat[ROWS][COLS])
{
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << "Element at (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }
}
int main()
{

    int mat1[ROWS][COLS];

    // int mat2[ROWS][COLS] = {
    //     {2, 2, 7},
    //     {6, 5, 5},
    //     {3, 2, 1}};

    // int result[ROWS][COLS]; // Matrix to store the result

    // Add the matrices
    // addMatrices(mat1, mat2, result);

    // Print the result
    // printMatrix(mat1);

    char *ptr[5] = {"A", "B", "C", "D", "E"};
    cout << *ptr[0] << endl;

    // int *arr[5];

    // for (int i = 0; i < 5; ++i)
    // {
    //     arr[i] = new int; // Allocate memory for an integer
    // }

    // for (int i = 0; i < 5; ++i)
    // {

    //     cout << "Enter the element at index " << i << " : ";
    //     cin >> *(arr[i]);
    // }
    // cout << "Array elements are: ";
    // for (int i = 0; i < 5; ++i)
    // {
    //     cout << *(arr[i]) << " "; // Access the value through the pointer
    // }
    // cout << endl;

    // // Free allocated memory
    // for (int i = 0; i < 5; ++i)
    // {
    //     delete arr[i]; // Deallocate memory
    // }

    // int arr[5] = {1, 2, 3, 4, 5};
    // // int matrix[10][10] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // printArray(arr, 5);
    // changeArray(arr, 5);
    // printArray(arr, 5);

    // decimalToBinary(4);
    // towerOfHanoi(3, 'X', 'Y', 'Z');

    // cout << fact(5) << endl;
    // cout << nthFib(5);
    // cout << (isLeapYear(230) ? "Leap Year" : "Not a Leap Year") << endl;

    // fibonacci

    // char str[6];
    // short unsigned int a = 5;

    // int add(int, int, int); // function declaration inside main
    // cout << add(5, 4, 2);

    //  signed long a = 5;
    // string s = "hello";

    // int x = 10, y = 20;
    // cout << "Before swapByValue: x = " << x << ", y = " << y << endl;
    // swapUsingPointers(&x, &y);
    // cout << "After swapByValue: x = " << x << ", y = " << y << endl; // Valu
    // cout << endl;

    // cout << "Before swapByValue: x = " << x << ", y = " << y << endl;
    // swapByReference(x, y);
    // cout << "After swapByValue: x = " << x << ", y = " << y << endl; // Valu

    // add(2);
    // fib(5);
    // factorialUsingWhile(3);
    // factorialUsingFor(5);
    // factorialUsingDoWhile(5);
    // fibUsingDoWhile(10);
    // factorial(5);
    // cout << s.length();
    // int num;
    // for(num=1;num<=3;num++)
    // cout<<num; 123
    // int num;
    // for(num=1;num<=3;num++);
    // cout<<num; //4

    // cout<<"\nhello\n";

    // int num = 6;

    // switch (num)
    // {

    // case 1:
    //     cout << " 1st case" << endl;
    //     break;
    // case 2:
    //     cout << " 2nd case" << endl;
    //     break;
    // case 3:
    //     cout << " 3rd case" << endl;
    //     break;
    // default:
    //     cout << " default case" << endl;
    // }

    cout
        << endl;

    return 0;
}

void factorialUsingFor(int n)
{

    int result = 1;

    for (int i = 1; i <= n; i++)
    {

        result = result * i;
    }
    cout << result;
}
