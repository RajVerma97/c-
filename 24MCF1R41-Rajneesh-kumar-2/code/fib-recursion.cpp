#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciSeries(int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci series up to " << n << " terms: ";
    printFibonacciSeries(n);
    return 0;
}