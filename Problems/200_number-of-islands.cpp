#include <vector>
#include <queue>
void BFS(std::vector<std::vector<char>> &grid, std::size_t row, std::size_t column);

int numIslands(std::vector<std::vector<char>> &grid)
{
    std::size_t rows = grid.size();
    std::size_t columns = grid[0].size();
    int counter = 0;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < columns; ++j)
        {
            if (grid[i][j] == '1')
            {
                ++counter;
                BFS(grid, i, j);
            }
        }
    }
    return counter;
}

void BFS(std::vector<std::vector<char>> &grid, std::size_t row, std::size_t column)
{
    std::queue<std::pair<std::size_t, std::size_t>> pending;
    grid[row][column] = '0';
    pending.emplace(row, column);
    while (!pending.empty())
    {
        auto cur = pending.front();
        pending.pop();
        auto r = cur.first;
        auto c = cur.second;
        if ((r != 0) && grid[r - 1][c] == '1')
        {
            grid[r-1][c] = '0';
            pending.emplace(r - 1, c);
        }
        if ((r+1 < grid.size()) && grid[r + 1][c] == '1')
        {
            grid[r+1][c] = '0';
            pending.emplace(r + 1, c);
        }
        if ((c != 0) && grid[r][c - 1] == '1')
        {
            grid[r][c-1] = '0';
            pending.emplace(r, c - 1);
        }
        if ((c+1 < grid[0].size()) && grid[r][c + 1] == '1')
        {
            grid[r][c+1] = '0';
            pending.emplace(r, c + 1);
        }
    }
}

int main()
{
}