#include "assert.h"
#include <vector>

namespace p_240
{
    class Solution
    {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
            int ROWS = matrix.size();
            int COLS = matrix[0].size();

            int r = 0;
            int c = COLS - 1;

            while (r < ROWS && c >= 0)
            {
                if (matrix[r][c] == target)
                {
                    return true;
                }
                else if (matrix[r][c] < target)
                {
                    r++;
                }
                else // matrix[r][c] > target
                {
                    c--;
                }
            }

            return false;
        }
    };
} // namespace p_240

/*
# Problem:
https://leetcode.com/problems/search-a-2d-matrix-ii/

## HINT:
* Find from right-top to left-bottom by following rule
* - if taking node == target, return true.
* - if taking node < target, find bottom.  (need to find a bigger one but due to start at the rightest value, so just go bottom)
* - if taking node > target, find left.    (need to find a smaller one but due to start at the topest value, so just left)

## Time Complexity:
BigO(m + n)

## Space Complexity:
BigO(1)
*/