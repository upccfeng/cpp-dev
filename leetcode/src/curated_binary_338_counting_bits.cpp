#include <vector>

namespace p_curated_binary_338_counting_bits
{
    class Solution
    {
    public:
        std::vector<int> countBits(int n)
        {
            std::vector<int> ans(n + 1);

            for (int i = 0; i < n + 1; ++i)
            {
                int cnt = 0;
                int taking = i;
                while (taking != 0)
                {
                    if (taking & 0x1)
                    {
                        ++cnt;
                    }
                    taking >>= 1;
                }

                ans[i] = cnt;
            }

            return ans;
        }
    };
} // namespace p_curated_binary_338_counting_bits

/*
# Problem:
https://leetcode.com/problems/counting-bits/

## HINT:

## Algorithm:

ans = []

for i in range(0, n + 1):
    cnt = 0
    taking = i
    while (taking != 0):
        if (taking & 0x1):
            ++cnt
        taking >>= 1

    ans[i] = cnt
}

return ans;

## Time Complexity:
Worst Case: BigO(n*32)

## Space Complexity:
BigO(1)
*/