#include <cstdint>

namespace p_curated_binary_191_numbers_of_1_bits
{
    class Solution
    {
    public:
        int hammingWeight(uint32_t n)
        {
            int cnt = 0;
            while (n != 0)
            {
                cnt += (n & 0x1);

                n >>= 1;
            }

            return cnt;
        }
    };
} // namespace p_curated_binary_191_numbers_of_1_bits

/*
# Problem:
https://leetcode.com/problems/number-of-1-bits/

## HINT:
* Bitwise operator

## Algorithm:

cnt = 0
while (n != 0):
    cnt += (n & 0x1)
    n >>= 1

return cnt

## Time Complexity:
Worst Case: BigO(32)

## Space Complexity:
BigO(1)
*/