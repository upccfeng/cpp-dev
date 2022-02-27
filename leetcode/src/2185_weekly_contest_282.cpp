#include <vector>
#include <string>

namespace p_2185_weekly_contest_282
{
    class Solution
    {
    public:
        int prefixCount(std::vector<std::string>& words, std::string pref)
        {
            int cnt = 0;

            for (const auto& w : words)
            {
                if (w.size() >= pref.size())
                {
                    cnt = w.substr(0, pref.size()) == pref ? cnt + 1 : cnt;
                }
            }

            return cnt;
        }
    };
} // namespace p_2185_weekly_contest_282

/*
# Problem:
https://leetcode.com/problems/counting-words-with-a-given-prefix/

## HINT:

## Time Complexity:
BigO(w * s)

## Space Complexity:
BigO(1)
*/