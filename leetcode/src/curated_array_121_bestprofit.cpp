#include <vector>

namespace p_curated_array_121_bestprofit
{
    class Solution
    {
    public:
        int maxProfit(std::vector<int>& prices)
        {
            int max = 0;
            int min = prices[0];

            for (int i = 1; i < prices.size(); ++i)
            {
                if (prices[i] < min)
                {
                    min = prices[i];
                }
                else
                {
                    if (prices[i] - min > max)
                    {
                        max = prices[i] - min;
                    }
                }
            }
            return max;
        }
    };
} // namespace p_curated_array_121_bestprofit

/*
# Problem:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## HINT:
if prices[i + 1] < prices[i], the profit must be higher by using prices[i + 1]

## Algorithm:

max = 0
min = prices[0]

for e in prices:
    if (e < min):
        min = e
    else:
        if (e - min > max):
            max = e - min

return max

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/