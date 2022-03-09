#include <vector>
#include <string>

namespace p_131
{
    class Solution
    {
        void getPalindrome(const std::string& s, std::vector<std::vector<std::string>>& ret, std::vector<std::string>& partition, int left_boundary, int right_boundary)
        {
            if (left_boundary > right_boundary)
            {
                ret.push_back(partition);
                return;
            }

            for (int mid = left_boundary; mid <= right_boundary; mid++)
            {
                // ood
                int left = mid;
                int right = mid;
                while (left >= left_boundary && right <= right_boundary && s[left] == s[right])
                {
                    if (left == left_boundary)
                    {
                        partition.emplace_back(s.substr(left, right - left + 1));
                        getPalindrome(s, ret, partition, right + 1, right_boundary);
                        partition.pop_back();
                    }

                    left--;
                    right++;
                }

                // even
                left = mid;
                right = mid + 1;
                while (left >= left_boundary && right <= right_boundary && s[left] == s[right])
                {
                    if (left == left_boundary)
                    {
                        partition.emplace_back(s.substr(left, right - left + 1));
                        getPalindrome(s, ret, partition, right + 1, right_boundary);
                        partition.pop_back();
                    }

                    left--;
                    right++;
                }
            }
        }

    public:
        std::vector<std::vector<std::string>> partition(std::string s)
        {
            std::vector<std::vector<std::string>> ret;
            std::vector<std::string> partition;
            getPalindrome(s, ret, partition, 0, s.size() - 1);

            return ret;
        }
    };
} // namespace p_131

/*
# Problem:
https://leetcode.com/problems/palindrome-partitioning/

## HINT:
* Start from mid to find the palindrome str.
* Find the palindrome strings which is connected.
* For a found palindrome str, find the left palindrome str which is started at previous' end + 1.

## Time Complexity:
BigO(n^3)

## Space Complexity:
BigO(n)
*/