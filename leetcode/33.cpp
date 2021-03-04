#include <vector>

using namespace std;

namespace p33
{
    class Solution
    {
    public:
        int search(vector<int>& nums, int target)
        {
            int left = nums[0];
            int right = nums[nums.size() - 1];

            if (left == target)
                return 0;

            if (right == target)
                return nums.size() - 1;

            if (left < right)
            {
                for (int i = 0; i < nums.size(); ++i)
                {
                    if (target == nums[i])
                        return i;
                }
            }
            else
            {
                if (target > left)
                {
                    int i = 1;
                    int pre = left;
                    while (i < nums.size() && nums[i] > pre)
                    {
                        if (target == nums[i])
                            return i;

                        pre = nums[i++];
                    }
                }
                else if (target < right)
                {
                    int i = nums.size() - 2;
                    int pre = right;
                    while (i >= 0 && nums[i] < pre)
                    {
                        if (target == nums[i])
                            return i;

                        pre = nums[i--];
                    }
                }
            }

            return -1;
        }
    };
} // namespace p33

/*
# Problem:

https://leetcode.com/problems/search-in-rotated-sorted-array/

## HINT:

There is a relation between head and tail.
Time complexity should be O(logn)


## Algorithm:

```
if head:
    return head.pos

if tail:
    return tail.pos

if head < tail:
    for e in nums :
        if e == target:
            return e.pos

else:
    if target > head:
        taking = 1
        pre = head
        while taking < nums.size() and nums[taking] > pre:
            if target == nums[taking]:
                return taking

            pre = nums[taking++]
    elif: target < tail:
        taking = tail.pos - 1
        pre = tail
        while taking >= 0 and nums[taking] < pre:
            if target == nums[taking]:
                return taking

            pre = nums[taking--]

```

## Time Complexity:
O(log n)

## Space Complexity:
O(1)
*/