#include <vector>
#include <cmath>
#include <algorithm>

namespace p_2191_biweekly
{
    class Solution
    {
        int getMappedValue(std::vector<int>& mapping, int target)
        {
            int new_value = 0;
            int times = 0;
            if (target == 0)
            {
                return mapping[0];
            }

            while (target)
            {
                int taking = target % 10;

                new_value = new_value + std::pow(10, times) * mapping[taking];

                target /= 10;
                times++;
            }

            return new_value;
        }

    public:
        std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums)
        {
            std::vector<std::pair<int, int>> nums_with_mapped_value(nums.size());

            for (int i = 0; i < nums.size(); i++)
            {
                nums_with_mapped_value[i] = { nums[i], getMappedValue(mapping, nums[i]) };
            }

            std::sort(nums_with_mapped_value.begin(), nums_with_mapped_value.end(), [](std::pair<int, int>& lhs, std::pair<int, int>& rhs) {
                if (lhs.second != rhs.second)
                {
                    return lhs.second < rhs.second;
                }
                else
                {
                    return false;
                }
                });

            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = nums_with_mapped_value[i].first;
            }

            return std::move(nums);
        }
    };
} // namespace p_2191_biweekly

/*
# Problem:
https://leetcode.com/problems/sort-the-jumbled-numbers/

## HINT:
* Implement the cmp function for sort
* Compare mapped value first, then return false if mapped value is the same to keep the order.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(n)
*/