#include <vector>
#include <limits.h>
#include <cstdlib>

namespace p_41
{
    class Solution
    {
    public:
        int firstMissingPositive(std::vector<int>& nums)
        {
            for (auto& n : nums)
            {
                if (n < 0)
                {
                    n = 0;
                }
            }

            for (auto n : nums)
            {
                int taking = std::abs(n);
                if (taking - 1 >= 0 && taking - 1 < nums.size())
                {
                    if (nums[taking - 1] > 0)
                    {
                        nums[taking - 1] *= -1;
                    }

                    if (nums[taking - 1] == 0)
                    {
                        nums[taking - 1] = INT_MIN;
                    }

                }
            }

            int ret = 1;
            for (ret; ret <= nums.size(); ret++)
            {
                if (nums[ret - 1] >= 0)
                {
                    break;
                }
            }

            return ret;
        }
    };
} // namespace p_41

/*
# Problem:
https://leetcode.com/problems/first-missing-positive/

## HINT:
* The possible ans will be in range 1 to len(nums)
* Set all negative elements into 0 in first round
* Use original nums as hash table, negative value means marked.
* Deal with the changing element which value is zero, make it as INT_MIN as marked.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/