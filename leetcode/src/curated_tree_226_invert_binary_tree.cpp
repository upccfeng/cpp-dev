#include "treenode.hpp"

namespace p_curated_tree_226_invert_binary_tree
{
    class Solution
    {
        void invert(TreeNode* root)
        {
            if (root == nullptr)
            {
                return;
            }

            invert(root->left);
            invert(root->right);

            std::swap(root->left, root->right);
        }

    public:
        TreeNode* invertTree(TreeNode* root)
        {
            invert(root);

            return root;
        }
    };
} // namespace p_curated_tree_226_invert_binary_tree

/*
# Problem:
https://leetcode.com/problems/invert-binary-tree/

## HINT:
* For each root, invert the left tree and right tree.
* Change the link between left and right after inverting.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(Height)
*/