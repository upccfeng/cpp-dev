#include <vector>

using namespace std;

namespace p36
{
    class Solution
    {
    public:
        bool isValidSudoku(vector<vector<char>>& board)
        {
            bool col[9][9] = {false};
            bool row[9][9] = {false};
            bool grd[9][9] = {false};

            for (int c = 0; c < 9; ++c)
            {
                for (int r = 0; r < 9; ++r)
                {
                    if (board[c][r] != '.')
                    {
                        int e_int = board[c][r] - 48 - 1;

                        if (col[c][e_int])
                        {
                            return false;
                        }

                        if (row[r][e_int])
                        {
                            return false;
                        }

                        int g = c / 3 + 3 * (r / 3);

                        if (grd[g][e_int])
                        {
                            return false;
                        }

                        col[c][e_int] = true;
                        row[r][e_int] = true;
                        grd[g][e_int] = true;
                    }
                }
            }

            return true;
        }
    };
} // namespace pX36

/*
# Problem:

https://leetcode.com/problems/valid-sudoku/

## HINT:

Use three 9*9 array to record the rules for col, row, and grid.

## Algorithm:

```
col[9][9] = {false};
row[9][9] = {false};
grd[9][9] = {false};

for (int c = 0; c < 9; ++c):
    for (int r = 0; r < 9; ++r):
        if (board[c][r] != '.'):
            e_int = board[c][r] - 48 - 1;

            if (col[c][e_int]):
                return false;

            if (row[r][e_int]):
                return false;

            g = c / 3 + 3 * (r / 3);

            if (grd[g][e_int]):
                return false;

            col[c][e_int] = true
            row[r][e_int] = true
            grd[g][e_int] = true

return true
```

## Time Complexity:
O(9*9)

## Space Complexity:
O(3*9*9)
*/