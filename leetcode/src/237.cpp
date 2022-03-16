#include "listnode.hpp"
#include "assert.h"

namespace p_237
{
    class Solution
    {
    public:
        void deleteNode(ListNode* node)
        {
            std::swap(node->val, node->next->val);

            ListNode* next = node->next->next;

            delete node->next;

            node->next = next;
        }
    };
} // namespace p_237

/*
# Problem:
https://leetcode.com/problems/delete-node-in-a-linked-list/

## HINT:
* The node value can be replaced.
* No need to insist on moving node, just swap the value and delete the next one.

## Time Complexity:
BigO(1)

## Space Complexity:
BigO(1)
*/