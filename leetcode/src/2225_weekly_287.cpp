#include <vector>
#include <map>

namespace p_2225_weekly_287
{
    class Solution {
    public:
        std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
        {
            std::map<int, std::pair<int, int>> result_cnt;

            for (auto& m : matches)
            {
                result_cnt[m[0]].first++;
                result_cnt[m[1]].second++;
            }

            std::vector<std::vector<int>> ret(2, std::vector<int>());

            for (auto& kv : result_cnt)
            {
                if (kv.second.second == 0)
                {
                    ret[0].push_back(kv.first);
                }

                if (kv.second.second == 1)
                {
                    ret[1].push_back(kv.first);
                }
            }

            return ret;
        }
    };
} // namespace p_2225_weekly_287

/*
# Problem:
https://leetcode.com/problems/find-players-with-zero-or-one-losses/

## HINT:
* Using map instead of unordered_map to get increasing order result.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/