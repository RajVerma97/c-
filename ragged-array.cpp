#include <iostream>
#include <algorithm>
using namespace std;

void inputMatrix(char arr[100][100], int rowSizes[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> rowSizes[i];

        for (int j = 0; j < rowSizes[i]; j++)
        {
            cout << "Enter the element at [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void printMatrix(char arr[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m; // Number of rows
    cout << "Enter the number of rows: ";
    cin >> m;

    int rowSizes[100];
    char arr[100][100] = {};

    // Input the matrix with variable row sizes
    inputMatrix(arr, rowSizes, m);

    // Sort each row individually
    for (int i = 0; i < m; ++i)
    {
        sort(arr[i], arr[i] + rowSizes[i]);
    }

    // Find the maximum number of columns across all rows
    int maxCols = *max_element(rowSizes, rowSizes + m);

    // Transpose the array into result
    char result[100][100] = {};

    for (int i = 0; i < maxCols; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i < rowSizes[j]) // Ensure not to access out-of-bounds elements
            {
                result[i][j] = arr[j][i];
            }
            else
            {
                result[i][j] = ' '; // Fill with space if the row does not have enough elements
            }
        }
    }

    // Print the transposed result
    cout << "Transposed and sorted matrix:" << endl;
    printMatrix(result, maxCols, m);
    
    return 0;
}