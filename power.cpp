#include <iostream>

using namespace std;

int pow(int n, int p)
{

    if (p == 0)
        return 1;

    return n * pow(n, p - 1);
}

int main()
{

    int n, p;

    cout << "Enter the number: ";
    cin >> n;

    cout << "Enter the power: ";
    cin >> p;

    cout << "The power of " << n << " is: " << pow(n, p) << endl;
    return 0;
}