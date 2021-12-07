#include "listnode.hpp"

namespace p1290_daily
{
    class Solution
    {
    public:
        int getDecimalValue(ListNode* head)
        {
            int ret = 0;
            while (head)
            {
                ret = ret * 2 + head->val;
                head = head->next;
            }

            return ret;
        }
    };
} // namespace p1290_daily

/*
# Problem:
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

## HINT:

## Algorithm:

```pseudo code
ans = 0
while head:
    ans = (ans * 2 ) + head->val
    head = head->next

return ans
```

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/