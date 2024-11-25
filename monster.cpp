#include <iostream>
using namespace std;

// Function to return the gcd of two numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to return the minimum possible health for the monster
// (using the GCD of all health values)
int min_health(int health[], int n)
{
    // Start with the gcd of the first two elements
    int currentgcd = health[0];

    // Calculate GCD across all elements in the array
    for (int i = 1; i < n; ++i)
    {
        currentgcd = gcd(currentgcd, health[i]);
    }
    return currentgcd;
}

// Driver code
int main()
{
    int health[] = {2, 14, 28, 56};
    int n = sizeof(health) / sizeof(health[0]);

    // Minimum possible health
    cout << "Minimum possible health for the monster: " << min_health(health, n) << endl;

    return 0;
}