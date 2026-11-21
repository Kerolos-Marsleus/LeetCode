#include <vector>
#include <queue>

bool BFS(std::vector<std::vector<int>> &grid, std::size_t row, std::size_t column);
int closedIsland(std::vector<std::vector<int>> &grid)
{
    std::size_t rows = grid.size();
    std::size_t columns = grid[0].size();
    int counter = 0;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < columns; ++j)
        {
            if (grid[i][j] == 0)
            {
                if (!BFS(grid, i, j))
                {
                    ++counter;
                }
            }
        }
    }
    return counter;
}

bool BFS(std::vector<std::vector<int>> &grid, std::size_t row, std::size_t column)
{
    bool touchesBoarder = false;
    std::queue<std::pair<std::size_t, std::size_t>> pending;
    grid[row][column] = 1;
    pending.emplace(row, column);
    while (!pending.empty())
    {
        auto cur = pending.front();
        pending.pop();
        auto r = cur.first;
        auto c = cur.second;
        if (r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1)
        {
            touchesBoarder = true;
        }
        if ((r != 0) && grid[r - 1][c] == 0)
        {
            grid[r - 1][c] = 1;
            pending.emplace(r - 1, c);
        }
        if ((r + 1 < grid.size()) && grid[r + 1][c] == 0)
        {
            grid[r + 1][c] = 1;
            pending.emplace(r + 1, c);
        }
        if ((c != 0) && grid[r][c - 1] == 0)
        {
            grid[r][c - 1] = 1;
            pending.emplace(r, c - 1);
        }
        if ((c + 1 < grid[0].size()) && grid[r][c + 1] == 0)
        {
            grid[r][c + 1] = 1;
            pending.emplace(r, c + 1);
        }
    }
    return touchesBoarder;
}
