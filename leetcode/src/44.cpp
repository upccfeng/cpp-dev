#include <map>
#include <string>

namespace p_44
{
    class Solution
    {
        std::map<std::pair<int, int>, bool> cache;

        bool isSkippable(std::string& str, int pos)
        {
            if (pos >= str.size())
            {
                return true;
            }

            if (str[pos] != '*')
            {
                return false;
            }
            else
            {
                return isSkippable(str, pos + 1);
            }
        }

        bool isPosMatch(std::string& s, std::string& p, int s_pos, int p_pos)
        {
            if (cache.find({ s_pos, p_pos }) != cache.end())
            {
                return cache[{s_pos, p_pos}];
            }

            if (s_pos >= s.size() ||
                p_pos >= p.size())
            {
                if (s_pos >= s.size() && p_pos >= p.size())
                {
                    return true;
                }
                else if (s_pos < s.size())
                {
                    return false;
                }
                else
                {
                    return isSkippable(p, p_pos);
                }
            }

            cache[{s_pos, p_pos}] = false;

            char pc = p[p_pos];

            if (pc >= 'a' && pc <= 'z')
            {
                if (s[s_pos] == pc)
                {
                    cache[{s_pos, p_pos}] = isPosMatch(s, p, s_pos + 1, p_pos + 1);
                }
                else
                {
                    cache[{s_pos, p_pos}] = false;
                }
            }
            else if (pc == '?')
            {
                cache[{s_pos, p_pos}] = isPosMatch(s, p, s_pos + 1, p_pos + 1);
            }
            else // pc == '*'
            {
                bool c1 = isPosMatch(s, p, s_pos + 1, p_pos + 1);
                bool c2 = isPosMatch(s, p, s_pos, p_pos + 1);
                bool c3 = isPosMatch(s, p, s_pos + 1, p_pos);

                cache[{s_pos, p_pos}] = c1 || c2 || c3;
            }

            return cache[{s_pos, p_pos}];
        }

    public:
        bool isMatch(std::string s, std::string p)
        {
            return isPosMatch(s, p, 0, 0);
        }
    };
} // namespace p_44

/*
# Problem:
https://leetcode.com/problems/wildcard-matching/

## HINT:
* For s_pos and p_pos, there are belows cases
* - if p[p_pos] == '?', check (s_pos+1, p_pos+1).
* - if p[p_pos] == '*', check match_and_move(s_pos+1, p_pos+1), match_but_not_move(s_pos+1, p_pos), and do_not_match(s_pos, p_pos+1).
* - else              , if s[s_pos] == p[p_pos], check (s_pos+1, p_pos+1), else return false
* If s_pos out and p_pos out, return true
* If p_pos is not the end, check the rest of p is skippable or not.
* If s_pos is not the end, return false

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n * m)
*/