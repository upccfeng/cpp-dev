#include <string>
#include <unordered_map>
#include <limits.h>

namespace p_curated_string_76_minimum_window_substring
{
    class Solution
    {
        int moveLeftToMin(std::string& s/*, std::unordered_map<char, int>& s_map*/, std::unordered_map<char, int>& t_char_remained, int left, int right)
        {
            int new_left = left;

            for (new_left; new_left < right; ++new_left)
            {
                const char& taking_char = s[new_left];
                if (t_char_remained.find(taking_char) == t_char_remained.end())
                {
                    // --s_map[taking_char];
                }
                else
                {
                    if (t_char_remained[taking_char] < 0)
                    {
                        // --s_map[taking_char];
                        ++t_char_remained[taking_char];
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return new_left;
        }

        bool isValid(std::unordered_map<char, int>& t_char_cnt)
        {
            for (const auto& e : t_char_cnt)
            {
                if (e.second > 0)
                {
                    return false;
                }
            }

            return true;
        }

    public:
        std::string minWindow(std::string s, std::string t)
        {
            int ret_start = -1, ret_len = INT_MAX;

            std::unordered_map<char, int> /*s_char_cnt,*/ t_char_remained;

            for (const auto& c : t)
            {
                ++t_char_remained[c];
            }

            int left = 0;
            for (int right = 0; right < s.size(); ++right)
            {
                // ++s_char_cnt[s[right]];

                if (t_char_remained.find(s[right]) != t_char_remained.end())
                {
                    --t_char_remained[s[right]];
                }

                left = moveLeftToMin(s/*, s_char_cnt*/, t_char_remained, left, right);

                if (right - left + 1 >= t.size() && isValid(t_char_remained) && right - left + 1 < ret_len)
                {
                    ret_start = left;
                    ret_len = right - left + 1;
                }
            }


            return ret_start == -1 ? "" : s.substr(ret_start, ret_len);
        }
    };
} // namespace p_curated_string_76_minimum_window_substring

/*
# Problem:
https://leetcode.com/problems/minimum-window-substring/

## HINT:
* Use sliding windows
* Use a map to store how many chars are required for each target's element.
* Move left ptr to the position which is in target string and its required number is less than or equal to 0.
* Make sure all the elements' value in map is less than or equal to 0.

P.S. Use remained to cache the total number of elements in target is wrong, because there is a case that (-1 + 1) will be 0.
-> Can use another s_char_cnt map to just store the number of target char appearing number in s.
-> And you s_char_cnt == t_char_cnt to determine whether it is valid or not.

## Time Complexity:
BigO(t + t * s) -> BigO(t * s)

## Space Complexity:
BigO(t + s)
*/