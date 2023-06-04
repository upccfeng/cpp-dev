namespace p_2220_biweekly_75
{
    class Solution {
    public:
        int minBitFlips(int start, int goal)
        {
            int ret = start ^ goal;

            int cnt = 0;
            for (int i = 0; i < 32; i++)
            {
                if (ret & (1 << i))
                {
                    cnt++;
                }
            }

            return cnt;
        }
    };
} // namespace p_2220_biweekly_75

/*
# Problem:
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

## HINT:
* Use xor concept.

## Time Complexity:
BigO(32)

## Space Complexity:
BigO(1)
*/