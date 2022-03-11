#include "assert.h"
#include <vector>
#include <string>
#include <stack>

namespace p_150
{
    class Solution
    {

        bool isOperator(const std::string& str)
        {
            if (str.size() == 1 &&
                (str == "+" || str == "-" || str == "*" || str == "/"))
            {
                return true;
            }

            return false;
        }

        int getValue(const std::string& str)
        {
            int sign = 1;
            int value = 0;

            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == '-')
                {
                    assert(i == 0);

                    sign = -1;
                }
                else
                {
                    int val = str[i] - '0';

                    value = value * 10 + val;
                }
            }

            return value * sign;
        }

    public:
        int evalRPN(std::vector<std::string>& tokens)
        {
            std::stack<int> values;
            for (const auto& token : tokens)
            {
                if (isOperator(token))
                {
                    assert(values.size() >= 2);

                    int v1 = values.top();
                    values.pop();
                    int v2 = values.top();
                    values.pop();

                    int val;
                    if (token == "+")
                    {
                        val = v2 + v1;
                    }
                    else if (token == "-")
                    {
                        val = v2 - v1;
                    }
                    else if (token == "*")
                    {
                        val = v2 * v1;
                    }
                    else // token == "/"
                    {
                        val = v2 / v1;
                    }

                    values.push(val);
                }
                else
                {
                    int val = getValue(token);
                    values.push(val);
                }
            }

            assert(values.size() == 1);

            return values.top();
        }
    };
} // namespace p_150

/*
# Problem:
https://leetcode.com/problems/evaluate-reverse-polish-notation/

## HINT:
* Use stack.
* For each number, push it into stack.
* For each operator, calculate the top 2 of stack.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/