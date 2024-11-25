#include <iostream>
#include <climits>
using namespace std;

int findPath(char maze[5][5], int x, int y)
{
    // Out of bounds or hit a hurdle
    if (x < 0 || y < 0 || x >= 5 || y >= 5 || maze[x][y] == 'X')
        return INT_MAX;

    // Reached destination
    if (maze[x][y] == 'D')
        return 0;

    // Mark current cell as visited to avoid cycles
    char temp = maze[x][y];
    maze[x][y] = 'X';

    // Try all four directions
    int up = findPath(maze, x - 1, y);
    int down = findPath(maze, x + 1, y);
    int left = findPath(maze, x, y - 1);
    int right = findPath(maze, x, y + 1);

    // Restore the cell backtracking
    maze[x][y] = temp;

    // Find minimum of all possible paths
    int minPath = min(min(up, down), min(left, right));

    if (minPath == INT_MAX)
        return INT_MAX;
    return minPath + 1;
}

int main()
{
    char maze[5][5] = {
        {' ', 'S', ' ', ' ', ' '},
        {' ', ' ', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', 'X', ' ', ' '},
        {' ', 'X', ' ', 'D', ' '}};

    // Find starting position ('S')
    int startX = 0, startY = 1; // position of 'S' in the maze

    int result = findPath(maze, startX, startY);

    if (result == INT_MAX)
        cout << "No path exists!" << endl;
    else
        cout << "Minimum steps to reach destination: " << result << endl;

    return 0;
}