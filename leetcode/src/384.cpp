#include "assert.h"
#include <cstdlib>
#include <vector>

namespace p_384
{
    class Solution
    {
        std::vector<int> nums;

    public:
        Solution(std::vector<int>& nums) : nums(std::move(nums)) {}

        std::vector<int> reset()
        {
            return nums;
        }

        std::vector<int> shuffle()
        {
            std::vector<int> copy = nums;

            for (int i = 0; i < copy.size(); i++)
            {
                int random_pos = std::rand() % nums.size();

                std::swap(copy[i], copy[random_pos]);
            }

            return copy;
        }
    };
} // namespace p_384

/*
# Problem:
https://leetcode.com/problems/shuffle-an-array/

## HINT:
* For a random shuffled list, for each elements in copy, swap with a random position of copy.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/