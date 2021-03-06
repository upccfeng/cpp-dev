#include <vector>
using namespace std;

#include "common.hpp"
using namespace common;

namespace p19
{
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *current_ptr, *delay_ptr, *pre_delay_ptr;
            current_ptr = delay_ptr = pre_delay_ptr = head;

            int delay = 0;
            while (current_ptr)
            {
                if (delay != n)
                {
                    delay++;
                }
                else
                {
                    pre_delay_ptr = delay_ptr;
                    delay_ptr = delay_ptr->next;
                }

                current_ptr = current_ptr->next;
            }

            if (delay_ptr == head)
            {
                head = head->next;
            }

            // delete n-th data
            pre_delay_ptr->next = delay_ptr->next;
            delete delay_ptr;

            return head;
        }
    };
} // namespace p19

/*
# Problem:
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

## HINT:
Maintain two pointers and update one with a delay of n steps.

## Algorithm:

```
cur = del = pre = head
delay = 0
while cur != nullptr:
    if delay != n:
        delay++
    else:
        pre = del
        del = del->next

    cur = cur->next

if del = head:
    head = head->next

pre->next = del->next
delete del

return head
```

## Time Complexity:
O(n), n is length of input list

## Space Complexity:
O(1)
*/