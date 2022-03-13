#include <vector>

namespace p_2200_weekly
{
    class Solution
    {
    public:
        std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k)
        {
            std::vector<int> key_pos;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == key)
                {
                    key_pos.emplace_back(i);
                }
            }

            std::vector<int> ret;
            for (int i = 0; i < nums.size(); i++)
            {
                bool is_key = false;
                for (auto pos : key_pos)
                {
                    if (i >= pos - k && i <= pos + k)
                    {
                        is_key = true;
                        break;
                    }
                }

                if (is_key)
                {
                    ret.emplace_back(i);
                }
            }

            return ret;
        }
    };
} // namespace p_2200_weekly

/*
# Problem:
https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

## HINT:

## Time Complexity:
BigO(n * numberofK)

## Space Complexity:
BigO(numberofK)
*/