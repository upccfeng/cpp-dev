namespace p_116
{
    // TODO: Implement the NodeHelper for test cases.
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

        Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };

    class Solution
    {
        void dfs(Node* father, Node* node, bool is_left)
        {
            if (node == nullptr)
            {
                return;
            }

            if (father == nullptr)
            {
                node->next = nullptr;
                dfs(node, node->right, false);
                dfs(node, node->left, true);
            }
            else
            {
                if (!is_left)
                {
                    if (father->next == nullptr)
                    {
                        node->next = nullptr;
                    }
                    else
                    {
                        node->next = father->next->left;
                    }
                }
                else
                {
                    node->next = father->right;
                }

                dfs(node, node->right, false);
                dfs(node, node->left, true);
            }
        }

    public:
        Node* connect(Node* root) {
            dfs(nullptr, root, false);

            return root;
        }
    };
} // namespace p_116

/*
# Problem:
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

## HINT:
* Order: mid-right-left
* The next of right will be the left of father's next.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/