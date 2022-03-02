#include "treenode.hpp"

namespace p_curated_tree_98_validate_bindary_search_tree
{
    class Solution
    {
        void inorderTraverse(TreeNode* root, std::vector<int>& inorder)
        {
            if (root == nullptr)
            {
                return;
            }

            inorderTraverse(root->left, inorder);
            inorder.push_back(root->val);
            inorderTraverse(root->right, inorder);
        }

        bool isBst(TreeNode* root, long long left_boundary, long long right_boundary)
        {
            if (root == nullptr)
            {
                return true;
            }


            if (root->val <= left_boundary || root->val >= right_boundary)
            {
                return false;
            }

            return isBst(root->left, left_boundary, root->val) && isBst(root->right, root->val, right_boundary);
        }

    public:
        bool isValidBSTVector(TreeNode* root)
        {
            std::vector<int> inorder;
            inorderTraverse(root, inorder);

            bool ret = true;
            int pre = inorder[0];
            for (int i = 1; i < inorder.size(); ++i)
            {
                if (inorder[i] <= pre)
                {
                    return false;
                }
                pre = inorder[i];
            }

            return ret;
        }

        bool isValidBSTBoundary(TreeNode* root)
        {
            return isBst(root, LLONG_MIN, LLONG_MAX);
        }
        bool isValidBST(TreeNode* root)
        {
            return isValidBSTBoundary(root);
        }
    };
} // namespace p_curated_tree_98_validate_bindary_search_tree

/*
# Problem:
https://leetcode.com/problems/validate-binary-search-tree/

## HINT:
* Inorder Traversal can check the order, and determine that is it BST or not
* Method-2: Use left and right boundary for each subtree.
*           Need to handle the INT_MAX and INT_MIN case.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/