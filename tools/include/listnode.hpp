#pragma once
#include <vector>
#include <memory>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListHelper {
public:
    static ListNode* create(std::vector<int> elements);
    static void remove(ListNode* head);
    static ListNode* get_tail(ListNode* head);
    static ListNode* add_loop(ListNode* head, ListNode* taking, int pos);
    static bool compare(ListNode* lhs, ListNode* rhs);
    static bool compare(ListNode* lhs, const std::vector<int>& rhs_v);
    static bool compare(std::shared_ptr<ListNode> lhs, const std::vector<int>& rhs_v);
    static bool compare(ListNode* lhs, std::shared_ptr<ListNode> rhs);
};