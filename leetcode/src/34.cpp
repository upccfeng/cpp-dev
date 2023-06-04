#include <vector>
using namespace std;

namespace p34
{
    class Solution
    {
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            int left = -1;
            int right = nums.size();
            int taking = (left + right) / 2;

            while (taking >= 0 && taking < nums.size())
            {
                if (nums[taking] > target)
                {
                    if (taking == (taking + left) / 2)
                        break;

                    right = taking;
                    taking = (left + right) / 2;
                }
                else if (nums[taking] < target)
                {
                    if (taking == (taking + right) / 2)
                        break;

                    left = taking;
                    taking = (left + right) / 2;
                }
                else
                {
                    // find left and right boundary
                    int i, j;
                    for (i = taking + 1; i < nums.size() && i <= right; ++i)
                    {
                        if (nums[i] != target)
                            break;
                    }

                    for (j = taking - 1; j >= 0 && j >= left; --j)
                    {
                        if (nums[j] != target)
                            break;
                    }

                    return {j + 1, i - 1};
                }
            }

            return {-1, -1};
        }
    };
} // namespace p34

/*
# Problem:
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

## HINT:

Becuase it is sorted array, use the middle one to decide which part should be the target.

## Algorithm:

```
left = -1
right = nums.size()

taking = (left + right) / 2
while(taking >= 0 and taking < nums.size()):
    if nums[taking] > target:
        if taking == (taking + left) / 2:
            break;

        right = taking
        taking = (left + right) / 2

    elif nums[taking] < target:
        if taking == (taking + right) / 2:
            break;

        left = taking
        taking = (left + right) / 2
    else:
        i = taking + 1
        j = taking - 1
        while (i < nums.size and i <= right):
            if nums[i] != target
                break
            ++i

        while (j >= 0 and j >= left):
            if nums[j] != target:
                break;

            --j

        return {j + 1, i - 1};
```

## Time Complexity:
O(lon n)

## Space Complexity:
O(log 1)

*/