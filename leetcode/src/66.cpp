#include <vector>

using namespace std;

namespace p66
{
    class Solution
    {
    public:
        vector<int> plusOne(vector<int>& digits)
        {
            vector<int> ret;

            bool carry = true;
            for (int taking = digits.size() - 1; taking >= 0; --taking)
            {
                int current = digits[taking];
                if (carry)
                {
                    ++current;
                    if (current == 10)
                    {
                        ret.insert(ret.begin(), 0);
                        carry = true;
                    }
                    else
                    {
                        ret.insert(ret.begin(), current);
                        carry = false;
                    }
                }
                else
                {
                    ret.insert(ret.begin(), current);
                    carry = false;
                }
            }

            if (carry)
                ret.insert(ret.begin(), 1);

            return ret;
        }
    };
} // namespace p66

/*
# Problem:

https://leetcode.com/problems/plus-one/

## HINT:

iter from end to front, and use carry.

## Algorithm:

```
ret = []

carry = true
for taking = digits.size() - 1; taking >= 0; --taking:
    int current = digits[taking]
    if carry:
        ++current
        if current == 10:
            ret.insert(ret.begin(), 0)
            carry = true
        else:
            ret.insert(ret.begin(), current)
            carry = false
    else:
        ret.insert(ret.begin(), current)
        carry = false

if carry:
    ret.insert(ret.begin(), 1)

return ret
```

## Time Complexity:
O(n)

## Space Complexity:
O(n)
*/