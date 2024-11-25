#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num)
{
    if (num <= 1)
        return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false; // If divisible, not prime
    }
    return true; // The number is prime
}

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

// Function to generate the required sequence
// Function to generate the prime and non-prime sequence

void generateSequence(int n)
{
    int sequence[100];     // Static array to store the sequence (adjust size as needed)
    int primeCount = 3;    // Start with 3 primes
    int nonPrimeCount = 3; // Start with 3 non-primes
    int number = 2;        // Start checking from 2
    int index = 0;         // Index to keep track of the sequence array

    while (index < n)
    {
        // Add prime numbers
        for (int i = 0; i < primeCount && index < n; i++)
        {
            while (!isPrime(number))
            {
                number++; // Find the next prime
            }
            sequence[index] = number; // Add to sequence
            number++;                 // Move to the next number
            index++;                  // Increment index
        }

        // Add non-prime numbers
        for (int i = 0; i < nonPrimeCount && index < n; i++)
        {
            while (isPrime(number))
            {
                number++; // Find the next non-prime
            }
            sequence[index] = number; // Add to sequence
            number++;                 // Move to the next number
            index++;                  // Increment index
        }

        // Increment the counts for the next round
        primeCount++;
        nonPrimeCount++;
    }

    // Print the generated sequence
    for (int i = 0; i < n; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl; // New line after the sequence
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n; // Input value of n

    // Generate and print the sequence based on the value of n
    generateSequence(n);
    // cout << "Sieve of Eratosthenes: ";
    // SieveOfEratosthenes(n);

    return 0;
}