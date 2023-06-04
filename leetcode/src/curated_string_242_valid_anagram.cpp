#include <string>
#include <vector>
#include <unordered_map>

namespace p_curated_string_242_valid_anagram
{
    class Solution
    {
    public:
        bool isAnagram(std::string s, std::string t)
        {
            if (s.size() != t.size())
            {
                return false;
            }

            std::unordered_map<char, int> s_char_cnt;
            std::unordered_map<char, int> t_char_cnt;
            // std::vector<int> s_char_cnt(26, 0);
            // std::vector<int> t_char_cnt(26, 0);

            for (const auto& c : s)
            {
                ++s_char_cnt[c];
                // ++s_char_cnt[c - 97];

            }

            for (const auto& c : t)
            {
                ++t_char_cnt[c];
                // ++t_char_cnt[c - 97];
            }


            return s_char_cnt == t_char_cnt;
        }
    };
} // namespace p_curated_string_242_valid_anagram

/*
# Problem:
https://leetcode.com/problems/valid-anagram/

## HINT:
* Use two data structures(vector, map, hash_map) to record the number of appearing characters in each string.
* Return the comparison of these two structures.

## Time Complexity:
BigO(s + t)

## Space Complexity:
BigO(s + t) or BigO(26)
*/