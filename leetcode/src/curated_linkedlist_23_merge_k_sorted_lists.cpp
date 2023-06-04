#include "listnode.hpp"
#include <vector>

namespace p_curated_linkedlist_23_merge_k_sorted_lists
{
    class Solution
    {
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

    public:
        ListNode* mergeKLists(std::vector<ListNode*>& lists)
        {
            if (lists.size() == 0)
                return nullptr;

            if (lists.size() == 1)
                return lists[0];

            ListNode* first = lists[0];

            // TODO: Use binary seach to reduce the merge times.
            for (int i = 1; i < lists.size(); ++i)
            {
                first = mergeTwoLists(first, lists[i]);
            }

            return first;
        }
    };
} // namespace p_curated_linkedlist_23_merge_k_sorted_lists

/*
# Problem:
https://leetcode.com/problems/merge-k-sorted-lists/

## HINT:
* Refer to Problem-21, mergeTwoLists.
* Use divide and counquer (binary seach) to reduce merge time for speeding up.

## Time Complexity:
BigO(k^2 * n)
Use divide and conquer to make k^2 to klogk

## Space Complexity:
BigO(1)
*/