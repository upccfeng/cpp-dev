#include "graph.hpp"

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

Node* GraphHelper::create(std::vector<std::vector<int>> adjlist)
{
    if (adjlist.size() == 0)
    {
        return nullptr;
    }

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

void GraphHelper::dfs_discover(Node* taking, std::set<Node*>& discovered, std::set<std::pair<Node*, Node*>>& edges)
{
    if (taking == nullptr)
    {
        return;
    }

    if (discovered.find(taking) == discovered.end())
    {
        discovered.insert(taking);

        for (auto nei : taking->neighbors)
        {
            edges.insert({ taking, nei });
            dfs_discover(nei, discovered, edges);
        }
    }
}

void GraphHelper::remove(Node* head)
{
    std::set<Node*> discovered;
    std::set<std::pair<Node*, Node*>> edges;

    dfs_discover(head, discovered, edges);

    for (auto node : discovered)
    {
        delete node;
    }
}

bool GraphHelper::compare(Node* lhs, Node* rhs)
{
    std::set<Node*> lhs_discovered;
    std::set<std::pair<Node*, Node*>> lhs_edges;

    dfs_discover(lhs, lhs_discovered, lhs_edges);

    std::set<Node*> rhs_discovered;
    std::set<std::pair<Node*, Node*>> rhs_edges;

    dfs_discover(rhs, rhs_discovered, rhs_edges);

    if (lhs_discovered.size() != rhs_discovered.size() || lhs_edges.size() != rhs_edges.size())
    {
        return false;
    }

    for (auto l_e : lhs_discovered)
    {
        bool is_found = false;
        for (auto r_e : rhs_discovered)
        {
            if (l_e->val == r_e->val)
            {
                is_found = true;
                break;
            }
        }

        if (!is_found)
        {
            return false;
        }
    }

    for (auto l_e : lhs_edges)
    {
        bool is_found = false;
        for (auto r_e : rhs_edges)
        {
            if (l_e.first->val == r_e.first->val && l_e.second->val == r_e.second->val)
            {
                is_found = true;
                break;
            }
        }

        if (!is_found)
        {
            return false;
        }
    }

    return true;
}

bool GraphHelper::compare(Node* lhs, std::vector<std::vector<int>> rhs_v)
{
    std::shared_ptr<Node> rhs = std::shared_ptr<Node>(GraphHelper::create(rhs_v), GraphHelper::remove);
    return compare(lhs, rhs.get());
}