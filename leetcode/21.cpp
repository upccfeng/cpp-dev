#include <vector>

using namespace std;

namespace p21
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}

        static ListNode* makeList(const vector<int>& target)
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
        static void freeList(ListNode* head)
        {
            while(head)
            {
                ListNode* current = head;
                head = head->next;
                delete current;
            }
        }
        static bool cmp(ListNode* head, const vector<int>& rhs_v)
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
    };

    class Solution
    {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* head = nullptr;
            ListNode* tail = nullptr;

            while(l1 && l2)
            {
                ListNode* taking;
                if (l1->val < l2->val)
                {
                    taking = l1;
                    l1 = l1->next;
                }
                else
                {
                    taking = l2;
                    l2 = l2->next;
                }

                if (head == nullptr)
                {
                    taking->next = nullptr;
                    head = tail = taking;
                }
                else
                {
                    taking->next = nullptr;
                    tail->next = taking;
                    tail = tail->next;
                }
            }

            if (l1)
            {
                if (head == nullptr)
                {
                    return l1;
                }

                tail->next = l1;
            }
            else if (l2)
            {
                if (head == nullptr)
                {
                    return l2;
                }

                tail->next = l2;
            }

            return head;
        }
    };
} // namespace p21

/*
# Problem:

https://leetcode.com/problems/merge-two-sorted-lists/

## HINT:

Traverse two linked list and take the smaller one.

## Algorithm:

```
head = nullptr
tail = nullptr

while l1 and l2:
    if l1->val < l2->val:
        taking = l1
        l1 = l1->next
    else:
        taking = l2;
        l2 = l2->next;

    if head == nullptr:
        taking->next = nullptr
        head = tail = taking
    else:
        taking->next = nullptr
        tail->next = taking
        tail = tail->next

if l1:
    if head == nullptr:
        return l1

    tail->next = l1

elif l2:
    if head == nullptr:
        return l2

    tail->next = l2

return head;
```

## Time Complexity:
log(m+n)

## Space Complexity:
log(1)
*/