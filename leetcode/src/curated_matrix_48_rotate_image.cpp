#include <vector>

namespace p_curated_matrix_48_rotate_image
{
    class Solution
    {
    public:
        void rotateWithSpaceNN(std::vector<std::vector<int>>& matrix)
        {
            int ROWS = matrix.size();
            int COLS = ROWS;

            std::vector<std::vector<int>> copy = matrix;

            int new_c = COLS - 1;
            for (int r = 0; r < ROWS; ++r)
            {
                for (int c = 0; c < COLS; ++c)
                {
                    matrix[c][new_c] = copy[r][c];
                }

                --new_c;
            }

            return;
        }

        void rotateWithSpace1(std::vector<std::vector<int>>& matrix)
        {
            int LENGTH = matrix.size();

            int start = 0;
            int end = LENGTH;
            int rounds = LENGTH - 1;

            while (start < end)
            {
                for (int r = 0; r < rounds; ++r)
                {
                    // store the left-top
                    int temp = matrix[start][start + r];

                    // move left-bottom to left-top
                    matrix[start][start + r] = matrix[end - 1 - r][start];

                    // move right-bottom to left-bottom
                    matrix[end - 1 - r][start] = matrix[end - 1][end - 1 - r];

                    // move right-top to right-bottom
                    matrix[end - 1][end - 1 - r] = matrix[start + r][end - 1];

                    // move left-top to right-top
                    matrix[start + r][end - 1] = temp;
                }

                rounds = rounds - 2;
                ++start;
                --end;
            }
        }

        void rotate(std::vector<std::vector<int>>& matrix)
        {
            rotateWithSpace1(matrix);
        }
    };
} // namespace p_curated_matrix_48_rotate_image

/*
# Problem:
https://leetcode.com/problems/rotate-image/

## HINT:
* Method-1: Row(0) will be Column(n-1), Row(1) will be Column(n-2), ..., Row(n-1) will be Column(0)
*           Make a copy of matrix, and update each element in matrix by the rule.
* Method-2: Store start and end boundary, update external only with start and end, and update start and end for each external elemtns.

## Time Complexity:
BigO(n^2)

## Space Complexity:
Method-1: BigO(n^2)
Method-2: BigO(1)
*/