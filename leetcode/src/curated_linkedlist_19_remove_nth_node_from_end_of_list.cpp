#include "listnode.hpp"

namespace p_curated_linkedlist_19_remove_nth_node_from_end_of_list
{
    class Solution
    {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            int delay = n;

            ListNode* taking = head;
            ListNode* delay_ptr = head;
            ListNode* pre_delay_ptr = head;

            while (taking)
            {
                if (delay > 0)
                {
                    --delay;
                }
                else
                {
                    pre_delay_ptr = delay_ptr;
                    delay_ptr = delay_ptr->next;
                }

                taking = taking->next;
            }

            if (pre_delay_ptr == delay_ptr)
            {
                // case: delete the first node, pre_delay_ptr == delay_ptr == head because:
                // - list.size() must be greater than 0
                // - n must be greater than 0

                head = head->next;
                delete delay_ptr;

                return head;
            }

            pre_delay_ptr->next = delay_ptr->next;
            delete delay_ptr;

            return head;
        }
    };
} // namespace p_curated_linkedlist_19_remove_nth_node_from_end_of_list

/*
# Problem:
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

## HINT:
* Use another pointer with delay steps.
* There are limits that n and list.size() will be greater than 0, so we can initialize delay_ptr and pre_delay_ptr with head.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/