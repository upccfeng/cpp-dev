#include <vector>

using namespace std;

namespace p52_daily
{
    class Solution
    {
        vector<bool> cols;
        vector<bool> slash_1;
        vector<bool> slash_2;

        int _n;

        int result;

        void _init(int n)
        {
            _n = n;
            for (int i = 0; i < n; ++i)
            {
                cols.emplace_back(false);
                slash_1.emplace_back(false);
                slash_2.emplace_back(false);
            }

            for (int i = 0; i < n - 1; ++i)
            {
                slash_1.emplace_back(false);
                slash_2.emplace_back(false);
            }
        }

        bool _isOccupied(int x, int y)
        {
            return cols[x] || slash_1[x + y] || slash_2[x - y + _n - 1];
        }

        void _updateMpa(int x, int y, bool occupied)
        {
            cols[x] = occupied;
            slash_1[x + y] = occupied;
            slash_2[x - y + _n - 1] = occupied;
        }

        void _totalNQueens(int current_row)
        {
            if (current_row == _n)
            {
                ++result;
                return;
            }
            else
            {
                for (int col = 0; col < _n; ++col)
                {
                    if (_isOccupied(col, current_row))
                        continue;


                    _updateMpa(col, current_row, true);
                    _totalNQueens(current_row + 1);
                    _updateMpa(col, current_row, false);
                }
            }
        }


    public:
        int totalNQueens(int n)
        {
            _init(n);

            result = 0;
            _totalNQueens(0);

            return result;
        }
    };
} // namespace p52_daily

/*
# Problem:

https://leetcode.com/problems/n-queens-ii/

## HINT:

Recursive each row or each column, and mark the occupied another(row/column).

If n is the square's length and the point is (x, y).
The slash-1(right-top to left-down) is start from 0 to (x + y).
The slash-2(left-top to left-down) is start from 0 to (x - y + n -1).

For recursiving each row.
A new point, (x, y) will occupy col[y], slash-1[x + y], and slash-2[x - y + n -1].
Update the occupied data in col, slash-1, and slash-2 before next recursive.
De-update the occupied data after recursive.

## Algorithm:

```
vector<bool> cols = [];
vector<bool> slash_1 = [];
vector<bool> slash_2 = [];

int _n;

int result;

def init(n):
    # init for cols, slash_1, and slash_2.
    # there are n cols, (2n - 1) slashes.

def _isOccupied(x, y):
    return cols[x] || slash_1[x + y] || slash_2[x - y + _n - 1];

def _updateMpa(x, y, occupied):
    cols[x] = occupied;
    slash_1[x + y] = occupied;
    slash_2[x - y + _n - 1] = occupied;

def _totalNQueens(current_row):
    if current_row == _n:
        ++result
        return
    else:
        for col in range(0, n):
            if _isOccupied(col, current_row):
                continue

            _updateMpa(col, current_row, true)
            _totalNQueens(current_row + 1)
            _updateMpa(col, current_row, false)

def totalNQueens():
    _init(n)

    result = 0
    _totalNQueens(0)

    return result
```

## Time Complexity:
O(n^2)

## Space Complexity:
O(n)
*/