#include <string>
#include <unordered_map>

namespace p_curated_dp_91_decode_ways
{
    class Solution
    {
        std::unordered_map<int, int> cache;

        int get_max_count(std::string& s, int pos)
        {
            if (pos > s.size())
            {
                return 0;
            }
            else if (pos == s.size())
            {
                return 1;
            }
            else
            {
                if (cache.find(pos) != cache.end())
                {
                    return cache[pos];
                }

                int len = 1;
                cache[pos] = 0;
                while (len <= 2)
                {
                    if (pos + len - 1 < s.size())
                    {
                        int number = 0;

                        for (int i = 0; i < len; ++i)
                        {
                            number = number * 10 + (s[pos + i] - 48);
                        }

                        if (number <= 26 && number > 0)
                        {
                            cache[pos] += get_max_count(s, pos + len);
                        }
                        else
                        {
                            break;
                        }

                        ++len;
                    }
                    else
                    {
                        break;
                    }
                }

                return cache[pos];
            }
        }

    public:
        int numDecodings(std::string s)
        {
            return get_max_count(s, 0);
        }
    };
} // namespace p_curated_dp_91_decode_ways

/*
# Problem:
https://leetcode.com/problems/decode-ways/

## HINT:
* get_count(0) means get the counts from position 0.
* get_count(0) is equal to get_count(0 + 1), if s.substr(0, 1) is valid + get_count(0 + 2), if s.substr(0, 2) is valid.
* get_count(pos), if pos == s.size() return 1 (decode successfully), if pos > s.size() return 1 (fail to decode).
* Use cache to speed up.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/