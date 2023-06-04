#include "assert.h"
#include "listnode.hpp"

namespace p_160
{
    class Solution {
        int getLength(ListNode* head)
        {
            ListNode* taking = head;

            int cnt = 0;
            while (taking != nullptr)
            {
                cnt++;
                taking = taking->next;
            }

            return cnt;
        }

    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
        {
            int lenA = getLength(headA);
            int lenB = getLength(headB);

            if (lenA > lenB)
            {
                int move = lenA - lenB;

                for (int i = 0; i < move; i++)
                {
                    headA = headA->next;
                }
            }
            else
            {
                int move = lenB - lenA;

                for (int i = 0; i < move; i++)
                {
                    headB = headB->next;
                }
            }

            while (headA != nullptr && headB != nullptr)
            {
                if (headA == headB)
                {
                    return headA;
                }

                headA = headA->next;
                headB = headB->next;
            }

            return nullptr;
        }
    };
} // namespace p_160

/*
# Problem:
https://leetcode.com/problems/intersection-of-two-linked-lists/

## HINT:
* Find the diff of len(headA) and len(headB)
* Move the longer one for diff steps
* Compare there two head to find intersection because of they are in the same len.

## Time Complexity:
BigO(n + m)

## Space Complexity:
BigO(1)
*/