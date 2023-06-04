#include "assert.h"
#include <string>
#include <stack>

namespace p_227
{
    class Solution
    {
        long long getNextValue(std::string& s, int& start)
        {
            while (s[start] == ' ')
            {
                start++;
            }

            assert(s[start] >= '0' && s[start] <= '9');

            long long value = 0;
            for (start; start < s.size(); start++)
            {
                if (s[start] < '0' || s[start] > '9')
                {
                    break;
                }
                else
                {
                    value = value * 10 + s[start] - '0';
                }
            }

            return value;
        }

    public:
        int calculate(std::string s)
        {
            char pre_op = '+';
            int val1, val2;
            val1 = 0;
            val2 = 0;

            int pos = 0;
            while (pos < s.size())
            {
                if (s[pos] >= '0' && s[pos] <= '9')
                {
                    long long value = getNextValue(s, pos);
                    val2 = value;
                }
                else if (s[pos] == ' ')
                {
                    pos++;
                }
                else
                {
                    if (s[pos] == '+' || s[pos] == '-')
                    {
                        assert(pre_op == '+' || pre_op == '-');
                        if (pre_op == '+')
                        {
                            val1 += val2;
                            val2 = 0;

                            pre_op = s[pos];
                        }
                        else
                        {
                            val1 -= val2;
                            val2 = 0;

                            pre_op = s[pos];
                        }

                        pos++;
                    }
                    else
                    {
                        char op = s[pos++];
                        long long value = getNextValue(s, pos);

                        if (op == '*')
                        {
                            val2 *= value;
                        }
                        else
                        {
                            val2 /= value;
                        }
                    }
                }
            }

            return pre_op == '+' ? val1 + val2 : val1 - val2;
        }
    };
} // namespace p_227

/*
# Problem:
https://leetcode.com/problems/basic-calculator-ii/

## HINT:
* Use a stack(or just two value).
* For operator '*' and '/', get the next and calculate immediately.
* For operator '+' and '-', calculate the top 2 values and set it back to stack(or val1) to keep the space utilization is just 2.

## Time Complexity:
BigO(len(str))

## Space Complexity:
BigO(1)
*/