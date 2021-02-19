#include <string>
#include <stack>

using namespace std;

namespace p20
{
    class Solution
    {
    public:
        bool isValid(string s) {
            std:stack<char> pro_stack;

            for (const auto& e : s)
            {
                if (e == '(')
                {
                    pro_stack.emplace('(');
                }
                else if (e == '[')
                {
                    pro_stack.emplace('[');
                }
                else if (e == '{')
                {
                    pro_stack.emplace('{');
                }
                else if (e == ')')
                {
                    if (pro_stack.empty())
                        return false;

                    auto pop = pro_stack.top();
                    pro_stack.pop();
                    if (pop == '(')
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (e == ']')
                {
                    if (pro_stack.empty())
                        return false;

                    auto pop = pro_stack.top();
                    pro_stack.pop();
                    if (pop == '[')
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (e == '}')
                {
                    if (pro_stack.empty())
                        return false;

                    auto pop = pro_stack.top();
                    pro_stack.pop();
                    if (pop == '{')
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }

            if (pro_stack.empty())
                return true;
            else
                return false;
        }
    };
} // namespace p20

/*
# Problem:

https://leetcode.com/problems/valid-parentheses/

## HINT:

Need to use a stack to record the order of left parentheses

## Algorithm:

```
stack = []
for e in s:
    if e in ['(', '[', '{']:
        stack.push(e)
    elif e in [')', ']', '}']:
        if stack.empty():
            return false

        p = stack.get_and_pop()
        if e == '(' and p == ')':
            pass
        elif e == '[' and p == ']':
            pass
        elif e == '{' and p == '}':
            pass
        else
            return false
    else:
        return false

if stack.empty():
    return true
else:
    return false
```

## Time Complexity:
log(n)

## Space Complexity:
log(n)
*/