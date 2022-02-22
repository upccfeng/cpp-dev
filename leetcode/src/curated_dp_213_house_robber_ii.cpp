#include <vector>
#include <unordered_map>

namespace p_curated_dp_213_house_robber_ii
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
            else
            {
                valid[pos + 1 - valid.size()] = status;
            }

            if (pos - 1 >= 0)
            {
                valid[pos - 1] = status;
            }
            else
            {
                valid[valid.size() - 1] = status;
            }
        }

        std::unordered_map<int, int> cache_pick;
        std::unordered_map<int, int> cache_unpick;

        int get_max(std::vector<bool>& valid, std::vector<int>& nums, int pos, int end_pos, bool first_time)
        {
            if (pos < 0)
            {
                pos = nums.size() - 1;
            }

            if (pos == end_pos && !first_time)
            {
                return 0;
            }
            else
            {
                if (!valid[pos])
                {
                    if (cache_unpick.find(pos) == cache_unpick.end())
                    {
                        cache_unpick[pos] = get_max(valid, nums, pos - 1, end_pos, false);
                    }

                    return cache_unpick[pos];
                }
                else
                {
                    if (cache_pick.find(pos) == cache_pick.end())
                    {
                        // no
                        int no_max;
                        no_max = get_max(valid, nums, pos - 1, end_pos, false);

                        // yes
                        int yes_max;
                        mark(valid, pos, false);
                        yes_max = nums[pos] + get_max(valid, nums, pos - 1, end_pos, false);
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
            if (nums.size() == 1)
            {
                return nums[0];
            }

            int max = nums[0];
            int start_pos, end_pos;

            // Do twice to avoid the case which include first and end.

            // Just get the max from 1 -> nums.size() - 1;
            start_pos = nums.size() - 1;
            cache_pick.clear();
            cache_unpick.clear();
            end_pos = start_pos + 1 < nums.size() ? start_pos + 1 : 0;
            max = std::max(max, get_max(valid, nums, start_pos, end_pos, true));

            // Just get the max from 0 -> nums.size() - 2;
            start_pos = nums.size() - 2;
            cache_pick.clear();
            cache_unpick.clear();
            end_pos = start_pos + 1 < nums.size() ? start_pos + 1 : 0;
            max = std::max(max, get_max(valid, nums, start_pos, end_pos, true));

            return max;
        }

        int rob(std::vector<int>& nums)
        {
            return rob_cache(nums);
        }
    };
} // namespace p_curated_dp_213_house_robber_ii

/*
# Problem:
https://leetcode.com/problems/house-robber-ii/

## HINT:
* Refer to proble 198: https://leetcode.com/problems/house-robber/
* Because we can not pick the first and end together. So we get the max from get_max(1, nums.size() - 1) and get_max(0, nums.size() - 2)
*
## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/