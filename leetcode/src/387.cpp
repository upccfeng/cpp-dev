#include "assert.h"
#include <string>
#include <unordered_map>

namespace p_387
{
    class Solution
    {
    public:
        int firstUniqChar(std::string s)
        {
            std::unordered_map<char, int> char_cnt;

            for (int i = 0; i < s.size(); i++)
            {
                char_cnt[s[i]]++;
            }

            for (int i = 0; i < s.size(); i++)
            {
                if (char_cnt[s[i]] == 1)
                {
                    return i;
                }
            }

            return -1;
        }
    };
} // namespace p_387

/*
# Problem:
https://leetcode.com/problems/first-unique-character-in-a-string/

## HINT:
* Use hash map

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/