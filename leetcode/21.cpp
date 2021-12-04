#include <vector>

using namespace std;

#include "listnode.hpp"

namespace p21
{
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
O(m+n)

## Space Complexity:
O(1)
*/