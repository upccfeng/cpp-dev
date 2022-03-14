#include "assert.h"
#include <vector>
#include <algorithm>

namespace p_189
{
    class Solution {
        void reverse(std::vector<int>& nums, int l, int r)
        {
            while (l < r)
            {
                std::swap(nums[l], nums[r]);

                l++;
                r--;
            }
        }

    public:
        void rotateSpace1(std::vector<int>& nums, int k)
        {
            k = k % nums.size();

            if (k == 0)
            {
                return;
            }

            reverse(nums, 0, nums.size() - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, nums.size() - 1);
        }

        void rotateSpaceN(std::vector<int>& nums, int k)
        {
            std::vector<int> copy(nums.begin(), nums.end());

            k = k % nums.size();

            for (int i = 0; i < copy.size(); i++)
            {
                int pos = (i + k) % nums.size();

                nums[pos] = copy[i];
            }
        }

        void rotate(std::vector<int>& nums, int k)
        {
            rotateSpace1(nums, k);
        }
    };
} // namespace p_189

/*
# Problem:
https://leetcode.com/problems/rotate-array/

## HINT:
* Use reverse concept to reach BigO(1) space.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n) or BigO(1)
*/