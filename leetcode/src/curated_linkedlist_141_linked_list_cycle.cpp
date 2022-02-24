#include "listnode.hpp"

namespace p_curated_linkedlist_141_linked_list_cycle
{
    class Solution
    {
    public:
        bool hasCycle(ListNode* head)
        {
            if (!head || !head->next)
            {
                return false;
            }

            ListNode* it_one, * it_two;
            it_one = head;
            it_two = head;
            while (it_two->next)
            {
                it_one = it_one->next;
                it_two = it_two->next->next;

                if (it_one == it_two)
                {
                    return true;
                }

                if (!it_two)
                {
                    break;
                }
            }

            return false;
        }
    };
} // namespace p_curated_linkedlist_141_linked_list_cycle

/*
# Problem:
https://leetcode.com/problems/linked-list-cycle/

## HINT:
* Use two iterators with different steps.
* If there is a loop, the iterators will be the same except the first time.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/