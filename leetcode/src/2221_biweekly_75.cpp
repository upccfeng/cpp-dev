#include <vector>

namespace p_2221_biweekly_75
{
    class Solution {
    public:
        int triangularSum(std::vector<int>& nums)
        {
            int right = nums.size() - 1;

            while (right != 0)
            {
                for (int i = 0; i < right; i++)
                {
                    nums[i] = (nums[i] + nums[i + 1]) % 10;
                }

                right--;
            }

            return nums[0];
        }
    };
} // namespace p_2221_biweekly_75

/*
# Problem:
https://leetcode.com/problems/find-triangular-sum-of-an-array/

## HINT:
* Just simulate the whole process.

## Time Complexity:
BigO(n ^ 2)

## Space Complexity:
BigO(1)
*/