#include "assert.h"

namespace p_172
{
    class Solution {
    public:
        int trailingZeroes(int n)
        {
            int ret = 0;
            ret += n / 5;
            ret += n / 25;      // one more five than 5
            ret += n / 125;     // one more five than 25
            ret += n / 625;     // one more five than 125
            ret += n / 3125;    // one more five than 625

            return ret;
        }
    };
} // namespace p_172

/*
# Problem:
https://leetcode.com/problems/factorial-trailing-zeroes/

## HINT:
* For each 5 will get one more zero.
* Due to than limit from 0 ~ 10^4, count the number of 5, 25, 125, 625, 3125

## Time Complexity:
BigO(1)

## Space Complexity:
BigO(1)
*/