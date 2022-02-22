#include <vector>
#include <set>

namespace graph
{
    class Node {
    public:
        int val;
        std::vector<Node*> neighbors;

        Node();
        Node(int _val);
        Node(int _val, std::vector<Node*> _neighbors);

        static Node* create(std::vector<std::vector<int>>);
        static void delete_graph(Node* head);
    };
}