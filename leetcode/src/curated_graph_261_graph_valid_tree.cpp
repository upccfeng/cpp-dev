#include "assert.h"
#include <vector>
#include <set>
#include <unordered_map>

namespace p_curated_graph_261_graph_valid_tree
{
    class Solution
    {
        bool isValid(std::unordered_map<int, std::set<int>>& graph, std::vector<bool>& visited, int taking, int father, int& cnt)
        {
            if (visited[taking])
            {
                return false;
            }

            visited[taking] = true;
            cnt++;

            bool is_valid = true;
            for (auto next : graph[taking])
            {
                if (next != father)
                {
                    is_valid &= isValid(graph, visited, next, taking, cnt);

                    if (!is_valid)
                    {
                        break;
                    }
                }
            }

            return is_valid;
        }
    public:
        bool validTree(int n, std::vector<std::vector<int>>& edges)
        {
            std::unordered_map<int, std::set<int>> graph;

            for (auto& e : edges)
            {
                graph[e[0]].insert(e[1]);
                graph[e[1]].insert(e[0]);
            }

            std::vector<bool> visited(n, false);

            int cnt = 0;
            bool is_valid = isValid(graph, visited, 0, -1, cnt);

            return is_valid && cnt == n;
        }
    };
} // namespace p_curated_graph_261_graph_valid_tree

/*
# Problem:
https://leetcode.com/problems/graph-valid-tree/

## HINT:
* Detect loop in graph

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/