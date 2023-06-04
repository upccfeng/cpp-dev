#include <vector>
#include <unordered_map>

namespace p_curated_graph_128_longest_consecutive_sequence
{
    class Solution
    {
        void dfs(std::unordered_map<int, bool>& exist, int taking, int& cnt)
        {
            if (exist.find(taking) == exist.end())
            {
                return;
            }
            else
            {
                ++cnt;
                dfs(exist, taking + 1, cnt);
                return;
            }
        }

    public:
        int longestConsecutive(std::vector<int>& nums)
        {
            int max_cnt = 0;

            std::unordered_map<int, bool> exist;

            for (auto e : nums)
            {
                exist[e] = true;
            }

            for (auto e : nums)
            {
                // Start just from begining
                auto isBegin = exist.find(e - 1) == exist.end();
                if (isBegin)
                {
                    // Recursive Way
                    // int cnt = 0;
                    // dfs(exist, e, cnt);

                    int cnt = 1;
                    auto next = exist.find(e + cnt);
                    while (next != exist.end())
                    {
                        ++cnt;

                        next = exist.find(e + cnt);
                    }

                    if (cnt > max_cnt)
                        max_cnt = cnt;
                }
            }

            return max_cnt;
        }
    };
} // namespace p_curated_graph_128_longest_consecutive_sequence

/*
# Problem:
https://leetcode.com/problems/longest-consecutive-sequence/

## HINT:
* Construct a set(map) to know what numbers we have in BigO(n).
* Just find the sequece of i if only if (i - 1) is not exist in the set to speed up. Because if (i-1) exist, there must be longer one from (i-1).
* Remove recursive for speeding up.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/