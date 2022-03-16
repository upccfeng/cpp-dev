#include "assert.h"
#include <vector>
#include <algorithm>

namespace p_215
{
    class Solution
    {
    public:
        int findKthLargest(std::vector<int>& nums, int k)
        {
            std::sort(nums.begin(), nums.end(), std::greater<int>());

            return nums[k - 1];
        }
    };
} // namespace p_215

/*
# Problem:
https://leetcode.com/problems/kth-largest-element-in-an-array/

## HINT:
* Just sort it, and return kth element.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(log(n)) if quick sort
*/