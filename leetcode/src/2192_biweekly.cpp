#include <unordered_map>
#include <vector>
#include <set>

namespace p_2192_biweekly
{
    class Solution
    {

        void dfs(std::unordered_map<int, std::set<int>>& graph, std::vector<std::vector<int>>& ret, std::vector<bool>& visited, int taking, int anc)
        {
            if (visited[taking])
            {
                return;
            }

            visited[taking] = true;

            for (int n : graph[taking])
            {
                if (!visited[n])
                {
                    ret[n].push_back(anc);

                    dfs(graph, ret, visited, n, anc);
                }
            }
        }

    public:
        std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges)
        {
            std::unordered_map<int, std::set<int>> graph;

            for (auto& e : edges)
            {
                graph[e[0]].insert(e[1]);
            }

            std::vector<std::vector<int>> ret(n);

            for (int i = 0; i < n; i++)
            {
                std::vector<bool> vistied(n, false);

                dfs(graph, ret, vistied, i, i);
            }


            return ret;
        }
    };
} // namespace p_2192_biweekly

/*
# Problem:
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

## HINT:
* Go through from parent to leaf and construct ret instead of go dfs each leaf to get all parents.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/