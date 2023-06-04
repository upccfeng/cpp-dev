#include "treenode.hpp"

namespace p_curated_tree_572_subtree_of_another_tree
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

        void dfsRoot(TreeNode* root, TreeNode* subRoot, bool& ret)
        {
            if (root == nullptr)
            {
                return;
            }

            ret |= isTheSame(root, subRoot);

            dfsRoot(root->left, subRoot, ret);
            dfsRoot(root->right, subRoot, ret);
        }

    public:
        bool isSubtree(TreeNode* root, TreeNode* subRoot)
        {
            bool ret = false;
            dfsRoot(root, subRoot, ret);

            return ret;
        }
    };
} // namespace p_curated_tree_572_subtree_of_another_tree

/*
# Problem:
https://leetcode.com/problems/subtree-of-another-tree/

## HINT:
* Dfs the root.
* For each element in root, compare the element and the subTree.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n + m)
*/