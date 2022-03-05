#include <map>
#include <string>

namespace p_10
{
    class Solution
    {
        std::map<std::pair<int, int>, bool> cache;

        bool isRemainingSkippable(std::string& str, int pos)
        {
            bool moved = true;

            while (moved)
            {
                moved = false;

                if (pos + 1 >= str.size())
                {
                    break;
                }

                if (str[pos + 1] == '*')
                {
                    pos += 2;
                    moved = true;
                }
            }

            if (pos == str.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isPosMatch(std::string& s, std::string& p, int s_pos, int p_pos)
        {
            if (cache.find({ s_pos, p_pos }) != cache.end())
            {
                return cache[{ s_pos, p_pos }];
            }

            if (s_pos >= s.size())
            {
                if (p_pos >= p.size())
                {
                    return true;
                }
                else
                {
                    return isRemainingSkippable(p, p_pos);
                }
            }

            if (s_pos >= s.size())
            {
                return false;
            }

            auto pattern_char = p[p_pos];
            bool repeatable = true;
            if (p_pos + 1 >= p.size() ||
                p[p_pos + 1] != '*')
            {
                repeatable = false;
            }

            cache[{ s_pos, p_pos }] = false;

            if (pattern_char == '.' ||
                pattern_char == s[s_pos])
            {
                if (repeatable)
                {
                    bool match_move = isPosMatch(s, p, s_pos + 1, p_pos + 2);
                    bool match_no_move = isPosMatch(s, p, s_pos + 1, p_pos);
                    bool no_match = isPosMatch(s, p, s_pos, p_pos + 2);

                    cache[{ s_pos, p_pos }] = match_move || match_no_move || no_match;
                }
                else
                {
                    cache[{ s_pos, p_pos }] = isPosMatch(s, p, s_pos + 1, p_pos + 1);
                }
            }
            else
            {
                if (repeatable)
                {
                    cache[{ s_pos, p_pos }] = isPosMatch(s, p, s_pos, p_pos + 2);
                    return isPosMatch(s, p, s_pos, p_pos + 2);
                }
                else
                {
                    cache[{ s_pos, p_pos }] = false;
                }
            }

            return cache[{ s_pos, p_pos }];
        }

    public:
        bool isMatch(std::string s, std::string p)
        {
            return isPosMatch(s, p, 0, 0);
        }
    };
} // namespace p_10

/*
# Problem:
https://leetcode.com/problems/regular-expression-matching/

## HINT:
* Dynamic Programming
* Consider the cases of isMatch * isRepeatable(move, no_move, no_match)

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n * m)
*/