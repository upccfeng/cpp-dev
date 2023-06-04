#include <vector>

namespace p_136
{
    class Solution
    {
    public:
        int singleNumber(std::vector<int>& nums)
        {
            int ret = 0;

            for (auto n : nums)
            {
                ret ^= n;
            }

            return ret;
        }
    };
} // namespace p_136

/*
# Problem:
https://leetcode.com/problems/single-number/

## HINT:
* Use bit operation with XOR
* A XOR 0 = A
* A XOR A = 0
* A XOR B XOR A = A XOR A XOR B = B

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/