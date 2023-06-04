#include <stdint.h>

namespace p_curated_binary_190_reverse_bits
{
    class Solution
    {
    public:
        uint32_t reverseBits(uint32_t n)
        {
            uint32_t ans = 0;

            for (int i = 0; i < 32; ++i)
            {
                ans = (ans << 1) | ((n >> i) & 0x1);
            }

            return ans;
        }
    };
} // namespace p_curated_binary_190_reverse_bits

/*
# Problem:
https://leetcode.com/problems/reverse-bits/

## HINT:
* Use bitwise operator
* Can not just loop until n is 0. It should loop 32 times to make sure reverse value is correct.

## Algorithm:

ans = 0;

for i in range(0, 32):
    ans = (ans << 1) | ((n >> i) & 0x1)

return ans

## Time Complexity:
BigO(32)

## Space Complexity:
BigO(1)
*/