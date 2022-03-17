#include "assert.h"
#include <vector>

namespace p_283
{
    class Solution {
    public:
        void moveZeroes(std::vector<int>& nums)
        {
            int l = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != 0)
                {
                    if (i != l)
                    {
                        std::swap(nums[i], nums[l]);
                    }

                    l++;
                }
            }

        }
    };
} // namespace p_283

/*
# Problem:
https://leetcode.com/problems/move-zeroes/

## HINT:
* To do in-place movements, record the last none zero positon.
* Swap the taking and none zero position once the taking is none zero and none zero position++.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/