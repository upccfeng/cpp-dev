#include <string>
#include <vector>
#include <unordered_map>

namespace p_curated_tree_211_design_add_and_search_words_data_structure
{
    class Node
    {
    public:
        std::unordered_map<char, Node*> nexts_map;
        //std::vector<Node*> nexts;
        bool is_end;

        Node(char value) : /*nexts(26, nullptr),*/ is_end(false) {}

        Node() : /*nexts(26, nullptr),*/ is_end(false) {}

        ~Node() {
            //for (auto c : nexts)
            //{
            //    if (c != nullptr)
            //    {
            //        delete c;
            //    }
            //}

            for (auto& c : nexts_map)
            {
                delete c.second;
            }
        }
    };

    class WordDictionary {
        Node* head;

    public:
        WordDictionary() {
            head = new Node();
        }

        ~WordDictionary() {
            delete head;
        }

        void addWord(std::string word)
        {
            Node* taking = head;

            for (char c : word)
            {
                //if (taking->nexts[c - 'a'] == nullptr)
                //{
                //    taking->nexts[c - 'a'] = new Node(c);
                //    taking = taking->nexts[c - 'a'];
                //}
                //else
                //{
                //    taking = taking->nexts[c - 'a'];
                //}

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

            taking->is_end = true;
        }

        bool isMatch(const std::string& word, Node* root, int pos)
        {
            const char& c = word[pos];

            if (pos == word.size())
            {
                return root->is_end;
            }

            if (c == '.')
            {
                //for (auto child : root->nexts)
                //{
                //    if (child != nullptr && isMatch(word, child, pos + 1))
                //    {
                //        return true;
                //    }
                //}

                for (auto child_kv : root->nexts_map)
                {
                    if (isMatch(word, child_kv.second, pos + 1))
                    {
                        return true;
                    }
                }

                return false;
            }
            else
            {
                //if (root->nexts[c - 'a'] != nullptr)
                //{
                //    return isMatch(word, root->nexts[c - 'a'], pos + 1);
                //}
                //else
                //{
                //    return false;
                //}

                if (root->nexts_map.find(c) != root->nexts_map.end())
                {
                    return isMatch(word, root->nexts_map[c], pos + 1);
                }
                else
                {
                    return false;
                }
            }
        }

        bool search(std::string word)
        {
            return isMatch(word, head, 0);
        }
    };
} // namespace p_curated_tree_211_design_add_and_search_words_data_structure

/*
# Problem:
https://leetcode.com/problems/design-add-and-search-words-data-structure/

## HINT:
* Use Trie.
* Mark the node which is the end of a word.

## Time Complexity:
Insert: BigO(n)
Search: BigO(n)

## Space Complexity:
BigO(Height) for Insert and Search.
*/