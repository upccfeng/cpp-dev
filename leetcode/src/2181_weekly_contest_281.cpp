#include "listnode.hpp"

namespace p_2181_weekly_contest_281
{
    class Solution
    {
    public:
        ListNode* mergeNodes(ListNode* head)
        {
            ListNode* next, * taking;

            // delete first 0 node
            taking = head;
            head = taking->next;
            delete taking;

            taking = head;
            next = taking->next;

            while (taking != nullptr)
            {
                if (taking->val != 0)
                {
                    while (next->val != 0)
                    {
                        taking->val += next->val;

                        taking->next = next->next;
                        delete next;
                        next = taking->next;
                    }

                    if (next->next != nullptr)
                    {
                        taking->next = next->next;
                        taking = next->next;
                        delete next;
                        next = taking->next;
                    }
                    else
                    {
                        taking->next = next->next;
                        taking = next->next;
                        delete next;
                    }
                }
            }

            return head;
        }
    };
} // namespace p_2181_weekly_contest_281

/*
# Problem:
https://leetcode.com/problems/merge-nodes-in-between-zeros/

## HINT:

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/