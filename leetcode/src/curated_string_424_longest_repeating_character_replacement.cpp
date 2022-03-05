#include <vector>
#include <unordered_map>

namespace p_curated_string_424_longest_repeating_character_replacement
{
    class Solution
    {
        int getMaxCntChar(std::vector<int>& char_cnt)
        {
            int max_cnt = 0;

            for (int i = 0; i < char_cnt.size(); ++i)
            {
                if (char_cnt[i] >= max_cnt)
                {
                    max_cnt = char_cnt[i];
                }
            }

            return max_cnt;
        }

    public:
        int characterReplacement(std::string s, int k)
        {
            int ret = 0;

            std::vector<int> char_cnt(26, 0);

            int left = 0;
            for (int right = 0; right < s.size(); ++right)
            {
                ++char_cnt[s[right] - 65];

                while (right - left + 1 - getMaxCntChar(char_cnt) > k)
                {
                    --char_cnt[s[left] - 65];
                    ++left;
                }

                ret = std::max(ret, right - left + 1);
            }

            return ret;
        }
    };
} // namespace p_curated_string_424_longest_repeating_character_replacement

/*
# Problem:
https://leetcode.com/problems/longest-repeating-character-replacement/

## HINT:
* Use sliding window.
* The (right - left + 1) - max_count shoud be smaller than k.
* Once substr is invalid, move left to left+1 until substr is valid.

## Time Complexity:
BigO(26 * n)

## Space Complexity:
BigO(26)
*/