#include "assert.h"
#include <string>

namespace p_171
{
    class Solution
    {
    public:
        int titleToNumber(std::string columnTitle)
        {
            long long ret = 0;

            for (char c : columnTitle)
            {
                ret = ret * 26 + c - 'A' + 1;
            }

            return ret;
        }
    };
} // namespace p_171

/*
# Problem:
https://leetcode.com/problems/excel-sheet-column-number/

## HINT:
* Be careful of the overflow case.

## Time Complexity:
BigO(len(str))

## Space Complexity:
BigO(1)
*/