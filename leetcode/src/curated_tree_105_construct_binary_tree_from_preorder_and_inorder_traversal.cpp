#include "assert.h"
#include "treenode.hpp"
#include <vector>

namespace p_curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal
{
    class Solution
    {
        int getPos(const std::vector<int>& preorder, int target)
        {
            for (int i = 0; i < preorder.size(); ++i)
            {
                if (preorder[i] == target)
                {
                    return i;
                }
            }

            assert(false);
            return -1;
        }

        std::pair<std::pair<int, int>, std::pair<int, int>> getBound(std::vector<int>& inorder, int target, int left_boundary, int right_boundary, int& inorder_pos)
        {
            for (int i = left_boundary; i <= right_boundary; ++i)
            {
                if (inorder[i] == target)
                {
                    inorder_pos = i;
                    return { { left_boundary, i - 1 }, { i + 1, right_boundary } };
                }
            }

            inorder_pos = -1;
            return { { -1, -1 }, { -1, -1 } };
        }

        //std::pair<int, int> getLeftBound(std::vector<int>& inorder, int target, int left_boundary, int right_boundary)
        //{
        //    for (int i = left_boundary; i <= right_boundary; ++i)
        //    {
        //        if (inorder[i] == target)
        //        {
        //            return { left_boundary, i - 1 };
        //        }
        //    }
        //
        //    return { -1, -1 };
        //}
        //
        //std::pair<int, int> getRightBound(std::vector<int>& inorder, int target, int left_boundary, int right_boundary)
        //{
        //    for (int i = left_boundary; i <= right_boundary; ++i)
        //    {
        //        if (inorder[i] == target)
        //        {
        //            return { i + 1, right_boundary };
        //        }
        //    }
        //
        //    return { -1, -1 };
        //}

        TreeNode* createTree(std::vector<int>& preorder, int pre_left, int pre_right, std::vector<int>& inorder, int in_left, int in_right)
        {
            if (pre_left > pre_right)
            {
                return nullptr;
            }

            int root_val = preorder[pre_left];
            TreeNode* root = new TreeNode(root_val);

            if (pre_left == pre_right)
            {
                return root;
            }

            int inorder_pos;                                        // int inorder_pos = getPos(inorder, root_val);
            std::pair<std::pair<int, int>, std::pair<int, int>> in_bound = getBound(inorder, root_val, in_left, in_right, inorder_pos);
            std::pair<int, int>& in_left_bound = in_bound.first;    // getLeftBound(inorder, root_val, in_left, in_right);
            std::pair<int, int>& in_right_bound = in_bound.second;  // getRightBound(inorder, root_val, in_left, in_right);

            std::pair<int, int> pre_left_bound = { pre_left + 1, pre_left + 1 + in_left_bound.second - in_left_bound.first };
            std::pair<int, int> pre_right_bound = { pre_left + 1 + in_left_bound.second - in_left_bound.first + 1, pre_right };

            root->left = createTree(preorder, pre_left_bound.first, pre_left_bound.second, inorder, in_left_bound.first, in_left_bound.second);
            root->right = createTree(preorder, pre_right_bound.first, pre_right_bound.second, inorder, in_right_bound.first, in_right_bound.second);

            return root;
        }

    public:
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
        {
            return createTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        }
    };
} // namespace p_curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal

/*
# Problem:
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

## HINT:
* Each element in preorder means a root of a tree.
* Find the root in inorder to get the position which will divie the list into two list.
* - Left list can be used to create the left subtree of the tree.
* - Right list can be used to create the right subtree of the tree.

## Time Complexity:
BigO(n * n)

## Space Complexity:
BigO(n)
*/