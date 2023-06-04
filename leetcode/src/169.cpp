#include "assert.h"
#include <vector>

namespace p_169
{
    class Solution
    {
    public:
        int majorityElement(std::vector<int>& nums)
        {
            int votes = 0;
            int ret = -1;
            for (auto n : nums)
            {
                if (votes == 0)
                {
                    ret = n;
                }

                if (n == ret)
                {
                    votes++;
                }
                else
                {
                    votes--;
                }
            }

            return ret;

        }
    };
} // namespace p_169

/*
# Problem:
https://leetcode.com/problems/majority-element/

## HINT:
* Solution-1: use unordered_map and count the appearing number.
* Solution-2: Use vote algorithm, if votes == 0, change the candidate, if candidate is different to taking number, votes--.

## Time Complexity:
BigO(n)

## Space Complexity:
Solution-1: BigO(n)
Solution-2: BigO(1)
*/