#include <stdint.h>
#include "assert.h"

namespace p_326
{
    class Solution {
    public:
        bool isPowerOfThree(int n)
        {
            if (n == 0)
            {
                return false;
            }

            while (n != 1)
            {
                if (n % 3 != 0)
                {
                    return false;
                }

                n /= 3;
            }

            return true;
        }
    };
} // namespace p_326

/*
# Problem:
https://leetcode.com/problems/power-of-three/

## HINT:
* Continuously % 3, and return false once the result is not zero, otherwise return true.
* Solution-2: For a integer, the max value is 2^31 - 1, and the max value of power of three is 3^19 (3^20 > 2^31 -1).
*             So, return 3^19 % n.

## Time Complexity:
BigO(log3(n))

## Space Complexity:
BigO(1)
*/