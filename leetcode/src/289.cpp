#include "assert.h"
#include <vector>

namespace p_289
{
    class Solution {

        bool isOutOfBoundary(std::vector<std::vector<int>>& board, int r, int c)
        {
            if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            {
                return true;
            }

            return false;
        }

        std::pair<int, int> getDeadAliveCnt(std::vector<std::vector<int>>& board, int r, int c)
        {
            int alive_cnt = 0;
            int dead_cnt = 0;

            for (int i = r - 1; i <= r + 1; i++)
            {
                if (!isOutOfBoundary(board, i, c - 1))
                {
                    if (board[i][c - 1] >= 1)   // case for 1 and 2
                    {
                        alive_cnt++;
                    }

                    if (board[i][c - 1] <= 0)   // case for 0 and -1
                    {
                        dead_cnt++;
                    }
                }

                if (!isOutOfBoundary(board, i, c + 1))
                {
                    if (board[i][c + 1] >= 1)   // case for 1 and 2
                    {
                        alive_cnt++;
                    }

                    if (board[i][c + 1] <= 0)   // case for 0 and -1
                    {
                        dead_cnt++;
                    }
                }
            }

            if (!isOutOfBoundary(board, r - 1, c))
            {
                if (board[r - 1][c] >= 1)   // case for 1 and 2
                {
                    alive_cnt++;
                }

                if (board[r - 1][c] <= 0)   // case for 0 and -1
                {
                    dead_cnt++;
                }
            }

            if (!isOutOfBoundary(board, r + 1, c))
            {
                if (board[r + 1][c] >= 1)   // case for 1 and 2
                {
                    alive_cnt++;
                }

                if (board[r + 1][c] <= 0)   // case for 0 and -1
                {
                    dead_cnt++;
                }
            }

            return { alive_cnt, dead_cnt };
        }

        bool isStillAlive(std::vector<std::vector<int>>& board, int r, int c)
        {
            auto cnts = getDeadAliveCnt(board, r, c);

            if (cnts.first < 2)
            {
                return false;
            }
            else if (cnts.first == 2 || cnts.first == 3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isStillDead(std::vector<std::vector<int>>& board, int r, int c)
        {
            auto cnts = getDeadAliveCnt(board, r, c);

            if (cnts.first == 3)
            {
                return false;
            }

            return true;
        }

    public:
        void gameOfLife(std::vector<std::vector<int>>& board)
        {
            int ROWS = board.size();
            int COLS = board[0].size();


            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    if (board[r][c] == 1)
                    {
                        if (!isStillAlive(board, r, c))
                        {
                            board[r][c] = 2;           // -1 means alive become dead
                        }
                    }
                    else
                    {
                        if (!isStillDead(board, r, c))
                        {
                            board[r][c] = -1;            // 2 means dead become to alive
                        }
                    }

                }
            }


            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    if (board[r][c] == 2)
                    {
                        board[r][c] = 0;
                    }

                    if (board[r][c] == -1)
                    {
                        board[r][c] = 1;
                    }
                }
            }
        }
    };
} // namespace p_289

/*
# Problem:
https://leetcode.com/problems/game-of-life/

## HINT:
* Count the alive neighbor of each position and change it to temporary value.
* Change to temporary value insteal of 0 and 1 to do in-place changing.
* Change the value from 0 to -1 means it will become 1 after all processes. -1 is convenient for comparsion becuase it is also smaller than 0.
* Change the value form 1 to 2 means it will become 0 after all processes. 2 is convenient for comparison because it is also bigger than 1.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(1)
*/