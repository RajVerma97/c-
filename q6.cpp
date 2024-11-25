#include <iostream>
#include <climits> // for INT_MIN

using namespace std;

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

class Biggest
{
private:
    int arr[10];

public:
    // Constructor to initialize the array and find the biggest number at prime indices
    Biggest(int inputArr[])
    {
        // Copy the input array to the member variable
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = inputArr[i];
        }

        int maxValue = INT_MIN; // Initialize maxValue to the minimum integer value

        // Loop through the array to find the maximum value at prime indices
        for (int i = 0; i < 10; ++i)
        {
            if (isPrime(i)) // Check if the index is prime
            {
                if (arr[i] > maxValue) // Compare the value at the prime index
                {
                    maxValue = arr[i]; // Update maxValue if a larger number is found
                }
            }
        }

        // If no prime index found, print a message; otherwise, print the max value
        if (maxValue == INT_MIN)
        {
            cout << "No prime indices with values found." << endl;
        }
        else
        {
            cout << "Maximum value at prime indices: " << maxValue << endl;
        }
    }

    // Destructor (if needed)
    ~Biggest()
    {
        // Clean up resources if necessary
        // Currently, no dynamic memory allocation is used
    }
};

int main()
{
    int arr[10] = {1, 4, 45, 2, 92, 108, 116, 7, 6, 9}; // Sample input array

    Biggest b(arr); // Create an instance of Biggest, invoking the constructor

    return 0;
}