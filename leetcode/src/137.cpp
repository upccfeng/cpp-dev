#include <vector>

namespace p_137
{
    class Solution
    {
    public:
        int singleNumber(std::vector<int>& nums) {


            int ret = 0;
            for (int i = 0; i < 32; i++)
            {
                int cnt = 0;
                for (auto n : nums)
                {
                    if (n & (1 << i))
                    {
                        cnt++;
                    }
                }

                if (cnt % 3 == 1)
                {
                    ret = ret | (1 << i);
                }
            }

            return ret;

        }
    };
} // namespace p_137

/*
# Problem:
https://leetcode.com/problems/single-number-ii/

## HINT:
* Bit operation
* Count each bit's amount. If the result of amount % 3 will be one's bit value.

## Time Complexity:
BigO(32 * n)

## Space Complexity:
BigO(1)
*/