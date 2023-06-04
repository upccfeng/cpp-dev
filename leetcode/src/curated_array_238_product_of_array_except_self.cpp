#include <vector>

namespace p_curated_array_238_product_of_array_except_self
{
    class Solution
    {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums)
        {
            int total_except_zero = 1;
            int zero_index = -1;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    if (zero_index == -1)
                        zero_index = i;
                    else
                        return std::vector<int>(nums.size());
                }
                else
                {
                    total_except_zero *= nums[i];
                }
            }

            std::vector<int> ans(nums.size());

            for (int i = 0; i < nums.size(); i++)
            {
                if (zero_index == -1)
                {
                    ans[i] = total_except_zero / nums[i];
                }
                else
                {
                    if (i == zero_index)
                    {
                        ans[i] = total_except_zero;
                    }
                }
            }

            return ans;
        }
    };
} // namespace p_curated_array_238_product_of_array_except_self

/*
# Problem:
https://leetcode.com/problems/product-of-array-except-self/

## HINT:
* Sum the not-zero elements.
* If there are over 2 elements that are zero, the ans will be all zero.

## Algorithm:

total = 1
zero_index = -1

for each e in nums:
    if e == 0:
        if zero_index == -1:
            zero_index = e.index()
        else:
            return all zero array
    else:
        total *= e

ans = []
for each i in range(0, nums.size()):
    if (zero_index == -1):
        ans[i] = total / nums[i]
    else:
        if (i == zero_index):
            ans[i] = total
        else:
            // do nothing, init are all zero

return ans

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/