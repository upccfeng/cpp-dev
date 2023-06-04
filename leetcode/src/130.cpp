#include <vector>

namespace p_130
{
    class Solution
    {
        void markLinkedO(std::vector<std::vector<char>>& board/*, std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& o_board*/, int r, int c)
        {
            if (r < 0 || r >= board.size() ||
                c < 0 || c >= board[0].size() ||
                board[r][c] == 'X')
            {
                return;
            }

            //if (visited[r][c] || o_board[r][c] == 'O')
            if (board[r][c] == '#')
            {
                return;
            }

            board[r][c] = '#';
            //visited[r][c] = true;
            //o_board[r][c] = 'O';

            markLinkedO(board/*, visited, o_board*/, r - 1, c);
            markLinkedO(board/*, visited, o_board*/, r + 1, c);
            markLinkedO(board/*, visited, o_board*/, r, c - 1);
            markLinkedO(board/*, visited, o_board*/, r, c + 1);

            //visited[r][c] = false;
        }

    public:
        void solve(std::vector<std::vector<char>>& board)
        {
            int ROWS = board.size();
            int COLS = board[0].size();

            //std::vector<std::vector<char>> o_board(ROWS, std::vector<char>(COLS, 'X'));
            //std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

            for (int r : {0, ROWS - 1})
            {
                for (int c = 0; c < COLS; c++)
                {
                    if (board[r][c] == 'O')
                    {
                        markLinkedO(board/*, visited, o_board*/, r, c);
                    }
                }
            }

            for (int c : {0, COLS - 1})
            {
                for (int r = 0; r < ROWS; r++)
                {
                    if (board[r][c] == 'O')
                    {
                        markLinkedO(board/*, visited, o_board*/, r, c);
                    }
                }
            }

            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    if (board[r][c] == '#')
                    {
                        board[r][c] = 'O';
                    }
                    else
                    {
                        board[r][c] = 'X';
                    }
                    //board[r][c] = o_board[r][c];
                }
            }
        }
    };
} // namespace p_130

/*
# Problem:
https://leetcode.com/problems/surrounded-regions/

## HINT:
* From bound to mark the adjacent 'O'.

## Time Complexity:
BigO((n + m) * 4^(n*m))

## Space Complexity:
BigO(1)
*/