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
    // FIXME: Handle the exist loop case.
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

ListNode* ListHelper::get_tail(ListNode* head)
{
    ListNode* pre = head;
    while (head)
    {
        pre = head;
        head = head->next;
    }

    return pre;
}

ListNode* ListHelper::add_loop(ListNode* head, ListNode* taking, int pos)
{
    ListNode* tail = get_tail(head);

    int cnt = 0;
    ListNode* it = head;
    while (it)
    {
        if (cnt == pos)
        {
            taking->next = it;
        }

        if (it == tail)
        {
            break;
        }

        it = it->next;
        cnt++;
    }

    return head;
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