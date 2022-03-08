#include <vector>

namespace p_122
{
    class Solution
    {
    public:
        int maxProfit(std::vector<int>& prices) {
            int max = 0;

            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    max += prices[i] - prices[i - 1];
                }
            }

            return max;
        }
    };
} // namespace p_122

/*
# Problem:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

## HINT:
* profit(n) = profit(n - 1) + (if prices[n] - prices[n - 1] > 0, prices[n] - prices[n - 1] else 0)

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/