#include <vector>
#include <map>

namespace p_799
{
    class Solution
    {
        double input;

        // std::map<std::pair<int, int>, double> cache;
        std::vector<std::vector<double>> cache_v;

        double howFull(int row, int glass)
        {
            //std::pair<int, int> key = { row, glass };

            //if (cache.find(key) != cache.end())
            //{
            //    return cache[key];
            //}

            if (row == 0 && glass == 0)
            {
                return input;
            }

            if (glass < 0 || glass > row)
            {
                return 0.0;
            }

            if (cache_v[row][glass] != -1)
            {
                return cache_v[row][glass];
            }

            double left = std::max(0.0, (howFull(row - 1, glass - 1) - 1.0) / 2.0);
            double right = std::max(0.0, (howFull(row - 1, glass) - 1.0) / 2.0);


            //cache[key] = left + right;
            //return cache[key];
            cache_v[row][glass] = left + right;
            return cache_v[row][glass];
        }


    public:
        double champagneTower(int poured, int query_row, int query_glass)
        {
            cache_v.resize(101, std::vector<double>(101, -1));

            input = poured;
            return std::min(1.0, howFull(query_row, query_glass));
        }
    };
} // namespace p_799

/*
# Problem:
https://leetcode.com/problems/champagne-tower/

## HINT:
* Use cache or dp.
* ans will be min(1.0, howFull(row, glass)), howFull(row, glass) = max(0.0, (howFull(row - 1, glass -1) - 1) / 2) + max(0.0, (howFull(row - 1, glass) - 1) / 2)
*             ^^^^^^^                                                 ^^^^                                             ^^^^
*             can not over 1                                       treat negative as 0                            treat negative as 0

## Time Complexity:
BigO(100)

## Space Complexity:
BigO(100 * 100)
*/