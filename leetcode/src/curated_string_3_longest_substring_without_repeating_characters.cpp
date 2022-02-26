#include <string>
#include <set>
#include <unordered_map>

namespace p_curated_string_3_longest_substring_without_repeating_characters
{
    class Solution
    {
        void clearUsed(const std::string& s, std::unordered_map<char, int>& used, int start, int end)
        {
            for (int i = start; i < end; ++i)
            {
                used.erase(s[i]);
            }
        }

    public:
        int lengthOfLongestSubstring(std::string s)
        {
            int ret = 0;
            int left = 0;

            std::unordered_map<char, int> used;
            // std::set<char> used;

            for (int right = 0; right < s.size(); ++right)
            {
                char& right_char = s[right];

                // Use set: Remove left element continuously until right_char doesn't exist.
                //while (used.find(right_char) != used.end())
                //{
                //    used.erase(s[left]);
                //    ++left;
                //}
                //
                //used.insert(right_char);

                if (used.find(right_char) == used.end())
                {
                    used[right_char] = right;
                }
                else
                {
                    int tmp = left;
                    left = used[right_char] + 1;

                    clearUsed(s, used, tmp, left);
                    used[right_char] = right;
                }

                ret = std::max(ret, right - left + 1);
            }


            return ret;
        }
    };
} // namespace p_curated_string_3_ngest-sub_ing-wit_t-repeati_characters

/*
# Problem:
https://leetcode.com/problems/longest-substring-without-repeating-characters/

## HINT:
* Use sliding window concept
* Adjust the right for each taking element.
* Adjust the left while there is a duplicated element. Note: Need to remove all of elements between left and new_left.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/