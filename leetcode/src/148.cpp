#include "listnode.hpp"

namespace p_148
{
    class Solution
    {
        ListNode* getPreMid(ListNode* head, ListNode* end)
        {
            ListNode* ptr1, * ptr2;

            ptr1 = head;
            ptr2 = head->next;

            while (ptr2 != nullptr && ptr2->next != end->next)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next->next;
            }

            return ptr1;
        }

        ListNode* mergeTwoSortedList(ListNode* head1, ListNode* head2)
        {
            if (head1 == nullptr)
            {
                return head2;
            }

            if (head2 == nullptr)
            {
                return head1;
            }

            ListNode* iter1, * iter2;

            iter1 = head1;
            iter2 = head2;

            ListNode* iter1_pre = nullptr;
            while (iter1 != nullptr && iter2 != nullptr)
            {
                if (iter2->val <= iter1->val)
                {
                    ListNode* next = iter2->next;

                    if (iter1_pre == nullptr)
                    {
                        iter2->next = head1;
                        head1 = iter2;
                        iter1 = head1;
                    }
                    else
                    {
                        iter1_pre->next = iter2;
                        iter2->next = iter1;
                        iter1 = iter2;
                    }

                    iter2 = next;
                }
                else
                {
                    iter1_pre = iter1;
                    iter1 = iter1->next;
                }
            }

            if (iter2 == nullptr)
            {
                return head1;
            }

            iter1_pre->next = iter2;

            return head1;
        }

        ListNode* sortList(ListNode* head, ListNode* end)
        {
            if (head == end)
            {
                return head;
            }

            auto pre_mid = getPreMid(head, end);

            ListNode* second_head = pre_mid->next;
            pre_mid->next = nullptr;
            ListNode* h1 = sortList(head, pre_mid);
            ListNode* h2 = sortList(second_head, end);
            return mergeTwoSortedList(h1, h2);
        }

    public:
        ListNode* sortList(ListNode* head)
        {
            ListNode* taking = head;
            ListNode* pre = nullptr;
            while (taking != nullptr)
            {
                pre = taking;
                taking = taking->next;
            }

            return sortList(head, pre);
        }
    };
} // namespace p_148

/*
# Problem:
https://leetcode.com/problems/sort-list/

## HINT:
* Use merge sort in linked list
* Use two pointer to find the mid
* Sort the right hand side and left hand side.
* Merge right and left.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(1)
*/