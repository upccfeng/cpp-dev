#include <vector>
#include <string>

namespace p_curated_matrix_79_word_search
{
    class Solution
    {
        bool isOutOfBoundary(const std::vector<std::vector<char>>& board, int r, int c)
        {
            if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            {
                return true;
            }

            return false;
        }

        bool isMatch(const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, const std::string& word, int taking, int r, int c)
        {
            if (taking == word.size())
            {
                return true;
            }

            if (isOutOfBoundary(board, r, c) || visited[r][c])
            {
                return false;
            }

            if (board[r][c] != word[taking])
            {
                return false;
            }
            else
            {
                bool ret = false;
                visited[r][c] = true;

                ret |= isMatch(board, visited, word, taking + 1, r + 1, c);
                ret |= isMatch(board, visited, word, taking + 1, r - 1, c);
                ret |= isMatch(board, visited, word, taking + 1, r, c + 1);
                ret |= isMatch(board, visited, word, taking + 1, r, c - 1);

                visited[r][c] = false;
                return ret;
            }
        }

    public:
        bool exist(std::vector<std::vector<char>>& board, std::string word)
        {
            int ROWS = board.size();
            int COLS = board[0].size();
            std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

            for (int r = 0; r < ROWS; ++r)
            {
                for (int c = 0; c < COLS; ++c)
                {
                    if (isMatch(board, visited, word, 0, r, c))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    };
} // namespace p_curated_matrix_79_word_search

/*
# Problem:
https://leetcode.com/problems/word-search/

## HINT:
* For each element in grid, use dfs to find is matched or not.
* No cache solution.

## Time Complexity:
BigO(n * m * dfs) = BigO(n * m * 4^word.length), for each char in word has 4 branches, and it will take word.length times.

## Space Complexity:
BigO(n * m)
*/