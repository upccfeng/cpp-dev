#include <vector>
#include <string>

namespace p_curated_tree_208_implement_trie_or_prefix_tree
{
    class Trie {
        class Node
        {
        public:
            char value;
            std::vector<Node*> nexts;
            bool is_end;

            Node(char value) : value(value), nexts(26, nullptr), is_end(false) {}

            Node() : value('#'), nexts(26, nullptr), is_end(false) {}
        };

        Node* head;

        std::pair<Node*, int> findRoot(std::string& word)
        {
            Node* taking = head;

            int pos = 0;

            for (pos = 0; pos < word.size(); ++pos)
            {
                char& c = word[pos];
                if (taking->nexts[c - 'a'] != nullptr)
                {
                    taking = taking->nexts[c - 'a'];
                }
                else
                {
                    break;
                }
            }

            return { taking, pos };
        }

    public:
        Trie() {
            head = new Node();
        }

        void insert(std::string word)
        {
            std::pair<Node*, int> root_pos = findRoot(word);

            Node* taking = root_pos.first;
            for (int pos = root_pos.second; pos < word.size(); ++pos)
            {
                char c = word[pos];
                Node* new_node = new Node(c);

                taking->nexts[c - 'a'] = new_node;
                taking = new_node;
            }

            taking->is_end = true;
        }

        bool search(std::string word)
        {
            std::pair<Node*, int> root_pos = findRoot(word);

            return root_pos.second == word.size() && root_pos.first->is_end;
            //    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            //    Make sure there is no char left.
        }

        bool startsWith(std::string prefix)
        {
            std::pair<Node*, int> root_pos = findRoot(prefix);

            bool is_more = false;

            if (root_pos.second == prefix.size()) // Make sure there is no char left.
            {
                for (auto e : root_pos.first->nexts)
                {
                    if (e != nullptr)
                    {
                        is_more = true;
                    }
                }

                return root_pos.first->is_end || is_more;
            }
            else
            {
                return false;
            }
        }
    };
} // namespace p_curated_tree_208_implement_trie_or_prefix_tree

/*
# Problem:
https://leetcode.com/problems/implement-trie-prefix-tree/

## HINT:
* Use a structure to store the valid next char.
* Do not forget the case which is just partial matched when Search0 and startsWith
* Use map to speed up.

## Time Complexity:
Insert: BigO(n)
Search: BigO(n)
StartWith: BigO(n)

## Space Complexity:
BigO(n * 26)
*/