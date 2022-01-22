#include <vector>

namespace p_curated_binary_268_missing_number
{
    class Solution
    {
    public:
        int missingNumber(std::vector<int>& nums)
        {
            int maxsum = (nums.size() + 1) * nums.size() / 2;

            int sum = 0;
            for (auto a : nums)
            {
                sum += a;
            }

            return maxsum - sum;
        }
    };
} // namespace p_curated_binary_268_missing_number

/*
# Problem:
https://leetcode.com/problems/missing-number/

## HINT:
* Use math concept: 1 + 2 + ... + n-1 + n == (1+n)*n / 2

## Algorithm:

maxsum = (nums.size() + 1) * nums.size() / 2

sum = 0
for a in nums:
    sum += a

return maxsum - sum

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/