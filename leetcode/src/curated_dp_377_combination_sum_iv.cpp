#include <vector>

namespace p_curated_dp_377_combination_sum_iv
{
    class Solution
    {
    public:
        int combinationSum4(std::vector<int>& nums, int target)
        {
            std::vector<uint32_t> dp(target + 1);
            dp[0] = 1;

            for (int i = 1; i <= target; ++i)
            {
                uint32_t cnt = 0;
                for (int taking = 0; taking < nums.size(); ++taking)
                {
                    if (i - nums[taking] >= 0)
                    {
                        // handle overflow case
                        // Other Solution: if cnt is int, cnt = cnt > INT_MAX - dp[i - nums[taking]] ? INT_MAX : cnt + dp[i - nums[taking]];
                        cnt += dp[i - nums[taking]];
                    }
                }

                dp[i] = cnt;
            }

            return dp[target];

        }
    };
} // namespace p_curated_dp_377_combination_sum_iv

/*
# Problem:
https://leetcode.com/problems/combination-sum-iv/

## HINT:
* f(i) means how many pairs we can use elements in nums to reach i. f(0) is 1, means reached. f(negitive) will return 0, means there is no way to reach.
* f(target) = sumof(f(target - nums[0]), f(target - nums[1]), ..., f(target - nums[nums.size() - 1]))
* Need to handle overflow cases, use uint or store as INT_MAX

## Time Complexity:
BigO(n*target)

## Space Complexity:
BigO(target)
*/