#include <string>

using namespace std;

namespace p28
{
    class Solution
    {
    public:
        int strStr(string haystack, string needle)
        {
            if (needle == "")
                return 0;

            int pos = -1;
            int match = 0;
            for (int taking = 0; taking < haystack.size(); ++taking)
            {
                if (haystack[taking] == needle[match])
                {
                    match++;
                    if (match == needle.size())
                    {
                        pos = taking - match + 1;
                        break;
                    }
                }
                else
                {
                    taking = taking - match;
                    match = 0;
                }
            }

            return pos;
        }
    };
} // namespace p28

/*
# Problem:

https://leetcode.com/problems/implement-strstr/

## HINT:

Record the match count.
If unmatch, go back taking - match , and make match to 0.

## Algorithm:

```
if needle == "":
    return 0

pos = -1
match = 0

for taking in range(0, haystack.size()):
    if haystack[taking] == needle[match]:
        match++
        if match == needle.size():
            pos = taking - match + 1
            break
    else:
        taking = taking - match
        match = 0

return pos
```

## Time Complexity:
O(n+n/m)?

## Space Complexity:
O(1)
*/