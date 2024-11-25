#include <iostream>

using namespace std;

void printMatrix(std::vector<std::vector<int>> &matrix)
{
    cout << "\nPrinting the matrix" << endl;
    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            std::cout << elem << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> matrix = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};

    sort(matrix.begin(), matrix.end());
    printMatrix(matrix);
    sort(matrix.begin(), matrix.end(), less<vector<int>>());
    printMatrix(matrix);
    sort(matrix.begin(), matrix.end(), greater<vector<int>>());
    printMatrix(matrix);

    return 0;
}