#include "treenode.hpp";
#include <vector>

namespace p_108
{
    class Solution
    {
        TreeNode* createBstTree(const std::vector<int>& nums, int start, int end)
        {
            if (start > end)
            {
                return nullptr;
            }

            int mid = (start + end) / 2;

            TreeNode* root = new TreeNode(nums[mid]);

            root->left = createBstTree(nums, start, mid - 1);
            root->right = createBstTree(nums, mid + 1, end);

            return root;
        }
    public:
        TreeNode* sortedArrayToBST(std::vector<int>& nums)
        {
            return createBstTree(nums, 0, nums.size() - 1);
        }
    };
} // namespace p_108

/*
# Problem:
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

## HINT:
* The mid of array will be the root, the left will be left tree, and the right will be right tree.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(Height)
*/