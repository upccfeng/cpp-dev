#include "assert.h"
#include <vector>
#include <queue>

namespace p_2208_biweekly_74
{
    class Solution {
    public:
        int halveArray(std::vector<int>& nums)
        {
            double target = 0;

            std::priority_queue<double, std::vector<double>, std::less<double>> pq;
            for (auto n : nums)
            {
                pq.push(n);
                target += n;
            }

            double current_sum = target;
            target /= 2;

            int ret = 0;
            while (current_sum > target)
            {
                double top = pq.top();
                pq.pop();

                current_sum -= top;
                top /= 2;
                current_sum += top;

                pq.push(top);

                ret++;
            }

            return ret;
        }
    };
} // namespace p_2208_biweekly_74

/*
# Problem:
https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

## HINT:
* Use heap and halve the biggest one for each operation.

## Time Complexity:
BigO(n * log(n) * k), k is the times to reduce to half.

## Space Complexity:
BigO(n)
*/