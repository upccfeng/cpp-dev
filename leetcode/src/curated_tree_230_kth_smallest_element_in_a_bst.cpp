#include "treenode.hpp"
#include <vector>

namespace p_curated_tree_230_kth_smallest_element_in_a_bst
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

        void inorderTraverseWithCount(TreeNode* root, int k, int& cnt, int& value)
        {
            if (root == nullptr)
            {
                return;
            }

            inorderTraverseWithCount(root->left, k, cnt, value);
            ++cnt;
            if (cnt == k)
            {
                value = root->val;
            }

            inorderTraverseWithCount(root->right, k, cnt, value);
        }
    public:

        int kthSmallestInorder(TreeNode* root, int k)
        {
            std::vector<int> inorder;
            inorderTraverse(root, inorder);

            for (int i = 0; i < inorder.size(); ++i)
            {
                if (i == k - 1)
                {
                    return inorder[i];
                }
            }

            return -1;
        }

        int kthSmallestCount(TreeNode* root, int k)
        {
            int value = -1;
            int cnt = 0;
            inorderTraverseWithCount(root, k, cnt, value);

            return value;
        }

        int kthSmallest(TreeNode* root, int k)
        {
            return kthSmallestCount(root, k);
        }
    };
} // namespace p_curated_tree_230_kth_smallest_element_in_a_bst

/*
# Problem:
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

## HINT:
* Use Inorder Traversal and store each element in a vector
* Return ith value in vector
* Method-2: In Inorder Traversal, use a cnt to record what is the current sequence.
*           If the sequence is k, store it into value.

## Time Complexity:
BigO(n)

## Space Complexity:
Method-1: BigO(n)
Method-2: BigO(Height)
*/