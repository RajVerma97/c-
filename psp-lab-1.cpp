#include <iostream>
using namespace std;

void series(int arr[100][100], int n, int level)
{
    // base
    if (level >= n / 2 + 1)
        return;

    int mid = n / 2;
    if (level == 0)
    {
        cout << arr[mid][mid] << " ";
    }

    else
    {
        // square
        cout << arr[mid - level][mid] << " " << arr[mid][mid + level] << " " << arr[mid + level][mid] << " " << arr[mid][mid - level] << " ";

        // hard code :
        for (int i = 1; i < level; i++)
        {
            cout << arr[mid - level][mid + i] << " "; // Top
            cout << arr[mid - i][mid + level] << " "; // Top-right
            cout << arr[mid + i][mid + level] << " "; // Right
            cout << arr[mid + level][mid + i] << " "; // Bottom-right
            cout << arr[mid + level][mid - i] << " "; // Bottom
            cout << arr[mid - i][mid - level] << " "; // Bottom-left
            cout << arr[mid + i][mid - level] << " "; // Left
            cout << arr[mid - level][mid - i] << " "; // Top-left
        }

        // corner
        cout << arr[mid - level][mid + level] << " " << arr[mid + level][mid + level] << " " << arr[mid + level][mid - level] << " " << arr[mid - level][mid - level] << " ";
    }

    series(arr, n, level + 1);
}

int main()
{
    const int n = 5;
    int arr[100][100] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };

    series(arr, n, 0);
    cout<<endl;
    return 0;
}