#include <vector>
#include <map>
#include <limits.h>

namespace p_curated_array_53_max_sub_array
{
    class Solution
    {
    public:
        int maxSubArray(std::vector<int>& nums)
        {
            int max = nums[0];
            int sum = max < 0 ? 0 : max;
            for (int i = 1; i < nums.size(); ++i)
            {
                sum += nums[i];
                if (sum > max)
                    max = sum;

                if (sum < 0)
                    sum = 0;
            }

            return max;
        }
    };

    class Solution_divide_and_conquer
    {
        std::map<int, int> index_cache;

        int getMax(std::vector<int>& nums, int left, int right)
        {
            if (left == right)
                return nums[left];

            auto it = index_cache.find(left);
            if (it != index_cache.end())
            {
                return it->second;
            }
            else
            {
                index_cache[left] = std::max(nums[left], nums[left] + getMax(nums, left + 1, right));
                return index_cache[left];
            }
        }
    public:
        int maxSubArray(std::vector<int>& nums)
        {
            int ans = INT_MIN;
            for (int i = 0; i < nums.size(); ++i)
            {
                int max = getMax(nums, i, nums.size() - 1);

                if (max > ans)
                {
                    ans = max;
                }
            }
            return ans;
        }
    };
} // namespace p_curated_array_53_max_sub_array

/*
# Problem:
https://leetcode.com/problems/maximum-subarray/

## HINT:
Initail should be INT_MIN.
If SUM + num[i] is less than 0, num[i+1] must be greater than (SUM + num[i] + num[i+1])

## Algorithm:

```pseudo code
ans = INT_MIT
sum = 0
for e in nums:
    sum += e
    if sum > ans: ans = sum
    if sum < 0: sum = 0

return ans
```

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/
