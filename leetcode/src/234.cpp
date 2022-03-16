#include "listnode.hpp"
#include "assert.h"

namespace p_234
{
    class Solution
    {
        ListNode* getMidPtr(ListNode* head)
        {
            assert(head->next != nullptr);

            ListNode* iter1, * iter2;

            iter1 = head;
            iter2 = head->next;

            while (iter2 != nullptr && iter2->next != nullptr)
            {
                iter1 = iter1->next;

                iter2 = iter2->next->next;
            }

            return iter1;
        }

        int getLength(ListNode* head)
        {
            ListNode* taking = head;
            int len = 0;
            while (taking != nullptr)
            {
                len++;
                taking = taking->next;
            }

            return len;
        }

        ListNode* reverseList(ListNode* head)
        {
            ListNode* taking = head;
            ListNode* next = taking->next;
            ListNode* pre = nullptr;

            while (next != nullptr)
            {
                taking->next = pre;
                pre = taking;
                taking = next;
                next = taking->next;
            }

            taking->next = pre;
            return taking;
        }

        bool isTheSame(ListNode* list1, ListNode* list2)
        {
            ListNode* t1 = list1;
            ListNode* t2 = list2;

            while (t1 != nullptr && t2 != nullptr)
            {
                if (t1->val != t2->val)
                {
                    return false;
                }

                t1 = t1->next;
                t2 = t2->next;
            }

            if (t1 == nullptr && t2 == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    public:
        bool isPalindrome(ListNode* head)
        {
            if (head->next == nullptr)
            {
                return true;
            }

            int len = getLength(head);
            assert(len > 1);

            ListNode* mid = getMidPtr(head);

            bool is_odd = len % 2;

            ListNode* list1, * list2;
            list1 = head;
            list2 = mid->next;

            mid->next = nullptr;

            list1 = reverseList(list1);

            if (is_odd)
            {
                list1 = list1->next;
            }

            return isTheSame(list1, list2);
        }
    };
} // namespace p_234

/*
# Problem:
https://leetcode.com/problems/palindrome-linked-list/

## HINT:
* Solution-1: Use stack, put 0 -> len/2 - 1, and pop len/2 -> len to check is the same.
* Solution-2: Find the mid and divide it into two lists, reverse the previous list, and then compare them. Note: If odd, skip the first of previous list.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/