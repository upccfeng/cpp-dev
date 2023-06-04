#include <vector>
#include <map>

namespace p_2190_biweekly
{
    class Solution
    {
    public:
        int mostFrequent(std::vector<int>& nums, int key)
        {
            std::map<int, int> cnt_map;

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] == key)
                {
                    cnt_map[nums[i]]++;
                }
            }

            int max_cnt = 0;
            int max = -1;
            for (auto& kv : cnt_map)
            {
                if (kv.second > max_cnt)
                {
                    max = kv.first;
                    max_cnt = kv.second;
                }
            }

            return max;
        }
    };
} // namespace p_2190_biweekly

/*
# Problem:
https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

## HINT:

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/