#include <vector>
#include <set>
#include <memory>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node();
    Node(int _val);
    Node(int _val, std::vector<Node*> _neighbors);
};

class GraphHelper {
private:
    static void dfs_discover(Node* taking, std::set<Node*>& discovered, std::set<std::pair<Node*, Node*>>& edges);

public:
    static Node* create(std::vector<std::vector<int>>);
    static void remove(Node* head);
    static bool compare(Node* lhs, Node* rhs);
    static bool compare(Node* lhs, std::vector<std::vector<int>> rhs_v);
};