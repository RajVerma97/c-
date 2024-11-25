#include <iostream>
using namespace std;

bool isPrimeHelper(int n, int divisor)
{
    if (divisor == 1)
        return true;
    if (n % divisor == 0)
        return false;
    return isPrimeHelper(n, divisor - 1);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    return isPrimeHelper(n, n - 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}