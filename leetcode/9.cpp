#include <limits.h>
using namespace std;

namespace p9
{
    class Solution
    {
    public:
        bool isPalindrome(int x) {
             if (x < 0)
            {
                return false;
            }

            int taking = x, pal_int = 0;
            while(taking > 0)
            {
                if (pal_int > (INT_MAX - taking % 10) / 10)
                {
                    break;
                }

                pal_int = pal_int * 10 + taking % 10;
                taking = taking / 10;
            }

            if (pal_int == x)
                return true;

            return false;
        }
    };
} // namespace p9

/*
# Problem:
https://leetcode.com/problems/palindrome-number/

## HINT:

## Algorithm:

```python
if negative:
    return false
taking = x
pal = 0
while(taking > 0):
    if is_overflow(pal, taking%10):
        return false

    pal = pal * 10 + taking % 10
    taking = taking / 10

if (pal == x)
    return true

return false
```

## Time Complexity:
O(n)

## Space Complexity:
O(1)
*/