#include <vector>

namespace p_curated_matrix_54_spiral_matrix
{
    class Solution
    {
    public:
        std::vector<int> spiralOrderSpiral(std::vector<std::vector<int>>& matrix)
        {
            int ROWS = matrix.size();
            int COLS = matrix[0].size();

            std::vector<int> ret(ROWS * COLS);

            enum class Directions {
                RIGHT,
                DOWN,
                LEFT,
                UP
            };

            Directions direct = Directions::RIGHT;
            int cycle = 0;
            int r = 0;
            int c = 0;
            int cnt = 0;
            while (true)
            {
                if (cnt == ROWS * COLS)
                {
                    break;
                }

                ret[cnt] = matrix[r][c];
                ++cnt;

                if (direct == Directions::RIGHT)
                {
                    if (c == COLS - 1 - cycle)
                    {
                        direct = Directions::DOWN;
                        ++r;
                    }
                    else
                    {
                        ++c;
                    }
                }
                else if (direct == Directions::DOWN)
                {
                    if (r == ROWS - 1 - cycle)
                    {
                        direct = Directions::LEFT;
                        --c;
                    }
                    else
                    {
                        ++r;
                    }
                }
                else if (direct == Directions::LEFT)
                {
                    if (c == 0 + cycle)
                    {
                        ++cycle;
                        direct = Directions::UP;
                        --r;
                    }
                    else
                    {
                        --c;
                    }
                }
                else // (direct == Directions::UP)
                {
                    if (r == 0 + cycle)
                    {
                        direct = Directions::RIGHT;
                        ++c;
                    }
                    else
                    {
                        --r;
                    }
                }

            }

            return ret;
        }
        std::vector<int> spiralOrderBounary(std::vector<std::vector<int>>& matrix)
        {
            int ROWS = matrix.size();
            int COLS = matrix[0].size();

            std::vector<int> ret(ROWS * COLS);

            int left = 0;
            int right = COLS;
            int top = 0;
            int bottom = ROWS;
            int cnt = 0;

            while (left < right && top < bottom)
            {
                for (int c = left; c < right; ++c)
                {
                    ret[cnt++] = matrix[top][c];
                }
                ++top;

                for (int r = top; r < bottom; ++r)
                {
                    ret[cnt++] = matrix[r][right - 1];
                }
                --right;

                // for single row or single column case
                if (left >= right || top >= bottom)
                {
                    break;
                }

                for (int c = right - 1; c >= left; --c)
                {
                    ret[cnt++] = matrix[bottom - 1][c];
                }
                --bottom;

                for (int r = bottom - 1; r >= top; --r)
                {
                    ret[cnt++] = matrix[r][left];
                }
                ++left;
            }

            return ret;
        }

        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
        {
            return spiralOrderBounary(matrix);
        }
    };
} // namespace p_curated_matrix_54_spiral_matrix

/*
# Problem:
https://leetcode.com/problems/spiral-matrix/

## HINT:
* Adjust the r and c with direction to meet the spiral rule.
* The cycle should increase in LEFT -> UP
* Another Method: Set 4 boundaries to process each elements according to TOP-ROW, RIGHT-COLUMN , BOTTOM-ROW, LEFT-COLUMN sequece.
* After each ROW or COLUMN, update the boundary, and be careful with single row or single column cases.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(1)
*/