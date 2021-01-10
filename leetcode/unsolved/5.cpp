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

Test Code:
namespace p5
{
    TEST(test_5, Case_1)
    {
        Solution s;
        string result = s.longestPalindrome("babad");
        string expect = "bab";
        ASSERT_EQ(result, expect);
    }

    TEST(test_5, Case_2)
    {
        Solution s;
        string result = s.longestPalindrome("cbbd");
        string expect = "bb";
        ASSERT_EQ(result, expect);
    }

    TEST(test_5, Case_3)
    {
        Solution s;
        string result = s.longestPalindrome("a");
        string expect = "a";
        ASSERT_EQ(result, expect);
    }

    TEST(test_5, Case_4)
    {
        Solution s;
        string result = s.longestPalindrome("ac");
        string expect = "a";
        ASSERT_EQ(result, expect);
    }
} // namespace p5
*/