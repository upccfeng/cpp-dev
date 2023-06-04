#include <string>
#include <vector>
#include <sstream>
#include "assert.h"

namespace p_140
{
    class Solution
    {
        void findBreakable(std::string& s, std::vector<std::string>& wordDict, std::vector<std::string>& ret, std::vector<std::string>& words, int pos)
        {
            if (pos > s.size())
            {
                assert(false);
                return;
            }

            if (pos == s.size())
            {
                std::stringstream ss;

                for (int i = 0; i < words.size(); i++)
                {
                    ss << words[i];

                    if (i != words.size() - 1)
                    {
                        ss << " ";
                    }
                }

                ret.emplace_back(ss.str());
                return;
            }

            for (const auto& str : wordDict)
            {
                if (pos + str.size() - 1 < s.size() && s.substr(pos, str.size()) == str)
                {
                    words.emplace_back(str);

                    findBreakable(s, wordDict, ret, words, pos + str.size());

                    words.pop_back();
                }
            }
        }

    public:
        std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict)
        {
            std::vector<std::string> ret;
            std::vector<std::string> words;

            findBreakable(s, wordDict, ret, words, 0);

            return ret;
        }
    };
} // namespace p_140

/*
# Problem:
https://leetcode.com/problems/word-break-ii/

## HINT:
* Find the next breakable word in wordDict until the position is just exactly equal to s.size().

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n)
*/