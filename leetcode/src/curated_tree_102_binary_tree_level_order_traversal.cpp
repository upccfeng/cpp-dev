#include "treenode.hpp"
#include <vector>

namespace p_curated_tree_102_binary_tree_level_order_traversal
{
    class Solution
    {
        void levelOrderTraversal(TreeNode* root, std::vector<std::vector<int>>& ret, int level)
        {
            if (root == nullptr)
            {
                return;
            }

            if (ret.size() == level)
            {
                // ret.push_back(std::vector<int>());
                ret.emplace_back(std::vector<int>());
            }

            // ret[level].push_back(root->val);
            ret[level].emplace_back(root->val);

            // left should be first to meet level order traversal definition
            levelOrderTraversal(root->left, ret, level + 1);
            levelOrderTraversal(root->right, ret, level + 1);
        }

    public:
        std::vector<std::vector<int>> levelOrder(TreeNode* root)
        {
            std::vector<std::vector<int>> ret;

            levelOrderTraversal(root, ret, 0);

            return ret;
        }
    };
} // namespace p_curated_tree_102_binary_tree_level_order_traversal

/*
# Problem:
https://leetcode.com/problems/binary-tree-level-order-traversal/

## HINT:
* For each root, push the value into level position.
* Level will increase by call.
* Left should be first than right to meet the level order definition.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/