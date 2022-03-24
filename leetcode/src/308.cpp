#include "assert.h"
#include <vector>

namespace p_308
{
    class NumMatrix
    {
        std::vector<std::vector<int>> data;
        int ROWS;
        int COLS;

        std::vector<int> rows_sum;
        std::vector<int> cols_sum;
        int total;


    public:
        NumMatrix(std::vector<std::vector<int>>& matrix)
        {
            data = matrix;
            ROWS = matrix.size();
            COLS = matrix[0].size();

            rows_sum.resize(ROWS);
            cols_sum.resize(COLS);
            total = 0;

            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    total += data[r][c];
                    rows_sum[r] += data[r][c];
                    cols_sum[c] += data[r][c];
                }
            }
        }

        void update(int row, int col, int val)
        {
            int old = data[row][col];

            data[row][col] = val;
            total = total - old + val;

            rows_sum[row] = rows_sum[row] - old + val;
            cols_sum[col] = cols_sum[col] - old + val;
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            int row_dist = row2 - row1;
            int col_dist = col2 - col1;

            if (row_dist > col_dist)
            {
                // remove col
                int ret = total;

                for (int c = 0; c < col1; c++)
                {
                    ret -= cols_sum[c];
                }

                for (int c = col2 + 1; c < COLS; c++)
                {
                    ret -= cols_sum[c];
                }

                for (int c = col1; c <= col2; c++)
                {
                    for (int r = 0; r < row1; r++)
                    {
                        ret -= data[r][c];
                    }
                }

                for (int c = col1; c <= col2; c++)
                {
                    for (int r = row2 + 1; r < ROWS; r++)
                    {
                        ret -= data[r][c];
                    }
                }

                return ret;

            }
            else
            {
                // remove row
                int ret = total;

                for (int r = 0; r < row1; r++)
                {
                    ret -= rows_sum[r];
                }

                for (int r = row2 + 1; r < ROWS; r++)
                {
                    ret -= rows_sum[r];
                }

                for (int r = row1; r <= row2; r++)
                {
                    for (int c = 0; c < col1; c++)
                    {
                        ret -= data[r][c];
                    }
                }

                for (int r = row1; r <= row2; r++)
                {
                    for (int c = col2 + 1; c < COLS; c++)
                    {
                        ret -= data[r][c];
                    }
                }

                return ret;
            }
        }
    };
} // namespace p_308

/*
# Problem:
https://leetcode.com/problems/range-sum-query-2d-mutable/

## HINT:
* Cache the total and the row/col sum

## Time Complexity:
BigO(n*m)

## Space Complexity:
BigO(n*m)
*/