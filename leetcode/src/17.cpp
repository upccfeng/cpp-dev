#include <vector>
#include <map>
#include <string>

using namespace std;

namespace p17
{
    class Solution
    {
        map<char, vector<char>> number_value_table = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };
    public:
        vector<string> letterCombinations(string digits)
        {
            if (digits.empty())
                return {};

            int len = digits.size();
            auto ans = output(digits.substr(0, len-1), digits.back());

            return ans;
        }

        vector<string> output(string left_string, char output_char)
        {
            int len = left_string.size();
            vector<string> out;
            if (len == 1)
            {
                for (const auto& l : number_value_table[left_string[0]])
                {
                    for (const auto& r : number_value_table[output_char])
                    {
                        string t = "";
                        t = t + l + r;
                        out.push_back(t);
                    }
                }
                return out;
            }
            else if (len > 1)
            {
                for (const auto& o : output(left_string.substr(0, len-1), left_string.back()))
                {
                    for (const auto& r : number_value_table[output_char])
                    {
                        string t = "";
                        t = t + o + r;
                        out.push_back(t);
                    }
                }
                return out;
            }
            else
            {
                for (const auto& r : number_value_table[output_char])
                {
                    string t = "";
                    t = t + r;
                    out.push_back(t);
                }
                return out;
            }
        }
    }; // namespace p17
} // namespace p17

/*
# Problem:

https://leetcode.com/problems/letter-combinations-of-a-phone-number/

## HINT:

recursive or DFS

## Algorithm:

```
def output(left_string, output_char):
    len = left_string.size()
    out = []
    if (len == 1):
        for (const auto& l : number_value_table[left_string[0]]):
            for (const auto& r : number_value_table[output_char]):
                t = ""
                t = t + l + r
                out.append(t)
        return out;
    elif (len > 1):
        for (const auto& o : output(left_string.substr(0, len-1), left_string.back()))
            for (const auto& r : number_value_table[output_char])
                t = ""
                t = t + o + r
                out.append(t)
        return out
    else:
        for (const auto& r : number_value_table[output_char]):
            t = ""
            t = t + r
            out.append(t)
        return out;

if (digits.empty())
    return {};

len = digits.size()
ans = output(digits.substr(0, len-1), digits.back())

return ans
```

## Time Complexity:
O(4^n)

## Space Complexity:
O(1)
*/