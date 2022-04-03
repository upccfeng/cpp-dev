#include <vector>

namespace p_2226_weekly_287
{
    class Solution {
    public:
        int maximumCandies(std::vector<int>& candies, long long k)
        {
            long long sum = 0;
            long long max = INT_MIN;
            for (int i = 0; i < candies.size(); i++)
            {
                if (candies[i] > max)
                {
                    max = candies[i];
                }

                sum += candies[i];
            }

            if (sum < k)
            {
                return 0;
            }

            long long left = 1;
            long long right = max;

            while (left <= right)
            {
                long long mid = (left + right) / 2;

                long long cnt = 0;

                for (int i = 0; i < candies.size(); i++)
                {
                    cnt += candies[i] / mid;
                }

                if (cnt < k)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return left - 1;

        }
    };
} // namespace p_2226_weekly_287

/*
# Problem:
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

## HINT:
* Binary search from 0 to Max of candies.

## Time Complexity:
BigO(n + log(Max))

## Space Complexity:
BigO(1)
*/