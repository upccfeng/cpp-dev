#include <vector>

namespace p_curated_dp_300_longest_increasing_subsequence
{
    class Solution
    {
    public:
        int lengthOfLIS(std::vector<int>& nums)
        {
            if (nums.size() == 1)
                return 1;

            std::vector<int> dp(nums.size(), nums.size() + 1);

            int ans = 0;

            dp[nums.size() - 1] = 1;

            for (int i = nums.size() - 2; i >= 0; --i)
            {
                int taking = nums[i];

                int max = 1;
                for (int j = nums.size() - 1; j > i; --j)
                {
                    if (nums[j] > taking)
                    {
                        max = std::max(max, 1 + dp[j]);
                    }
                }

                dp[i] = max;

                if (max > ans)
                {
                    ans = max;
                }
            }

            return ans;
        }
    };
} // namespace p_curated_dp_300_longest_increasing_subsequence

/*
# Problem:
https://leetcode.com/problems/longest-increasing-subsequence/

## HINT:
* Start from the end. And find the longest solution from i to end.
* Use dp.
* Find the max from dp.
* Get max in main loop to speed up.

## Time Complexity:
Big((1+n)*n/2) == Big(n^2)

## Space Complexity:
Big(n)
*/