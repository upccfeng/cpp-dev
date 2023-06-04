#include "assert.h"
#include <functional>

namespace p_277
{
    std::function<bool(int, int)> knows;

    class Solution
    {
    public:
        int findCelebrity(int n)
        {
            int candidate = 0;
            int taking = 1;

            while (taking < n)
            {
                if (knows(candidate, taking))
                {
                    candidate = taking;
                }

                taking++;
            }

            for (int i = 0; i < n; i++)
            {
                if (i != candidate && knows(candidate, i))
                {
                    return -1;
                }

                if (i != candidate && !knows(i, candidate))
                {
                    return -1;
                }
            }

            return candidate;
        }
    };
} // namespace p_277

/*
# Problem:
https://leetcode.com/problems/find-the-celebrity/

## HINT:
* If knows(a, b) == true, a will not be candidate.
* If knows(a, b) == false, b will not be candidate.
* From 0 -> n, find most possible to be the candidate just through a loop.
* For this most possible candidate, check all n with knows(candidate, n) and knows(n, candidate)

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/