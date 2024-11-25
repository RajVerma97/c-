#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchMatrixBinary(vector<vector<int>>& matrix, int rows, int cols, int target) {
    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int elem = matrix[mid / cols][mid % cols];

        if (elem == target) {
            return {mid / cols, mid % cols}; // Return the row and column indices
        } else if (elem < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {-1, -1}; // Indicate that the target was not found
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Matrix initialization

    int target = 8;

    int rows = matrix.size();
    int cols = matrix[0].size();

    pair<int, int> result = searchMatrixBinary(matrix, rows, cols, target);

    if (result.first != -1) {
        cout << "Found at index: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}