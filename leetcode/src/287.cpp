#include "assert.h"
#include <vector>

namespace p_287
{
    class Solution {
    public:
        int findDuplicate(std::vector<int>& nums)
        {
            int slow = 0;
            int fast = 0;

            do
            {
                int next;

                slow = nums[slow];
                fast = nums[nums[fast]];
            } while (slow != fast);

            int iter = 0;

            while (iter != slow)
            {
                iter = nums[iter];
                slow = nums[slow];
            }

            return iter;
        }
    };
} // namespace p_287

/*
# Problem:
https://leetcode.com/problems/find-the-duplicate-number/

## HINT:
* Treat it like linked list. Detect the cycle and the begin of the cycle by floyd's algorithm.
* Each position will point out the next position. A position pointed by multiple position means there is a cycle.
* Position-0 is promised not in the cycle due to the values will only be 1->n.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/