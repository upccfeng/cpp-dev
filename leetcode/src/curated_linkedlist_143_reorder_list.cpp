#include "listnode.hpp"
#include <vector>

namespace p_curated_linkedlist_143_reorder_list
{
    class Solution
    {
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

        std::pair<ListNode*, ListNode*> divideListByHalf(ListNode* head)
        {
            ListNode* fast, * slow;

            // fast.begin = 2 * slow.begin
            // fast.step = 2 * slow.step
            // fast.pos = fast.begin + n * fast.step 
            //          = 2 * slow.begin + n * 2 * slow.step 
            //          = 2 * (slow.begin + n * slow.step)
            //          = 2 * slow.pos
            slow = head;
            fast = head->next;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* second_head = slow->next;
            slow->next = nullptr;

            return { head, second_head };
        }

        ListNode* mergeTwoByOrder(ListNode* first, ListNode* second)
        {
            while (first != nullptr && second != nullptr)
            {
                ListNode* fnext = first->next;
                ListNode* snext = second->next;

                first->next = second;
                second->next = fnext;

                first = fnext;
                second = snext;
            }

            return nullptr;
        }

    public:
        void reorderListWithSpace1(ListNode* head)
        {
            auto lists = divideListByHalf(head);

            lists.second = reverseList(lists.second);

            head = mergeTwoByOrder(lists.first, lists.second);

            return;
        }

        void reorderListWithSpaceN(ListNode* head)
        {
            ListNode* taking = head;
            std::vector<ListNode*> map;

            while (taking)
            {
                map.emplace_back(taking);
                taking = taking->next;
            }

            int distant = 0;
            bool is_front = true;

            int base = 0;
            while (true)
            {
                if (is_front)
                {
                    taking = map[base + distant];
                    base = map.size() - 1;


                    if (taking == map[base - distant])
                    {
                        taking->next = nullptr;
                        break;
                    }

                    ListNode* next = map[base - distant];
                    taking->next = next;
                    is_front = false;
                }
                else
                {
                    taking = map[base - distant];
                    base = 0;
                    ++distant;

                    if (taking == map[base + distant])
                    {
                        taking->next = nullptr;
                        break;
                    }

                    ListNode* next = map[base + distant];
                    taking->next = next;
                    is_front = true;
                }
            }

            return;
        }

        void reorderList(ListNode* head)
        {
            reorderListWithSpace1(head);
        }
    };
} // namespace p_curated_linkedlist_143_reorder_list

/*
# Problem:
https://leetcode.com/problems/reorder-list/

## HINT:
* Method1: Use a array to sort the ptr. And re-lind all pointer in array by rule.
* Method2: Divide the list into two lists by half, reverse the second one and merge two lists by order.
* Reason of dividing mothod
    fast.begin = 2 * slow.begin
    fast.step = 2 * slow.step
    fast.pos = fast.begin + n * fast.step 
             = 2 * slow.begin + n * 2 * slow.step 
             = 2 * (slow.begin + n * slow.step)
             = 2 * slow.pos

## Time Complexity:
BigO(n)

## Space Complexity:
Method1: BigO(n)
Method2: BigO(1)
*/