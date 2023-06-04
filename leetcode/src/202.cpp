#include "assert.h"
#include <unordered_set>

namespace p_202
{
    class Solution {
    public:
        bool isHappy(int n)
        {
            std::unordered_set<int> pattern;

            while (n != 1)
            {
                if (pattern.find(n) != pattern.end())
                {
                    return false;
                }

                pattern.insert(n);

                int new_n = 0;

                while (n != 0)
                {
                    int digit = n % 10;
                    new_n += digit * digit;
                    n /= 10;
                }

                n = new_n;
            }

            return true;
        }
    };
} // namespace p_202

/*
# Problem:
https://leetcode.com/problems/happy-number/

## HINT:
* Use hash.

## Time Complexity:
BigO(??)

## Space Complexity:
BigO(??)
*/