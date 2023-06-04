#include <vector>
#include <string>
#include <set>
#include <unordered_map>

namespace p_curated_tree_212_word_search_ii
{
    class Solution
    {
    public:
        class Node
        {
        public:
            std::unordered_map<char, Node*> nexts_map;
            bool is_end;
            std::string word;

            Node(char value) : is_end(false), word("") {}

            Node() : is_end(false), word("") {}

            ~Node() {
                for (auto& c : nexts_map)
                {
                    delete c.second;
                }
            }
        };

        class WordDictionary {
        public:
            Node* head;

            WordDictionary() {
                head = new Node();
            }

            ~WordDictionary() {
                delete head;
            }

            void addWord(std::string& word)
            {
                Node* taking = head;

                for (char c : word)
                {
                    if (taking->nexts_map.find(c) == taking->nexts_map.end())
                    {
                        taking->nexts_map[c] = new Node(c);
                        taking = taking->nexts_map[c];
                    }
                    else
                    {
                        taking = taking->nexts_map[c];
                    }
                }

                taking->word = std::move(word);
                taking->is_end = true;
            }
        };

        void dfs(Node* root, std::vector<std::string>& ret, std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& used, int row, int col)
        {
            int ROWS = board.size();
            int COLS = board[0].size();
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS ||
                used[row][col] == true)
            {
                return;
            }

            char c = board[row][col];

            if (root->nexts_map.find(c) == root->nexts_map.end())
            {
                return;
            }

            used[row][col] = true;

            if (root->nexts_map[c]->is_end == true)
            {
                ret.emplace_back(root->nexts_map[c]->word);
                root->nexts_map[c]->is_end = false;         // avoid duplicate case.
            }

            dfs(root->nexts_map[c], ret, board, used, row - 1, col);
            dfs(root->nexts_map[c], ret, board, used, row + 1, col);
            dfs(root->nexts_map[c], ret, board, used, row, col - 1);
            dfs(root->nexts_map[c], ret, board, used, row, col + 1);

            used[row][col] = false;
        }

        std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
        {
            WordDictionary  wd;
            for (auto& s : words)
            {
                wd.addWord(s);
            }

            int ROWS = board.size();
            int COLS = board[0].size();

            std::vector<std::string> ret;
            std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size(), false));

            for (int r = 0; r < ROWS; ++r)
            {
                for (int c = 0; c < COLS; ++c)
                {
                    dfs(wd.head, ret, board, used, r, c);
                }
            }

            return ret;
        }
    };
} // namespace p_curated_tree_212_word_search_ii

/*
# Problem:
https://leetcode.com/problems/word-search-ii/

## HINT:
* Use Trie structure
* Add word in words into Trie
* For each node in the grid, use dfs to traverse the node to know is there any word in Trie.

## Time Complexity:
BigO(n * m * 4^BiggestWord)

## Space Complexity:
BigO(n * m + Word)
*/