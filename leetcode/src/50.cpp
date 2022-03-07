namespace p_50
{
    class Solution
    {
    public:
        double myPow(double x, int n)
        {
            if (n == 0)
            {
                return 1;
            }

            bool sign = true;

            long long lln = n;

            if (lln < 0)
            {
                sign = false;
                lln = -lln;
            }

            double rest = 1;

            while (lln != 1)
            {
                if (lln % 2 == 1)
                {
                    rest *= x;
                }
                x *= x;
                lln /= 2;
            }

            x *= rest;

            return sign ? x : 1 / x;
        }
    };
} // namespace p_50

/*
# Problem:
https://leetcode.com/problems/powx-n/

## HINT:
* Use 2^5 == (2^2)^2 * 2 concept
* Need to handle INT_MIN case

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(1)
*/