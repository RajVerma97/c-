#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// Utility function to check if a number is prime
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

class ArrayProcessor
{
private:
    int *arr; // Pointer to hold the array
    int size; // Size of the array

public:
    // Constructor to initialize the array and take input
    ArrayProcessor(int size) : size(size)
    {
        arr = new int[size]; // Dynamically allocate memory for the array
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; ++i)
        {
            cin >> arr[i]; // Take input directly inside the constructor
        }
    }

    // Function to find the largest element at prime indices
    int findMaxAtPrimeIndices()
    {
        int maxVal = INT_MIN;
        for (int i = 0; i < size; ++i)
        {
            if (isPrime(i))
            {
                maxVal = max(maxVal, arr[i]);
            }
        }
        return maxVal;
    }

    // Destructor to delete the dynamically allocated array
    ~ArrayProcessor()
    {
        delete[] arr; // Free the allocated memory
        cout << "ArrayProcessor object destroyed" << endl;
    }
};

int main()
{
    int size;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create an ArrayProcessor object
    ArrayProcessor processor(size);

    // Find and display the maximum value at prime indices
    int maxPrimeIndexValue = processor.findMaxAtPrimeIndices();
    cout << "The biggest number at prime indices is: " << maxPrimeIndexValue << endl;

    return 0;
}