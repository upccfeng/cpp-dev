#include "assert.h"
#include <limits.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cstddef>


namespace p_340
{
    struct MyHash
    {
        size_t operator()(const std::pair<int, int>& key) const
        {
            return std::hash<int>()(key.first) ^ (std::hash<int>()(key.second) << 1);
        }
    };

    class Solution
    {
        // std::map<std::pair<int, int>, int> cache;

        std::unordered_map<std::pair<int, int>, int, MyHash> cache;

        int getMax(std::string& s, std::unordered_set<int>& char_set, int pos, int left_cnt)
        {
            std::pair<int, int> key = { pos, left_cnt };
            if (cache.find(key) != cache.end())
            {
                return cache[key];
            }


            if (pos == s.size())
            {
                return 0;
            }

            if (char_set.find(s[pos]) != char_set.end())
            {
                cache[key] = 1 + getMax(s, char_set, pos + 1, left_cnt);
                return cache[key];
            }

            if (left_cnt == 0)
            {
                return 0;
            }
            else
            {
                char_set.insert(s[pos]);

                cache[key] = 1 + getMax(s, char_set, pos + 1, left_cnt - 1);
                return cache[key];
            }

        }

        char getSmallest(std::map<char, int>& char_map)
        {
            assert(char_map.size() > 0);

            int min = INT_MAX;
            char min_char;

            for (auto& kv : char_map)
            {
                if (kv.second < min)
                {
                    min = kv.second;
                    min_char = kv.first;
                }
            }

            return min_char;
        }

    public:

        int lengthOfLongestSubstringKDistinctTwoPointers(std::string& s, int k)
        {
            if (k == 0)
            {
                return 0;
            }

            int l = 0;
            int r = 0;

            std::map<char, int> char_map;
            int max = 0;
            while (r < s.size())
            {
                if (k > 0)
                {
                    if (char_map.find(s[r]) == char_map.end())
                    {
                        k--;
                    }

                    char_map[s[r]] = r;
                }
                else
                {
                    assert(k == 0);

                    if (char_map.find(s[r]) == char_map.end())
                    {
                        // move left to smallest positon + 1
                        char c = getSmallest(char_map);

                        l = char_map[c] + 1;
                        char_map.erase(c);

                        char_map[s[r]] = r;
                    }
                    else
                    {
                        char_map[s[r]] = r;
                    }
                }

                max = std::max(max, r - l + 1);

                r++;
            }


            return max;
        }

        int lengthOfLongestSubstringKDistinctRecursive(std::string& s, int k)
        {
            int max = 0;

            for (int i = 0; i < s.size(); i++)
            {
                std::unordered_set<int> char_set;
                max = std::max(max, getMax(s, char_set, i, k));
            }

            return max;
        }

        int lengthOfLongestSubstringKDistinct(std::string s, int k)
        {
            return lengthOfLongestSubstringKDistinctTwoPointers(s, k);
        }
    };
} // namespace p_340

/*
# Problem:
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

## HINT:
* Use two pointer with map which record the char_set's last position.
* While k is zero, move the left pointer to the smallest position + 1, and remove the samllest entry.

## Time Complexity:
BigO(n * k)

## Space Complexity:
BigO(k)
*/