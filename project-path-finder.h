#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CELL_SIZE = 40;
const int GRID_WIDTH = WINDOW_WIDTH / CELL_SIZE;
const int GRID_HEIGHT = WINDOW_HEIGHT / CELL_SIZE;

enum CellType
{
    EMPTY,
    WALL,
    START,
    END,
    PATH,
    VISITED
};

struct Cell
{
    CellType type = EMPTY;
    int distance = INT_MAX;
    bool visited = false;
    pair<int, int> parent = {-1, -1};
};

class PathFinder
{
private:
    vector<vector<Cell>> grid;
    RenderWindow &window;
    pair<int, int> startPos;
    pair<int, int> endPos;
    bool isRunning;

    const vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    PathFinder(RenderWindow &win) : window(win),
                                    grid(GRID_HEIGHT, vector<Cell>(GRID_WIDTH)),
                                    startPos(-1, -1),
                                    endPos(-1, -1),
                                    isRunning(false) {}

    void handleClick(int x, int y, Mouse::Button button)
    {
        int gridX = x / CELL_SIZE;
        int gridY = y / CELL_SIZE;
        if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 && gridY < GRID_HEIGHT)
        {
            if (button == Mouse::Left)
            {
                if (startPos.first == -1)
                {
                    startPos = {gridY, gridX};
                    grid[gridY][gridX].type = START;
                }
                else if (endPos.first == -1 && (gridY != startPos.first || gridX != startPos.second))
                {
                    endPos = {gridY, gridX};
                    grid[gridY][gridX].type = END;
                }
                else if (grid[gridY][gridX].type == EMPTY)
                {
                    grid[gridY][gridX].type = WALL;
                }
            }
            else if (button == Mouse::Right)
            {
                if (grid[gridY][gridX].type == START)
                {
                    startPos = {-1, -1};
                }
                else if (grid[gridY][gridX].type == END)
                {
                    endPos = {-1, -1};
                }
                grid[gridY][gridX].type = EMPTY;
            }
        }
    }

    bool isValid(int row, int col)
    {
        return row >= 0 && row < GRID_HEIGHT && col >= 0 && col < GRID_WIDTH;
    }

    void dijkstra()
    {
        if (startPos.first == -1 || endPos.first == -1)
            return;

        for (int i = 0; i < GRID_HEIGHT; i++)
        {
            for (int j = 0; j < GRID_WIDTH; j++)
            {
                if (grid[i][j].type != WALL)
                {
                    grid[i][j].distance = INT_MAX;
                    grid[i][j].visited = false;
                    grid[i][j].parent = {-1, -1};
                    if (grid[i][j].type == PATH || grid[i][j].type == VISITED)
                    {
                        grid[i][j].type = EMPTY;
                    }
                }
            }
        }

        using pPair = pair<int, pair<int, int>>;
        priority_queue<pPair, vector<pPair>, greater<pPair>> pq;

        grid[startPos.first][startPos.second].distance = 0;
        pq.push({0, startPos});

        while (!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (grid[row][col].visited)
                continue;

            grid[row][col].visited = true;
            if (grid[row][col].type != START && grid[row][col].type != END)
            {
                grid[row][col].type = VISITED;
            }

            if (row == endPos.first && col == endPos.second)
            {
                reconstructPath();
                return;
            }

            for (const auto &dir : directions)
            {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (isValid(newRow, newCol) && !grid[newRow][newCol].visited &&
                    grid[newRow][newCol].type != WALL)
                {
                    int newDist = grid[row][col].distance + 1;
                    if (newDist < grid[newRow][newCol].distance)
                    {
                        grid[newRow][newCol].distance = newDist;
                        grid[newRow][newCol].parent = {row, col};
                        pq.push({newDist, {newRow, newCol}});
                    }
                }
            }

            draw();
            window.display();
            sleep(milliseconds(50));
        }
    }

    void reconstructPath()
    {
        int row = endPos.first;
        int col = endPos.second;
        while (grid[row][col].parent.first != -1)
        {
            auto parent = grid[row][col].parent;
            row = parent.first;
            col = parent.second;
            if (grid[row][col].type != START && grid[row][col].type != END)
            {
                grid[row][col].type = PATH;
            }
        }
    }
    void draw()
    {

        window.clear(Color(40, 44, 52));

        RectangleShape cell(Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));

        for (int i = 0; i < GRID_HEIGHT; i++)
        {
            for (int j = 0; j < GRID_WIDTH; j++)
            {
                cell.setPosition(j * CELL_SIZE + 1, i * CELL_SIZE + 1);

                switch (grid[i][j].type)
                {
                case EMPTY:
                    cell.setFillColor(Color(60, 63, 72));
                    break;
                case WALL:
                    cell.setFillColor(Color(120, 121, 130));
                    break;
                case START:
                    cell.setFillColor(Color(0, 255, 0));
                    break;
                case END:
                    cell.setFillColor(Color(239, 83, 80));
                    break;
                case PATH:
                    cell.setFillColor(Color(255, 193, 7));
                    break;
                case VISITED:
                    cell.setFillColor(Color(0, 191, 235));
                    break;
                }

                cell.setOutlineThickness(1);
                cell.setOutlineColor(Color(50, 50, 60));

                window.draw(cell);
            }
        }

        for (int i = 0; i <= GRID_HEIGHT; i++)
        {
            RectangleShape line(Vector2f(WINDOW_WIDTH, 1));
            line.setPosition(0, i * CELL_SIZE);
            line.setFillColor(Color(80, 80, 90));
            window.draw(line);
        }

        for (int j = 0; j <= GRID_WIDTH; j++)
        {
            RectangleShape line(Vector2f(1, WINDOW_HEIGHT));
            line.setPosition(j * CELL_SIZE, 0);
            line.setFillColor(Color(80, 80, 90));
            window.draw(line);
        }
    }
    void run()
    {
        isRunning = true;
        dijkstra();
    }

    bool running() const
    {
        return isRunning;
    }
};
