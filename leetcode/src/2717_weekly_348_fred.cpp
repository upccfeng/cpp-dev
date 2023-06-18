#include <vector>
#include <limits.h>

namespace p_2717_weekly_348_fred
{
    class Solution {
    public:
        int semiOrderedPermutation(std::vector<int>& nums) {
            int max = INT_MIN;
            int min = INT_MAX;

            int max_idx = -1;
            int min_idx = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] < min)
                {
                    min_idx = i;
                    min = nums[i];
                }

                if (nums[i] > max)
                {
                    max_idx = i;
                    max = nums[i];
                }
            }

            int min_dis = min_idx;
            int max_dis = nums.size() - max_idx - 1;
            int dis = min_dis + max_dis;

            return min_idx < max_idx ? dis : dis - 1;
        }
    };
} // namespace p_2717_weekly_348_fred

/*
# Problem:
https://leetcode.com/problems/semi-ordered-permutation/

## HINT:

## Time Complexity:

## Space Complexity:
*/