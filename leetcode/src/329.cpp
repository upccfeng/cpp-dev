#include "assert.h"
#include <map>
#include <unordered_map>

namespace p_329
{
    class Solution {

        struct MyHash
        {
            std::size_t operator()(const std::pair<int, int>& k) const
            {
                return std::hash<int>()(k.first)
                    ^ (std::hash<int>()(k.second) << 1);

            }
        };

        // std::unordered_map<std::pair<int, int>, int, MyHash> cache;
        std::map<std::pair<int, int>, int> cache;

        bool isOutOfBoundary(std::vector<std::vector<int>>& matrix, int r, int c)
        {
            if (r < 0 || r >= matrix.size() ||
                c < 0 || c >= matrix[0].size())
            {
                return true;
            }

            return false;
        }

        int getMaxPathLength(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited, int r, int c, int target)
        {

            if (isOutOfBoundary(matrix, r, c) ||
                matrix[r][c] <= target ||
                visited[r][c])
            {
                return 0;
            }

            if (cache.find({ r, c }) != cache.end())
            {
                return cache[{r, c}];
            }

            visited[r][c] = true;
            int max = 0;

            max = std::max(max, 1 + getMaxPathLength(matrix, visited, r - 1, c, matrix[r][c]));
            max = std::max(max, 1 + getMaxPathLength(matrix, visited, r + 1, c, matrix[r][c]));
            max = std::max(max, 1 + getMaxPathLength(matrix, visited, r, c - 1, matrix[r][c]));
            max = std::max(max, 1 + getMaxPathLength(matrix, visited, r, c + 1, matrix[r][c]));

            visited[r][c] = false;

            cache[{r, c}] = max;

            return max;
        }

    public:
        int longestIncreasingPath(std::vector<std::vector<int >>& matrix) {
            int ROWS = matrix.size();
            int COLS = matrix[0].size();

            int max = 0;

            std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    int len = getMaxPathLength(matrix, visited, r, c, -1);
                    max = std::max(max, len);
                }
            }

            return max;
        }
    };
} // namespace p_329

/*
# Problem:
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

## HINT:
* dfs with cache.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n * m)
*/