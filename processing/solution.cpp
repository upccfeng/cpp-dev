#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

namespace p8
{
    class Solution
    {
        bool is_overflow(bool sign, int data, int e)
        {
            if (sign)
            {
                if (data <= (INT_MAX - e) / 10)
                    return false;
            }
            else
            {
                if (data >= (INT_MIN + e) / 10)
                    return false;
            }
            return true;
        }
    public:
        int myAtoi(std::string s)
        {

            auto a = -5 % 10;
            bool sign = true;
            int data = 0;
            bool start = false;

            for (const auto& e : s)
            {
                if (e == '-' || e == '+')
                {
                    if (!start)
                    {
                        start = true;
                        sign = (e == '+') ? true : false;
                    }
                    else
                        return data;
                }
                else if (e == ' ')
                {
                    if (!start)
                    {
                        continue;
                    }
                    else
                        return data;
                }
                else if (e > 57 || e < 48)
                {
                    return data;
                }
                else
                {
                    start = true;
                    if (is_overflow(sign, data, e - 48))
                    {
                        return sign ? pow(2, 31) -1 : -pow(2, 31);
                    }
                    else
                    {
                        data = sign ? data * 10 + (e - 48) : data * 10 - (e - 48);
                    }
                }
            }

            return data;
        }
    };
} // namespace p8

/*
# Problem:
https://leetcode.com/problems/string-to-integer-atoi/

## HINT:
use marco to avoid the time spend in pow().
use INT_MAX and INT_MIN instead of `pow(2, 31) - 1` and `-pow(2, 31)`

ASCII:
' ' -> 32
'-' -> 45
'+' -> 43
'0' -> 48
'9' -> 57

## Algorithm:

```pseudo code
sign = true
data = 0
start = false

for e in s:
    if e == '+' or e == '-':
        if not start:
            sign = true
        else:
            return data
    elif e == ' ':
        if not start:
            continue:
        else:
            return data
    elif e > 57 or e < 48:
        return data
    else:
        if not start:
            start = true
            data = data * 10 + (e-48)
            data = sign ? data : -data
        else:
            if is_overflow(sign, data, e):
                return sign ? pow(2, 31) -1 : -pow(2, 31);
            else:
                data = sign ? data : -data
```


## Time Complexity:
log(n)

## Space Complexity:
log(1)
*/