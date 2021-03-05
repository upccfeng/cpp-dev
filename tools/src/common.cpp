#include "common.hpp"
using namespace common;

ListNode* ListNode::makeList(const std::vector<int>& target)
{
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (const auto& e : target)
    {
        ListNode* data = new ListNode(e);

        if (!head)
        {
            head = data;
            current = data;
        }
        else
        {
            current->next = data;
            current = current->next;
        }
    }
    return head;
}

void ListNode::freeList(ListNode* head)
{
    while(head)
    {
        ListNode* current = head;
        head = head->next;
        delete current;
    }
}

bool ListNode::cmp(ListNode* head, const std::vector<int>& rhs_v)
{
    ListNode* current = head;
    for (const auto& e : rhs_v)
    {
        if (current == nullptr)
            return false;

        if (current->val != e)
            return false;

        current = current->next;
    }
    return current == nullptr;
}
