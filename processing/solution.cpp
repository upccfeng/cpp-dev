#include <string>
#include <cmath>

using namespace std;

namespace p8
{
    class Solution
    {
        bool is_overflow(bool sign, int data, int e)
        {
            if (sign)
            {
                if (data <= (pow(2, 31) - 1 - e) / 10)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                if (-data >= (-pow(2, 31) + e) / 10)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    public:
        int myAtoi(std::string s)
        {
            bool sign = true;
            long long int data = 0;
            bool start = false;

            for (const auto& e : s)
            {
                if (e == '-')
                {
                    if (start)
                    {
                        return sign ? data : -data;
                    }

                    start = true;
                    sign = false;
                }
                else if (e == '+')
                {
                    if (start)
                    {
                        return sign ? data : -data;
                    }

                    start = true;
                    sign = true;
                }
                else if (e == ' ')
                {
                    if (start)
                    {
                        break;
                    }
                }
                else if (e > 57 || e < 48)
                {
                    if (start)
                    {
                        break;
                    }
                    else
                    {
                        return 0;
                    }

                    sign = true;
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
                        data = data * 10 + (e - 48);
                    }
                }
            }

            return sign ? data : -data;
        }
    };
} // namespace p8

/*
# Problem:
https://leetcode.com/problems/string-to-integer-atoi/

## HINT:

## Algorithm:

ASCII:
'-' -> 45
'+' -> 43
'0' -> 48
'9' -> 57

```pseudo code
sign = 1
data = 0
start = false

for e in s:
    if e == 45:
        sign = false
    elif e == 43:
        sign = true
    elif e > 57 or e < 48:
        sign = true
        if start:
            break
    else:
        start = true
        if is_overflow(sign, data, e):
            return 2^31 - 1 ? sign : -2^31
        else:
            data = data * 10 + (e-48)

return data ? sign : -data
```


## Time Complexity:

## Space Complexity:
*/