#include <string>
#include <cmath>

using namespace std;

namespace p7
{
    class Solution
    {
    public:
        int reverse(int x)
        {
            std::string target = std::to_string(x);
            int data = 0;
            int sign = 1;
            auto it = target.end() - 1;
            for (it; it != target.begin(); --it)
            {
                if (data <= (pow(2, 31) - 1 - (*it - 48)) / 10)
                {
                    data = data * 10 + (*it - 48);
                }
                else
                {
                    return 0;
                }
            }

            if (*it == '-')
            {
                sign = -1;
            }
            else
            {
                if (data <= (pow(2, 31) - 1 - (*it - 48)) / 10)
                {
                    data = data * 10 + (*it - 48);
                }
                else
                {
                    return 0;
                }
            }

            return sign * data;
        }
    };
} // namespace p7

/*
# Problem:
https://leetcode.com/problems/reverse-integer/

## HINT:
max int(2^31 -1) reverse will overflow -> check if overflow before add element.

not to overflow -> data * 10 + element <= 2^31 - 1 -> data <= (2^31 - 1 - element) / 10

## Algorithm:

```python
s_input = int_to_string(input)
data = 0
sign = 1
for e from s_input.end()-1 to s_input.begin()+1:
    if not_overflow(data, e):
        data = data * 10 + e
    else
        return 0

e = s_input.begin()
if e == '-':
    sign = -1
else:
    if not_overflow(data, e):
        data = data * 10 + e
    else
        return 0
```

## Time Complexity:

O(T + N)

T is to_string time complexity.
N is the digits of input.

## Space Complexity:

O(N)

N is the digits of input.
*/