#include <vector>
#include <unordered_map>

////////////////////////////////////////////////////////

namespace p_curated_dp_198_house_robber
{
    class Solution
    {
        void mark(std::vector<bool>& valid, int pos, bool status)
        {
            valid[pos] = status;

            // No need actually, because only find the pos which is smaller.
            if (pos + 1 < valid.size())
            {
                valid[pos + 1] = status;
            }

            if (pos - 1 >= 0)
            {
                valid[pos - 1] = status;
            }
        }

        std::unordered_map<int, int> cache_pick;
        std::unordered_map<int, int> cache_unpick;

        int get_max(std::vector<bool>& valid, std::vector<int>& nums, int pos)
        {
            if (pos < 0)
            {
                return 0;
            }
            else
            {
                if (!valid[pos])
                {
                    if (cache_unpick.find(pos) == cache_unpick.end())
                    {
                        cache_unpick[pos] = get_max(valid, nums, pos - 1);
                    }

                    return cache_unpick[pos];
                }
                else
                {
                    if (cache_pick.find(pos) == cache_pick.end())
                    {
                        // no
                        int no_max;
                        no_max = get_max(valid, nums, pos - 1);

                        // yes
                        int yes_max;
                        mark(valid, pos, false);
                        yes_max = nums[pos] + get_max(valid, nums, pos - 1);
                        mark(valid, pos, true);

                        cache_pick[pos] = std::max(yes_max, no_max);
                    }

                    return cache_pick[pos];
                }
            }
        }

    public:
        int rob_cache(std::vector<int>& nums)
        {
            std::vector<bool> valid(nums.size(), true);

            return get_max(valid, nums, nums.size() - 1);
        }

        int rob_dp(std::vector<int>& nums)
        {
            if (nums.size() == 1)
            {
                return nums[0];
            }

            std::vector<int> dp(nums.size(), 0);

            dp[0] = nums[0];
            dp[1] = std::max(nums[0], nums[1]);

            for (int i = 2; i < nums.size(); ++i)
            {
                dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
            }

            return dp[nums.size() - 1];
        }

        int rob(std::vector<int>& nums)
        {
            return rob_dp(nums);
        }
    };
} // namespace p_curated_dp_198_house_robber

/*
# Problem:
https://leetcode.com/problems/house-robber/

## HINT:
* For each element can choose to pick or not to pick. For pick, the biggest value is "nums[current] + get_max(rest_of)", for not pick, the biggest value is "get_max(rest_of)".
* Need a valid_map to check whether the current position is pickable or not. Mark the valid_map before get_max, and rollback it after get_max.
* Use two map to cache the value of pos-picked and pos-unpicked to speed up.
* Use DP to speed up.
* For DP[i] means, the max value from 0 -> i.
* For each i, get the max of "nums[i] + dp[i - 2]" or "dp[i - 1]". If "i - 1" or "i - 2" is smaller than 0, return 0.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/