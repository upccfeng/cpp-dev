#include <vector>
#include <string>
using namespace std;

namespace p14
{
    class Solution
    {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty())
            {
                return "";
            }

            std::string prefix = "";
            int pos = 0;
            while (true)
            {
                for (const auto& s : strs)
                {
                    if (pos == s.size() || s[pos] != strs[0][pos])
                    {
                        return prefix;
                    }
                }
                prefix += strs[0][pos++];
            }

            return prefix;
        }
    };
} // namespace p14

/*
# Problem:
https://leetcode.com/problems/longest-common-prefix/submissions/

## HINT:

Need to check the string boundary.
Using check size before "or" to avoid out of boundary.

## Algorithm:

```
if strs.empty:
    return ""

prefix = ""
pos = 0
while true:
    for s : strs:
        if pos == s.size() or s[pos] != strs[0][pos]:
            return prefix
    prefix += strs[0][pos++]

return prefix
```

## Time Complexity:
log(m*n): m is the size of strs, and n is the length of longest str in strs

## Space Complexity:
log(1)
*/