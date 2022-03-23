#include "treenode.hpp"
#include "assert.h"
#include <vector>

namespace p_285
{
    class Solution
    {
        void inOrderTraverse(TreeNode* root, TreeNode* p, std::vector<TreeNode*>& inorder)
        {
            if (root == nullptr)
            {
                return;
            }

            inOrderTraverse(root->left, p, inorder);
            inorder.push_back(root);
            inOrderTraverse(root->right, p, inorder);
        }

        void inOrderTraverseFlag(TreeNode* root, TreeNode* p, bool& flag, TreeNode*& result)
        {
            if (root == nullptr)
            {
                return;
            }

            inOrderTraverseFlag(root->left, p, flag, result);

            if (flag && result == nullptr)
            {
                result = root;
                return;
            }

            if (root == p)
            {
                flag = true;
            }

            inOrderTraverseFlag(root->right, p, flag, result);
        }

    public:
        TreeNode* inorderSuccessorVector(TreeNode* root, TreeNode* p)
        {
            std::vector<TreeNode*> inorder;

            inOrderTraverse(root, p, inorder);

            int i = 0;
            for (i; i < inorder.size(); i++)
            {
                if (inorder[i] == p)
                {
                    break;
                }
            }

            return i + 1 == inorder.size() ? nullptr : inorder[i + 1];
        }

        TreeNode* inorderSuccessorFlag(TreeNode* root, TreeNode* p)
        {
            bool flag = false;
            TreeNode* result = nullptr;

            inOrderTraverseFlag(root, p, flag, result);

            return result;
        }

        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
        {
            return inorderSuccessorFlag(root, p);
        }
    };
} // namespace p_285

/*
# Problem:
https://leetcode.com/problems/inorder-successor-in-bst/

## HINT:
* in-order traversal

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(n)
BigO(HEIGH)
*/