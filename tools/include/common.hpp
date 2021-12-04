#pragma once
#include <vector>

namespace common{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

        static TreeNode* makeTree(const std::vector<int>& target, const std::vector<bool>& valid, const int level);
        static void freeTree(TreeNode* head);
    };
} // namespace common

