#include "assert.h"
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

namespace p_18
{
    class Solution {
    public:
        std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
        {
            std::sort(nums.begin(), nums.end());

            // std::set<std::vector<int>> ret_set;
            std::vector<std::vector<int>> ret;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    int remaind = target - nums[i] - nums[j];

                    int l_ptr = j + 1;
                    int r_ptr = nums.size() - 1;

                    while (l_ptr < r_ptr)
                    {
                        int current_sum = nums[l_ptr] + nums[r_ptr];
                        if (remaind > current_sum)
                        {
                            l_ptr++;
                        }
                        else if (remaind < current_sum)
                        {
                            r_ptr--;
                        }
                        else // (remaind == current_sum)
                        {
                            // ret_set.emplace(std::vector<int>({ nums[i], nums[j], nums[l_ptr], nums[r_ptr] }));
                            ret.emplace_back(std::vector<int>({ nums[i], nums[j], nums[l_ptr], nums[r_ptr] }));
                            l_ptr++;
                            r_ptr--;

                            while (l_ptr < r_ptr && nums[l_ptr - 1] == nums[l_ptr]) ++l_ptr;                // skip duplicated cases
                            while (l_ptr < r_ptr && nums[r_ptr + 1] == nums[r_ptr]) --r_ptr;
                        }
                    }

                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j;                              // skip duplicated cases
                }
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;                                  // skip duplicated cases
            }

            // return std::vector<std::vector<int>>(ret_set.begin(), ret_set.end());
            return ret;
        }
    };
} // namespace p_18

/*
# Problem:
https://leetcode.com/problems/4sum/

## HINT:
* Sort first.
* Refers to 3sum, use two pointer.
* Skip the same value instead of using set to speed up.

## Time Complexity:
BigO(n^3)

## Space Complexity:
BigO(1) or BigO(sort)
*/