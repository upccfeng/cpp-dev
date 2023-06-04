#include "listnode.hpp"
#include <vector>

namespace p_curated_linkedlist_206_reverse_linked_list
{
    class Solution
    {
    public:
        ListNode* reverseList(ListNode* head)
        {
            ListNode* new_head = nullptr;

            ListNode* previous = head;
            while (head)
            {
                head = head->next;

                previous->next = new_head;
                new_head = previous;
                previous = head;
            }

            return new_head;
        }
    };
} // namespace p_curated_linkedlist_206_reverse_linked_list

/*
# Problem:
https://leetcode.com/problems/reverse-linked-list/

## HINT:
* Move the original nodes.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/