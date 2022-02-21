#include <vector>
#include <unordered_map>
#include <string>

namespace p_curated_dp_139_word_break
{
    class Solution
    {
        std::unordered_map<int, bool> cache;

        bool isBreakable(std::string& target, std::vector<std::string>& dict, int start_pos)
        {
            if (start_pos == target.size())
            {
                return true;
            }
            else if (start_pos > target.size())
            {
                return false;
            }
            else
            {
                if (cache.find(start_pos) != cache.end())
                {
                    return cache[start_pos];
                }

                cache[start_pos] = false;

                for (auto& word : dict)
                {
                    if (target.substr(start_pos, word.size()) == word)
                    {
                        cache[start_pos] |= isBreakable(target, dict, start_pos + word.size());
                    }
                }

                return cache[start_pos];
            }
        }

    public:
        bool wordBreak_cache(std::string s, std::vector<std::string>& wordDict)
        {
            return isBreakable(s, wordDict, 0);
        }

        bool wordBreak_dp(std::string s, std::vector<std::string>& wordDict)
        {
            std::vector<bool> dp(s.size() + 1, false);

            dp[s.size()] = true;

            for (int i = s.size() - 1; i >= 0; --i)
            {
                for (auto& word : wordDict)
                {
                    if (word.size() <= s.size() - i)
                    {
                        dp[i] = (s.substr(i, word.size()) == word) & dp[i + word.size()];

                        if (dp[i])
                            break;
                    }
                }
            }

            return dp[0];
        }

        bool wordBreak(std::string s, std::vector<std::string>& wordDict)
        {
            return wordBreak_dp(s, wordDict);
        }
    };
} // namespace p_curated_dp_139_word_break

/*
# Problem:
https://leetcode.com/problems/word-break/

## HINT:
* Use start_pos and use s.substr(start_pos, word.size()) to compare with word instead of constructing new string and pass into next function.
* Use DP with Bottom-up method to speed up.
* In DP method, dp[s.size()] means there is no more charator to compare, so it is true.

## Time Complexity:
BigO(n * m * n)

Note:
The second n is the times of compare two string.

## Space Complexity:
BigO(n)
*/