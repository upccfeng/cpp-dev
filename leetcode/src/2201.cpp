#include "assert.h"
#include <vector>
#include <unordered_map>

namespace p_2201_weekly
{
    class Solution
    {
    public:
        int digArtifacts(int n, std::vector<std::vector<int>>& artifacts, std::vector<std::vector<int>>& dig)
        {
            std::vector<std::vector<int>> grid(n, std::vector<int>(n, -1));

            std::unordered_map<int, int> artifacts_cnt;

            int art_id = 0;
            for (const auto& art : artifacts)
            {
                assert(art.size() == 4);

                int left_top_r = art[0];
                int left_top_c = art[1];
                int right_bottom_r = art[2];
                int right_bottom_c = art[3];

                for (int r = left_top_r; r <= right_bottom_r; r++)
                {
                    for (int c = left_top_c; c <= right_bottom_c; c++)
                    {
                        grid[r][c] = art_id;

                        artifacts_cnt[art_id]++;
                    }
                }

                art_id++;
            }

            int ret = 0;
            for (const auto& d : dig)
            {
                int r = d[0];
                int c = d[1];

                int id = grid[r][c];

                if (id != -1)
                {
                    artifacts_cnt[id]--;

                    if (artifacts_cnt[id] == 0)
                    {
                        ret++;
                    }
                }
            }

            return ret;
        }
    };
} // namespace p_2201_weekly

/*
# Problem:
https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

## HINT:
* Count the remained number of artifacts, if reach 0, ret++

## Time Complexity:
BigO(n * n)

## Space Complexity:
BigO(n * n)
*/