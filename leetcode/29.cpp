#include <limits.h>

using namespace std;

namespace p29
{
    class Solution
    {
    public:
        int divide(int dividend, int divisor)
        {
            if (divisor == 0 || dividend == INT_MIN && divisor == -1)
                return INT_MAX;

             int dividend_sign = 1, divisor_sign = 1;

            if (dividend < 0)
                dividend_sign = -1;

            if (divisor < 0)
                divisor_sign = -1;

            unsigned int A = divisor < 0 ? -(unsigned)divisor : divisor;
            unsigned int B = dividend < 0 ? -(unsigned)dividend : dividend;
            int ret = 0;

            for (int i = 31; i >= 0; --i)
            {
                if ((B >> i) >= A)
                {
                    ret = (ret << 1) | 0x1;
                    B -= (A << i);
                }
                else
                {
                    ret = ret << 1;
                }
            }

            if (ret == INT_MIN)
                return INT_MIN;

            return (dividend_sign * divisor_sign) * ret;
        }

        int divide_self(int dividend, int divisor)
        {
            int count = 0;

            int dividend_sign = 1, divisor_sign = 1;

            if (dividend < 0)
                dividend_sign = -1;

            if (divisor < 0)
                divisor_sign = -1;

            if (divisor == 1 || divisor == -1)
            {
                if (dividend == INT_MIN && divisor == -1)
                    return INT_MAX;

                return divisor_sign * dividend;
            }

            int remain = dividend;
            if (dividend >= 0)
            {
                while (remain > 0)
                {
                    if (count == INT_MAX)
                        return INT_MAX;

                    if (divisor == INT_MIN && dividend_sign == 1)
                    {
                        remain = -1;
                    }
                    else
                    {
                        remain = remain - (dividend_sign * divisor_sign) * divisor;

                        if (remain >= 0)
                        {
                            ++count;
                        }
                    }
                }
            }
            else
            {
                while (remain < 0)
                {
                    if (count == INT_MAX)
                        return INT_MAX;

                    remain = remain - dividend_sign * divisor_sign * divisor;

                    if (remain <= 0)
                    {
                        ++count;
                    }
                }
            }

            return dividend_sign * divisor_sign * count;
        }
    };
} // namespace p29

/*
# Problem:

https://leetcode.com/problems/divide-two-integers/

## HINT:

INT_MIN to positive will possibly cause overflow.
Use bitwise calculate to avoid overtime.

ret can be presented as a0 + a1*2^1 + a2*2^2 + ... + a31*2^31
divisor*ret = dividend
=> divisor*(a0 + a1*2^1 + a2*2^2 + ... + a31*2^31) = dividend

divide 2^31:
divisor*(a31) = dividend>>31
=> a31 = (dividend>>31)/divisor
if dividend>>31 > divisor, a31 will be 1, else 0

divide 2^30:
divisor*(a30+2*a31) = dividend>>30
=> a30 = (dividend>>30 - 2*a31*divisor)divisor
=> a30 = (B-a31*divisor<<31)>>30/divisor
-> B' = B-a31*divisor<<31
=> a30 = B'>>30/divisor
Can get B' by a31
...

## Algorithm:

```
if divisor == 0 || dividend == INT_MIN && divisor == -1:
    return INT_MAX

    int dividend_sign = 1, divisor_sign = 1
if dividend < 0:
    dividend_sign = -1
if divisor < 0:
    divisor_sign = -1

unsigned int A = divisor < 0 ? -(unsigned)divisor : divisor;
unsigned int B = dividend < 0 ? -(unsigned)dividend : dividend;
ret = 0;

for int i = 31; i >= 0; --i:
    if (B >> i) >= A:
        ret = (ret << 1) | 0x1
        B -= (A << i)
    else:
        ret = ret << 1

# ret is unsigned value, so INT_MIN not mean negative
if ret == INT_MIN:
    return INT_MIN

return (dividend_sign * divisor_sign) * ret;
```

## Time Complexity:
log(32) -> log(1)

## Space Complexity:
log(1)
*/