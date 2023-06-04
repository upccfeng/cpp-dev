#include <vector>

namespace p_curated_dp_70_climbing_stairts
{
    class Solution
    {
        std::vector<int> dp;

        int divide_conquer(int start, int target)
        {
            if (start == target)
            {
                return 1;
            }

            if (start > target)
            {
                return 0;
            }

            if (dp[start] != -1)
            {
                return dp[start];
            }

            dp[start] = divide_conquer(start + 1, target) + divide_conquer(start + 2, target);

            return dp[start];
        }
    public:
        int climbStairs_recursive(int n)
        {
            dp.resize(n + 1, -1);
            return divide_conquer(0, n);
        }

        int climbStairs(int n) // none-recursive
        {
            dp.resize(n + 1, -1);

            dp[n] = 1;
            dp[n - 1] = 1;

            for (int i = n - 2; i >= 0; --i)
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }

            return dp[0];
        }

        int climbStairs_save_space(int n)
        {
            int one, two;

            one = two = 1;

            for (int i = n - 2; i >= 0; --i)
            {
                int temp = one;
                one = two + one;
                two = temp;
            }

            return one;
        }
    };
} // namespace p_curated_dp_70_climbing_stairts

/*
# Problem:
https://leetcode.com/problems/climbing-stairs/

## HINT:
* Make a decision tree frist.
* Use dynamic programming (extra spaces as dp) to cache data to save time.
* f(m) means the number of ways from stair-m to stair-n.

## Algorithm:

dp = []

dp[n] = 1
dp[n - 1] = 1

i = n - 2
while (i >= 0):
    dp[i] = dp[i + 1] + dp[i + 2]
    n--

return dp[0]

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n): climbStairs_recursive() and climbStairs()
or
BigO(2): climbStairs_save_space()
*/