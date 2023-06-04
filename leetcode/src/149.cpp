#include <map>
#include <vector>
#include <cmath>

namespace p_149
{
    class Solution
    {
        void miniXY(int& x, int& y)
        {
            int a = std::abs(x);
            int b = std::abs(y);

            int max_factor;
            while (a != 0 && b != 0)
            {
                if (a >= b)
                {
                    a = a % b;
                }
                else
                {
                    b = b % a;
                }
            }

            if (a > 0)
            {
                max_factor = a;
            }
            else
            {
                max_factor = b;
            }

            x /= max_factor;
            y /= max_factor;
        }

    public:
        int maxPoints(std::vector<std::vector<int>>& points)
        {
            if (points.size() < 3)
            {
                return points.size();
            }

            int max = 0;

            for (int base = 0; base < points.size(); base++)
            {
                std::map<std::pair<int, int>, int> diff_cnt;

                for (int other = base + 1; other < points.size(); other++)
                {
                    if (base != other)
                    {
                        int x_diff = points[other][0] - points[base][0];
                        int y_diff = points[other][1] - points[base][1];

                        if (x_diff < 0)
                        {
                            x_diff = -x_diff;
                            y_diff = -y_diff;
                        }

                        miniXY(x_diff, y_diff);

                        if (x_diff == 0 || y_diff == 0)
                        {
                            x_diff = std::abs(x_diff);
                            y_diff = std::abs(y_diff);
                        }

                        diff_cnt[{x_diff, y_diff}]++;

                        if (diff_cnt[{x_diff, y_diff}] > max)
                        {
                            max = diff_cnt[{x_diff, y_diff}];
                        }
                    }
                }
            }

            return max + 1;
        }
    };
} // namespace p_149

/*
# Problem:
https://leetcode.com/problems/max-points-on-a-line/

## HINT:
* Find each pair's proprotion(x_diff and y_diff), adjust them to make x_diff is positive.
* For the same proportions, count them together.
* If x_diff or y_diff is zero, make another as position value.

## Time Complexity:
BigO(n^2)

## Space Complexity:
BigO(n)
*/