#include <vector>

namespace p_2133_weekly_contest
{
    class Solution
    {
    public:
        bool checkValid(std::vector<std::vector<int>>& matrix)
        {
            int size = matrix.size();

            std::vector<std::vector<int>> row_r(size, std::vector<int>(size + 1));
            std::vector<std::vector<int>> col_r(size, std::vector<int>(size + 1));

            for (int row = 0; row < size; row++)
            {
                for (int col = 0; col < size; col++)
                {
                    int taking = matrix[row][col];
                    if (row_r[row][taking] == 0)
                    {
                        row_r[row][taking] = 1;
                    }
                    else
                    {
                        return false;
                    }

                    if (col_r[col][taking] == 0)
                    {
                        col_r[col][taking] = 1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    };
} // namespace p_2133_weekly_contest

/*
# Problem:
https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

## HINT:

## Algorithm:

## Time Complexity:
BigO(n^2)

## Space Complexity:
BigO(n^2)
*/