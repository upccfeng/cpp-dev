#include <string>

using namespace std;

namespace p696_daily
{
    class Solution
    {
    public:
        int countBinarySubstrings(string s)
        {
            int res = 0;
            for (int pos = 0; pos < s.size(); ++pos)
            {
                bool is_revers = false;
                int pre_cnt = 1;
                int post_cnt = 0;
                for (int i = pos + 1; i < s.size(); ++i)
                {
                    if (!is_revers && s[pos] == s[i])
                    {
                        ++pre_cnt;
                    }
                    else if (!is_revers && s[pos] != s[i])
                    {
                        is_revers = true;
                        ++post_cnt;
                    }
                    else if (is_revers && s[pos] != s[i])
                    {
                        ++post_cnt;
                    }
                    else
                    {
                        break;
                    }

                    if (post_cnt == pre_cnt)
                    {
                        pos += pre_cnt - 1;
                        res += pre_cnt;
                        break;
                    }
                }

                if (post_cnt != pre_cnt)
                    pos += pre_cnt - post_cnt - 1;
            }

            return res;
        }
    };
} // namespace p696_daily

/*
# Problem:

https://leetcode.com/problems/count-binary-substrings/

## HINT:

If match fail, remember to move iterator position for fitting requirement of time.

## Algorithm:

```
def countBinarySubstrings(s: str):
    res = 0
    pos = 0
    while pos < s.size():
        is_revers = false
        pre_cnt = 1
        post_cnt = 0
        i = pos + 1
        while i < s.size():
            if not is_revers and s[pos] == s[i]:
                pre_cnt += 1
            elif not is_revers and s[pos] != s[i]:
                is_revers = true
                post_cnt += 1
            elif is_revers and s[pos] != s[i]:
                ++post_cnt
            else:
                break

            if post_cnt == pre_cnt:
                pos += pre_cnt - 1
                res += pre_cnt
                break

            i += 1

        if post_cnt != pre_cnt:
            pos += pre_cnt - post_cnt - 1
        pos += 1

    return res
```

## Time Complexity:
O(n^2)

## Space Complexity:
O(1)
*/