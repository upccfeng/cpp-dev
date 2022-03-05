#include <vector>
#include <map>

namespace p_740
{
    class Solution
    {
        std::map<std::pair<std::map<int, int>, int>, int> cache;

        int getMax(std::map<int, int>& value_cnt, int left_cnt)
        {
            if (cache.find({ value_cnt, left_cnt }) != cache.end())
            {
                return cache[{ value_cnt, left_cnt }];
            }

            if (left_cnt == 0)
            {
                return 0;
            }

            int max = 0;

            for (auto& kv : value_cnt)
            {
                if (kv.second > 0)
                {

                    int left = left_cnt - 1;

                    int pre = 0;
                    if (value_cnt.find(kv.first - 1) != value_cnt.end())
                    {
                        pre = value_cnt[kv.first - 1];
                        left -= value_cnt[kv.first - 1];
                        value_cnt[kv.first - 1] = 0;
                    }

                    value_cnt[kv.first] -= 1;

                    int next = 0;
                    if (value_cnt.find(kv.first + 1) != value_cnt.end())
                    {
                        next = value_cnt[kv.first + 1];
                        left -= value_cnt[kv.first + 1];
                        value_cnt[kv.first + 1] = 0;
                    }

                    max = std::max(max, kv.first + getMax(value_cnt, left));

                    if (value_cnt.find(kv.first - 1) != value_cnt.end())
                    {
                        value_cnt[kv.first - 1] = pre;
                    }

                    value_cnt[kv.first] += 1;

                    if (value_cnt.find(kv.first + 1) != value_cnt.end())
                    {
                        value_cnt[kv.first + 1] = next;
                    }
                }
            }

            cache[{value_cnt, left_cnt}] = max;
            return cache[{value_cnt, left_cnt}];
        }
    public:
        int deleteAndEarnRecursive(std::vector<int>& nums)
        {
            std::map<int, int> value_cnt;

            for (auto e : nums)
            {
                ++value_cnt[e];
            }

            return getMax(value_cnt, nums.size());
        };

        int deleteAndEarn(std::vector<int>& nums)
        {
            std::vector<int> value_cnt(10001, 0);

            int max = 0;
            for (auto n : nums)
            {
                value_cnt[n]++;

                if (n > max)
                {
                    max = n;
                }
            }

            std::vector<int> dp(max + 1, 0);

            dp[0] = 0;
            dp[1] = value_cnt[1];

            for (int i = 2; i <= max; ++i)
            {
                dp[i] = std::max(dp[i - 2] + i * value_cnt[i], dp[i - 1]);
            }

            return dp[max];
        }
    };
} // namespace p_740

/*
# Problem:
https://leetcode.com/problems/delete-and-earn/

## HINT:
* The recursive way by coin remained count works, but not efficient.
* Should use adjacent concept to choose one or not.

## Time Complexity:
BigO(10000)

## Space Complexity:
BigO(10000)
*/