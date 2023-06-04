#include "treenode.hpp"

namespace p_curated_tree_104_maximum_depth_of_binary_tree
{
    class Solution
    {
        int getDepth(TreeNode* root)
        {
            if (root)
            {
                return std::max(1 + getDepth(root->left), 1 + getDepth(root->right));
            }
            else
            {
                return 0;
            }
        }

    public:
        int maxDepth(TreeNode* root)
        {
            return getDepth(root);
        }
    };
} // namespace p_curated_tree_104_maximum_depth_of_binary_tree

/*
# Problem:
https://leetcode.com/problems/maximum-depth-of-binary-tree/

## HINT:
* For each node, the depth is max(left + 1, right + 1)

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(Heigh)
*/