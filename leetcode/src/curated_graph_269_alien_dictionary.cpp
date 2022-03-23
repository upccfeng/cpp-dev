#include "assert.h"
#include <string>
#include <sstream>
#include <set>
#include <unordered_set>
#include <unordered_map>

namespace p_curated_graph_269_alien_dictionary
{
    class Solution
    {
        int getDiffPos(const std::string& lhs, const std::string& rhs)
        {
            int i = 0;

            for (i; i < lhs.size(); i++)
            {
                if (i == rhs.size() || lhs[i] != rhs[i])
                {
                    return i;
                }
            }

            return i;
        }

        bool dfsPostOrder(std::unordered_map<char, std::set<char>>& graph, std::unordered_map<char, bool>& visited, std::unordered_set<char>& path_set, std::vector<char>& path, char taking)
        {
            if (visited[taking])
            {
                return true;
            }

            visited[taking] = true;

            for (auto next : graph[taking])
            {
                if (dfsPostOrder(graph, visited, path_set, path, next))
                {
                    return true;
                }
            }
            visited[taking] = false;

            if (path_set.find(taking) == path_set.end())
            {
                path.push_back(taking);
                path_set.insert(taking);
            }

            return false;
        }

    public:
        std::string alienOrder(std::vector<std::string>& words)
        {
            std::unordered_map<char, std::set<char>> graph;

            for (auto& s : words)
            {
                for (int i = 0; i < s.size(); i++)
                {
                    graph[s[i]]; // if exist, do nothing, otherwise init
                }
            }

            for (int i = 1; i < words.size(); i++) // just compare i and i+1 instead of i for i+1, i+2, ..., n
            {
                auto& word1 = words[i - 1];
                auto& word2 = words[i];

                if (word1 == word2)
                {
                    continue;
                }

                int pos = getDiffPos(word1, word2);

                if (pos < word1.size() && pos < word2.size())
                {
                    char fc = word1[pos];
                    char sc = word2[pos];

                    assert(fc != sc);
                    graph[fc].insert(sc);
                }
                else if (pos < word1.size())
                {
                    return "";
                }
                else
                {
                    continue;
                }
            }

            std::unordered_map<char, bool> visited;

            for (auto& kv : graph)
            {
                visited[kv.first] = false;
            }

            std::vector<char> path;
            std::unordered_set<char> path_set;

            for (auto& kv : graph)
            {
                if (dfsPostOrder(graph, visited, path_set, path, kv.first)) // Post-order dfs guarantees the father(previous char) will appear after all children(following char).
                {
                    return "";
                }
            }

            std::stringstream ss;
            for (int i = path.size() - 1; i >= 0; i--)
            {
                ss << path[i];
            }

            return ss.str();
        }
    };
} // namespace p_curated_graph_269_alien_dictionary

/*
# Problem:
https://leetcode.com/problems/alien-dictionary/

## HINT:
* Use graphic concept.
* Use post-order dfs to get the reverse sequence.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(26)
*/