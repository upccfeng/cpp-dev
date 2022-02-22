#include "graph.hpp"

namespace graph
{
    Node::Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    };

    Node::Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    };

    Node::Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    };

    Node* Node::create(std::vector<std::vector<int>> adjlist)
    {
        Node* head = nullptr;

        std::vector<Node*> all(adjlist.size() + 1);

        for (int i = 1; i < adjlist.size() + 1; ++i)
        {
            all[i] = new Node(i);
        }

        for (int i = 1; i < adjlist.size() + 1; ++i)
        {
            std::vector<Node*> neighs(adjlist[i - 1].size());

            for (int n = 0; n < adjlist[i - 1].size(); ++n)
            {
                neighs[n] = all[adjlist[i - 1][n]];
            }

            all[i]->neighbors = neighs;
        }

        return all[1];
    }

    void dfs(Node* taking, std::set<Node*>& discovered)
    {
        if (discovered.find(taking) == discovered.end())
        {
            discovered.insert(taking);

            for (auto nei : taking->neighbors)
            {
                dfs(nei, discovered);
            }
        }
    }

    void Node::delete_graph(Node* head)
    {
        std::set<Node*> discovered;

        dfs(head, discovered);

        for (auto node : discovered)
        {
            delete node;
        }
    }
}
