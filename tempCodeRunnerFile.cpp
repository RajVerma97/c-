#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{

    char arr[10][10] = {
        {'E', 'A'},
        {'Q', 'W', 'G', 'B', 'A', 'F'},
        {'R', 'E', 'X'},
        {'T'},
        {'U', 'A', 'D', 'M', 'V'}};

    // Define the number of elements in each row
    int rowSizes[] = {2, 6, 3, 1, 5};
    int rows = 5;

    // Sort each row
    for (int i = 0; i < rows; ++i)
    {
        sort(arr[i], arr[i] + rowSizes[i]);
    }

    // Transpose the array to result
    char result[10][10] = {}; // Initialize with 0 or empty chars

    // Find the maximum number of columns across all rows
    int maxCols = 6; // Based on the largest row size

    // Transpose
    for (int i = 0; i < maxCols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            if (i < rowSizes[j])
            { // Ensure not to access out-of-bounds elements
                result[i][j] = arr[j][i];
            }
            else
            {
                result[i][j] = ' '; // Fill with space if row does not have enough elements
            }
        }
    }

    // Print the transposed result
    for (int i = 0; i < maxCols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}