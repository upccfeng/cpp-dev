#include <unordered_map>
#include <string>

namespace p_2186_weekly_contest_282
{
    class Solution
    {
    public:
        int minSteps(std::string s, std::string t)
        {
            std::unordered_map<char, int> s_char_cnt;
            std::unordered_map<char, int> t_char_cnt;

            int s_total = 0;
            for (const auto& c : s)
            {
                ++s_char_cnt[c];
                ++s_total;
            }

            int t_total = 0;
            for (const auto& c : t)
            {
                ++t_char_cnt[c];
                ++t_total;
            }

            int ret = 0;

            for (const auto& s_kv : s_char_cnt)
            {
                if (t_char_cnt.find(s_kv.first) == t_char_cnt.end())
                {
                    ret += s_kv.second;
                }
                else
                {
                    if (s_kv.second > t_char_cnt[s_kv.first])
                    {
                        ret += s_kv.second - t_char_cnt[s_kv.first];
                    }
                }
            }

            for (const auto& t_kv : t_char_cnt)
            {
                if (s_char_cnt.find(t_kv.first) == s_char_cnt.end())
                {
                    ret += t_kv.second;
                }
                else
                {
                    if (t_kv.second > s_char_cnt[t_kv.first])
                    {
                        ret += t_kv.second - s_char_cnt[t_kv.first];
                    }
                }
            }

            return ret;
        }
    };
} // namespace p_2186_weekly_contest_282

/*
# Problem:
https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

## HINT:
* Use two structures (s_char_cnt, t_char_cnt) to store the appearing number of each element in each string.
* For each elements in each structures, count the difference between s_char_cnt and t_char_cnt.

## Time Complexity:
BigO(s + t)

## Space Complexity:
BigO(s + t)
*/