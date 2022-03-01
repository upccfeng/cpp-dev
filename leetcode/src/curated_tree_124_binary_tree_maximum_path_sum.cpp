#include "treenode.hpp"

namespace p_curated_tree_124_binary_tree_maximum_path_sum
{
    class Solution
    {
        int getMaxSum(TreeNode* root, int& max)
        {
            if (root == nullptr)
            {
                return 0;
            }

            int left = getMaxSum(root->left, max);
            int right = getMaxSum(root->right, max);
            int sub_max = std::max(left, right);

            max = std::max(max, root->val + left + right); // from left to right, or right to left
            max = std::max(max, root->val + sub_max);      // left or right
            max = std::max(max, root->val);                // node only

            if (sub_max <= 0)
            {
                return root->val;
            }
            else
            {
                return root->val + sub_max;
            }
        }
    public:
        int maxPathSum(TreeNode* root)
        {
            int ret = root->val;

            int _ = getMaxSum(root, ret);

            return ret;
        }
    };
} // namespace p_curated_tree_124_binary_tree_maximum_path_sum

/*
# Problem:
https://leetcode.com/problems/binary-tree-maximum-path-sum/

## HINT:
* Given a Tree, the max happens in tree case:
* - Case-1: From left to right, or right to left
* - Case-2: From parent and go to one of left or right
* - Case-3: Just the root.
* Each root, return the max of one of left or right or the root only.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(Height)
*/