#include <vector>

namespace p_curated_dp_55_jump_game
{
    class Solution
    {
        bool isReachable(int pos, int steps, int pre_true_pos)
        {
            if (pos + steps >= pre_true_pos)
            {
                return true;
            }
            else
            {
                return false;
            }

            // Original Method
            //bool ret = false;
            //for (int s = 1; s <= steps; ++s)
            //{
            //    if (pos + s < boundary)
            //    {
            //        ret |= dp[pos + s];
            //    }
            //    else
            //    {
            //        continue;
            //    }
            //}

            //return ret;
        }
    public:
        bool canJump(std::vector<int>& nums)
        {
            std::vector<int> dp(nums.size());

            dp[nums.size() - 1] = true;

            int pre_true_pos = nums.size() - 1;

            for (int i = nums.size() - 2; i >= 0; --i)
            {
                int steps = nums[i];

                if (isReachable(i, steps, pre_true_pos))
                {
                    dp[i] = true;
                    pre_true_pos = i;
                }
                else
                {
                    dp[i] = false;
                }
            }

            return dp[0];
        }
    };
} // namespace p_curated_dp_55_jump_game

/*
# Problem:
https://leetcode.com/problems/jump-game/

## HINT:
* dp[i] means is it possible to get the end position from i.
* dp[i] = true if i + steps > previous_true_position else false
* dp[nums.size() - 1] = 1

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/