#include "listnode.hpp"
#include <unordered_map>

namespace p_82
{
    class Solution
    {
    public:
        ListNode* deleteDuplicates(ListNode* head)
        {
            std::unordered_map<int, int> cnt_map;

            ListNode* taking = head;
            while (taking != nullptr)
            {
                cnt_map[taking->val]++;

                taking = taking->next;
            }

            taking = head;
            ListNode* pre = nullptr;
            while (taking != nullptr)
            {
                if (cnt_map[taking->val] > 1)
                {
                    if (pre == nullptr)
                    {
                        head = head->next;

                        delete taking;
                        taking = head;
                    }
                    else
                    {

                        pre->next = taking->next;

                        delete taking;
                        taking = pre->next;
                    }
                }
                else
                {
                    pre = taking;
                    taking = taking->next;
                }

            }

            return head;
        }
    };
} // namespace p_82

/*
# Problem:
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

## HINT:
* Use map to record the cnt, and remove the elements whose cnt is greater than 1.
* Can enhance to Space(1).

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/