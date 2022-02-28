#include <string>

namespace p_curated_string_5_longest_palindromic_substring
{
    class Solution
    {
    public:
        std::string longestPalindrome(std::string s)
        {
            int ret_start = -1;
            int ret_len = -1;
            for (int mid = 0; mid < s.size(); ++mid)
            {
                // odd case
                int left = mid;
                int right = mid;

                while (left >= 0 && right < s.size() && s[left] == s[right])
                {
                    --left;
                    ++right;
                }

                if (right - left - 1 > ret_len)
                {
                    ret_start = left + 1;
                    ret_len = right - left - 1;
                }

                // even case
                left = mid;
                right = mid + 1;

                while (left >= 0 && right < s.size() && s[left] == s[right])
                {
                    --left;
                    ++right;
                }

                if (right - left - 1 > ret_len)
                {
                    ret_start = left + 1;
                    ret_len = right - left - 1;
                }
            }

            return ret_len == -1 ? "" : s.substr(ret_start, ret_len);
        }
    };
} // namespace p_curated_string_5_longest_palindromic_substring

/*
# Problem:
https://leetcode.com/problems/longest-palindromic-substring/

## HINT:
* Use each element in the string as a middle instead of a beginning.
* For each element try in both of odd case and even case.
* Each element has its own char (len == 1) as result at least.

## Time Complexity:
BigO(n ^ 2)

## Space Complexity:
BigO(1)
*/