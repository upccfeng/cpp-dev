#include "listnode.hpp"

namespace p_curated_linkedlist_21_sorted_lists
{
    class Solution
    {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
        {
            if (!list1)
            {
                return list2;
            }

            if (!list2)
            {
                return list1;
            }

            ListNode* main, * other;

            if (list1->val > list2->val)
            {
                main = list2;
                other = list1;
            }
            else
            {
                main = list1;
                other = list2;
            }


            ListNode* it_main, * it_other;
            it_main = main;
            it_other = other;

            while (it_main->next != nullptr)
            {
                ListNode* main_next = it_main->next;

                // insert all elements which are smaller than it_main->next behind it_main
                while (it_other->val < main_next->val)
                {
                    ListNode* other_next = it_other->next;

                    it_main->next = it_other;
                    it_other->next = main_next;

                    it_main = it_main->next;
                    it_other = other_next;

                    if (!it_other)
                    {
                        return main; // there is no more elements need to merge into main
                    }
                }

                it_main = it_main->next;
            }

            it_main->next = it_other;

            return main;
        }
    };
} // namespace p_curated_linkedlist_21_sorted_lists

/*
# Problem:

https://leetcode.com/problems/merge-two-sorted-lists/

## HINT:
* Merge the smaller list into main list.

## Time Complexity:
O(m+n)

## Space Complexity:
O(1)
*/