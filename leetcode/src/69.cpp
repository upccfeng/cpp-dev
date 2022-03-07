namespace p_69
{
    class Solution
    {
    public:
        int mySqrt(int x)
        {
            if (x == 0 || x == 1)
            {
                return x;
            }

            int right = x / 2;
            int left = 0;

            while (left < right)
            {
                int taking = (left + right) / 2 + 1;

                if (taking > x / taking)
                {
                    right = taking - 1;
                }
                else // (taking * taking < x)
                {
                    left = taking;
                }
            }
            return left;
        }
    };
} // namespace p_69

/*
# Problem:
https://leetcode.com/problems/sqrtx/

## HINT:
* The probably answer is from 0 ~ x/2.
* Use binary search.
* For left < right condition, use left + 1 will choose the more right one, use right - 1 will choose the more left one.

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(1)
*/