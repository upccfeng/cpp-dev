#include <vector>

namespace p35_daily
{
    class Solution
    {
    public:
        int searchInsert(std::vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;
            size_t middle;


            while (left < right)
            {
                middle = (left + right) / 2;
                if (target == nums[middle])
                {
                    return middle;
                }
                else if (target < nums[middle])
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }

            if (target > nums[left])
                return left + 1;
            else
                return left;
        }
    };
} // namespace p35_daily

/*
# Problem:
https://leetcode.com/problems/search-insert-position/

## HINT:
Divide and conquer
Use "size_t" for "right" will cause "middle - 1" become overflow. The result is unexpected.

## Algorithm:

```pseudo code
while given array is bigger than 1:
    if targe == middle of array:
        return middle

    elif target is greater:
        find the rest elements on right
    else: # target is smaller
        find the rest elements on left
```

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(1)
*/