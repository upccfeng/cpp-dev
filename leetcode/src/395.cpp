#include "assert.h"

#include <string>
#include <unordered_map>

namespace p_395
{
    class Solution
    {
        int longestSubstringByK(std::string& s, int k, int left, int right)
        {
            if (right - left + 1 < k)
            {
                return 0;
            }

            std::unordered_map<char, int> char_cnt;

            for (int i = left; i <= right; i++)
            {
                char_cnt[s[i]]++;
            }

            bool is_valid = true;
            for (auto& kv : char_cnt)
            {
                if (kv.second < k)
                {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid)
            {
                return right - left + 1;
            }

            int max = 0;
            int new_left = left;
            for (int i = left; i <= right; i++)
            {
                if (char_cnt[s[i]] < k)
                {
                    max = std::max(max, longestSubstringByK(s, k, new_left, i - 1));
                    new_left = i + 1;
                }
            }

            return std::max(max, longestSubstringByK(s, k, new_left, right));
        }

    public:
        int longestSubstring(std::string s, int k)
        {
            return longestSubstringByK(s, k, 0, s.size() - 1);
        }
    };
} // namespace p_395

/*
# Problem:
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

## HINT:
* For each string range, check is valid or not.
* If invalid, use the unvalid char to divide string into two string and check again.

## Time Complexity:
BigO(n ^ n)

## Space Complexity:
BigO(n)
*/