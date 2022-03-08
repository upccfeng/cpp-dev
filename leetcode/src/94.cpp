#include "treenode.hpp"
#include <vector>

namespace p_94
{
    class Solution
    {
        void dfs(TreeNode* root, std::vector<int>& ret)
        {
            if (root == nullptr)
            {
                return;
            }

            dfs(root->left, ret);
            ret.emplace_back(root->val);
            dfs(root->right, ret);
        }

    public:
        std::vector<int> inorderTraversal(TreeNode* root) {
            std::vector<int> ret;

            dfs(root, ret);

            return ret;
        }
    };
} // namespace p_94

/*
# Problem:
https://leetcode.com/problems/binary-tree-inorder-traversal/

## HINT:
* left-mid-right

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/