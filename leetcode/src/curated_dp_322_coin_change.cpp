#include <limits.h>
#include <vector>
#include <unordered_map>

namespace p_curated_dp_322_coin_change
{
    class Solution
    {
        std::unordered_map<int, int> dp_map;


        int get_min(int left, std::vector<int>& coins)
        {
            if (dp_map.find(left) != dp_map.end())
                return dp_map[left];

            if (left == 0)
            {
                return 0;
            }
            else if (left < 0)
            {
                return -1;
            }
            else
            {
                int min = INT_MAX;

                for (auto e : coins)
                {
                    int amount_min = get_min(left - e, coins);

                    if (amount_min != -1)
                    {
                        min = std::min(min, 1 + amount_min);
                    }
                }

                dp_map[left] = min == INT_MAX ? -1 : min;

                return dp_map[left];
            }
        }

    public:
        int coinChange_recursive(std::vector<int>& coins, int amount)
        {
            return get_min(amount, coins);
        }

        int coinChange_bottom_up(std::vector<int>& coins, int amount)
        {
            std::vector<int> dp_list(amount + 1, amount + 1);

            dp_list[0] = 0;

            for (int i = 1; i < amount + 1; ++i)
            {
                for (auto coin : coins)
                {
                    if (i - coin >= 0)
                    {
                        dp_list[i] = std::min(dp_list[i], 1 + dp_list[i - coin]);
                    }
                }
            }

            return dp_list[amount] == amount + 1 ? -1 : dp_list[amount];
        }

        int coinChange(std::vector<int>& coins, int amount)
        {
            return coinChange_bottom_up(coins, amount);
        }
    };
} // namespace p_curated_dp_322_coin_change

/*
# Problem:
https://leetcode.com/problems/coin-change/

## HINT:
* Use decision tree.
* Find the min in DFS.
* Use dp to speed up
* Use bottom-up to speed up again.

## Algorithm:

recursive
```python

def get_min(coins, amount):
    if dp[amount] != NULL:
        return dp[amount]

    if amount == 0:
        return 0
    elif amount < 0:
        return -1
    else:
        min = INT_MAX

        for coin in coins:
            amount_min = get_min(coins, amount - coin)

            if (amount_min != -1):
                min = min(min, 1+amount_min)

        dp[amount] = min

        return dp[amount]

def main():
    get_min(coins, amount)
```

Bottom-up
```python
def main(coins, amount)
{
    dp_list = [amount + 1] * (amount + 1)

    dp_list[0] = 0;

    for i in range(1, amount+1):
        for coin in coins:
            if i - coin >= 0:
                dp_list[i] = min(dp_list[i], 1 + dp_list[i - coin])

    return dp_list[amount] if dp_list[amount] != amount + 1 else -1
}
```

## Time Complexity:
Big(n)

## Space Complexity:
Big(n * len(coins))
*/
