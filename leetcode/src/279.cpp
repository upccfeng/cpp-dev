#include "assert.h"
#include <vector>
#include <cmath>

namespace p_279
{
    class Solution {

        int getMin(std::vector<int>& dp, int max_factor, int target)
        {
            int min = INT_MAX;
            for (int i = 1; i <= max_factor && i * i < target; i++)
            {
                min = std::min(min, dp[i * i] + dp[target - i * i]);
            }

            return min;
        }

    public:
        int numSquares(int n) {

            std::vector<int> dp(n + 1, 0);

            int max = std::pow(n, 0.5);

            for (int i = 1; i <= max; i++)
            {
                dp[i * i] = 1;
            }


            for (int i = 2; i < dp.size(); i++)
            {
                if (dp[i] == 0)
                {
                    dp[i] = getMin(dp, max, i);
                }
            }

            return dp[n];
        }
    };
} // namespace p_279

/*
# Problem:
https://leetcode.com/problems/perfect-squares/

## HINT:
* Use a dp and go through from 1 to n.
* The values of perfect square (1, 4, 9, ...) position are 1.
* To find the min, just find the combination of perfect square and the left to reduce the time.

## Time Complexity:
BigO(n * sqrt(n))

## Space Complexity:
BigO(n)
*/