#include <string>
#include <vector>

using namespace std;

namespace p1209_daily
{
    class Solution
    {
    public:
        string removeDuplicates(string s, int k)
        {
            using char_cnt = std::pair<char, int>;

            std::vector<char_cnt> res_stack;

            for (const auto c : s)
            {
                if (res_stack.empty() || res_stack.back().first != c)
                {
                    res_stack.push_back(std::make_pair(c, 1));
                }
                else
                {
                    if (res_stack.back().second + 1 == k)
                    {
                        res_stack.pop_back();
                    }
                    else
                    {
                        res_stack.back().second += 1;
                    }
                }
            }

            string res = "";

            for (const auto p : res_stack)
            {
                res.append(p.second, p.first);
            }

            return res;
        }
    };
} // namespace p1209_daily

/*
# Problem:

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

## HINT:

Using stack, and just increase the top's cnt if the incoming char is the same as top

## Algorithm:

```
def removeDuplicates(s, k):
    res_stack = [];
    res_cnt = []

    for c in s:
        if res_stack.empty() or res_stack.top() != c:
            res_stack.append(c)
            res_cnt.append(1)
        else:
            if res_cnt.top() + 1 == k:
                del res_stack.top()
            else:
                res_cnt.top() += 1

    res = ""

    for p_pos in range(0, res_stack.size()):
        res.append(res_cnt.top(), res_stack.top())

    return res
```

## Time Complexity:
O(n)

## Space Complexity:
O(n)
*/