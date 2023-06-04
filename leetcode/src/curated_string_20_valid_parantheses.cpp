#include <string>
#include <stack>

////////////////////////////////////////////////////////

namespace p_curated_string_20_valid_parantheses
{
    class Solution
    {
    public:
        bool isValid(std::string s)
        {
            std::stack<char> stack;

            for (const auto& c : s)
            {
                if (c == '(' || c == '[' || c == '{')
                {
                    // stack.push(c);
                    stack.emplace(c);
                }
                else
                {
                    if (stack.empty())
                    {
                        return false;
                    }

                    char taking = stack.top();

                    if (c == ')')
                    {
                        if (taking != '(')
                        {
                            return false;
                        }
                    }
                    else if (c == ']')
                    {
                        if (taking != '[')
                        {
                            return false;
                        }
                    }
                    else // c == '}'
                    {
                        if (taking != '{')
                        {
                            return false;
                        }
                    }

                    stack.pop();
                }
            }

            return stack.size() == 0;
        }
    };
} // namespace p_curated_string_20_valid_parantheses

/*
# Problem:
https://leetcode.com/problems/valid-parentheses/

## HINT:
* Use stack
* Pop should check the corresponding char.
* Handle the empty stack case.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/