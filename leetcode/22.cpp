#include <vector>
#include <string>
#include <set>
using namespace std;

namespace p22
{
    class Solution
    {
        void addpar(vector<string>& v, const string& str, int left, int right) {
            if (left == 0 && right == 0)
            {
                v.push_back(str);
                return;
            }

            if (left > 0)
            {
                addpar(v, str + "(", left - 1, right + 1);
            }

            if (right > 0)
            {
                addpar(v, str + ")", left, right - 1);
            }
        }
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            addpar(res, "", n, 0);
            return res;
        }

        vector<string> generateParenthesis_self(int n) {
            if (n == 1)
            {
                return {"()"};
            }

            vector<string> pre = generateParenthesis_self(n - 1);
            set<string> res_set;
            for (const auto& taking : pre)
            {
                for (int i = 0; i <= taking.size(); ++i)
                {
                    if (i == taking.size())
                    {
                        auto s = taking + "()";
                        res_set.emplace(s);
                    }

                    for (int j = i + 1; j <= taking.size(); ++j)
                    {
                        auto s = taking.substr(0, i) + "(" + taking.substr(i, j - i) + ")" + taking.substr(j, taking.size() - j);
                        res_set.emplace(s);
                    }
                }
            }

            vector<string> res(res_set.begin(), res_set.end());
            return res;
        }
    };
} // namespace p22

/*
# Problem:

https://leetcode.com/problems/generate-parentheses/

## HINT:

Use recursive.
Only output a right after one left already be presented.

## Algorithm:

```
# Self
For n, one pair of '(' and ')' to combine with (n-1)'s result.
If n is 1, result is ["()"]
```

```
# Reference in discuss
In initial state, there are n left, 0 right, and empty string to be made combination.

res = {}
addpar(res, "", n, 0);
return res;

def addpar(res, str, n, m):
    if n == 0 and m == 0:
        res.append(str)

    addpar with str=str+"(", (n-1) left, and (m+1) right
    addpar with str=str+")", (n)   left, and (m)   right
```

## Time Complexity:
O(n^2)?

## Space Complexity:
O(n)
*/