#include <iostream>

using namespace std;
#include <vector>

void traverseDiagonalsFromFirstRow(const vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    cout << "\nPrinting the Diagonals from first Row" << endl;

    for (int col = 0; col < n; ++col)
    {
        int i = 0;
        int j = col;

        while (i < m && j < n)
        {
            cout << mat[i][j] << " ";
            ++i;
            ++j;
        }
        cout << endl;
    }
}

void traverseDiagonalsFromFirstColumn(const vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    cout << "\nPrinting the diagonals from first column" << endl;

    for (int row = 1; row < m; ++row)
    {
        int i = row;
        int j = 0;

        while (i < m && j < n)
        {
            cout << mat[i][j] << " ";
            ++i;
            ++j;
        }
        cout << endl;
    }
}

void printMatrix(vector<vector<int>> &matrix)
{

    cout << "\nPrinting the matrix" << endl;

    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }

        cout << endl;
    }
}

void transpose(vector<vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    // swapped dimensions

    vector<vector<int>> transposed(cols, vector<int>(rows, 0));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {

            transposed[j][i] = matrix[i][j];
        }
    }

    matrix = transposed;
}

int main()
{

    int rows = 4;
    int col = 7;

    // vector<vector<int>> matrix(rows, vector<int>(col, 0));
    vector<vector<int>> mat = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2}};

    // printMatrix(matrix);

    // matrix[0][1] = 3;
    // printMatrix(matrix);

    // vector<int> newRow = {4, 3, 6, 3};

    // matrix.push_back(newRow);
    // printMatrix(matrix);

    // vector<int> newCol = {20, 21, 22};

    // for (size_t i = 0; i < matrix.size(); ++i)
    // {
    //     matrix[i].push_back(newCol[i]);
    // }
    // printMatrix(matrix);
    // cout << "\nNumber of rows of the matrix: " << matrix.size() << endl;
    // cout << "\nNumber of cols of the first row matrix: " << matrix[0].size() << endl;

    // // matrix.clear();
    // printMatrix(matrix);

    // matrix.resize(2, vector<int>(2, 0));
    // printMatrix(matrix);

    // traverseDiagonalsFromFirstRow(mat);
    // traverseDiagonalsFromFirstColumn(mat);

    transpose(mat);
    printMatrix(mat);

    return 0;
}