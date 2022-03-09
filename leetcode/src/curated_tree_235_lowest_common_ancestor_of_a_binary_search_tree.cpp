#include "assert.h"
#include "treenode.hpp"
#include <vector>

namespace p_curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree
{
    class Solution
    {
        void binarySeach(TreeNode* root, std::vector<TreeNode*>& path, int target)
        {
            if (root == nullptr)
            {
                return;
            }

            path.push_back(root);

            if (root->val == target)
            {
                return;
            }
            else if (root->val < target)
            {
                binarySeach(root->right, path, target);
            }
            else // (root->val > target)
            {
                binarySeach(root->left, path, target);
            }
        }

        TreeNode* getLowestCommon(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            if (root == nullptr)
            {
                return nullptr;
            }

            if (p->val > root->val && q->val > root->val)
            {
                return getLowestCommon(root->right, p, q);
            }
            else if (p->val < root->val && q->val < root->val)
            {
                return getLowestCommon(root->left, p, q);
            }
            else
            {
                return root;
            }
        }

    public:
        TreeNode* lowestCommonAncestorBindarySearchTwice(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            std::vector<TreeNode*> p_path;
            binarySeach(root, p_path, p->val);

            std::vector<TreeNode*> q_path;
            binarySeach(root, q_path, q->val);

            for (int p = p_path.size() - 1; p >= 0; --p)
            {
                for (int q = q_path.size() - 1; q >= 0; --q)
                {
                    if (p_path[p]->val == q_path[q]->val)
                    {
                        return p_path[p];
                    }
                }
            }

            return nullptr;
        }

        TreeNode* lowestCommonAncestorTogetherBinary(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            return getLowestCommon(root, p, q);
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            return lowestCommonAncestorTogetherBinary(root, p, q);
        }
    };
} // namespace p_curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree

/*
# Problem:
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

## HINT:
* Binary Search twice and record the paths.
* Find from the end to begining to get the lowest common node.
* Method-2: Do binary search together, if they don't go the same way, return the current point.

## Time Complexity:
Method-1: BigO(Height * Height) // can imporve to Height
Method-2: BigO(Height)

## Space Complexity:
BigO(Height)
*/