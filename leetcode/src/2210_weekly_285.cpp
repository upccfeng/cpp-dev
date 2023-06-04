#include <vector>

namespace p_2210_weekly_285
{
    class Solution {
    public:
        int countHillValley(std::vector<int>& nums)
        {
            int status = 0;

            if (nums[1] > nums[0])
            {
                status = 1;
            }
            else if (nums[1] < nums[0])
            {
                status = -1;
            }
            else
            {
                status = 0;
            }

            int before_equal = 0;
            int ret = 0;
            for (int i = 2; i < nums.size(); i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    if (status == -1)
                    {
                        ret++;
                    }
                    else if (status == 1)
                    {
                        ;
                    }
                    else
                    {
                        if (before_equal == -1)
                        {
                            ret++;
                            before_equal = 0;
                        }
                    }

                    status = 1;
                }
                else if (nums[i] < nums[i - 1])
                {
                    if (status == -1)
                    {
                        ;
                    }
                    else if (status == 1)
                    {
                        ret++;
                    }
                    else
                    {
                        if (before_equal == 1)
                        {
                            ret++;
                            before_equal = 0;
                        }
                    }

                    status = -1;
                }
                else
                {

                    if (status != 0)
                    {
                        before_equal = status;
                    }

                    status = 0;
                }
            }

            return ret;
        }
    };
} // namespace p_2210_weekly_285

/*
# Problem:
https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

## HINT:
* Record the dirrection change(up->down, or down->up)

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/