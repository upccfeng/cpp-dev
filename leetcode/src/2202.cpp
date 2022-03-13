#include <vector>

namespace p_2202_weekly
{
    class Solution
    {
    public:
        int maximumTop(std::vector<int>& nums, int k)
        {
            if (k == 0)
            {
                return nums[0];
            }

            if (k % 2 == 1 && nums.size() == 1)
            {
                return -1;
            }

            int max = 0;

            int i = 0;

            while (i < nums.size() && i < k - 1)
            {
                max = std::max(nums[i], max);
                i++;
            }

            if (k < nums.size())
            {
                max = std::max(max, nums[k]);
            }

            return max;
        }
    };
} // namespace p_2202_weekly

/*
# Problem:
https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

## HINT:
* There are below test cases:
* - k == 0, return nums[0]
* - k % 2 == 1, and len(nums) == 1, return -1
* - else, maxOf(nums[0], nums[1], ..., nums[max(n, k-2)], and nums[k])
* P.S. For k > n case, we can push any one of k as the topelement.

## Time Complexity:
BigO(max(n, k))

## Space Complexity:
BigO(1)
*/