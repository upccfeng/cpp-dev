#include <vector>s

namespace p_2216_weekly_286
{
    class Solution
    {
    public:
        int minDeletion(std::vector<int>& nums)
        {
            if (nums.size() == 0)
            {
                return 0;
            }

            if (nums.size() == 1)
            {
                return 1;
            }

            int len = 1;
            int pre_pos = 0;
            int remove_cnt = 0;

            for (int i = 1; i < nums.size(); i++)
            {
                if (len % 2 == 1)
                {
                    if (nums[i] == nums[pre_pos])
                    {
                        remove_cnt++;
                    }
                    else
                    {
                        len++;
                        pre_pos = i;
                    }
                }
                else
                {
                    len++;
                    pre_pos = i;
                }
            }

            if (len % 2 == 1)
            {
                return remove_cnt + 1;
            }
            else
            {
                return remove_cnt;
            }
        }
    };
} // namespace p_2216_weekly_286

/*
# Problem:
https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

## HINT:

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/