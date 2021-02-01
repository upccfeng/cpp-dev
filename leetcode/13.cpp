#include <string>
#include <map>

using namespace std;

namespace p13
{
    class Solution
    {
    public:
        int romanToInt(string s) {
            std::map<char, int> roman_char_map = {
                {'M', 1000},
                {'D', 500},
                {'C', 100},
                {'L', 50},
                {'X', 10},
                {'V', 5},
                {'I', 1},
            };

            int result = 0;

            for (auto it = s.begin(); it != s.end(); ++it)
            {

                if (*it == 'I' && *(it + 1) == 'V')
                {
                    result += 4;
                    ++it;
                }
                else if (*it == 'I' && *(it + 1) == 'X')
                {
                    result += 9;
                    ++it;
                }
                else if (*it == 'X' && *(it + 1) == 'L')
                {
                    result += 40;
                    ++it;
                }
                else if (*it == 'X' && *(it + 1) == 'C')
                {
                    result += 90;
                    ++it;
                }
                else if (*it == 'C' && *(it + 1) == 'D')
                {
                    result += 400;
                    ++it;
                }
                else if (*it == 'C' && *(it + 1) == 'M')
                {
                    result += 900;
                    ++it;
                }
                else
                {
                    result += roman_char_map[*it];
                }
            }
            return result;
        }
    };
} // namespace p13

/*
# Problem:
https://leetcode.com/problems/roman-to-integer/

## HINT:

just list all rule and take care them in if-else.

## Algorithm:

```
roman_char_map = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1},
};

def is_special_case(c1, c2):
    if c1+c2 in ['IV', 'IX', 'XL', 'XC', 'CD', 'CM']:
        return true

result = 0
for e in s:
    if is_special_case(e, e+1):
        result += specail_case_table(e, e+1)
    else:
        result += roman_char_table[e]

return result
```

## Time Complexity:
log(n) - which n is length of input string - s.

## Space Complexity:
log(7) -> log(1)
P.S. the space can be avoid if use if-else to get roman-char value.
*/