#include "treenode.hpp"

namespace p_101
{
    class Solution
    {

        bool isSymmetricTheSame(TreeNode* root_1, TreeNode* root_2)
        {
            if (root_1 == nullptr && root_2 == nullptr)
            {
                return true;
            }

            if (root_1 == nullptr || root_2 == nullptr)
            {
                return false;
            }

            if (root_1->val == root_2->val)
            {
                return isSymmetricTheSame(root_1->left, root_2->right) && isSymmetricTheSame(root_1->right, root_2->left);
            }
            else
            {
                return false;
            }
        }

    public:
        bool isSymmetric(TreeNode* root)
        {
            return isSymmetricTheSame(root->left, root->right);
        }
    };
} // namespace p_101

/*
# Problem:
https://leetcode.com/problems/symmetric-tree/

## HINT:
* Symmetric means the roots should be the same.
* The left of root_1 should be the same as the right of root_2.
* The right of root_1 should be the same as the left of root_2.

## Time Complexity:
BigO(Height)

## Space Complexity:
BigO(Height)
*/