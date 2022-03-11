#include "listnode.hpp"

namespace p_61
{
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k)
        {
            if (head == nullptr)
            {
                return head;
            }

            ListNode* tail = nullptr;
            ListNode* taking = head;
            int cnt = 0;

            while (taking != nullptr)
            {
                if (taking->next == nullptr)
                {
                    tail = taking;
                }

                cnt++;
                taking = taking->next;
            }

            int move = cnt - k % cnt;

            tail->next = head;

            ListNode* new_head = head;
            for (int i = 0; i < move; i++)
            {
                ListNode* next = new_head->next;
                if (i == move - 1)
                {
                    new_head->next = nullptr;
                }

                new_head = next;
            }

            return new_head;
        }
    };
} // namespace p_61

/*
# Problem:
https://leetcode.com/problems/rotate-list/

## HINT:
* Calculate the len of linked list.
* Connect the tail to original head
* Move the head to (head + len - k%len).
* Disconnect the link between new_head and the node before new_head.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/