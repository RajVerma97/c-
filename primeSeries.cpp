#include <iostream>
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

// Function to generate and display the prime sequence
void generatePrimeSequence(int terms)
{
    int count = 0;      // Count of prime numbers generated
    int number = 2;     // Starting number to check for primality
    int termLength = 1; // Initial length of the term to be generated
    int printed = 0;    // Total number of printed primes in the sequence

    while (printed < terms)
    {
        int primesToPrint = termLength; // Number of primes to print in this term
        while (primesToPrint > 0)
        {
            if (isPrime(number))
            {
                cout << number << " "; // Print the prime number
                printed++;             // Increase total printed count
                primesToPrint--;       // Decrease the number of primes left to print
            }
            number++; // Move to the next number to check
        }
        termLength++; // Increase the length for the next term
    }
    cout << endl; // New line after printing the sequence
}

int main()
{
    int n = 10; // Total terms in the sequence
    cout << "Prime sequence: ";
    generatePrimeSequence(n); // Generate the prime sequence
    return 0;
}