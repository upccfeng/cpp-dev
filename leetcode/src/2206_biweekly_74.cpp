#include "assert.h"
#include <vector>
#include <unordered_map>

namespace p_2206_biweekly_74
{
    class Solution
    {
    public:
        bool divideArray(std::vector<int>& nums)
        {
            if (nums.size() % 2 == 1)
            {
                return false;
            }

            std::unordered_map<int, int> value_cnt;

            for (int i = 0; i < nums.size(); i++)
            {
                value_cnt[nums[i]]++;
            }

            for (auto& kv : value_cnt)
            {
                if (kv.second % 2 == 1)
                {
                    return false;
                }
            }

            return true;
        }
    };
} // namespace p_2206_biweekly_74

/*
# Problem:
https://leetcode.com/problems/divide-array-into-equal-pairs/

## HINT:

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/