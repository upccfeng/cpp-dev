#pragma once
#include <vector>

namespace common{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}

        static ListNode* makeList(const std::vector<int>& target);
        static void freeList(ListNode* head);
        static bool cmp(ListNode* head, const std::vector<int>& rhs_v);
    };

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

