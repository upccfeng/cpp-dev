#include "assert.h"
#include <vector>

namespace p_162
{
    class Solution
    {
    public:
        int findPeakElement(std::vector<int>& nums)
        {
            int left = 0;
            int right = nums.size() - 1;

            while (left < right)
            {
                int mid = left + (right - left) / 2;

                if (nums[mid] < nums[mid + 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

            return left;
        }
    };
} // namespace p_162

/*
# Problem:
https://leetcode.com/problems/find-peak-element/

## HINT:
* Just find one peak insteal of the max.
* Check the mid and its neighbors. Find the bigger neighbor's side.

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(1)
*/