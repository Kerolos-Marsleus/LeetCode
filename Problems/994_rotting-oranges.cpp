#include <iostream>
#include <vector>
#include <queue>
class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        std::queue<std::pair<std::size_t, std::size_t>> pending;
        std::size_t rows = grid.size();
        std::size_t columns = grid[0].size();
        int counter = 0;
        int fresh = 0;
        for (std::size_t _row = 0; _row < rows; ++_row)
        {
            for (std::size_t _column = 0; _column < columns; ++_column)
            {
                if (grid[_row][_column] == 2)
                {
                    pending.emplace(_row, _column);
                }
                if (grid[_row][_column] == 1)
                {
                    ++fresh;
                }
            }
        }
        int n = pending.size();
        while (!pending.empty())
        {
            while (n > 0)
            {
                auto cur = pending.front();
                pending.pop();
                --n;
                auto r = cur.first;
                auto c = cur.second;
                if ((r != 0) && grid[r - 1][c] == 1) // up
                {
                    grid[r - 1][c] = 2;
                    pending.emplace(r - 1, c);
                    --fresh;
                }
                if ((r + 1 < grid.size()) && grid[r + 1][c] == 1) // down
                {
                    grid[r + 1][c] = 2;
                    pending.emplace(r + 1, c);
                    --fresh;
                }
                if ((c != 0) && grid[r][c - 1] == 1) // left
                {
                    grid[r][c - 1] = 2;
                    pending.emplace(r, c - 1);
                    --fresh;
                }
                if ((c + 1 < grid[0].size()) && grid[r][c + 1] == 1) // right
                {
                    grid[r][c + 1] = 2;
                    pending.emplace(r, c + 1);
                    --fresh;
                }
            }
            if(!pending.empty()){
                ++counter;
            }
            n = pending.size();
        }
        if(fresh > 0) return -1;
        return counter;
    }
};



int main() {
    struct Test { std::vector<std::vector<int>> grid; int expected; };
    std::vector<Test> tests = {
        {{{2,1,1},{1,1,0},{0,1,1}},  4},
        {{{2,1,1},{0,1,1},{1,0,1}}, -1},
        {{{0,2}},                    0},
        {{{0}},                      0},
    };
    for (std::size_t i = 0; i < tests.size(); ++i) {
        Solution s;
        const int got = s.orangesRotting(tests[i].grid);
        std::cout << "Test " << i << ": expected " << tests[i].expected
                  << ", got " << got
                  << (got == tests[i].expected ? "  PASS" : "  FAIL") << '\n';
    }
}