#include <vector>

namespace p_2212_weekly_285
{
    class Solution
    {
        void calculate(std::vector<int>& Arrows, std::vector<int>& ret, int& ret_total, std::vector<int>& current, int current_total, int pos, int left_arrows)
        {
            if (left_arrows < 0 || pos < 0)
            {
                if (left_arrows >= 0)
                {
                    if (current_total > ret_total)
                    {
                        current[0] += left_arrows;
                        ret = current;
                        ret_total = current_total;
                    }
                }

                return;
            }

            if (left_arrows == 0)
            {
                if (current_total > ret_total)
                {
                    ret = current;
                    ret_total = current_total;
                }
            }

            // ok
            current_total += pos;
            current[pos] = Arrows[pos] + 1;
            calculate(Arrows, ret, ret_total, current, current_total, pos - 1, left_arrows - current[pos]);
            current[pos] = 0;
            current_total -= pos;

            // no okay
            calculate(Arrows, ret, ret_total, current, current_total, pos - 1, left_arrows);
        }

    public:
        std::vector<int> maximumBobPoints(int numArrows, std::vector<int>& aliceArrows)
        {
            std::vector<int> ret(aliceArrows.size());

            std::vector<int> current(aliceArrows.size());
            int points = 0;
            calculate(aliceArrows, ret, points, current, 0, aliceArrows.size() - 1, numArrows);

            return ret;
        }
    };
} // namespace p_2212_weekly_285

/*
# Problem:
https://leetcode.com/problems/maximum-points-in-an-archery-competition/

## HINT:
* Recursive for each score for picking or not picking.
* Record the combination which is max.
* Deal with the case that there is no choice but to shut to 0-score.

## Time Complexity:
BigO(2^12)

## Space Complexity:
BigO(12)
*/