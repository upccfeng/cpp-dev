#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>

namespace p_2718_weekly_348_fred
{
    class Solution {
    public:
        long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries) {
            std::set<int> occupied_row;
            std::set<int> occupied_col;

            std::reverse(queries.begin(), queries.end());

            long long result = 0;
            for (auto& q : queries)
            {
                int type = q[0];
                int idx = q[1];
                int value = q[2];

                if (type == 0)
                {
                    // fill row
                    int cnt = n - occupied_col.size();
                    result += occupied_row.count(idx) ? 0 : value * cnt;

                    occupied_row.insert(idx);
                }
                else
                {
                    // fill col
                    int cnt = n - occupied_row.size();
                    result += occupied_col.count(idx) ? 0 : value * cnt;

                    occupied_col.insert(idx);
                }
            }

            return result;
        }
    };
} // namespace p_2718_weekly_348_fred

/*
# Problem:
https://leetcode.com/problems/sum-of-matrix-after-queries/

## HINT:

## Time Complexity:

## Space Complexity:
*/