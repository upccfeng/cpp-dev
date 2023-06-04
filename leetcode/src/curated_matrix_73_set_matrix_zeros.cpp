#include <vector>

namespace p_curated_matrix_73_set_matrix_zeros
{
    class Solution
    {
    public:
        void setZeroes(std::vector<std::vector<int>>& matrix)
        {
            int ROWS = matrix.size();
            int COLS = matrix[0].size();

            std::vector<bool> row(ROWS, false);
            std::vector<bool> col(COLS, false);

            for (int r = 0; r < ROWS; ++r)
            {
                for (int c = 0; c < COLS; ++c)
                {
                    if (matrix[r][c] == 0)
                    {
                        row[r] = true;
                        col[c] = true;
                    }
                }
            }

            for (int r = 0; r < ROWS; ++r)
            {
                for (int c = 0; c < COLS; ++c)
                {
                    matrix[r][c] = row[r] || col[c] ? 0 : matrix[r][c];
                }
            }
        }
    };
} // namespace p_curated_matrix_73_set_matrix_zeros

/*
# Problem:
https://leetcode.com/problems/set-matrix-zeroes/

## HINT:
* Use two vector to record which row or which col should be 0.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n + m)
*/