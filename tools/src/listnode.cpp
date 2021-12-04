#include "listnode.hpp"

ListNode* ListHelper::create(std::vector<int> elements)
{
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (const auto& e : elements)
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

void ListHelper::remove(ListNode* head)
{
    while (head)
    {
        ListNode* current = head;
        head = head->next;
        delete current;
    }
}

bool ListHelper::compare(ListNode* lhs, ListNode* rhs)
{
    while (lhs)
    {
        if (!rhs || lhs->val != rhs->val)
        {
            return false;
        }

        rhs = rhs->next;
        lhs = lhs->next;
    }

    return rhs == nullptr;
}

bool ListHelper::compare(ListNode* lhs, const std::vector<int>& rhs_v)
{
    std::shared_ptr<ListNode> rhs = std::shared_ptr<ListNode>(ListHelper::create(rhs_v), ListHelper::remove);
    return compare(lhs, rhs.get());
}

bool ListHelper::compare(std::shared_ptr<ListNode> lhs, const std::vector<int>& rhs_v)
{
    std::shared_ptr<ListNode> rhs = std::shared_ptr<ListNode>(ListHelper::create(rhs_v), ListHelper::remove);
    return compare(lhs.get(), rhs.get());
}

bool ListHelper::compare(ListNode* lhs, std::shared_ptr<ListNode> rhs)
{
    return compare(lhs, rhs.get());
}