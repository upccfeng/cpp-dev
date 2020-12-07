#include <string>
#include <vector>
#include <map>

using namespace std;

namespace p5
{
    class Solution
    {
    public:
        string longestPalindrome(string s)
        {
            return "";
        }
    };
} // namespace p5

/*
Problem: https://leetcode.com/problems/longest-palindromic-substring/

HINT:

Algorithm:

```
for start_c in s:
    longgest_pal = start_c
    r_boundary = start_c.pos() + 1
    l_boundary = start_c.pos() - 1
    while(??):
        case: r == l:
        case: r == r-1:
        case: l == l+1:
```

Time Complexity:

Space Complexity:
*/