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
} // namespace common

