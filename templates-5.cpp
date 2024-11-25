#include <iostream>
#include <iomanip>

template <typename T = float, int count = 3>
void printArray()
{
    T arr[count]; // Create an array of type T and size `count`

    // Initialize and print the array
    for (int i = 0; i < count; ++i)
    {
        arr[i] = i * 1.0; // Example: filling with float values (0, 1, 2, ...)
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    printArray<>();       // Uses default T = float, count = 3
    printArray<int, 5>(); // Uses T = int, count = 5
    return 0;
}