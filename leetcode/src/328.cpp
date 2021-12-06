#include "listnode.hpp"

namespace p328
{
    class Solution
    {
    public:
        ListNode* oddEvenList(ListNode* head)
        {
            if (nullptr == head || nullptr == head->next)
                return head;

            ListNode* first_tail, * second, * second_tail, * ptr;
            first_tail = head;
            second = second_tail = head->next;
            ptr = second->next;

            first_tail->next = nullptr;
            second_tail->next = nullptr;
            int cnt = 2;
            while (ptr)
            {
                if (0 == cnt++ % 2)
                {
                    first_tail->next = ptr;
                    ptr = ptr->next;
                    first_tail = first_tail->next;
                    first_tail->next = nullptr;
                }
                else
                {
                    second_tail->next = ptr;
                    ptr = ptr->next;
                    second_tail = second_tail->next;
                    second_tail->next = nullptr;
                }
            }
            first_tail->next = second;

            return head;
        }
    };
} // namespace p328

/*
# Problem:
https://leetcode.com/problems/odd-even-linked-list/

## HINT:
Use pointers to point at the second group's head and tail. And the current positon.

## Algorithm:

```pseudo code
first_tail = head
second = second_tail = head->next

ptr = second->next

cnt = 2
while ptr is not nullptr:
    if cnt++ % 2 == 0:
        link the ptr after the first_tail.
    else:
        link the ptr after the second_tail.

first_tail->next = second;

return head
```

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/