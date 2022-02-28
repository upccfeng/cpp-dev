#include <string>

namespace p_curated_string_647_palindromic_substrings
{
    class Solution
    {
        int getPalindromicCount(const std::string& s, int pos)
        {
            int cnt = 0;

            // odd case
            int left = pos;
            int right = pos;
            while (left >= 0 && right <= s.size() && s[left] == s[right])
            {
                --left;
                ++right;

                ++cnt;
            }

            // even case
            left = pos;
            right = pos + 1;
            while (left >= 0 && right <= s.size() && s[left] == s[right])
            {
                --left;
                ++right;

                ++cnt;
            }

            return cnt;
        }

    public:
        int countSubstrings(std::string s)
        {
            int ret = 0;

            for (int pos = 0; pos < s.size(); ++pos)
            {
                ret += getPalindromicCount(s, pos);
            }

            return ret;
        }
    };
} // namespace p_curated_string_647_palindromic_substrings

/*
# Problem:
https://leetcode.com/problems/palindromic-substrings/

## HINT:
* Refer to problem-5: longest_palindromic_substring
* Use each element in the string as a middle instead of a beginning.
* Consider the odd case and even case.

## Time Complexity:
BigO(n ^ 2)

## Space Complexity:
BigO(1)
*/