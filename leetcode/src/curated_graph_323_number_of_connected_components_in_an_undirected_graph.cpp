#include "assert.h"
#include <vector>
#include <set>
#include <stack>

namespace p_curated_graph_323_number_of_connected_components_in_an_undirected_graph
{
    class Solution
    {
        void dfs(std::vector<std::set<int>>& graph, std::vector<bool>& visited, int taking, int father)
        {
            if (visited[taking])
            {
                return;
            }

            visited[taking] = true;

            for (auto next : graph[taking])
            {
                if (next != father)
                {
                    dfs(graph, visited, next, taking);
                }
            }

        }

    public:
        int countComponentsRecursive(int n, std::vector<std::vector<int>>& edges)
        {
            std::vector<std::set<int>> graph(n);

            for (auto& e : edges)
            {
                graph[e[0]].insert(e[1]);
                graph[e[1]].insert(e[0]);
            }

            std::vector<bool> visited(n, false);

            int ret = 0;
            for (int i = 0; i < visited.size(); i++)
            {
                if (!visited[i])
                {
                    dfs(graph, visited, i, -1);
                    ret++;
                }
            }

            return ret;
        }

        int countComponentsNoneRecursive(int n, std::vector<std::vector<int>>& edges)
        {
            std::vector<std::set<int>> graph(n);

            for (auto& e : edges)
            {
                graph[e[0]].insert(e[1]);
                graph[e[1]].insert(e[0]);
            }

            std::vector<bool> visited(n, false);

            std::stack<std::pair<int, int>> stack;
            int ret = 0;

            for (int i = 0; i < visited.size(); i++)
            {
                if (!visited[i])
                {
                    assert(stack.empty());
                    stack.push({ i, -1 });

                    while (!stack.empty())
                    {
                        std::pair<int, int> taking = stack.top();
                        stack.pop();

                        if (visited[taking.first])
                        {
                            continue;
                        }

                        visited[taking.first] = true;

                        for (auto next : graph[taking.first])
                        {
                            if (next != taking.second)
                            {
                                stack.push({ next, taking.first });
                            }
                        }
                    }

                    ret++;
                }
            }

            return ret;
        }

        int countComponents(int n, std::vector<std::vector<int>>& edges)
        {
            return countComponentsNoneRecursive(n, edges);
        }
    };
} // namespace p_curated_graph_323_number_of_connected_components_in_an_undirected_graph

/*
# Problem:
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

## HINT:
* For none-recursive one, if visited, just continue instead of break.
* For none-recursive one, need to use pair to record the taking's father.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/