#include "graph.hpp"

#include <unordered_map>

namespace p_curated_graph_133_clone_graph
{
    class Solution
    {
        Node* clone_and_get(Node* taking, std::unordered_map<Node*, Node*>& oldToNew)
        {
            if (oldToNew.find(taking) != oldToNew.end())
            {
                return oldToNew[taking];
            }

            Node* copy = new Node(taking->val);
            oldToNew[taking] = copy;

            for (auto nei : taking->neighbors)
            {
                copy->neighbors.emplace_back(clone_and_get(nei, oldToNew));
            }

            return copy;
        }

    public:
        Node* cloneGraph(Node* node)
        {
            std::unordered_map<Node*, Node*> oldToNew;

            return node != nullptr ? clone_and_get(node, oldToNew) : nullptr;
        }
    };
} // namespace p_curated_graph_133_clone_graph

/*
# Problem:
https://leetcode.com/problems/clone-graph/

## HINT:
* Use a Hash Map to mapping from old node to new node.
* Clone the taking node and it's neighbors. And make connections between taking node and neighbors.
* Need to handle nullptr case.

## Time Complexity:
BigO(E+V), Edge + Vertex -> BigO(n)

## Space Complexity:
BigO(n)
*/