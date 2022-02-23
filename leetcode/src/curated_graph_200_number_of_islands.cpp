#include <vector>

namespace p_curated_graph_200_number_of_islands
{
    class Solution
    {
        void dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int row, int col)
        {
            if ((row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) ||
                grid[row][col] == '0')
            {
                return;
            }

            if (!visited[row][col])
            {
                visited[row][col] = true;
                dfs(grid, visited, row - 1, col);
                dfs(grid, visited, row + 1, col);
                dfs(grid, visited, row, col - 1);
                dfs(grid, visited, row, col + 1);
                return;
            }
            else
            {
                return;
            }
        }

    public:
        int numIslands(std::vector<std::vector<char>>& grid)
        {
            int cnt = 0;

            std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), 0));

            for (int r = 0; r < grid.size(); ++r)
            {
                for (int c = 0; c < grid[r].size(); ++c)
                {
                    if (grid[r][c] == '1' && !visited[r][c])
                    {
                        dfs(grid, visited, r, c);
                        ++cnt;
                    }
                }
            }

            return cnt;
        }
    };
} // namespace p_curated_graph_200_number_of_islands

/*
# Problem:
https://leetcode.com/problems/number-of-islands/

## HINT:
* For each point (r, c), if !visited[r][c], dfs(r, c) and cnt++
* The same island's point will not do dfs again.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n * m)
*/