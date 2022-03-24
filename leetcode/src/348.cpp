#include "assert.h"
#include <vector>

namespace p_348
{
    class TicTacToe
    {
        int n;
        std::vector<int> rows_cnt;
        std::vector<int> cols_cnt;
        int dia_lt_rd;
        int dia_rt_ld;;

        int winner()
        {
            for (int i = 0; i < n; i++)
            {
                if (rows_cnt[i] == n)
                {
                    return 1;
                }

                if (rows_cnt[i] == -n)
                {
                    return 2;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (cols_cnt[i] == n)
                {
                    return 1;
                }

                if (cols_cnt[i] == -n)
                {
                    return 2;
                }
            }

            if (dia_lt_rd == n || dia_rt_ld == n)
            {
                return 1;
            }

            if (dia_lt_rd == -n || dia_rt_ld == -n)
            {
                return 2;
            }

            return 0;
        }

    public:
        TicTacToe(int n) : n(n), rows_cnt(n, 0), cols_cnt(n, 0), dia_lt_rd(0), dia_rt_ld(0) {}

        int move(int row, int col, int player)
        {
            if (player == 2)
            {
                player = -1;
            }

            rows_cnt[row] += player;
            cols_cnt[col] += player;

            if (row == col)
            {
                dia_lt_rd += player;
            }

            if (row + col == n - 1)
            {
                dia_rt_ld += player;
            }

            return winner();
        }
    };
} // namespace p_348

/*
# Problem:
https://leetcode.com/problems/design-tic-tac-toe/

## HINT:
* Just record the row's/col's/dia's sum.
* Make player-1 is 1 and player-2 is -1. Opposite value will be more easy to verify.
* Once sum is equal to player * n, this player win.

## Time Complexity:
BigO(2n)

## Space Complexity:
BigO(2n)
*/