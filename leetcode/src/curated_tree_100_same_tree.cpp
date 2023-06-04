#include "treenode.hpp"

namespace p_curated_tree_100_same_tree
{
    class Solution
    {
        bool isTheSame(TreeNode* p, TreeNode* q)
        {
            if (p != nullptr && q != nullptr)
            {
                if (p->val != q->val)
                {
                    return false;
                }
                else
                {
                    return isTheSame(p->left, q->left) && isTheSame(p->right, q->right);
                }
            }
            else
            {
                if (p == nullptr && q == nullptr)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    public:
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            return isTheSame(p, q);
        }
    };
} // namespace p_curated_tree_100_same_tree

/*
# Problem:
https://leetcode.com/problems/same-tree/

## HINT:
* For comparison of two trees, return the isTheSame(tree1->left, tree2->left) && isTheSame(tree1->right, tree2->right) if tree1->val == tree2->val else false

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(Height)
*/