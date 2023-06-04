#include <vector>

namespace p_134
{
    class Solution
    {
    public:
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
        {
            int total = 0;
            int current = 0;

            int ret = 0;
            for (int i = 0; i < gas.size(); i++)
            {
                int diff = gas[i] - cost[i];
                total += diff;

                current += diff;
                if (current < 0)
                {
                    ret = i + 1;
                    current = 0;
                }
            }

            return total < 0 ? -1 : ret;
        }
    };
} // namespace p_134

/*
# Problem:
https://leetcode.com/problems/gas-station/

## HINT:
* sum(gas) >= sum(cost) must have solution.
* Problem guarantee there is only one solution.
* One the current is less than zero means the start position is incorrect, so change it to i + 1.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/