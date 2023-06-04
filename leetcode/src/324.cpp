#include "assert.h"
#include <vector>
#include <algorithm>

namespace p_324
{
    class Solution {
    public:
        void wiggleSort(std::vector<int>& nums)
        {
            std::vector<int> tmp = nums;

            std::sort(tmp.begin(), tmp.end());

            int iter = tmp.size() - 1;
            for (int i = 1; i < nums.size(); i += 2)
            {
                nums[i] = tmp[iter--];
            }

            for (int i = 0; i < nums.size(); i += 2)
            {
                nums[i] = tmp[iter--];
            }
        }
    };
} // namespace p_324

/*
# Problem:
https://leetcode.com/problems/wiggle-sort-ii/

## HINT:
* Sort the nums first.
* Deal with the bigger one positions first (1, 3, 5, ...,). Extract max value from sorted nums.
* Then deal with the smaller one positions (0, 2, 4, ...,). Still extract the max value from sorted nums.
* For above rules, it guarantees the odd position will greater than even position and even position will not be equal to next due to there must be a valid answer.
* Method-2: Use quick select to find median. And use the median to do tree-way-partition with virtual index.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(n)
*/