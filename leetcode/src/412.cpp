#include "assert.h"
#include <vector>
#include <string>

namespace p_412
{
    class Solution
    {
    public:
        std::vector<std::string> fizzBuzz(int n)
        {
            std::vector<std::string> ret(n);

            for (int i = 1; i <= n; i++)
            {
                if (i % 3 != 0 && i % 5 != 0)
                {
                    ret[i - 1] += std::to_string(i);
                }
                else
                {
                    if (i % 3 == 0)
                    {
                        ret[i - 1] += "Fizz";
                    }

                    if (i % 5 == 0)
                    {
                        ret[i - 1] += "Buzz";
                    }
                }
            }

            return ret;
        }
    };
} // namespace p_412

/*
# Problem:
https://leetcode.com/problems/fizz-buzz/

## HINT:

## Time Complexity:
BigO(n * 8)

## Space Complexity:
BigO(8)
*/